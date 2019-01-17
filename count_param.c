#include <stdio.h>
#include <string.h>

void read_file(char *ch){
	FILE *fptr;
	int MAX = 100, idx = 1;

	fptr = fopen(ch, "r");
	if(fptr == NULL)
		printf("File does not exist.\n");
	else{
		printf("Contents of '%s':\n", ch);
		char line[MAX];
		// The maximum allowable length for an identifier is 31 characters long.
		while( fgets(line,MAX,fptr) ){
			printf("%d. %s", idx++, line);
		}
	}
}

int main(int argc, char *argv[]){
	printf("Number of arguments: %d\n", argc);
	if(argc==1){
		printf("Command line arguments not passed.\n");
	}
	else{
		printf("Arguments are: ");
		for(int i=0 ; i<argc ; i++){
			if(i<argc-1)
				printf("\"%s\", ", argv[i]);
			else
				printf("\"%s\".\n", argv[argc-1]);
		}
		/*
		   If "Keywords.txt" is passed as a first argument
			$ gcc count_param.c
			$ ./a.out Keywords.txt 
		*/
		read_file(argv[1]);	// Reading the keywords file
	}
	return 0;
}
