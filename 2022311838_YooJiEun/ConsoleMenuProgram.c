#include "ConsoleMenuProgram.h"     //��� ���

int main()
{
	int nSelectedMainMenu;		//���θ޴����� �� ��° ���α׷��� �����ϴ��� �Ƹ� ���� ���� ����
	int bIterationFlag = TRUE;	//���α׷��� �����ϱ� ���� ���� ����

	srand(time(NULL));			//���� �� ����(rand()�� ���� �Ź� ���� �� ����

	while (bIterationFlag) {	//bIterationFlag���� 0�� �� ��(���α׷��� ������ ��)���� �ݺ�
		system("cls");        //clear screen
		nSelectedMainMenu = displayMainMenu();		//dislayMainMenu �Լ����� return�� ���� nSelectedMainMenu�� ����
		getchar();            //remove enter

		system("cls");
		switch (nSelectedMainMenu) {   //����ڰ� ������ ��(displayMainMenu���� ������ ��)�� ���� � �Լ��� ������ �� �����ϱ� ���� swith��
		case DIE_SIMULATION:	//����ڰ� 1.DIE SIMULATION�� �������� ��
			dieSimulation();	//dieSimulation �Լ� ȣ��
			break;				//switch�� ����(�̹� DIE_SIMULATION�� �����߱� ������ ���� �޴����� �ٽ� �����ؾ� ��)
		case GAME_SHOW:			//����ڰ� 2.GAME SHOW�� �������� ��
			gameShow();			//gameShow �Լ� ȣ��
			break;				//switch�� ����
		case UPDOWN_GAME:		//����ڰ� 3.UPDOWN GAME�� �������� ��
			upDownGame();		//upDownGame �Լ� ȣ��
			break;				//switch�� ����
		case WORD_GAME:			//����ڰ� 4.WORD GAME�� �������� ��
			wordGame();			//wordGame �Լ� ȣ��
			break;				//switch�� ����
		case OX_GAME:			//����ڰ� 5.OX GAME�� �������� ��
			OXGame();			//OXGame �Լ� ȣ��
			break;				//switch�� ����
		case BASEBALL_GAME:
			baseballGame();
			break;
		case ABOUT:				//����ڰ� 6.ABOUT�� �������� ��
			about();			//about �Լ� ȣ��
			break;				//switch�� ����
		case EXIT:				//����ڰ� 0.EXIT�� �������� ��
				bIterationFlag = exitMessage();  //exitMessage���� ������ ���� 0�̶�� bIterationFlag�� 0�� �ǹǷ� while�� ����
			break;				//switch�� ����
		default:				//�޴��� ���� ��ȣ�� ����� ��
			printf("\n\n");		//�ٹٲ�
			printf("\tWrong number!! Please re-input @~@\n");	//�߸��� ��ȣ�� ����ٰ� ����ڿ��� �˷���
			break;				//switch�� ����
		}//switch

		if (bIterationFlag) {	//bIteration�� 1�� ��,�� ����ڰ� �������� �ʾ��� ��
			printf("\n\n\t");	//�ٹٲ�
			system("pause");	//�ٷ� ȭ���� �Ѿ�� �ʰ�, �ƹ� ��ư ������ ������ ȭ�� �Ͻ�����
		}//if

	}//while



	return 0;
}//main()




/*------------------------------------------*/
/* Implementation of User Defined Functions */

int displayMainMenu()		//�Լ� ����
{
	int nMainMenu;			//����ڰ� �����ϴ� ���ڸ� �ޱ� ���� ���� ����

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
	printf("\t    >> ");			//���format
	scanf("%d", &nMainMenu);		//����ڿ��Լ� ���� �Է¹ޱ�

	return nMainMenu;				//����ڿ��Լ� �Է¹��� ���� ��ȯ�ϱ�
}//displayMainMenu()

#define DIE_SUM       100			//DIE_SUM�� 100���� ����
#define DIE_ITERATION 1000000		//DIE_ITERATION�� 1000000���� ����

void dieSimulation()				//�Լ� ����
{
	int nFaceValue, nSum = 0, nCount = 0;		//�ֻ����� ������ ���� ���� ����, �ֻ����� ���� ��� ���ϱ� ���� ���� ����, �ֻ����� ������ Ƚ�� Ȯ���ϱ� ���� ���� ����

	printf("\n\n");
	printf("\t=====================================================\n");
	printf("\t                    DIE SIMULATION\n");
	printf("\t=====================================================\n");
	printf("\n\n");		//���format

	for (int i = 0; i < DIE_ITERATION; i++)		// �ֻ����� ������ �ùķ��̼��� DIE_ITERATION(1000000)�� ��ŭ �ݺ�
	{
		while (nSum < DIE_SUM)					//�ֻ����� ���� ���� ���� DIE_SUM���� ���� ������ �ݺ�(���� 100�� �Ƿ��� �� ���� ������ �ϴ��� �˱� ����)
		{
			nFaceValue = (rand() % 6) + 1;  //1~6 ������ �ֻ��� �� ������ �ùķ��̼�
			nSum += nFaceValue;				//1~6 ������ �ֻ��� �� �� ������ ���� ���� ����
			nCount++;						//�� ��°�� ������ ������ ����
		}//while
		nSum = 0;							//�ֻ��� ������ ���� �ʱ�ȭ��
	}//for
	printf("\t       For the cumulative sum of the dice is\n\n");
	printf("\t        more than 100, roll it % .2lf times\n", (double)nCount / DIE_ITERATION);
	printf("\n\n");
	printf("\t====================================================\n");		//���format


}// dieSimulation()

#define GAME_ITERATION 100000		//GAME_ITERATION�� 100000���� ����

void gameShow()			//�Լ� ����
{
	int nPrizeDoor, nChoiceDoor, nChoiceCount=0;	//������ �ִ� ���� ������ ���� ��Ÿ���� ����, �׸��� ���� Ƚ���� ���� ���� count ���� ����
	int nRevealDoor, nRechoiceDoor, nRechoiceCount=0;	//�̹� ������ ���� �ٽ� ������ ���� ��Ÿ���� ����, �׸��� �ٽ� ������ Ƚ���� ���� ���� count ���� ����
	
	printf("\n\n");
	printf("\t=====================================================\n");
	printf("\t                      GAME SHOW\n");
	printf("\t=====================================================\n");
	printf("\n\n");	//��� format

	for (int i = 0; i < GAME_ITERATION; i++)	//gameiteration��ŭ �ùķ��̼�
	{
		nPrizeDoor = rand() % 3;	//0~2������ ���ڵ� �߿��� ���� �� ���� ����
		nChoiceDoor = rand() % 3;	//0~2������ ���ڵ� �߿��� ���� �� ���� ����
		if (nPrizeDoor == nChoiceDoor) nChoiceCount++;	//���� ���� ���� ���� ��ġ�� ��찡 �� ������ ����
	}//for
	printf("\t                Choice    >> %.2lf %%\n\n", ((double)nChoiceCount/GAME_ITERATION)*100);	//������ ������ ��� ������ �����ϴ��� ���
	
	for (int i=0;i<GAME_ITERATION;i++)	//gameiteration��ŭ �ùķ��̼�
	{
		nPrizeDoor = rand() % 3;	//0~2������ ���ڵ� �߿��� ���� �� ���� ����
		nChoiceDoor = rand() % 3;	//0~2������ ���ڵ� �߿��� ���� �� ���� ����

		nRevealDoor = 0;	//�ϴ� 0���� ����
		while (nRevealDoor==nPrizeDoor || nRevealDoor==nChoiceDoor) nRevealDoor++;	//�����ϴ� ���� ���乮�̳� ���� ���� ��ġ�� �ʵ��� ���� �ٲ��ֱ�

		nRechoiceDoor = 0;	//�ϴ� 0���� ����
		while (nRechoiceDoor == nRevealDoor || nRechoiceDoor == nChoiceDoor) nRechoiceDoor++;	//�ٽ� ���� ���� ���� ���̳� �̹� �����ߴ� ���� ��ġ�� �ʵ��� ���� �ٲ��ֱ�

		if (nRechoiceDoor == nPrizeDoor)nRechoiceCount++;	//�ٲ� ���� ���� ���� ��ġ�� ��� ����

	}
	printf("\t                Re-Choice >> %.2lf %%\n\n", ((double)nRechoiceCount / GAME_ITERATION) * 100);	//�ٲ��� �� ������ ������ ��������� �����ϴ��� ���
	printf("\t=====================================================\n");

}// gameShow()

void upDownGame()	//�Լ� ����
{
	int nAnswer;			//���� ���� ����
	int nUser, nCount=0;	//������ �����ϴ� ���� ����, count���� ����

	nAnswer = rand() % 100 + 1;	//���� ���ڴ� �������� 1~100���̿��� ��

	while (TRUE) {
		system("cls");	//ȭ�� �����
		printf("\n\n");
		printf("\t=====================================================\n");
		printf("\t                      UP DOWN GAME\n");
		printf("\t=====================================================\n");
		printf("\n\n");
		printf("\t  >>  ");
		scanf("%d", &nUser);	//������ ���� �Է��ϵ���

		printf("\n\t====================================================\n");
		if (nUser == nAnswer) {//������ ������ ���ڿ� ������ ���ٸ�
			nCount++;	//�õ� Ƚ�� üũ
			printf("\t                   Try: %d \n\n",nCount);
			printf("\t                  SUCCESS!!\n");
			printf("\n\t======================================================\n");	//�õ� Ƚ���� �����̶�� ���� ���
			break;	//���������Ƿ� ����
		}
		else if (nUser < nAnswer) {	//������ ������ ������ ũ�ٸ�
			nCount++;	//�õ�Ƚ�� üũ
			printf("\t  >>  UP\n\n");	//�� ���ƾ� �Ѵٰ� ���
		}
		else if (nUser > nAnswer) {	//������ ������ ������ �۴ٸ�
			nCount++;	//�õ�Ƚ�� üũ
			printf("\t  >>  DOWN\n\n");	//�� ���ƾ� �Ѵٰ� ���
		}
		else if (nUser == 0) {	//������ 0�� ������
			nCount++;	//�õ�Ƚ�� üũ
			printf("\t                   FAILDED!!\n");
			printf("\n\t======================================================\n");	//0�� �������Ƿ� ���� ���
			break;	//0�� �������Ƿ� ����
		}
		system("pause");	//ȭ���� ������ ������ ������� �ʵ���
	}

	

}// upDownGame

#define WORDS        10			//WORDS�� 10���� ����
#define WORD_LENGTH  40			//WORD_LENGTH�� 40���� ����

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
	};//strWords�迭 ����

	char strAlphabet[27] = { "abcdefghijklmnopqrstuvwxyz" };	//���ĺ� �迭

	int nSelectedWord, nWordLength;	//���� �ܾ� ����, ���� �ܾ��� ���� ���� ����
	char strInput[WORD_LENGTH], chInput[WORD_LENGTH];	//���� ���� �迭, ������ �Է��ϴ� ���� ���� ����

	nSelectedWord = rand() % 10;	//0~9 �߿��� ���� �������� ����
	nWordLength = strlen(strWords[nSelectedWord]);	//�������� ������ �� �ڸ��� �ִ� strWords�迭�� �ܾ��� ���� ���
	for (int i = 0; i < nWordLength; i++) strInput[i] = '_';	//������ ���̸�ŭ '_' ���� ���
	strInput[nWordLength] = '\0';	//strInput�� ������ �ڸ��� '\0'�ֱ�

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
		for (int i = 0; i < 26; i++) {	//���ĺ��� 26���̹Ƿ� 26�� �ݺ�
			printf("%c ", strAlphabet[i]);	//���ĺ� ����
			if (!((i + 1) % 13)) printf("\n\n\t   ");	//13���� ������ ����
		}//for

		printf("\n\n");
		printf("\t-----------------------------------------------------\n");
		printf("\n\n\t  ");
		for (int i = 0; i < nWordLength; i++) printf("%c ", strInput[i]);	//���� ������ ���̸�ŭ'_' ����
		printf("\n\n");

		if (strcmp(strInput, strWords[nSelectedWord]) == 0) break;	//���ڿ��� ���� ������ �� �� ������ ����

		printf("\t  >> ");

		scanf("%s", &chInput);	//���� �� �Է¹ޱ�

		if (chInput[1] == '\0') {

			strAlphabet[chInput[0] - 'a'] = ' ';	//�̹� �Է��� ���ĺ��� ����
			for (int i = 0; i < nWordLength; i++) {
				if (chInput[0] == strWords[nSelectedWord][i]) {	//�Է¹��� ���ĺ��� ���信 �ִ� ���ĺ��� ���ٸ�
					strInput[i] = chInput[0];	//�� �ڸ��� ���ĺ����� ä���
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
	//���α׷� ���� �� ���
}// wordGame

void OXGame()
{
	char strOX[11] = "0123456789";	//���ڿ� ����
	char chTurn = 'O',chWin = '0';	//������ ��Ÿ���� ���� ������ ���� �̰���� ��Ÿ���� ���� ���� ����

	while (TRUE) {
		system("cls");
		printf("\n\n");
		printf("\t===============================\n");
		printf("\t           OX GAME\n");
		printf("\t===============================\n");
		printf("\n\n");

		displayOX(strOX);		//displayOX�Լ� ȣ��
		printf("\t===============================\n");

		if (chWin != '0') break;

		chTurn = playOX(chTurn, strOX);	//playOX�Լ� ȣ��
		chWin = winCheck(strOX);	//winCheck�Լ� ȣ��

	}//while

	printf("\t===============================\n");
	printf("\n\t     %c  WIN!!!\n\n", chWin);
	printf("\t===============================\n");

}// OXGame (�ߺ����� ���� ��쵵 �����غ���)

void displayOX(char strOX[])
{
	printf("\t    ");
	for (int i = 1; i < 10; i++) {	//9�� �ݺ�
		printf("%c       ", strOX[i]);	//���� ����
		if (!(i % 3)) printf("\n\n\t    ");	//�� �ٿ� 3���� ����
	}
	printf("\n\n");
}//displayOX

char playOX(char turn, char strOX[])
{
	int nPosition;	//�ڸ��Է¹ޱ� ���� ���� ����

	printf("\t%c's turn >> ", turn);	//������ �������� ��Ÿ��

	scanf("%d", &nPosition);	//�Է¹ޱ�

	strOX[nPosition] = turn;	//�Է¹��� �ڸ��� 'O'��'X'ä���ֱ�

	return (turn == 'O') ? 'X' : 'O';	//���� �������� ��ȯ
}

char winCheck(char strOX[])
{
	char chWin = '0';	//���� �̰���� Ȯ���ϱ� ���� ���� ����

	if (strOX[1] == strOX[2] && strOX[2] == strOX[3])chWin = strOX[1];
	else if (strOX[4] == strOX[5] && strOX[5] == strOX[6])chWin = strOX[4];
	else if (strOX[7] == strOX[8] && strOX[8] == strOX[9])chWin = strOX[7];
	else if (strOX[1] == strOX[4] && strOX[4] == strOX[7])chWin = strOX[1];
	else if (strOX[2] == strOX[5] && strOX[5] == strOX[8])chWin = strOX[2];
	else if (strOX[3] == strOX[6] && strOX[6] == strOX[9])chWin = strOX[3];
	else if (strOX[1] == strOX[5] && strOX[5] == strOX[9])chWin = strOX[1];
	else if (strOX[3] == strOX[5] && strOX[5] == strOX[7])chWin = strOX[3];
	//�̱�� ����� �� ����, �̱� ����� ���ڷ� chWin�� �ٲ�

	return chWin;	//���� �̰���� ��ȯ

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
	char chAnswer;	//�����ϱ� ���� ���� �Է¹ޱ�
	printf("\n\n");
	printf("\tAre you sure you want to quit? (y/n)  ");
	scanf("%c", &chAnswer);	//�Է¹ޱ�

	if (chAnswer == 'y')      return FALSE;		//����ڰ� 'y'�� ������ �� 0�� ��ȯ�Ͽ� ���α׷��� ������
	else                      return TRUE;		//����ڰ� 'y'�� �ƴ� �ٸ� ���ڸ� ������ �� �������� ����
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