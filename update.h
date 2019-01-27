namespace update {


class grampanch										//Gram Panchayat class.
{
	string block;
	string gp_name;
	string avgeduqual;
	string inc_src;
	protected:
		long unsigned popln;
		short sex_rat;
		float lit_rate;	
		long unsigned avg_inc;
		long unsigned noindus;
	public:
		void get_data()
		{
			
			cout<<"----------------------------------------------------------------------------------------------=== ENTER THE DETAILS ===----------------------------------------------------------------------------------------"<<endl;
			cout<<setw(100)<<"Block name: ";
			cin>>block;
			cout<<setw(100)<<"Gram Panchayat: ";
			cin>>gp_name;
			cout<<setw(100)<<"Population: ";
			cin>>popln;
			cout<<setw(100)<<"Sex ratio: ";
			cin>>sex_rat;
			cout<<setw(100)<<"Average educational qualification: ";
			cin>>avgeduqual;
			cout<<setw(100)<<"Literacy rate: ";
			cin>>lit_rate;
			cout<<setw(100)<<"Income source: ";
			cin>>inc_src;
			cout<<setw(100)<<"Average income: ";
			cin>>avg_inc;
			cout<<setw(100)<<"No. of industries: ";
			cin>>noindus;    	
		}
		
		void show_data()
		{
			cout<<"----------------------------------------------------------------------------------------------===  PREVIOUS DETAILS  ===----------------------------------------------------------------------------------------"<<endl;
			cout<<setw(100)<<"Block name: "<<block<<endl;
			cout<<endl<<setw(98)<<"Demographics "<<endl;
			cout<<setw(99)<<"_________________"<<endl;
			cout<<setw(100)<<"Population: "<<popln<<endl;
			cout<<setw(100)<<"Sex ratio: "<<sex_rat<<endl;
			cout<<setw(100)<<"Average educational qualification: "<<avgeduqual<<endl;
			cout<<setw(100)<<"Literacy rate: "<<lit_rate<<endl;
			cout<<endl<<setw(95)<<"Economy "<<endl;
			cout<<setw(99)<<"__________________"<<endl;
			cout<<setw(100)<<"Income source: "<<inc_src<<endl;
			cout<<setw(100)<<"Average income: "<<avg_inc<<endl;
			cout<<setw(100)<<"No. of industries: "<<noindus<<endl;
		}
		
		friend int check(string);
		friend void add_new();
		friend void delete_gp();
		friend void edit();
}g;


int check(string s)
{
	ifstream ifs("ooppro.csv",ios::in);																		//CHANGE THE FILE NAME
	string block,gp_name,line;
	getline(ifs,line,'\n');
	while(!ifs.eof())
	{
		getline(ifs,block,',');
		getline(ifs,gp_name,',');
		getline(ifs,line,'\n');
		if(!strcmpi(s.c_str(),gp_name.c_str()))
		{   ifs.close();
			return 1;
		}
	}
	ifs.close();
	return 0;
}


void add_new()
{
	system("cls");
	int x=80,y=19;
	gotoxy(x,y);
	int is_update = 0;
	cout<<"Enter the details of the Gram Panchayat to be added..."<<endl;
	g.get_data();
	if(check(g.gp_name) == 1)
	{
		gotoxy(x,y+25);
		cout<<"Record of the given entry already exists..."<<endl;
		gotoxy(x,y+26);
		cout<<"Cannot update..";
		gotoxy(x,y+28);
		cout<<"Press any key to go to main menu."<<endl;
		return ;
	}
	ifstream ifs("ooppro.csv",ios::in);
	ofstream ofs("temp.csv",ios::out);
	string dummy,line;
	string block,gp_name,popln,sexrat,lit_rate,avgeduqual,inc_src,avg_inc,noindus;
	getline(ifs,line,'\n');
	ofs<<line<<endl;
	getline(ifs,block,',');
	while(!ifs.eof())
	{      
		if((!strcmpi(block.c_str(),g.block.c_str()))&&(!is_update))
		{
			is_update = 1;
			ofs<<g.block<<","<<g.gp_name<<","<<g.popln<<","<<g.sex_rat<<","<<g.avgeduqual<<","<<g.lit_rate<<","<<g.inc_src<<","<<g.avg_inc<<","<<g.noindus<<endl;
		}
		ofs<<block<<",";
		getline(ifs,line,'\n');
		ofs<<line<<endl;
		getline(ifs,block,',');
	}
	if(is_update == 0)
	{
		ofs.seekp(0,ios::end);
		ofs<<g.block<<","<<g.gp_name<<","<<g.popln<<","<<g.sex_rat<<","<<g.avgeduqual<<","<<g.lit_rate<<","<<g.inc_src<<","<<g.avg_inc<<","<<g.noindus;
	}
	ifs.close();
	ofs.close();
	remove("ooppro.csv");
	rename("temp.csv","ooppro.csv");
	gotoxy(x,y+25);
	cout<<"Updated successfully.";
}

void delete_gp()												//function to delete a gram panchayat record
{
	system("cls");
	int is_delete = 0;
	int x=80,y=19;
	gotoxy(x,y);
	string line,block,gp_name,in_gp_name;
	ifstream ifs("ooppro.csv",ios::in);													//CHANGE THE FILE NAME
	ofstream ofs("temp.csv",ios::out);	
	gotoxy(x,y);															
	cout<<"Enter the name of the gram panchayat to be deleted: ";
	cin>>in_gp_name;																		//check this while execution...s
	getline(ifs,line,'\n');
	ofs<<line<<endl;
	getline(ifs,block,',');
	    getline(ifs,gp_name,',');
		getline(ifs,line,'\n');
	while(!ifs.eof())
	{
		
		if(!strcmpi(in_gp_name.c_str(),gp_name.c_str()))
		{
			is_delete = 1;
			gotoxy(x,y+3);
			cout<<"Deleted successfully...."<<endl;
		}
		else
		{
			ofs<<block<<","<<gp_name<<","<<line<<endl;
		}
		getline(ifs,block,',');
	    getline(ifs,gp_name,',');
		getline(ifs,line,'\n');
	}
	if(is_delete == 0)
	{
		gotoxy(x,y+5);
		cout<<"Given Gram Panchyat details doesn't exist!!! Please enter a valid name.";
	}
	ifs.close();
	ofs.close();
	remove("ooppro.csv");
	rename("temp.csv","ooppro.csv");
}


void edit()
{
	system("cls");
	int x=80,y=19;
	gotoxy(x,y);
	string u_gp_name;
	int is_update = 0;
	cout<<"Enter the details of the Gram Panchayat to be edited: ";
	cin>>u_gp_name;
	if(check(u_gp_name) == 0)
	{
		gotoxy(x,y+25);
		cout<<"Record of the given entry doesn't exists..."<<endl;
		gotoxy(x,y+26);
		cout<<"Cannot update..";
		gotoxy(x,y+28);
		cout<<"Press any key to go to main menu."<<endl;
		return ;
	}
	
	ifstream ifs("ooppro.csv",ios::in);
	ofstream ofs("temp.csv",ios::out);
	string dummy,line;
	string block,gp_name,popln,sex_rat,lit_rate,avgeduqual,inc_src,avg_inc,noindus;
	getline(ifs,line,'\n');
	ofs<<line<<endl;
	getline(ifs,block,',');
	getline(ifs,gp_name,',');
	while(!ifs.eof())
	{      
		if(!strcmpi(gp_name.c_str(),u_gp_name.c_str()))
		{
			is_update = 1;
			g.block = block;
			g.gp_name = u_gp_name;
			getline(ifs,popln,',');
			getline(ifs,sex_rat,',');
			getline(ifs,avgeduqual,',');
			getline(ifs,lit_rate,',');
			getline(ifs,inc_src,',');
			getline(ifs,avg_inc,',');
			getline(ifs,noindus,'\n');
			g. popln = atoi(popln.c_str());
			g.sex_rat = atoi(sex_rat.c_str());
			g.avgeduqual = avgeduqual;
			g.lit_rate = atof(lit_rate.c_str());
			g.inc_src = inc_src;
			g.avg_inc = atoi(avg_inc.c_str());
			g.noindus = atoi(noindus.c_str());
			g.show_data();
			cout<<"----------------------------------------------------------------------------------------------=== ENTER UPDATED DETAILS ===----------------------------------------------------------------------------------------"<<endl;
			cout<<setw(100)<<"Block name: ";
			cin>>g.block;
			cout<<setw(100)<<"Population: ";
			cin>>g.popln;
			cout<<setw(100)<<"Sex ratio: ";
			cin>>g.sex_rat;
			cout<<setw(100)<<"Average educational qualification: ";
			cin>>g.avgeduqual;
			cout<<setw(100)<<"Literacy rate: ";
			cin>>g.lit_rate;
			cout<<setw(100)<<"Income source: ";
			cin>>g.inc_src;
			cout<<setw(100)<<"Average income: ";
			cin>>g.avg_inc;
			cout<<setw(100)<<"No. of industries: ";
			cin>>g.noindus;
			ofs<<block<<","<<g.gp_name<<","<<g.popln<<","<<g.sex_rat<<","<<g.avgeduqual<<","<<g.lit_rate<<","<<g.inc_src<<","<<g.avg_inc<<","<<g.noindus<<endl;
			getline(ifs,line,'\n');
		}
		else
		{
			getline(ifs,line,'\n');
			ofs<<block<<","<<gp_name<<","<<line<<endl;
		}
		getline(ifs,block,',');
		getline(ifs,gp_name,',');
	}
	ifs.close();
	ofs.close();
	remove("ooppro.csv");
	rename("temp.csv","ooppro.csv");

	cout<<"\n\n\n"<<setw(100)<<"Updated successfully.";
		
}



}
