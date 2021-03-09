#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int
main( void )
{
	struct dirent *entry;
	struct stat filestat;
	DIR *folder = opendir("./pages");
	char filename[1024] = "pages/";

	if ( folder == NULL )
	{
		perror( "Unable to read directory\n" );
		return 1;
	}
	
	while(( entry = readdir( folder ) ))
	{
		char filename[1024] = "pages/";
		strcat( filename, entry->d_name );

		if ( stat( filename, &filestat ) == -1 )
		{
			perror("Got this while calling stat()");
		}

		char *type = S_ISDIR(filestat.st_mode) ? "Dir" : "File";
		printf( "%s: %s\n", type, filename );
	}

	closedir( folder );

	return 0;
}
