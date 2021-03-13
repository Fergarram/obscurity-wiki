#ifndef PAGES_H
#define PAGES_H

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
** Page* allocPages( int length )
**
** Returns a collection array.
*/
Page*
allocPages( int length )
{
	return ( Page * ) malloc(
		sizeof( Page ) * length
	);
}

/*
** PageCollection* allocPageCollectiosn( int length )
**
** Returns a collection array.
*/
PageCollection*
allocPageCollections( int length )
{
	return ( PageCollection * ) malloc(
		sizeof( PageCollection ) * length
	);
}

#endif