
namespace find_details
{


class entity
{
	protected:
		string block;
		long unsigned popln;
		short sex_rat;
		float lit_rate;	
		long unsigned avg_inc;
		long unsigned noindus;
	public:
		
		virtual void show_data() = 0;
}; 

class grampanch	: public entity 									//Gram Panchayat class.
{
	string gp_name;
	string avgeduqual;
	string inc_src;
	public:
		
		void show_data()
		{
			cout<<"----------------------------------------------------------------------------------------------===      DETAILS     ===----------------------------------------------------------------------------------------"<<endl;
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
		friend void disp_gram_panch();
		friend void disp_gram_panch(string);
}g;


		
		
class blockclass : public entity
{
	public:
		
		blockclass()
		{
			popln = 0;
			sex_rat = 0;
			lit_rate = 0;
			avg_inc = 0;
			noindus = 0;
		}
		void show_data()
		{
			cout<<"----------------------------------------------------------------------------------------------===      DETAILS     ===----------------------------------------------------------------------------------------"<<endl;
			cout<<setw(100)<<"Block name: "<<block<<endl;
			cout<<endl<<setw(98)<<"Demographics "<<endl;
			cout<<setw(99)<<"_________________"<<endl;
			cout<<setw(100)<<"Population: "<<popln<<endl;
			cout<<setw(100)<<"Sex ratio: "<<sex_rat<<endl;
			cout<<setw(100)<<"Literacy rate: "<<lit_rate<<endl;
			cout<<endl<<setw(95)<<"Economy "<<endl;
			cout<<setw(99)<<"__________________"<<endl;
			cout<<setw(100)<<"Average income: "<<avg_inc<<endl;
			cout<<setw(100)<<"No. of industries: "<<noindus<<endl;
		}
		
		friend blockclass operator+(blockclass &, blockclass &);
		friend blockclass operator/(blockclass &, int);
		friend void dispblock();
		friend void dispblock(string); 

}bl;

blockclass operator+(blockclass & ob1, blockclass &ob2)
{
	blockclass ob3;
	ob3.block = ob1.block;
	ob3.popln = ob1.popln+ob2.popln;
	ob3.sex_rat = ob1.sex_rat+ob2.sex_rat;
	ob3.lit_rate = ob1.lit_rate+ob2.lit_rate;
	ob3.avg_inc = ob1.avg_inc+ob2.avg_inc;
	ob3.noindus = ob1.noindus+ob2.noindus;
	return ob3;
}

blockclass operator/(blockclass &ob1, int count)
{
	blockclass ob2;
	ob2.block = ob1.block;
	ob2.popln = ob1.popln;
	ob2.sex_rat = ob1.sex_rat/count;
	ob2.lit_rate = ob1.lit_rate/count;
	ob2.avg_inc = ob1.avg_inc/count;
	ob2.noindus = ob1.noindus;
	return ob2;
}

void dispblock()																	//function to display all the block details
{
	blockclass b1,b2;
	int i=0,c=0,blnum=0;
	string line,dummy;
	string block,popln,sex_rat,lit_rate,avg_inc,noindus;
	ifstream ifs("ooppro.csv",ios::in);
	getline(ifs,line,'\n');
	int x = 25, y =17;
	gotoxy(x,y);
	cout<<"Block";
	gotoxy(x+25,y);
	cout<<("Average Income");
	gotoxy(x+50,y);
	cout<<"Population";
	gotoxy(x+75,y);
	cout<<"Sex Ratio";
	gotoxy(x+100,y);
	cout<<"Literacy Rate";	
	gotoxy(x+125,y);
	cout<<"No. of industries"<<endl;
	y++;
	gotoxy(x-17,y);
	cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	getline(ifs,b2.block,',');
	block = b2.block;
	
	while(!ifs.eof())
	{
		blnum++;
		getline(ifs,dummy,',');
		getline(ifs,popln,',');
		getline(ifs,sex_rat,',');
		getline(ifs,dummy,',');
		getline(ifs,lit_rate,',');
		getline(ifs,dummy,',');
		getline(ifs,avg_inc,',');
		getline(ifs,noindus);
		b1.block = b2.block;
		b2.popln = atoi(popln.c_str());
		b2.sex_rat = atoi(sex_rat.c_str());
		b2.lit_rate = atof(lit_rate.c_str());
		b2.avg_inc = atoi(avg_inc.c_str());
		b2.noindus = atoi(noindus.c_str());
		b1 = b1+b2;
		if(!ifs.eof())
		getline(ifs,block,',');	
		else
		break;
		if(!(block==b2.block))
		
		{
			b2.block = block;
			if(blnum!=0)
			b1 = b1/blnum;
			y++;
			gotoxy(x,y);
			cout<<b1.block;
			gotoxy(x+25,y);
			cout<<b1.popln;
			gotoxy(x+50,y);
			cout<<b1.sex_rat;
			gotoxy(x+75,y);
			cout<<b1.lit_rate;
			gotoxy(x+100,y);
			cout<<b1.avg_inc;
			gotoxy(x+125,y);
			cout<<b1.noindus<<endl;
			blnum = 0;
			b1.popln = b1.sex_rat = b1.lit_rate = b1.avg_inc = b1.noindus = 0;
			
		}
	}
	ifs.close();
}


void dispblock(string user_block)														//TO DISPLAY DETAILS OF A SPECIFIC BLOCK
{
	blockclass b1,b2;
	int i=0,c=0,blnum=0,found =0;
	string line,dummy;
	string block,popln,sex_rat,lit_rate,avg_inc,noindus;
	ifstream ifs("ooppro.csv",ios::in);
	getline(ifs,line,'\n');
	getline(ifs,b2.block,',');
	block = b2.block;
	while(!ifs.eof())
	{
		if(!strcmpi(block.c_str(),user_block.c_str()))
		{
			found =1;
			blnum++;
			getline(ifs,dummy,',');
			getline(ifs,popln,',');
			getline(ifs,sex_rat,',');
			getline(ifs,dummy,',');
			getline(ifs,lit_rate,',');
			getline(ifs,dummy,',');
			getline(ifs,avg_inc,',');
			getline(ifs,noindus,'\n');
			b1.block = b2.block;
			b2.popln = atoi(popln.c_str());
			b2.sex_rat = atoi(sex_rat.c_str());
			b2.lit_rate = atof(lit_rate.c_str());
			b2.avg_inc = atoi(avg_inc.c_str());
			b2.noindus = atoi(noindus.c_str());
			b1 = b1+b2;
		}
		else
		{
			getline(ifs,line,'\n');
		}
		getline(ifs,block,',');
		b2.block = block;
	}
	if(found == 0)
	{
		cout<<"Entered block does not exist in the database...."<<endl;
	}
	else	
	{
		b1 = b1/blnum;
		b1.show_data();	
	}
	ifs.close();
	
}

void disp_gram_panch()											//TO DISPLAY ENTIRE DATABASE OF GRAM PANCHAYATS
{
	string line;
	ifstream ifs("ooppro.csv",ios::in);
	string block,gp_name,popln,sex_rat,avgeduqual,lit_rate,inc_src,avg_inc,noindus;
	getline(ifs,line,'\n');
	int x = 7,y=4;
	gotoxy(x,y);
	cout<<"BLOCK";
	gotoxy(x+20,y);
	cout<<"GRAM PANCHAYAT";
	gotoxy(x+40,y);
	cout<<"POPULATION";
	gotoxy(x+60,y);
	cout<<"SEX RATIO";
	gotoxy(x+80,y);
	cout<<"AVG. EDU. QUALIFICATION";
	gotoxy(x+110,y);
	cout<<"LITERACY RATE";
	gotoxy(x+130,y);
	cout<<"INCOME SOURCE";
	gotoxy(x+150,y);
	cout<<"AVERAGE INCOME";
	gotoxy(x+170,y);
	cout<<"NO. OF INDUSTRIES";
	y++;
	gotoxy(x,y);
	cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	y++;
	getline(ifs,block,',');
	getline(ifs,gp_name,',');
	getline(ifs,popln,',');
	getline(ifs,sex_rat,',');
	getline(ifs,avgeduqual,',');
	getline(ifs,lit_rate,',');
	getline(ifs,inc_src,',');
	getline(ifs,avg_inc,',');
	getline(ifs,noindus,'\n');
	while(!ifs.eof())
	{
		
		g.block = block;
		g.gp_name = gp_name;
		g. popln = atoi(popln.c_str());
		g.sex_rat = atoi(sex_rat.c_str());
		g.avgeduqual = avgeduqual;
		g.lit_rate = atof(lit_rate.c_str());
		g.inc_src = inc_src;
		g.avg_inc = atoi(avg_inc.c_str());
		g.noindus = atoi(noindus.c_str());
		gotoxy(x,y);
		cout<<g.block;
		gotoxy(x+20,y);
		cout<<g.gp_name;
		gotoxy(x+40,y);
		cout<<g.popln;
		gotoxy(x+60,y);
		cout<<g.sex_rat;
		gotoxy(x+80,y);
		cout<<g.avgeduqual;
		gotoxy(x+110,y);
		cout<<g.lit_rate;
		gotoxy(x+130,y);
		cout<<g.inc_src;
		gotoxy(x+150,y);
		cout<<g.avg_inc;
		gotoxy(x+170,y);
		cout<<g.noindus;
		y++;
		gotoxy(x,y);
		getline(ifs,block,',');
		getline(ifs,gp_name,',');
		getline(ifs,popln,',');
		getline(ifs,sex_rat,',');
		getline(ifs,avgeduqual,',');
		getline(ifs,lit_rate,',');
		getline(ifs,inc_src,',');
		getline(ifs,avg_inc,',');
		getline(ifs,noindus,'\n');
	}
	ifs.close();
}

void disp_gram_panch(string user_gram_panch)
{
	string line;
	int found = 0;
	ifstream ifs("ooppro.csv",ios::in);
	string block,gp_name,popln,sex_rat,avgeduqual,lit_rate,inc_src,avg_inc,noindus;
	getline(ifs,line,'\n');
	while(!ifs.eof())
	{
		getline(ifs,block,',');
		getline(ifs,gp_name,',');
		if(!strcmpi(gp_name.c_str(),user_gram_panch.c_str()))
		{
			found = 1;
			getline(ifs,popln,',');
			getline(ifs,sex_rat,',');
			getline(ifs,avgeduqual,',');
			getline(ifs,lit_rate,',');
			getline(ifs,inc_src,',');
			getline(ifs,avg_inc,',');
			getline(ifs,noindus,'\n');
			g.block = block;
			g.gp_name = gp_name;
			g. popln = atoi(popln.c_str());
			g.sex_rat = atoi(sex_rat.c_str());
			g.avgeduqual = avgeduqual;
			g.lit_rate = atof(lit_rate.c_str());
			g.inc_src = inc_src;
			g.avg_inc = atoi(avg_inc.c_str());
			g.noindus = atoi(noindus.c_str());
			g.show_data();	
		}
		else
		{
			getline(ifs,line,'\n');
		}
	}
	if(found == 0)
	{
		cout<<setw(138)<<"!!!! Entered Gram panchyat record doesnot exist in the database..... !!!!"<<endl;
	}
	ifs.close();
}

}
