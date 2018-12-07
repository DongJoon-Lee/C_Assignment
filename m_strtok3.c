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



	//test case 1
	printf("test case 01 --------------------\n");

	ptr = strtok(str1, " ");
	while (ptr != NULL) {
        printf("%s\n", ptr);
		ptr = strtok(NULL, " ");
    }

	//test case 2
	printf("test case 02 --------------------\n");

	ptr = strtok(str2, " ");
	while (ptr != NULL) {
		printf("%s\n", ptr);
		ptr = strtok(NULL, " ");
	}

	//test case 3
	printf("test case 03 --------------------\n");

	ptr = strtok(str3, " ");
	while (ptr != NULL) {
		printf("%s\n", ptr);
		ptr = strtok(NULL, " ");
	}


	//test case 4
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

/*  한가지 문제가 있습니다. count가 strlen-1로 갔을때 그냥 NULL을 출력하는 바람에, 4번째 테스트 케이스처럼 str2다음에 한 글자만 오면 출력이 안되고     그냥 NULL로 나와버립니다.
	  그 문제를 해결하기 위해 꼼수를 사용했습니다. 요상한 int 변수를 만들어 0(false)으로 설정합니다. 그리고 아래의 for에서 strlen-1 == i가 되었을 때, 출력하>    기 전에 button을 1(true)로 바꿉니다. 이렇게 되면, str2 다음에 한 글자여도 일단 return이 되고, 다음 strtok에서 button이 true인 상태이기 때문에 for로 내려가기 전에 button == 1에서 잡혀 NULL을 출력하고, 끝나게 됩니다. f받을만한 꼼수입니다만,,이 정도는.. 코딩 처음 배우는데..  충성충성..^^7  ㅠㅠㅠㅠㅠ*/




char *strtok(char *str1, const char *str2) {
	static char *tmp = NULL;      // str1의 값이 NULL일때를 대비한 백업용 문자열입니다.
	static int count, count2;     // return을 출력하기 위한 int친구들입니다.
	static int button = 0;      // 수치스럽지만 해결하지 못한 문제를 꼼수를 사용하기 위해 만든 button입니다.

	static int strlen;      //string.h를 쓰면 안되기 때문에 strlen을 따로 구해줍니다.

	if (str1 != NULL) {
		
		tmp = str1;      // str1이 NULL이 아닐 때의 주소값을 tmp에 저장합니다.
		count = 0;      // 다른 test case가 들어오는 것을 대비하여 0으로 초기화합니다.
		count2 = 0;
		strlen = 0;
		button = 0;

		while( str1[strlen] != 0) {      //strlen을 구했습니다.
			strlen ++;
		}
	}

	if (button == 1) {      // 꼼수를 사용한 부분입니다. 4 번째 테스트 케이스에서 g가 출력이 안되는 바람에 사용했습니다. 설명은 위에 있습니다.
	    if (count == strlen-1) {      //문장의 끝으로 간 상태에서 함수를 실행하면 NULL을 출력합니다. strtok 함수의 특징입니다.
	    	return NULL;
	    }
	}

	count2 = count;      //str2가 아닌 문자가 나오면 count가 증가하기 때문에, 이전에 기억하고 있는 주소부터 출력하기 위해 count2를 저장합니다.(count2는 이전에 str2가 나온 다음 번호입니다.)

	for(int i = count2; i < strlen; i ++) {
		if (strlen - 1 == i) {      // 문장의 끝까지 나왔을 경우입니다. 이 경우 기억해놓은 주소부터 그냥 출력합니다.
			button = 1;
			return tmp + count2;  
		}
		if (tmp[i] != *str2) {      // 그 외에 str2와 같은 값이 아니면, count를 ++합니다.
			count ++;
		}
		else if (tmp[i] == *str2) {      // str2가 발견되면 나오는 행동입니다. 다음 번호를 기억해놓고, 발견된 자리에 NULL을 넣습니다. 그 후 전에 기억해놓은 위치부터 출력합니다.
			count ++;
			tmp[i] = '\0';
			return tmp + count2;
		}
	}
}

