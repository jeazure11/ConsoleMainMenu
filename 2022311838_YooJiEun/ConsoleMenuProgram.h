#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h> //���ڿ� ���� �˷��ִ� ���
#include<stdlib.h> //for clear function use
#include<time.h>	//�ð� ���� �Լ� ����ϱ� ����

/*---------------------------------------*/
/* Declaration of User Defined CONSTANTS */

#define TRUE   1				//TRUE�� 1�� ����
#define FALSE  0				//FALSE�� 0���� ����

#define DIE_SIMULATION  1		//DIE_SIMULATION�� 1�� ����
#define GAME_SHOW       2		//GAME_SHOW�� 2�� ����
#define UPDOWN_GAME     3		//UPDOWN_GAME�� 3���� ����
#define WORD_GAME       4		//WORD_GAME�� 4�� ����
#define OX_GAME         5		//OX_GAME�� 5�� ����
#define BASEBALL_GAME	6
#define ABOUT           7		//ABOUT�� 6���� ����
#define EXIT            0		//EXIT�� 0���� ����


/*---------------------------------------*/
/* Declaration of User Defined Functions */

int displayMainMenu();			//���� �޴��� �����ֱ� ���� �Լ� ����
int exitMessage();				//������ ������ �Լ� ����

void dieSimulation();			//die simulation �Լ� ����
void gameShow();				//game show �Լ� ����
void upDownGame();				//updown game �Լ� ����
void wordGame();				//word game �Լ� ����

void OXGame();					//OXgame �Լ� ����
void displayOX(char strOX[]);	//OXgame���� ������(������)�� ��Ÿ���� ���� �Լ� ����
char playOX(char turn, char strOX[]);	//������ �ٲ㰡�� ������ �����ϱ� ���� �Լ� ����
char winCheck(char strOX[]);	//O,X �� �̱� ����� �ִ��� Ȯ���ϴ� �Լ� ����

void baseballGame();

void about();					//���α׷� ������ ���� �Լ� ����

/*---------------------------------------*/#pragma once	//������� �ߺ����� �ʵ���
