//연습용 2
//string.h 파일 없이 strtok을 만드는데 성공했습니다.
//코드 정리가 필요해보입니다. 필요없거나 중복되어있는게 있습니다.

# include <stdio.h>

char *strtok(char *str1, const char *str2);

int main (void) {
	char str1[] = {"abcde fghij"}; // 테스트 문장 1
	char str2[] = {"abcde fghij klmno"}; // 테스트 문장 2
	char str3[] = {"abcde fghij klmno pqrst"}; //테스트 문장 3

	
	char *ptr = NULL;
	

	//테스트 케이스 1
	ptr = strtok(str1, " ");
	while (ptr != NULL) {
		printf("%s\n", ptr);
		ptr = strtok(NULL, " ");
	}

	printf("-----------------\n");
	
	//테스트 케이스 2
	ptr = strtok(str2, " ");
	while (ptr!= NULL) {
		printf("%s\n", ptr);
		ptr = strtok(NULL, " ");
	}

	printf("-----------------\n");

	//테스트 케이스 3
	ptr = strtok(str3, " ");
	while (ptr!=NULL) {
		printf("%s\n", ptr);
		ptr = strtok(NULL, " ");
	}

	return 0;
}



char *strtok(char *str1, const char *str2) {
	
	static char *tmp1 = NULL; // 메인 tmp입니다.
	static char *tmp2 = NULL; // 백업용 tmp입니다.

	static int count = 0, count2 = 0;

	static int strlen = 0; // str의 길이를 저장합니다.

	if (str1 != NULL) { // str1이 NULL이 아닐때, 즉 첫 번째 strtok에 들어갈때
	    if (str1 != tmp2) {
			count = 0;
			count2 = 0;
			strlen = 0;
		}
		while (str1[strlen] != 0) {
	    	strlen ++;
	    }
	    //str의 길이를 저장했습니다.
		
		tmp2 = str1;
		tmp1 = tmp2;

		for(int i = count; i < strlen; i ++) {
			if (tmp1[i] != *str2) {
				count ++;
			}

			else if (tmp1[i] == *str2) {
				count ++;
				tmp1[i] = '\0';
				return tmp1;
			}
			else {
				return NULL;
			}
		}
	}
	else { // str1이 NULL, 즉 두 번째 이상일 때 입니다.
		count2 = count;
		tmp1 = tmp2;
		if (count == strlen -1) {
			return NULL; // 문장 끝까지 도달한 상태에서 들어오면 NULL을 return 합니다.
		}
		for(int i = count; i < strlen; i ++) {
			if (i == strlen-1) {
				return tmp1 + count2; // 문장 끝에 도달하면 처음 null의 다음 주소부터 출력합니다.
			}
			else if (tmp1[i] != *str2) {
				count ++; 
			}
			else if (tmp1[i] == *str2) {
				count ++;
				tmp1[i] = '\0'; // str2가 도중에 나오면, 주소를 알기 위해 count를 추가하고 return합니다. count가 없이 i를 통해 저장할 수 있을지 고민해봐야합니다.
				return tmp1+count2;
			}
		}
	}
			
}
