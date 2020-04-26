#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;
int main()
{
	FILE *fp,*ft;
	char another,choice;
	
	struct student{
		char fname[50],lname[50];
		char course[100];
		int section;
	};
	
	struct student e;
	char xfname[50],xlname[50];
	long int recsize;
	
	fp=fopen("users.txt","rb+");
	 if(fp==NULL)
	 {
	 	fp=fopen("users.txt","ub+");
	 	
	 	if(fp==NULL)
	 	
	 	{
	 		puts("cannot open file");
	 		return 0;
		 }
	 }
	 
	 recsize=sizeof(e);
	 while(1)
	 
	 {
	 	system("cls");
	 	cout<<"\t\t----------STUDENT DATABASE MANAGEMENT SYSTEM------------\t\t";
	 	cout<<"\n\n\n";
	 	cout<<"\t\t1.Add Details\t\n";
	 	cout<<"\t\t2.List Details\n";
	 	cout<<"\t\t3.Modify details\n";
	 	cout<<"\t\t4.Delete details\n";
	 	cout<<"\t\t5.Exit\n";
	 	cout<<"\n\n";
	 	cout<<"\t\tSelect your choice:";
	 	fflush(stdin);
	 	choice=getche();
	 	switch(choice)
	 	{
	 		case '1':	
	 			fseek(fp,0,SEEK_END);
	 			another='Y';
	 			while(another=='Y'||another=='y')
	 			{
	 				system("cls");
	 				cout<<"Enter the First Name:";
	 				cin>>e.fname;
	 				cout<<"Enter the Last Name:";
	 				cin>>e.lname;
	 				cout<<"Enter the course:";
	 				cin>>e.course;
	 				cout<<"Enter the Section:";
	 				cin>>e.section;
	 				fwrite(&e,recsize,1,fp);
	 				cout<<"Add another record(Y/N)";
	 				fflush(stdin);
	 				another=getchar();
				}	
				break;
			case'2':
				system("cls");
				rewind(fp);
				cout<<"***View the Records in the Database***";
				cout<<"\n";
				while(fread(&e,recsize,1,fp)==1)
				{
					cout<<"\n\n";
					cout<<e.fname<<setw(10)<<e.lname;
					cout<<"\n\n"<<e.course<<setw(8)<<e.section;
				}
				cout<<"\n\n";
				system("pause");
				break;
			case'3':
				system("cls");
				another='Y';
				while(another=='Y'||another=='y')
				{
					cout<<"Enter the Last Name of the student: ";
					cin>>xlname;
					
					rewind(fp);
					while(fread(&e,recsize,1,fp)==1)
					{
						if(strcmp(e.lname,xlname)==0)
						{
							cout<<"\nEnter the First Name:";
	 						cin>>e.fname;
	 						cout<<"\nEnter the Last Name:";
	 						cin>>e.lname;
	 						cout<<"\nEnter the course:";
	 						cin>>e.course;
	 						cout<<"\nEnter the Section:";
	 						cin>>e.section;
	 						fseek(fp,-recsize,SEEK_CUR);
	 						fwrite(&e,recsize,1,fp);
	 						break;
						}
						else
							cout<<"Record not found\n";
					}
					cout<<"Modify another record(Y/N)";
	 				fflush(stdin);
	 				another=getchar();
				}
				break;
			case'4':
					system("cls");
					another='Y';
					while(another=='Y'||another=='y')
					{
						cout<<"\nEnter the last name of the student:";
						cin>>xlname;
						
						ft=fopen("temp.dat","ub");
						
						rewind(fp);
							while(fread(&e,recsize,1,fp)==1)
						
								if(strcmp(e.lname,xlname)!=0)
								{
									fwrite(&e,recsize,1,ft);
								}
							fclose(fp);
							fclose(ft);
							remove("users.txt");
							rename("temp.dat","users.txt");
							
							fp=fopen("users.txt","rb+");
							
							cout<<"Delete another record(Y/N)";
	 						fflush(stdin);
	 						another=getchar();
					}
					break;
			case '5':
					fclose(fp);
					cout<<"\n\n";
					cout<<"THANK YOU\n\n";
					exit(0);
			 }
		 }
		 system("pause");
		 return 0; 	
	 }

