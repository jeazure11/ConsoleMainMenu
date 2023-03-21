#include "ConsoleMenuProgram.h"     //헤더 사용

int main()
{
	int nSelectedMainMenu;		//메인메뉴에서 몇 번째 프로그램을 선택하는지 아릭 위한 변수 선언
	int bIterationFlag = TRUE;	//프로그램을 종료하기 위한 변수 선언

	srand(time(NULL));			//랜덤 수 생성(rand()만 쓰면 매번 같은 수 생성

	while (bIterationFlag) {	//bIterationFlag값이 0이 될 때(프로그램을 종료할 때)까지 반복
		system("cls");        //clear screen
		nSelectedMainMenu = displayMainMenu();		//dislayMainMenu 함수에서 return한 값을 nSelectedMainMenu에 저장
		getchar();            //remove enter

		system("cls");
		switch (nSelectedMainMenu) {   //사용자가 선택한 수(displayMainMenu에서 리턴한 값)에 따라 어떤 함수를 선택할 지 결정하기 위한 swith문
		case DIE_SIMULATION:	//사용자가 1.DIE SIMULATION을 선택했을 때
			dieSimulation();	//dieSimulation 함수 호출
			break;				//switch문 종료(이미 DIE_SIMULATION을 실행했기 때문에 메인 메뉴부터 다시 시작해야 함)
		case GAME_SHOW:			//사용자가 2.GAME SHOW를 선택했을 때
			gameShow();			//gameShow 함수 호출
			break;				//switch문 종료
		case UPDOWN_GAME:		//사용자가 3.UPDOWN GAME을 선택했을 때
			upDownGame();		//upDownGame 함수 호출
			break;				//switch문 종료
		case WORD_GAME:			//사용자가 4.WORD GAME을 선택했을 때
			wordGame();			//wordGame 함수 호출
			break;				//switch문 종료
		case OX_GAME:			//사용자가 5.OX GAME을 선택했을 때
			OXGame();			//OXGame 함수 호출
			break;				//switch문 종료
		case BASEBALL_GAME:
			baseballGame();
			break;
		case ABOUT:				//사용자가 6.ABOUT을 선택했을 때
			about();			//about 함수 호출
			break;				//switch문 종료
		case EXIT:				//사용자가 0.EXIT를 선택했을 때
				bIterationFlag = exitMessage();  //exitMessage에서 리턴한 값이 0이라면 bIterationFlag가 0이 되므로 while문 종료
			break;				//switch문 종료
		default:				//메뉴에 없는 번호를 골랐을 때
			printf("\n\n");		//줄바꿈
			printf("\tWrong number!! Please re-input @~@\n");	//잘못된 번호를 골랐다고 사용자에게 알려줌
			break;				//switch문 종료
		}//switch

		if (bIterationFlag) {	//bIteration이 1일 때,즉 사용자가 종료하지 않았을 때
			printf("\n\n\t");	//줄바꿈
			system("pause");	//바로 화면이 넘어가지 않고, 아무 버튼 누르기 전까지 화면 일시정지
		}//if

	}//while



	return 0;
}//main()




/*------------------------------------------*/
/* Implementation of User Defined Functions */

int displayMainMenu()		//함수 정의
{
	int nMainMenu;			//사용자가 선택하는 숫자를 받기 위한 변수 선언

	printf("\n\n");
	printf("\t=====================================================\n");
	printf("\t                      MAIN MENU\n");
	printf("\t-----------------------------------------------------\n");
	printf("\t    1. DIE SIMULATION\n");
	printf("\t    2. GAME SHOW\n");
	printf("\t    3. UP DOWN GAME\n");
	printf("\t    4. WORD GAME\n");
	printf("\t    5. OX GAME\n");
	printf("\t    6. BASEBALL GAME\n");
	printf("\t    7. ABOUT\n");
	printf("\t-----------------------------------------------------\n");
	printf("\t    0. EXIT\n");
	printf("\t=====================================================\n");
	printf("\t    >> ");			//출력format
	scanf("%d", &nMainMenu);		//사용자에게서 숫자 입력받기

	return nMainMenu;				//사용자에게서 입력받은 숫자 반환하기
}//displayMainMenu()

#define DIE_SUM       100			//DIE_SUM을 100으로 선언
#define DIE_ITERATION 1000000		//DIE_ITERATION을 1000000으로 선언

void dieSimulation()				//함수 정의
{
	int nFaceValue, nSum = 0, nCount = 0;		//주사위를 굴리기 위한 변수 선언, 주사위의 수를 모두 합하기 위한 변수 선언, 주사위를 굴리는 횟수 확인하기 위한 변수 선언

	printf("\n\n");
	printf("\t=====================================================\n");
	printf("\t                    DIE SIMULATION\n");
	printf("\t=====================================================\n");
	printf("\n\n");		//출력format

	for (int i = 0; i < DIE_ITERATION; i++)		// 주사위를 굴리는 시뮬레이션을 DIE_ITERATION(1000000)번 만큼 반복
	{
		while (nSum < DIE_SUM)					//주사위의 수를 합한 값이 DIE_SUM보다 작을 때까지 반복(합이 100이 되려면 몇 번을 굴려야 하는지 알기 위함)
		{
			nFaceValue = (rand() % 6) + 1;  //1~6 사이의 주사위 수 굴리는 시뮬레이션
			nSum += nFaceValue;				//1~6 사이의 주사위 수 중 굴려서 나온 수를 더함
			nCount++;						//몇 번째로 굴리는 중인지 세기
		}//while
		nSum = 0;							//주사위 수들의 합을 초기화함
	}//for
	printf("\t       For the cumulative sum of the dice is\n\n");
	printf("\t        more than 100, roll it % .2lf times\n", (double)nCount / DIE_ITERATION);
	printf("\n\n");
	printf("\t====================================================\n");		//출력format


}// dieSimulation()

#define GAME_ITERATION 100000		//GAME_ITERATION을 100000으로 설정

void gameShow()			//함수 정의
{
	int nPrizeDoor, nChoiceDoor, nChoiceCount=0;	//정답이 있는 문과 선택한 문을 나타내는 변수, 그리고 선택 횟수를 세기 위한 count 변수 선언
	int nRevealDoor, nRechoiceDoor, nRechoiceCount=0;	//이미 공개된 문과 다시 선택한 문을 나타내는 변수, 그리고 다시 선택한 횟수를 세기 위한 count 변수 선언
	
	printf("\n\n");
	printf("\t=====================================================\n");
	printf("\t                      GAME SHOW\n");
	printf("\t=====================================================\n");
	printf("\n\n");	//출력 format

	for (int i = 0; i < GAME_ITERATION; i++)	//gameiteration만큼 시뮬레이션
	{
		nPrizeDoor = rand() % 3;	//0~2사이의 숫자들 중에서 정답 문 랜덤 선택
		nChoiceDoor = rand() % 3;	//0~2사이의 숫자들 중에서 선택 문 랜덤 선택
		if (nPrizeDoor == nChoiceDoor) nChoiceCount++;	//정답 문과 선택 문이 일치한 경우가 몇 번인지 세기
	}//for
	printf("\t                Choice    >> %.2lf %%\n\n", ((double)nChoiceCount/GAME_ITERATION)*100);	//정답인 비율이 어느 정도에 수렴하는지 출력
	
	for (int i=0;i<GAME_ITERATION;i++)	//gameiteration만큼 시뮬레이션
	{
		nPrizeDoor = rand() % 3;	//0~2사이의 숫자들 중에서 정답 문 랜덤 선택
		nChoiceDoor = rand() % 3;	//0~2사이의 숫자들 중에서 선택 문 랜덤 선택

		nRevealDoor = 0;	//일단 0으로 설정
		while (nRevealDoor==nPrizeDoor || nRevealDoor==nChoiceDoor) nRevealDoor++;	//공개하는 문이 정답문이나 선택 문과 겹치지 않도록 숫자 바꿔주기

		nRechoiceDoor = 0;	//일단 0으로 설정
		while (nRechoiceDoor == nRevealDoor || nRechoiceDoor == nChoiceDoor) nRechoiceDoor++;	//다시 선택 문이 공개 문이나 이미 선택했던 문과 겹치지 않도록 숫자 바꿔주기

		if (nRechoiceDoor == nPrizeDoor)nRechoiceCount++;	//바꾼 문과 정답 문이 일치한 경우 세기

	}
	printf("\t                Re-Choice >> %.2lf %%\n\n", ((double)nRechoiceCount / GAME_ITERATION) * 100);	//바꿨을 때 정답의 비율이 어느정도에 수렴하는지 출력
	printf("\t=====================================================\n");

}// gameShow()

void upDownGame()	//함수 정의
{
	int nAnswer;			//정답 변수 선언
	int nUser, nCount=0;	//유저가 선택하는 숫자 변수, count변수 선언

	nAnswer = rand() % 100 + 1;	//정답 숫자는 랜덤으로 1~100사이에서 고름

	while (TRUE) {
		system("cls");	//화면 지우기
		printf("\n\n");
		printf("\t=====================================================\n");
		printf("\t                      UP DOWN GAME\n");
		printf("\t=====================================================\n");
		printf("\n\n");
		printf("\t  >>  ");
		scanf("%d", &nUser);	//유저가 숫자 입력하도록

		printf("\n\t====================================================\n");
		if (nUser == nAnswer) {//유저가 선택한 숫자와 정답이 같다면
			nCount++;	//시도 횟수 체크
			printf("\t                   Try: %d \n\n",nCount);
			printf("\t                  SUCCESS!!\n");
			printf("\n\t======================================================\n");	//시도 횟수와 성공이라는 글자 출력
			break;	//성공했으므로 종료
		}
		else if (nUser < nAnswer) {	//정답이 유저의 수보다 크다면
			nCount++;	//시도횟수 체크
			printf("\t  >>  UP\n\n");	//더 높아야 한다고 출력
		}
		else if (nUser > nAnswer) {	//정답이 유저의 수보다 작다면
			nCount++;	//시도횟수 체크
			printf("\t  >>  DOWN\n\n");	//더 낮아야 한다고 출력
		}
		else if (nUser == 0) {	//유저가 0을 누르면
			nCount++;	//시도횟수 체크
			printf("\t                   FAILDED!!\n");
			printf("\n\t======================================================\n");	//0을 눌렀으므로 실패 출력
			break;	//0을 눌렀으므로 종료
		}
		system("pause");	//화면이 게임이 끄나도 사라지지 않도록
	}

	

}// upDownGame

#define WORDS        10			//WORDS를 10으로 설정
#define WORD_LENGTH  40			//WORD_LENGTH를 40으로 설정

void wordGame()
{
	int count = 0;
	char strWords[WORDS][WORD_LENGTH]={
			"university",	//0
			"breadcast",	//1
			"student",		//2
			"media",		//3
			"assistant",	//4
			"institute",	//5
			"engineer",		//6
			"computer",		//7
			"education",	//8
			"department",	//9
	};//strWords배열 선언

	char strAlphabet[27] = { "abcdefghijklmnopqrstuvwxyz" };	//알파벳 배열

	int nSelectedWord, nWordLength;	//정답 단어 변수, 정답 단어의 길이 변수 선언
	char strInput[WORD_LENGTH], chInput[WORD_LENGTH];	//정답 길이 배열, 유저가 입력하는 문자 변수 선언

	nSelectedWord = rand() % 10;	//0~9 중에서 숫자 랜덤으로 생성
	nWordLength = strlen(strWords[nSelectedWord]);	//랜덤으로 생성된 수 자리에 있는 strWords배열의 단어의 길이 재기
	for (int i = 0; i < nWordLength; i++) strInput[i] = '_';	//정답의 길이만큼 '_' 문자 출력
	strInput[nWordLength] = '\0';	//strInput의 마지막 자리에 '\0'넣기

	while (TRUE)
	{
		count++;
		system("cls");
		printf("\n\n");
		printf("\t=====================================================\n");
		printf("\t                      WORD GAME\n");
		printf("\t=====================================================\n");
		printf("\n\n");

		printf("\t   ");
		for (int i = 0; i < 26; i++) {	//알파벳이 26개이므로 26번 반복
			printf("%c ", strAlphabet[i]);	//알파벳 나열
			if (!((i + 1) % 13)) printf("\n\n\t   ");	//13개씩 나눠서 나열
		}//for

		printf("\n\n");
		printf("\t-----------------------------------------------------\n");
		printf("\n\n\t  ");
		for (int i = 0; i < nWordLength; i++) printf("%c ", strInput[i]);	//정답 문자의 길이만큼'_' 나열
		printf("\n\n");

		if (strcmp(strInput, strWords[nSelectedWord]) == 0) break;	//문자열이 서로 같은지 비교 후 같으면 종료

		printf("\t  >> ");

		scanf("%s", &chInput);	//유저 답 입력받기

		if (chInput[1] == '\0') {

			strAlphabet[chInput[0] - 'a'] = ' ';	//이미 입력한 알파벳은 삭제
			for (int i = 0; i < nWordLength; i++) {
				if (chInput[0] == strWords[nSelectedWord][i]) {	//입력받은 알파벳이 정답에 있는 알파벳과 같다면
					strInput[i] = chInput[0];	//그 자리에 알파벳으로 채우기
				}//if
			}//for
		}
		else {
			if (strcmp(chInput, strWords[nSelectedWord]) == 0) {
				for (int i = 0; i < nWordLength; i++) {
					strInput[i] = chInput[i];
				}
			}
		}
	}


	printf("\n\t=====================================================\n");
	printf("\n\t                 Congratulations!!!\n");
	printf("\n\t                    Try: %d", count);
	printf("\n\t=====================================================\n");
	//프로그램 종료 후 모습
}// wordGame

void OXGame()
{
	char strOX[11] = "0123456789";	//문자열 선언
	char chTurn = 'O',chWin = '0';	//차레를 나타내기 위한 변수와 누가 이겼는지 나타내기 위한 변수 선언

	while (TRUE) {
		system("cls");
		printf("\n\n");
		printf("\t===============================\n");
		printf("\t           OX GAME\n");
		printf("\t===============================\n");
		printf("\n\n");

		displayOX(strOX);		//displayOX함수 호출
		printf("\t===============================\n");

		if (chWin != '0') break;

		chTurn = playOX(chTurn, strOX);	//playOX함수 호출
		chWin = winCheck(strOX);	//winCheck함수 호출

	}//while

	printf("\t===============================\n");
	printf("\n\t     %c  WIN!!!\n\n", chWin);
	printf("\t===============================\n");

}// OXGame (중복값과 비기는 경우도 생각해보기)

void displayOX(char strOX[])
{
	printf("\t    ");
	for (int i = 1; i < 10; i++) {	//9번 반복
		printf("%c       ", strOX[i]);	//숫자 나열
		if (!(i % 3)) printf("\n\n\t    ");	//한 줄에 3개씩 나열
	}
	printf("\n\n");
}//displayOX

char playOX(char turn, char strOX[])
{
	int nPosition;	//자리입력받기 위한 변수 선언

	printf("\t%c's turn >> ", turn);	//누구의 차례인지 나타냄

	scanf("%d", &nPosition);	//입력받기

	strOX[nPosition] = turn;	//입력받은 자리에 'O'나'X'채워넣기

	return (turn == 'O') ? 'X' : 'O';	//누구 차례인지 반환
}

char winCheck(char strOX[])
{
	char chWin = '0';	//누가 이겼는지 확인하기 위한 변수 선언

	if (strOX[1] == strOX[2] && strOX[2] == strOX[3])chWin = strOX[1];
	else if (strOX[4] == strOX[5] && strOX[5] == strOX[6])chWin = strOX[4];
	else if (strOX[7] == strOX[8] && strOX[8] == strOX[9])chWin = strOX[7];
	else if (strOX[1] == strOX[4] && strOX[4] == strOX[7])chWin = strOX[1];
	else if (strOX[2] == strOX[5] && strOX[5] == strOX[8])chWin = strOX[2];
	else if (strOX[3] == strOX[6] && strOX[6] == strOX[9])chWin = strOX[3];
	else if (strOX[1] == strOX[5] && strOX[5] == strOX[9])chWin = strOX[1];
	else if (strOX[3] == strOX[5] && strOX[5] == strOX[7])chWin = strOX[3];
	//이기는 경우의 수 나열, 이긴 사람의 문자로 chWin을 바꿈

	return chWin;	//누가 이겼는지 반환

}

void baseballGame()
{
	int a, b, c;
	int uA, uB, uC;
	int sCount = 0, bCount = 0,hCount=0;
	int cor = 0;

	while (1) {
		a = (rand() % 9) + 1;
		b = (rand() % 9) + 1;
		c = (rand() % 9) + 1;

		if (a != b && b != c) break;
	}

	while (1) {
		system("cls");
		printf("\n\n");
		printf("\t====================================\n");
		printf("\t            BASEBALL GAME\n");
		printf("\t====================================\n");
		printf("\n\n");

		hCount++;
		sCount = 0;
		bCount = 0;
		printf("\t >> ");
		scanf("%d%d%d", &uA, &uB, &uC);
		printf("\n");

		if (a == uA)sCount++;
		if (b == uB)sCount++;
		if (c == uC)sCount++;

		if (uA == b || uA == c) bCount++;
		if (uB == a || uB == c) bCount++;
		if (uC == b || uC == a) bCount++;

		printf("\n\t >> %dS %dB\n", sCount, bCount);

		if (sCount == 3) {
			cor = 1;
			break;
		}
		if (uA == 0 && uB == 0 && uC == 0) break;
		system("pause");
	}
	if (cor == 1) {
		printf("\n\n\t     SUCCESS!!");
		printf("\n\t      try:%d", hCount);
	}
	else {
		printf("\n\n\t     FAILD!!");
	}



}//baseballGame

int exitMessage()
{
	char chAnswer;	//종료하기 위한 변수 입력받기
	printf("\n\n");
	printf("\tAre you sure you want to quit? (y/n)  ");
	scanf("%c", &chAnswer);	//입력받기

	if (chAnswer == 'y')      return FALSE;		//사용자가 'y'를 눌렀을 때 0을 반환하요 프로그램을 종료함
	else                      return TRUE;		//사용자가 'y'가 아닌 다른 문자를 눌렀을 때 종료하지 않음
}//exitMessage

void about()
{
	printf("\n\n");
	printf("\t=====================================================\n");
	printf("\t          ConsoleMenu Program Ver 0.3\n");
	printf("\t          Prgrammed by Yoo, JiEun.\n");
	printf("\t=====================================================\n");

}//about

/*------------------------------------------*/