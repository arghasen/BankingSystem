

#ifndef CLIENT_H_
#define CLIENT_H_
#include<iostream>
#include<fstream>
#include "stdio.h"
#include <stdlib.h>
#include<cstring>
#include "server.h"
using namespace std;
void centerstring(const char* s)
{
	int l=strlen(s);
	int pos=(int)((180-l)/2);
	for(int i=0;i<pos;i++)
		cout<<" ";

	cout<<s;
}
void centerstring(char* s)
{
	int l=strlen(s);
	int pos=(int)((180-l)/2);
	for(int i=0;i<pos;i++)
		cout<<" ";

	cout<<s;
}
void activity(int acno)
{
	int i;
	cout<<"Enter 1 for change details and 2 for view details:\n";
	cin>>i;
	switch (i)
	{
	case 2:
		view_details(acno);
		break;
	case 1:
		edit_details(acno);
	}
}

int authorise()
{
	char fnd,password[20];
	int acno=0;
	char username[20];
	int timeout;
	cout<< "\n\n";
	cout<<"\n\n"<<endl;
	cout<<"Are you a new user Y/N : ";
	cin>>fnd;///take the input from the user whether
	clear_kb();
	if(fnd=='y'||fnd=='Y')
	{
		do{

				cout<<"Please Enter New Username";
				cin>>username;
				clear_kb();
				cout<<"Please Enter New Password";
				cin>>password;
				clear_kb();
				acno=crtusr(username,password);
				clear_kb();

			 if(acno<0)
			{
				cout<<"Username already exists.Please choose a new username";
			}

		}while(acno<=0);

		insert_details(acno);

	}
///All users must login
		do{
			cout<<"Please Enter New Username";
			cin>>username;
			clear_kb();
			cout<<"Please Enter New Password";
			cin>>password;
			clear_kb();
			acno=authenticate(username,password);
			clear_kb();
			if(acno<0)
			{
				cout<<"Username (and/or) Password incorrect";
				timeout++;
			}
			if(timeout==3)
				{
					cout<<"For security purposes we are unable to proceed with your login.\n Please try again later";
					return 0;
				}
		}while(acno<=0);
		return 1;
}

void initialscreen()
{
	system("clear");
	cout<< "\n\n";
	cout<<"\n\n"<<endl;
	centerstring("*************************************************\n");
	centerstring("Welcome To Banker\n");
	centerstring("Your One Stop Solution to all your Banking Needs\n");
	centerstring("*************************************************\n");
	cout<<"\n\n"<<endl;
	cout<<"Press Enter Key to Continue......";
	cin.get();
}

#endif /* CLIENT_H_ */
