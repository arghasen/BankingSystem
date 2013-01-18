//============================================================================
// Name        : Banking.cpp
// Author      : Shuvendu,Argha,Dipak
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "server.h"
#include "client.h"

void menu()
{
	int choice;
	do
	{
		choice=getchar();
		centerstring("*************************************************\n");
		centerstring("Main Menu\n");
		centerstring("*************************************************\n");
		centerstring("1.View Details                                   \n");
		centerstring("2.Change Details                                 \n");
		centerstring("3.Balance Inquiry                                \n");
		centerstring("4.Credit                                         \n");
		centerstring("5.Debit                                          \n");

		switch(choice)
		{

		}

	}while(choice=='y'||choice=='Y');
	return;
}

int main() {
	int session;
    initialscreen();
	session=authorise();
	if(session)
		menu();



	return EXIT_SUCCESS;
}
