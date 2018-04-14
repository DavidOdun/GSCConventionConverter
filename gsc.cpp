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
	while (fgets(buffer, BUFSIZ, stream))
	{
		int LOW = strlen(buffer);
		for (int i = 0; i < strlen(buffer); i++){
			
			if (buffer[i] == '_'){
				for (int j = i; j < LOW; j++)
				{
					buffer[j] = buffer[j+1];
				}
				buffer[i] = toupper(buffer[i]);
			}
		}
		fputs(buffer, stdout);
	}
}

void camelFile(const char *path)
{
	FILE *fs = fopen(path, "r+");
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
				camelFile(arg);
				break;
			case 'u':	// everything to become underscore
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
				camelcase(stdin);
			}
			else{
				camelFile(path);
			}
		}
	}

	return EXIT_SUCCESS;
}
