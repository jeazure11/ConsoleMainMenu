#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h> //문자열 길이 알려주는 헤더
#include<stdlib.h> //for clear function use
#include<time.h>	//시간 관련 함수 사용하기 위함

/*---------------------------------------*/
/* Declaration of User Defined CONSTANTS */

#define TRUE   1				//TRUE를 1로 설정
#define FALSE  0				//FALSE를 0으로 설정

#define DIE_SIMULATION  1		//DIE_SIMULATION를 1로 설정
#define GAME_SHOW       2		//GAME_SHOW를 2로 설정
#define UPDOWN_GAME     3		//UPDOWN_GAME을 3으로 설정
#define WORD_GAME       4		//WORD_GAME을 4로 설정
#define OX_GAME         5		//OX_GAME을 5로 설정
#define BASEBALL_GAME	6
#define ABOUT           7		//ABOUT을 6으로 설정
#define EXIT            0		//EXIT를 0으로 설정


/*---------------------------------------*/
/* Declaration of User Defined Functions */

int displayMainMenu();			//메인 메뉴를 보여주기 위한 함수 선언
int exitMessage();				//게임을 끝내는 함수 선언

void dieSimulation();			//die simulation 함수 선언
void gameShow();				//game show 함수 선언
void upDownGame();				//updown game 함수 선언
void wordGame();				//word game 함수 선언

void OXGame();					//OXgame 함수 선언
void displayOX(char strOX[]);	//OXgame에서 숫자판(게임판)을 나타내기 위한 함수 선언
char playOX(char turn, char strOX[]);	//순서를 바꿔가며 게임을 진행하기 위한 함수 선언
char winCheck(char strOX[]);	//O,X 중 이긴 사람이 있는지 확인하는 함수 선언

void baseballGame();

void about();					//프로그램 정보에 대한 함수 선언

/*---------------------------------------*/#pragma once	//헤더파일 중복되지 않도록
