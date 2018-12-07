// 최종 연습용 코드입니다.
// 이게 잘 되면 제출합니다!

# include <stdio.h>

char *strtok(char *str1, const char *str2); // strtok 선언

int main (void) { // 메인 함수
	char str1[] = {"abcde fghij"};
	char str2[] = {"abcde fghij klmno"};
	char str3[] = {"abcde fghij klmno pqrst"};
	char str4[] = {"a,b,c,d,e,f,g"};
	char *ptr = NULL;



	printf("test case 01 --------------------\n");

	ptr = strtok(str1, " ");
	while (ptr != NULL) {
        printf("%s\n", ptr);
		ptr = strtok(NULL, " ");
    }

	printf("test case 02 --------------------\n");

	ptr = strtok(str2, " ");
	while (ptr != NULL) {
		printf("%s\n", ptr);
		ptr = strtok(NULL, " ");
	}

	printf("test case 03 --------------------\n");

	ptr = strtok(str3, " ");
	while (ptr != NULL) {
		printf("%s\n", ptr);
		ptr = strtok(NULL, " ");
	}

	printf("test case 04 --------------------\n");

	ptr = strtok(str4, ",");
	while (ptr != NULL) {
        printf("%s\n", ptr);
		ptr = strtok(NULL, ",");
    }

	printf("---------------------------------\n");

	return 0;
}


//strtok 정의

char *strtok(char *str1, const char *str2) {
	static char *tmp = NULL;      // str1의 값이 NULL일때를 대비한 백업용 문자열입니다.
	static int count, count2;     // return을 출력하기 위한 int친구들입니다.

	static int strlen;      //string.h를 쓰면 안되기 때문에 strlen을 따로 구해줍니다.

	if (str1 != NULL) {
		
		tmp = str1;      // str1이 NULL이 아닐 때의 주소값을 tmp에 저장합니다.
		count = 0;      // 다른 test case가 들어오는 것을 대비하여 0으로 초기화합니다.
		count2 = 0;
		strlen = 0;

		while( str1[strlen] != 0) {      //strlen을 구했습니다.
			strlen ++;
		}
	}

	if (count == strlen-1) {      //문장의 끝으로 간 상태에서 함수를 실행하면 NULL을 출력합니다. strtok 함수의 특징입니다.
		return NULL;
	}

	count2 = count;      //str2가 아닌 문자가 나오면 count가 증가하기 때문에, 이전에 기억하고 있는 주소부터 출력하기 위해 count2를 저장합니다.(count2는 이전에 str2가 나온 다음 번호입니다.)

	for(int i = count2; i < strlen; i ++) {
		if (strlen - 1 == i) {      // 문장의 끝까지 나왔을 경우입니다. 이 경우 기억해놓은 주소부터 그냥 출력합니다.
			return tmp + count2;  
		}
		else if (tmp[i] != *str2) {      // 그 외에 str2와 같은 값이 아니면, count를 ++합니다.
			count ++;
		}
		else {      // str2가 발견되면 나오는 행동입니다. 다음 번호를 기억해놓고, 발견된 자리에 NULL을 넣습니다. 그 후 전에 기억해놓은 위치부터 출력합니다.
			count ++;
			tmp[i] = '\0';
			printf("count : %d\n", count);
			return tmp + count2;
		}
	}
}
