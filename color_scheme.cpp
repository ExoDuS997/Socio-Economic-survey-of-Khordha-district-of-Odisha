#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
using namespace std;


#include<windows.h>
COORD coord={0,0}; // this is global variable
                                    //center of axis is set to the top left corner of the screen
void gotoxy(int x,int y)
{
 	coord.X=x;
 	coord.Y=y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

#include "authenticate.h"
#include "update.h"
#include "find_details.h"
#include "sort.h"
int main()
{
	system("mode 245,9001");
	system("color 57");
	int x= 84,y = 19;
	gotoxy(0,17);
	cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	gotoxy(x-3,y);
	cout<<"SOCIO-ECONOMIC SURVEY OF DISTRICT KHORDHA";
	gotoxy(0,21);
	cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	gotoxy(88,25);
	cout<<"Press Enter to continue.";
	gotoxy(75,35);
	cout<<"***********************************************************";
	gotoxy(75,36);
	cout<<"*                    -Developed by-                       *";
	gotoxy(75,37);
	cout<<"*                Shakti Prasad Mishra                     *";
	gotoxy(75,38);
	cout<<"*                 Tanmay Kumar Bisoi                      *";
	cout<<"***********************************************************";
	getch();
	while(1)
	{	
		system("cls");
		char ch;
		x=83;y=19;
		gotoxy(x+7,y-5);
		cout<<"MAIN MENU";
		gotoxy(15,y-4);
		cout<<"***********************************************************************************************************************************************************************";
		gotoxy(x,y);
		cout<<"1.Update database(admin priviledge)";
		gotoxy(x,y+2);
		cout<<"2.Gram Panchayat details";
		gotoxy(x,y+4);
		cout<<"3.Block details";
		gotoxy(x,y+6);
		cout<<"4.Exit application";
		gotoxy(x,y+10);
		cout<<"Enter your option: ";
		cin>>ch;
		//int is_logged_in = 0;
		switch(ch)
		{
			case '1':		{
						system("cls");
						x=81;y=16;
						gotoxy(x-25,y);
						cout<<"!!!!!!!!!!!!   This page can be accessed only by administrators.   !!!!!!!!!!!!!";
						int  is_logged_in = authenticate::l.login();
						if(is_logged_in==1)
						{
							system("cls");
							x=89;y=16;	
							gotoxy(x,y);
							cout<<"Update database";
							gotoxy(x-4,y+1);
							cout<<"-----------------------";
							gotoxy(x-1,y+3);
							cout<<"1.Add new entry";
							gotoxy(x-1,y+5);
							cout<<"2.Delete an entry";
							gotoxy(x-1,y+7);
							cout<<"3.Edit an entry";
							gotoxy(x-7,y+13);
							cout<<"Or press any other key to go back.";
							gotoxy(x-1,y+15);
							char update_ch;
							cout<<"input: ";cin>>update_ch;
							switch(update_ch)
							{
								case '1':	{
												char cont_choice = 'y';
												while((cont_choice == 'y')||(cont_choice == 'Y'))
												{
													update::add_new();
													cout<<"\n\n\n"<<setw(120)<<"Do you want to add another gram panchayat details(y/n): ";
													cin>>cont_choice;
												}
												break;
											}
								case  '2':	{
												char cont_choice = 'y';
												while((cont_choice == 'y')||(cont_choice == 'Y'))
												{
													update::delete_gp();
													cout<<"\n\n\n"<<setw(120)<<"Do you want to delete another gram panchayat details(y/n): ";
													cin>>cont_choice;
												}
												break;
											}
								case  '3':	{
												char cont_choice = 'y';
												while((cont_choice == 'y')||(cont_choice == 'Y'))
												{
													update::edit();
													cout<<"\n\n\n"<<setw(120)<<"Do you want to edit another gram panchayat details(y/n): ";
													cin>>cont_choice;
												}
												break;
											}
								default: 	break;
							}
						}
						else 
						{
							system("cls");
							gotoxy(84,19);
							cout<<"Invalid credentials";
							gotoxy(84,21);
							cout<<"Press any key to return to main menu.";
							getch();
						}
						break;
						}
			case '2':	{
						system("cls");
						x=86;y=16;	
						gotoxy(x,y);
						cout<<"Gram Panchayat details";
						gotoxy(x-5,y+1);
						cout<<"--------------------------------";
						gotoxy(x,y+2);
						cout<<"1.Display all the details";
						gotoxy(x,y+3);
						cout<<"2.Display a specific gram panchayat details";
						gotoxy(x,y+4);
						cout<<"3.Display population wise";
						gotoxy(x,y+5);
						cout<<"4.Display average income wise";
						gotoxy(x-3,y+8);
						cout<<"Or press any other key to go back to main menu.";
						char input;
						gotoxy(x,y+10);
						cout<<"Enter your option: ";
						cin>>input;
						switch(input)
						{
							case '1':	{
											system("cls");
											find_details::disp_gram_panch();
											cout<<endl;
											cout<<setw(130)<<"--------- Press any key to go back to main menu. ---------"<<endl;
											break;
										}
							case '2':	{
											system("cls");
											string user_gram_panch;
											int x = 80,y=17;
											gotoxy(x,y);
											cout<<"Enter the name of the desired gram panchayat: ";
											cin>>user_gram_panch;
											cout<<"\n\n";
											find_details::disp_gram_panch(user_gram_panch);
											cout<<"\n\n\n\n"<<setw(130)<<"--------- Press any key to go back to main menu. ---------"<<endl;
											break;
										}
							case '3':	{
											system("cls");
											sort::sort_popln();
											cout<<endl;
											cout<<"\n\n\n"<<setw(130)<<"--------- Press any key to go back to main menu. ---------"<<endl;
											break;
										}
							case '4':	{
											system("cls");
											sort::sort_avg_inc();
											cout<<endl;
											cout<<"\n\n"<<setw(130)<<"--------- Press any key to go back to main menu. ---------"<<endl;
											break;
							}
										
						}
						getch();
						break;
						}
			case '3':	{
						system("cls");
						x=84;y=16;	
						gotoxy(x,y);
						cout<<"Block details";
						gotoxy(x-4,y+1);
						cout<<"-----------------------";
						gotoxy(x,y+2);
						cout<<"1.Display all blocks' details.";
						gotoxy(x,y+3);
						cout<<"2.Display specific block details";
						gotoxy(x,y+4);
						cout<<"3.Display blocks population wise ";
						gotoxy(x,y+5);
						cout<<"4.Display blocks average income wise";
						gotoxy(x-3,y+8);
						cout<<"Or press any other key to go back to main menu.";
						gotoxy(x,y+10);
						cout<<"Enter your option: ";
						char input;
						cin>>input;
						switch(input)
						{
							case '1':	{
											system("cls");
											find_details::dispblock();
											cout<<endl;
											cout<<"\n\n\n"<<setw(130)<<"--------- Press any key to go back to main menu. ---------"<<endl;
											break;
										}
							case '2':	{
											system("cls");
											string user_block;
											int x = 80,y=17;
											gotoxy(x,y);
											cout<<"Enter the name of the desired block: ";
											cin>>user_block;
											cout<<"\n\n";
											find_details::dispblock(user_block);
											cout<<"\n\n\n\n"<<setw(130)<<"--------- Press any key to go back to main menu. ---------"<<endl;
											break;
										}
							case '3':	{
											system("cls");
											sort::sort_popln(1);
											cout<<endl;
											cout<<"\n\n\n"<<setw(130)<<"--------- Press any key to go back to main menu. ---------"<<endl;
											break;
										}
							case '4':	{
											system("cls");
											sort::sort_avg_inc(1);
											cout<<endl;
											cout<<"\n\n"<<setw(130)<<"--------- Press any key to go back to main menu. ---------"<<endl;
											break;
										}
						}
						getch();
						break;
						}
			case '4':		{
						exit(0);
						}
			default: 	{
						x=84;y=19;
						system("cls");
						gotoxy(x,y);
						cout<<"Invalid input.... ";
						gotoxy(x,y+1);
						cout<<"Please enter valid option input. ";
						gotoxy(x,y+4);
						cout<<"Press any key to go back.";
						getch();
						}
		}
		
	}
	return 0;
}			
