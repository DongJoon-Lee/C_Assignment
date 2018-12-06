# include <stdio.h>
# include <string.h>

int main (void) {
	char test[100] = {"I am not a boy"};
	char * ptr;

	ptr = strtok(test," ");
	do {
		printf("%s\n", ptr);
		printf("%s\n", test);
		ptr = strtok(NULL, " ");
	} while (ptr != NULL) ;

	return 0;
}
