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

/* Main Execution */
int main(int argc, char* argv[]) {
    
    int argind = 1;
    
    /* Parse command line arguments */
    PROGRAM_NAME = argv[0];
    while(argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-'){
        char * arg = argv[argind++];
        switch(arg[1]){
            case 'h':
                usage(0);
                break;
			case 'c':
				//Call the CamelCase
				while(i<arc)
				{
					camelCase(argv[i]);
				}
				//Says I want every file here to become camelCase;
				break;
			case 'u':
				// Say I want a file with underscore
				break;
            default:
                usage(1);
                break;
      }
  }
  
  return EXIT_SUCCESS;
}
