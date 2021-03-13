#include <stdio.h>
#include <stdbool.h>

#include "fileutils.h"
#include "pages.h"
#include "ptrarray.h"


void printFiles( char* directory, PtrArray files )
{
	printf("\nDir: %s has %d files\n", directory, files.length );
	bool hasIndex = false;
	if ( files.length > 0 ) {
		for ( int i = 0; i < files.length; ++i )
		{
			printf( "%s/%s\n", directory, files.items[i] );
			hasIndex = strcmp( files.items[i], "index.md" ) == 0;
		}
	}
	printf( "Has index file? %s\n", hasIndex ? "Yes" : "No" );
}

//
// Entry call
//

int
main( void )
{
	PageCollection *collections;
	collections = allocPageCollections( 2 );

	fileSearch( "./pages", ".md", &printFiles );

	return 0;
}