#include <stdio.h>
#include <stdbool.h>

#include "fileutils.h"
#include "pages.h"
#include "ptrarray.h"

PageCollectionArray menu;

void createCollection( char* directory, PtrArray files )
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
	
	PageCollection menuItem;
	menuItem.name = malloc( strlen( directory ) + 1 );
	strcpy( menuItem.name, directory );
	appendPageCollectionArray( &menu, menuItem );
}

//
// Entry call
//

int
main( void )
{
	menu = newPageCollectionArray( 1 );
	fileSearch( "./pages", ".md", &createCollection );

	puts("");
	for (int i = 0; i < menu.length; ++i)
	{
		printf("%s\n", menu.items[i].name);
	}
	return 0;
}