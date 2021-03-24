#pragma once

#include <stdlib.h>

/*
** Page
** 
** Used for storing information about
** a page and its content.
*/
typedef struct Page {
	char *name;
	char *slug;
	char *mdFile;
} Page;

/*
** PageCollection
** 
** Used for storing information about
** a directory and its contents.
*/
typedef struct PageCollection {
	char *name;
	char *slug;
	Page *pages;
	struct PageCollection *children;
} PageCollection;

/*
** PageCollectionArray
**
** Dynamic array of PageCollections
*/
typedef struct {
  PageCollection *items;
  size_t length;
  size_t allocSize;
} PageCollectionArray;

PageCollectionArray newPageCollectionArray( size_t allocSize ) {
  PageCollectionArray a;
  a.items = malloc( sizeof( PageCollection ) * allocSize );
  a.length = 0;
  a.allocSize = allocSize;
  return a;
}

void appendPageCollectionArray(
	PageCollectionArray *a,
	PageCollection item
) {
  if ( a->length == a->allocSize ) {
    a->allocSize *= 2;
    a->items = realloc(
    	a->items,
    	a->allocSize * sizeof( PageCollection )
    );
  }
  a->items[a->length++] = item;
}

void freePageCollectionArray( PageCollectionArray *a ) {
  free( a->items );
  a->items = NULL;
  a->length = a->allocSize = 0;
}