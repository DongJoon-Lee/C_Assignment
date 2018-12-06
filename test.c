# include <stdio.h>
# include <string.h>

int main (void) {
	char str[20];
	fgets(str, 19, stdin);
	str[strlen(str)-1] = '\0';
	char * tmp = str;
	printf("%c\n", tmp[1]);
	printf("%s\n", str+1);
	return 0;
}
