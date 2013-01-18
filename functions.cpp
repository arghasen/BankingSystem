
#include"server.h"
using namespace std;

void clear_kb(void)
{
char junk[255];
fgets (junk,255,stdin);
}

void view_details(int acno)
{
	FILE *fp;
	usr u;
	long int size=sizeof(u);
	if((fp=fopen("usrinfo.sad","rb"))==NULL)
	{
//		if((fp=fopen("usrinfo.sad","wb+"))==NULL)
		{
			exit(-1);
		}

	}
	rewind(fp);
	while(fread(&u,size,1,fp)==1)
	{
		if(u.accountno==acno)
		{
			cout<<"Account No : "<<u.accountno<<"\nName : "<<u.name<<"\nAge : "<<u.age<<"\nSex : "<<u.sex<<"\nAddress : "<<u.address;
			break;
		}
	}
	fclose(fp);
	fflush(stdin);
}

void edit_details(int acno)
{
	FILE *fp;
	usr u;
	int i;
	char agn='y';

	long int size=sizeof(u);
	fflush(stdin);

	while((agn=='y')||(agn=='Y'))
	{if((fp=fopen("usrinfo.sad","rb+"))==NULL)
	{
//		if((fp=fopen("usrinfo.sad","wb+"))==NULL)
		{
			exit(-1);
		}

	}
	rewind(fp);
	while(fread(&u,size,1,fp)==1)
	{
		if(u.accountno==acno)
		{
			cout<<"give the option for changing field\n1:for name, 2:for age,3:for address\n";
			cin>>i;
			switch(i)
			{
			case 1:

				cout<<"enter name:($) ";
				clear_kb();
				scanf("%[^\n]s",u.name);
				clear_kb();
//				cin>>agn;
				fseek(fp,-size,SEEK_CUR);
				fwrite(&u,size,1,fp);
				break;
			case 2:
				cout<<"enter age: ";
				cin>>u.age;
				fseek(fp,-size,SEEK_CUR);
				fwrite(&u,size,1,fp);
				break;
			case 3:
				cout<<"enter New Address(NA for exit): ";
				scanf("%[^NA]s",u.address);
//				fflush();
				clear_kb();
//				cin>>agn>>agn;
				fseek(fp,-size,SEEK_CUR);
				fwrite(&u,size,1,fp);
				break;

			}


			break;

		}
	}
	fclose(fp);
	view_details(acno);
//	fflush(stdin);
	cout<<"change other details Y/N";
	cin>>agn;

//	cout<<agn<<"change other details Y/N";
//	cin>>agn;
//	fflush(stdin);
	}
//	fclose(fp);
	fflush(stdin);
}
void insert_details(int acno)
{
	system("clear");
	FILE *fp;
	usr u;
//	int q;
//	cout<<"pa";
//	cin>>q;
	long int size=sizeof(u);
	if((fp=fopen("usrinfo.sad","rb+"))==NULL)
	{
		fp=fopen("usrinfo.sad","wb+");

	}
//	cout<<"pa";
//	cin>>q;
//	fclose(fp);
	fseek(fp,0,SEEK_END);
	u.accountno=acno;
//	fclose(fp);
	cout<<"Enter Your Name :";
	clear_kb();
	scanf("%[^\n]s",u.name);
	clear_kb();
	cout<<"enter Age :";
	cin>>u.age;
	cout<<"enter Sex :";
	cin>>u.sex;
	cout<<"enter Address (NA for exit):\n";
	scanf("%[^NA]s",u.address);
	clear_kb();
	fwrite(&u,size,1,fp);
//	fflush(stdin);
//	cin>>q;
//	cout<<q;
	fclose(fp);
}

int validate(int acno, char *passwrd)
{
	FILE *fp;
	account ac;
	long int size=sizeof(ac);
	if((fp=fopen("validate.sad","rb"))==NULL)
		{
			return(-1);
		}
	rewind(fp);
		while(fread(&ac,size,1,fp)==1)
		{
			if(ac.accountno==acno)
			{
				if(strcmp(ac.password,passwrd)==0)
					return(ac.accountno);
				return(-1);
			}
		}
		fclose(fp);
}


int authenticate(char *username,char *password)
{

	FILE *fp;
	logn l;
	account ac;
	//strcpy(l.usrname,usrname);
	//strcpy(ac.password,password);
	long int size=sizeof(l);
	if((fp=fopen("authenticate.sad","rb"))==NULL)
	{
		return(-1);
	}
	rewind(fp);
	while(fread(&l,size,1,fp)==1)
	{
		if(strcmp(l.usrname,username)==0)
		{
			fclose(fp);
			return( validate(l.accountno,password));
		}
	}
	fclose(fp);
	return(-1);
}
int crtusr(char *usrname,char *password)
{
	FILE *fp;
	int accountno;
	int i=1;
	logn l;
	long int size=sizeof(l);
	if((fp=fopen("authenticate.sad","rb+"))==NULL)
	{
		fp=fopen("authenticate.sad","wb+");
	}
	rewind(fp);
	while(fread(&l,size,1,fp)==1)
	{
		if(strcmp(l.usrname,usrname)==0)
			return(-1);
	}
	while(i>=1)
	{
		srand((unsigned)time(NULL));
		accountno=(int)(rand()%100000);
		rewind(fp);
		while(fread(&l,size,1,fp)==1)
		{
			if(l.accountno==accountno)
			{
				i=2;
				break;
			}
		}
		if(i==1)
			i=0;

	}
	fseek(fp,0,SEEK_END);
	l.accountno=accountno;
	strcpy(l.usrname,usrname);
	fwrite(&l,size,1,fp);
	fclose(fp);
	account ac;
	ac.accountno=l.accountno;
	strcpy(ac.password,password);
	size=sizeof(ac);
	fp=NULL;
	if((fp=fopen("validate.sad","rb+"))==NULL)
	{
		fp=fopen("validate.sad","wb+");
	}
	rewind(fp);
	fseek(fp,0,SEEK_END);
	fwrite(&ac,size,1,fp);
	fclose(fp);
	return(l.accountno);

}



