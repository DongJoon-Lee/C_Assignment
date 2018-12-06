# include <stdio.h>


char * strtok(char* str1, const char *str2);

int main (void) {
	char str1[] = {"Hello World"};
	const char *str2 = " ";

	//strtok(str1, str2);
    char * ptr = strtok(str1, str2);
	while (ptr != NULL) {
		printf("*****************%s\n", ptr);
		ptr = strtok(NULL, str2);
	}
	return 0;
}


char *strtok(char *str1, const char *str2) {
	static int num = 0;
	static char *tmp = NULL;
	static char *tmp2 = NULL;
	static int strlen = 0;

	if (str1 != NULL) {
	    tmp2 = str1;
	    while( str1[strlen] != 0) {
		    strlen ++;
	    }
	}
	printf("test1 : %d\n", strlen); // test1

	tmp = tmp2;


	printf("test 1.5 = %d\n", num);//test 1.5
	printf("test2 : %s\n", tmp); // test2
	num++;
	if (str1 == NULL) {
		for(int i = num; i < strlen; i ++) {
			if (i == strlen-1) {
				return NULL;
			}
			else if(tmp[i] != *str2) {
				
				num ++;
				printf("num plus : %d\n", num); // num plus test
			}
			else {
				tmp[i] = '\0';
				break;
			}
		}
		
	}
	else {
		for (int i = num; i < strlen; i ++) {
			if (tmp[i] != *str2) {
				num ++;
			}
			else {
				tmp[i] = '\0';
				if ( i == strlen-1) {
					return NULL;
				}
				else {
				    tmp2 = tmp + i + 1;
			    	break;
				}
			}
		}
	}
	printf("test 3 : %s\n", tmp2);// test3
	printf("test 4 :%s\n", tmp);//test4

	return tmp;
}
