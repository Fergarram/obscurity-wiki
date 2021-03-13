#ifndef PTR_ARRAY_H
#define PTR_ARRAY_H

#include <stdlib.h>

typedef struct {
  void **items;
  size_t length;
  size_t allocSize;
} PtrArray;

PtrArray createPtrArray( size_t allocSize ) {
  PtrArray a;
  a.items = malloc(allocSize * sizeof(void*));
  a.length = 0;
  a.allocSize = allocSize;
  return a;
}

void appendPtrArray( PtrArray *a, void *item ) {
  if ( a->length == a->allocSize ) {
    a->allocSize *= 2;
    a->items = realloc( a->items, a->allocSize * sizeof(void*) );
  }
  a->items[a->length++] = item;
}

void freePtrArray( PtrArray *a ) {
  free( a->items );
  a->items = NULL;
  a->length = a->allocSize = 0;
}

#endif