#include<stdio.h>

/*---------------------------------------*/
/* Declaration of User Defined Functions */

int displayMainMenu();

/*---------------------------------------*/



int main()
{
	int nSelectedMainMenu;


	nSelectedMainMenu = displayMainMenu();


	return 0;
}//main()




/*------------------------------------------*/
/* Implementation of User Defined Functions */

int displayMainMenu()
{
	int nMainMenu;

	printf("\n\n");
	printf("\t=====================================================\n");
	printf("\t                      MAIN MENU\n");
	printf("\t-----------------------------------------------------\n");
	printf("\t    1. 1st MENU\n");
	printf("\t    2. 2nd MENU\n");
	printf("\t    3. 3rd MENU\n");
	printf("\t    4. 4th MENU\n");
	printf("\t-----------------------------------------------------\n");
	printf("\t    0. EXIT\n");
	printf("\t=====================================================\n");
	printf("\t    >> ");
	scanf("%d", &nMainMenu);

	return nMainMenu;
}//displayMainMenu()

/*------------------------------------------*/
