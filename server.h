/*
 * server.h
 *
 *  Created on: Aug 21, 2011
 *
 */
#include<iostream>
#include<fstream>
#include "stdio.h"
#include <stdlib.h>
#include<cstring>
using namespace std;

#ifndef SERVER_H_
#define SERVER_H_
struct logn
{
	char usrname[20];
//	typedef basic_string<char> ;
	int accountno;
};
struct account
{
	int accountno;
	char password[20];

};
struct balance
{
	int accountno;
	int balance;
};
struct usr
{
	int accountno;
//	typedef basic_string<char> ;
	char name[40];
	int age;
	char sex;
	char address[100];

};

void view_details(int acno);
void edit_details(int acno);
void insert_details(int acno);
void clear_kb(void);
int validate(int acno, char *passwrd);
int authenticate(char *username,char *password);
int crtusr(char *usrname,char*password);

#endif /* SERVER_H_ */
