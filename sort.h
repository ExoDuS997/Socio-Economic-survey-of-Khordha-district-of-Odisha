namespace sort
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

}; 

class grampanch	: public entity 									//Gram Panchayat class.
{
	string gp_name;
	string avgeduqual;
	string inc_src;
	public:
		friend void sort_popln();
		friend void sort_avg_inc();
		grampanch *next;
		
}*g_start;


		
		
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
		blockclass * next;
		friend blockclass operator+(blockclass &, blockclass &);
		friend blockclass operator/(blockclass &, int);
		friend void sort_popln(int);
		friend void sort_avg_inc(int);

}*bl_start;

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

void sort_popln()
{
	ifstream ifs("ooppro.csv",ios::in);
	string line,block,gp_name,popln,sex_rat,avgeduqual,lit_rate,inc_src,avg_inc,noindus;
	getline(ifs,line,'\n');
	int x = 7,y=4;
	gotoxy(x,y);
	cout<<"GRAM PANCHAYAT";
	gotoxy(x+20,y);
	cout<<"BLOCK";
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
	gotoxy(x,y);
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
	
		grampanch *g;
		g = new grampanch;
		g->block = block;
		g->gp_name = gp_name;
		g->popln = atoi(popln.c_str());
		g->sex_rat = atoi(sex_rat.c_str());
		g->avgeduqual = avgeduqual;
		g->lit_rate = atof(lit_rate.c_str());
		g->inc_src = inc_src;
		g->avg_inc = atoi(avg_inc.c_str());
		g->noindus = atoi(noindus.c_str());
		grampanch *temp ;
		if(g_start == NULL || g_start->popln <= g->popln)
		{
			g->next = g_start;
			g_start = g;
		}
		else
		{
			temp = g_start;
			while (temp->next!=NULL && temp->next->popln > g->popln)
        	{
            	temp  = temp->next;
        	}
        	g->next = temp->next;
        	temp->next = g;
		}
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
	grampanch *temp;
	temp = g_start;
	while(temp->next!=NULL)
	{	
		gotoxy(x,y);
		cout<<temp->gp_name;
		gotoxy(x+20,y);
		cout<<temp->block;
		gotoxy(x+40,y);
		cout<<temp->popln;
		gotoxy(x+60,y);
		cout<<temp->sex_rat;
		gotoxy(x+80,y);
		cout<<temp->avgeduqual;
		gotoxy(x+110,y);
		cout<<temp->lit_rate;
		gotoxy(x+130,y);
		cout<<temp->inc_src;
		gotoxy(x+150,y);
		cout<<temp->avg_inc;
		gotoxy(x+170,y);
		cout<<temp->noindus;
		y++;
		gotoxy(x,y);
		temp = temp->next;
	}
	gotoxy(x,y);
	cout<<temp->gp_name;
	gotoxy(x+20,y);
	cout<<temp->block;
	gotoxy(x+40,y);
	cout<<temp->popln;
	gotoxy(x+60,y);
	cout<<temp->sex_rat;
	gotoxy(x+80,y);
	cout<<temp->avgeduqual;
	gotoxy(x+110,y);
	cout<<temp->lit_rate;
	gotoxy(x+130,y);
	cout<<temp->inc_src;
	gotoxy(x+150,y);
	cout<<temp->avg_inc;
	gotoxy(x+170,y);
	cout<<temp->noindus;
	ifs.close();
	while(g_start!=NULL)
	{
		temp = g_start;
		g_start = temp->next;
		delete temp;
	}

}

void sort_avg_inc()
{
	ifstream ifs("ooppro.csv",ios::in);
	string line,block,gp_name,popln,sex_rat,avgeduqual,lit_rate,inc_src,avg_inc,noindus;
	getline(ifs,line,'\n');
	int x = 7,y=4;
	gotoxy(x,y);
	cout<<"GRAM PANCHAYAT";
	gotoxy(x+20,y);
	cout<<"BLOCK";
	gotoxy(x+40,y);
	cout<<"AVERAGE INCOME";
	gotoxy(x+60,y);
	cout<<"POPULATION";
	gotoxy(x+80,y);
	cout<<"SEX RATIO";
	gotoxy(x+100,y);
	cout<<"AVG. EDU. QUALIFICATION";
	gotoxy(x+130,y);
	cout<<"LITERACY RATE";
	gotoxy(x+150,y);
	cout<<"INCOME SOURCE";
	gotoxy(x+170,y);
	cout<<"NO. OF INDUSTRIES";
	y++;
	gotoxy(x,y);
	cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	gotoxy(x,y);
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
		
		grampanch *g;
		g = new grampanch;
		g->block = block;
		g->gp_name = gp_name;
		g->popln = atoi(popln.c_str());
		g->sex_rat = atoi(sex_rat.c_str());
		g->avgeduqual = avgeduqual;
		g->lit_rate = atof(lit_rate.c_str());
		g->inc_src = inc_src;
		g->avg_inc = atoi(avg_inc.c_str());
		g->noindus = atoi(noindus.c_str());
		grampanch *temp ;
		if(g_start == NULL || g_start->avg_inc <= g->avg_inc)
		{
			g->next = g_start;
			g_start = g;
		}
		else
		{
			temp = g_start;
			while (temp->next!=NULL && temp->next->avg_inc > g->avg_inc)
        	{
            	temp  = temp->next;
        	}
        	g->next = temp->next;
        	temp->next = g;
		}
		
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
	grampanch *temp;
	temp = g_start;
	while(temp->next!=NULL)
	{	
		gotoxy(x,y);
		cout<<temp->gp_name;
		gotoxy(x+20,y);
		cout<<temp->block;
		gotoxy(x+40,y);
		cout<<temp->avg_inc;
		gotoxy(x+60,y);
		cout<<temp->popln;
		gotoxy(x+80,y);
		cout<<temp->sex_rat;
		gotoxy(x+100,y);
		cout<<temp->avgeduqual;
		gotoxy(x+130,y);
		cout<<temp->lit_rate;
		gotoxy(x+150,y);
		cout<<temp->inc_src;
		gotoxy(x+170,y);
		cout<<temp->noindus;
		y++;
		gotoxy(x,y);
		temp = temp->next;
	}
	gotoxy(x,y);
	cout<<temp->gp_name;
	gotoxy(x+20,y);
	cout<<temp->block;
	gotoxy(x+40,y);
	cout<<temp->avg_inc;
	gotoxy(x+60,y);
	cout<<temp->popln;
	gotoxy(x+80,y);
	cout<<temp->sex_rat;
	gotoxy(x+100,y);
	cout<<temp->avgeduqual;
	gotoxy(x+130,y);
	cout<<temp->lit_rate;
	gotoxy(x+150,y);
	cout<<temp->inc_src;
	gotoxy(x+170,y);
	cout<<temp->noindus;
	ifs.close();
	while(g_start!=NULL)
	{
		temp = g_start;
		g_start = temp->next;
		delete temp;
	}

}


void sort_popln(int idummy)
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
	cout<<"Population";
	gotoxy(x+50,y);
	cout<<"Sex Ratio";
	gotoxy(x+75,y);
	cout<<"Literacy Rate";
	gotoxy(x+100,y);
	cout<<("Average Income");
	gotoxy(x+125,y);
	cout<<"No. of industries"<<endl;
	y++;
	gotoxy(x-17,y);
	cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	getline(ifs,b2.block,',');
	block = b2.block;
	getline(ifs,dummy,',');
		getline(ifs,popln,',');
		getline(ifs,sex_rat,',');
		getline(ifs,dummy,',');
		getline(ifs,lit_rate,',');
		getline(ifs,dummy,',');
		getline(ifs,avg_inc,',');
		getline(ifs,noindus,'\n');
	while(!ifs.eof())
	{
		blnum++;
		
		b1.block = b2.block;
		b2.popln = atoi(popln.c_str());
		b2.sex_rat = atoi(sex_rat.c_str());
		b2.lit_rate = atof(lit_rate.c_str());
		b2.avg_inc = atoi(avg_inc.c_str());
		b2.noindus = atoi(noindus.c_str());
		b1 = b1+b2;
		getline(ifs,block,',');	
		if(!(block==b2.block))
		
		{
			b2.block = block;
			if(blnum!=0)
			b1 = b1/blnum;
			blockclass *b3;
			b3 = new blockclass;
			*b3 = b1;
			blockclass *temp;
			if(bl_start == NULL || bl_start->popln <= b3->popln)
			{
				b3->next = bl_start;
				bl_start = b3;
			}
			else
			{
				temp = bl_start;
				while (temp->next!=NULL && temp->next->popln > b3->popln)
        		{
            		temp  = temp->next;
        		}
        		b3->next = temp->next;
        		temp->next = b3;
			}
			blnum = 0;
			b1.popln = b1.sex_rat = b1.lit_rate = b1.avg_inc = b1.noindus = 0;
			
		}
		getline(ifs,dummy,',');
		getline(ifs,popln,',');
		getline(ifs,sex_rat,',');
		getline(ifs,dummy,',');
		getline(ifs,lit_rate,',');
		getline(ifs,dummy,',');
		getline(ifs,avg_inc,',');
		getline(ifs,noindus,'\n');
	
	}
	if(blnum!=0)
	b1 = b1/blnum;
	blockclass *b3;
	b3 = new blockclass;
	*b3 = b1;
	blockclass *temp;
	if(bl_start == NULL || bl_start->popln <= b3->popln)
	{
		b3->next = bl_start;
		bl_start = b3;
	}
	else
	{
		temp = bl_start;
		while (temp->next!=NULL && temp->next->popln > b3->popln)
		{
    		temp  = temp->next;
		}
		b3->next = temp->next;
		temp->next = b3;
	}
	
	temp = bl_start;
	while(temp->next!=NULL)
	{
		y++;
		gotoxy(x,y);
		cout<<temp->block;
		gotoxy(x+25,y);
		cout<<temp->popln;
		gotoxy(x+50,y);
		cout<<temp->sex_rat;
		gotoxy(x+75,y);
		cout<<temp->lit_rate;
		gotoxy(x+100,y);
		cout<<temp->avg_inc;
		gotoxy(x+125,y);
		cout<<temp->noindus<<endl;
		temp = temp->next;
	}
/*	y++;
	gotoxy(x,y);
	cout<<temp->block;
	gotoxy(x+25,y);
	cout<<temp->popln;
	gotoxy(x+50,y);
	cout<<temp->sex_rat;
	gotoxy(x+75,y);
	cout<<temp->lit_rate;
	gotoxy(x+100,y);
	cout<<temp->avg_inc;
	gotoxy(x+125,y);
	cout<<temp->noindus<<endl;*/
	ifs.close();
	while(bl_start!=NULL)
	{
		temp = bl_start;
		bl_start = temp->next;
		delete temp;
	}
	
}


void sort_avg_inc(int idummy)
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
		getline(ifs,noindus,'\n');
		b1.block = b2.block;
		b2.popln = atoi(popln.c_str());
		b2.sex_rat = atoi(sex_rat.c_str());
		b2.lit_rate = atof(lit_rate.c_str());
		b2.avg_inc = atoi(avg_inc.c_str());
		b2.noindus = atoi(noindus.c_str());
		b1 = b1+b2;
		getline(ifs,block,',');	
		if(!(block==b2.block))
		
		{
			b2.block = block;
			if(blnum!=0)
			b1 = b1/blnum;
			blockclass *b3;
			b3 = new blockclass;
			*b3 = b1;
			blockclass *temp;
			if(bl_start == NULL || bl_start->avg_inc <= b3->avg_inc)
			{
				b3->next = bl_start;
				bl_start = b3;
			}
			else
			{
				temp = bl_start;
				while (temp->next!=NULL && temp->next->avg_inc > b3->avg_inc)
        		{
            		temp  = temp->next;
        		}
        		b3->next = temp->next;
        		temp->next = b3;
			}
			blnum = 0;
			b1.popln = b1.sex_rat = b1.lit_rate = b1.avg_inc = b1.noindus = 0;
			
		}
		
	
	}
	if(blnum!=0)
	b1 = b1/blnum;
	blockclass *b3;
	b3 = new blockclass;
	*b3 = b1;
	blockclass *temp;
	if(bl_start == NULL || bl_start->avg_inc <= b3->avg_inc)
	{
		b3->next = bl_start;
		bl_start = b3;
	}
	else
	{
		temp = bl_start;
		while (temp->next!=NULL && temp->next->avg_inc > b3->avg_inc)
		{
    		temp  = temp->next;
		}
		b3->next = temp->next;
		temp->next = b3;
	}
	
	temp = bl_start;
	while(temp->next!=NULL)
	{
		y++;
		gotoxy(x,y);
		cout<<temp->block;
		gotoxy(x+25,y);
		cout<<temp->avg_inc;
		gotoxy(x+50,y);
		cout<<temp->popln;
		gotoxy(x+75,y);
		cout<<temp->sex_rat;
		gotoxy(x+100,y);
		cout<<temp->lit_rate;
		gotoxy(x+125,y);
		cout<<temp->noindus<<endl;
		temp = temp->next;
	}
/*	y++;
	gotoxy(x,y);
	cout<<temp->block;
	gotoxy(x+25,y);
	cout<<temp->avg_inc;
	gotoxy(x+50,y);
	cout<<temp->popln;
	gotoxy(x+75,y);
	cout<<temp->sex_rat;
	gotoxy(x+100,y);
	cout<<temp->lit_rate;
	gotoxy(x+125,y);
	cout<<temp->noindus<<endl;*/
	ifs.close();
	while(bl_start!=NULL)
	{
		temp = bl_start;
		bl_start = temp->next;
		delete temp;
	}
	
}


}



