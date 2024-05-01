#include <stdlib.h>
#include <assert.h>
#include "world.h"

Body* bodies = NULL;
int bodyCount = 0;

Body* CreateBody()
{
    // malloc allocates memory for the new body
    Body* newBody = (Body*)malloc(sizeof(Body));

    if (newBody == NULL) 
    {
        return NULL;
    }

    // initializes prev in newBody to to NULL, and next to the head of the list
    newBody->prev = NULL;
    newBody->next = bodies; 

    // checks if list is empty, if not, updates prev in newBody
    if (bodies != NULL) 
    {
        bodies->prev = newBody;
    }

    // updates head of list with newBody
    bodies = newBody;

    bodyCount++;
    return newBody;
}

void DestroyBody(Body* body)
{
    // makes sure the body given is not null
    assert(body != NULL);

    // If 'prev' is not NULL, set 'prev->next' to 'body->next'
    if (body->prev != NULL) {
        body->prev->next = body->next;
    }

    // following two if statements essentially just check to see if the body is the first or last in the list, and then it makes
    // the necessary adjustments

    if (body->next != NULL) {
        body->next->prev = body->prev;
    }

    if (bodies == body) {
        bodies = body->next;
    }

    bodyCount--;

    // deletes the body and frees up the space in memory it was taking up
    free(body);
}