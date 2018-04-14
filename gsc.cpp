#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* PROGRAM_NAME = NULL;

/* Functions */
void usage(int status){
	fprintf(stderr, "Usage: %s FILES...\n", PROGRAM_NAME);
	exit(status);
}

void camelcase(FILE *stream)
{
	char buffer [BUFSIZ];
	size_t i = 0;
	while (fgets(buffer, BUFSIZ, stream))
	{
		if (buffer[i] == '_')
			buffer[i] = toupper(buffer[i-1]);
		i++;
		fputs(buffer, stdout);
	}
}

void camelFile(const char *path)
{
	FILE *fs = fopen(path, "w");
	if (fs == NULL)
	{
		fprintf(stderr, "%s: %s: %s\n", PROGRAM_NAME);
		return;
	}	else	{
		camelcase(fs);
		fclose(fs);
	}
}

/* Main Execution */
int main(int argc, char* argv[]) {

int argind = 1;

	/* Parse command line arguments */
	PROGRAM_NAME = argv[0];
	while(argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-')
	{
		//cout << "start parsing" << endl;
		char * arg = argv[argind++];
		switch(arg[1])	{
			case 'h':
		  		usage(0);
		  	break;
			case 'c':	// I was everything here to be camelcase
				puts("here1");
				camelFile(arg);
				break;
			case 'u':	// everything to become underscore*/
			default:
		  		usage(1);
		  	break;
		}
	}

	/* Process each file */
	if (argind == argc)
		camelcase(stdin);
	else
	{
		while (argind < argc){
			char *path = argv[argind++];
			if (strcmp(path, "-") == 0){
				puts("here2");
				camelcase(stdin);
			}
			else{
				camelFile(path);
			}
		}
	}

	return EXIT_SUCCESS;
}
