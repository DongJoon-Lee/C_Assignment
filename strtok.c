/* strtok함수의 테스트를 위한 파일입니다.
   오늘 처음 보는 함수라.................
   왜 git을 쓰라고 하신걸까..............
   검색을 통해 strtok에 대해 봤는데, 이 함수는 처음 받은 문자열의 주소를 저장해놓고 NULL값이 들어가는 다음으로 넘어가서 계속 이어간다. 첫 번째 인자?에 NULL이 들어가는 두, 세 번째 값이 포인트일것.처음 자르는건 쉬운데 그 다음이 문제.
   그냥 tmp를 두 개 만들어서 tmp2에 올려놓고 tmp로 자르고 다음에 부르면 다시 tmp2에 올려놓았던걸 tmp로 내려야 할까? 더 멋진게 있을텐데 멍청해서 떠오르지 않음. 아마 이렇게 할 듯.
   일단 느낌 가는대로 완성한 후, 이를 바탕으로 줄이고 다듬어서 제출하기.
*/

# include <stdio.h>
# include <string.h>

int main (void) {
	char test[100] = {"I am not a genius"};
	char * ptr;

	ptr = strtok(test," ");
	do {
		printf("%s\n", ptr);
		printf("%s\n", test);
		ptr = strtok(NULL, " ");
	} while (ptr != NULL) ;

	return 0;
}
