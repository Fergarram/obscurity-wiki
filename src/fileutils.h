#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#include "ptrarray.h"

/*
** void fileSearch(
**     char *directory,
**     char *extension,
** 	   void ( *callback )( char*, PtrArray )
** )
**
** Searches for files with a specific extension
** and executes a callback with the files within 
** each directory per directory found.
** 
*/

void fileSearch(
	char *directory,
	char *extension,
	void ( *callback )( char*, PtrArray )
) {
	DIR *folder;
	struct dirent *entry;

	if ( chdir( directory ) ) {
		fprintf( stderr, "Error changing to %s\n", directory );
		exit(1);
	}

	folder = opendir( "." );
	if ( folder == NULL ) {
		fprintf(
			stderr, "Unable to read directory %s\n", directory
		);
		exit(1);
	}

	PtrArray dirFiles = createPtrArray( 1 );

	while(( entry = readdir( folder ) ))
	{
		struct stat filestat;
		stat( entry->d_name, &filestat );

		if ( S_ISDIR( filestat.st_mode ) )
		{
			if (
				strcmp( entry->d_name, "." ) == 0 ||
				strcmp( entry->d_name, ".." ) == 0
			) {
				continue;
			}

			fileSearch(
				entry->d_name,
				extension,
				*callback
			);
		}
		else
		{
			if ( strstr( entry->d_name, extension ) != NULL ) {
				appendPtrArray( &dirFiles, entry->d_name );
			}
		}
	}

	char dirname[1024];
	getcwd( dirname, 1024 );
	(*callback)( dirname, dirFiles );

	chdir( ".." );
	closedir( folder );
}

/*
** void printMDFile( char *filepath )
**
** Prints an MD file's content.
*/
void
printMDFile( char *filepath )
{
	FILE *mdFile;
	int _char;

	mdFile = fopen( filepath, "r" );
	if ( mdFile == NULL ) {
		fprintf( stderr, "Unable to open %s\n", filepath );
		exit(1);
	}

	while( (_char = fgetc( mdFile )) != EOF )
	{
		putchar( _char );
	}

	fclose( mdFile );
}

#endif