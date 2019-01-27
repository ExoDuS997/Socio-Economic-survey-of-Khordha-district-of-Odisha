namespace authenticate
{
	class admin
	{
		char user_id[15];
		char password[15];
		public:
			void get_data()
			{
				int x = 85,y=19;
				gotoxy(x,y);
				cout<<"User id: ";
				gotoxy(x,y+1);
				cout<<"Password: ";
				gotoxy(x+10,y);
				cin>>user_id;
				gotoxy(x+10,y+1);
				cin>>password;
			}
			void show_data()
			{
				cout<<"User id: "<<user_id<<endl;
				cout<<"Password: "<<password<<endl;
			}
			friend class login_status;
			
	};
	class login_status
	{
		admin u;
		public:
			int login()
			{
				admin a;
				int x=83,y=17;
				gotoxy(x,y);
				cout<<"Enter your credentials...";
				u.get_data();
				
			
					if((!strcmp(u.user_id, "admin007"))&& (!strcmp(u.password , "admin1234")))
						return 1;
				
				
				return 0;
			}
	}l;
	
}
