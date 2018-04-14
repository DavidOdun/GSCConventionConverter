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

void camelCaseToUnderscore(char* s){
    int numCaps = 0;
    char final[BUFSIZ];
    int totalLength = 0;

    printf("string length: %d\n", strlen(s));

    // Loop through the string to find the 
    // number of upper-case letters in the string
    for(int i = 0; i < strlen(s); i++){
        if(isupper(s[i])){
            numCaps++;
        }
    }

    totalLength = strlen(s) + numCaps;

    // Initialize array to hold the indices of
    // of the upper-case letters
    int indexOfCaps[numCaps];

    for(int i = 0; i < strlen(s); i++){
        if(isupper(s[i])){
            char temp = final[i];
            final[i] = '_';
            final[i+1] = tolower(temp);
        } else {
            final[i] = s[i];
        }
    }

    puts(final);
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
            default:
                usage(1);
                break;
      }
  }
  
  return EXIT_SUCCESS;
}
