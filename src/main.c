#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

/*
** void get_md_files( char *directory, int depth )
**
** Finds all markdown files within a directory and 
** stores the filenames in an array.
*/

void get_md_files( char *directory );

/*
** void print_md_file( char *filepath )
**
** Prints an MD file's content.
*/

void print_md_file( char *filepath );


//
// Entry call
//

int
main( void )
{
	get_md_files( "./pages" );
	
	return 0;
}


//
// Function definitions
//

void
print_md_file( char *filepath )
{
	FILE *md_file;
	int _char;

	md_file = fopen( filepath, "r" );
	if ( md_file == NULL ) {
		fprintf( stderr, "Unable to open %s\n", filepath );
		exit(1);
	}

	while( (_char = fgetc( md_file )) != EOF )
	{
		putchar( _char );
	}

	fclose( md_file );
}

void
get_md_files( char *directory )
{
	DIR *folder;
	struct dirent *entry;
	struct stat filestat;

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

	while(( entry = readdir( folder ) ))
	{
		stat( entry->d_name, &filestat );
		if ( S_ISDIR( filestat.st_mode ) )
		{
			if (
				strcmp( entry->d_name, "." ) == 0 ||
				strcmp( entry->d_name, ".." ) == 0
			) {
				continue;
			}

			get_md_files( entry->d_name );
		}
		else
		{
			char filename[1024];
			getcwd( filename, 1024 );
			strcat( filename, "/" );
			strcat( filename, entry->d_name );
			printf( "%s\n", filename );
			print_md_file( filename );
			puts( "\n\n" );
		}
	}

	chdir( ".." );
	closedir( folder );
}
