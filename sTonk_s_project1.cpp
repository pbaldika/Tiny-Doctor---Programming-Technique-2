#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdlib>
using namespace std;

fstream in,out;

class Name{
	private:
		string first;
		string last;
	public:
		Name(string first="",string last="")
		{this->first=first; this->last=last;}
		void change(string first,string last)
		{this->first=first; this->last=last;}
		string getLast()
		{return last;}
		string getFull()
		{return first+last;}
};

class Complaint{
	private:
		string comp;
	public:
		Complaint(string comp="") 
		{this->comp=comp;}
		void manualInput();
		void edit();
		string getComplaint()
		{return comp;}
};

void Complaint::manualInput()
{
	string komp1;
	cout<<"What is your complaint Mr./Mrs ? "<<endl;
	getline(cin, comp);
}

void Complaint::edit()
{
	string komp;
	cout<<"What is your complaint now Mr./Mrs ? "<<endl;
	getline(cin, comp);
}

class Treatment{
	private:
		string advice;
	protected:
		void giveAdv()
		{cout<<"Is there any advice? "; getline(cin,advice);}
		virtual string getAdv()
		{return advice;}
	public:
		Treatment(string advice="") {this->advice=advice;}
};

class Physical{
	private:
		string terap;
	public:
		Physical(string terap="") {this->terap=terap;}
		void setTerap(string terap="")
		{this->terap=terap;}
		string getAdv()
		{return terap;}
};

class Herbal{
	private:
		string herb;
	public:
		Herbal(string herb="") {this->herb=herb;}
		void setHerb(string herb="")
		{this->herb=herb;}
		string getAdv()
		{return herb;}
};

class Medicine{
	private:
		string obat;
	public:
		Medicine(string obat="") 
		{this->obat=obat;}
		void setObat(string obat="")
		{this->obat=obat;}
		string getAdv()
		{return obat;}
};

class Disease{
	private:
		string name;
		string define;
		string symptomps;
		Medicine *med;
		Physical *terapi;
		Herbal *Herb;
	public:
		Disease(string name="",string define="",string symptomps="")
		{this->name=name; this->symptomps=symptomps;this->define=define;}
		Disease(string name="",string define="",string symptomps="", string a="", string b="", string c="")
		{this->name=name; this->symptomps=symptomps;this->define=define;med=new Medicine(a); Herb=new Herbal(b); terapi=new Physical(c);}
		void addMed(Medicine *ob1)
		{med=new Medicine; med=ob1;}
		void addPhys(Physical *ob2)
		{terapi=new Physical; terapi=ob2;}
		void addHerb(Herbal *ob3)
		{Herb=new Herbal; Herb=ob3;}
		string getName()
		{return name;}
		string getSymptomps()
		{return this->symptomps;}
		friend ostream &operator <<(ostream &out, Disease &d);
		friend void secondMenu(vector<Disease> i);
};

ostream &operator <<(ostream &out, Disease &d)
{
	out<<"You may suffer a/an "<<d.name<<".";
	out<<"\n\n"<<d.define;
	out<<". \n\nHere are some cure that may help you to heal from your disease.\n\n";
	out<<"Medicine:\n"; out<<d.med->getAdv()<<endl;
	out<<"Herbal:\n"; out<<d.Herb->getAdv()<<endl;
	out<<"Physical treatment:\n"; out<<d.terapi->getAdv()<<endl<<endl<<endl;
}

class Patient{
	private:
		Name nama;
		Complaint komplen;
		Disease *sakit;
	public:
		Patient() {}
		Patient(Name nama, Complaint komplen)
		{this->nama=nama; this->komplen=komplen;}
		void Input();
		void findCure(vector<Disease> il);
		friend ostream &operator <<(ostream &out, Patient &p);
};

void Patient::Input()
{
	string pert, ked;
	
	cout<<"Please enter your last name:  "; getline(cin,ked);
	cout<<"Please enter your first name:   "; getline(cin,pert);
	nama.change(pert,ked);
	komplen.manualInput();
	
}

void Patient::findCure(vector<Disease> il)
{
	int n;
	string sementara;
	bool x=false, y=false;
	int z=0;
	
	sementara=komplen.getComplaint();
	n=sementara.length();
	do
	{
		for(int i=0;i<il.size();i++)
		{
			Disease sakitt=il[i];
			string test=sakitt.getSymptomps();
			if(test.find(sementara)!=std::string::npos)
			{
				if(y && z==0)
				{
					cout<<"Sorry, we can only find the result for "<<sementara<<":\n"<<endl;
					z=1;
					x=true;
				}
				else if(!y && z==0)
				{
					cout<<"Search result:\n\n";
					z=1;
					x=true;
				}
				cout<<sakitt;				
			}
		}
		if(!x)
		{
			n=n-1;
			sementara.erase((n),1);
			y=true;
		}
	}while(n>0 && !x);
			
	if(n==0 && !x)
	{
		cout<<"We're really sorry, we can't find anything. It may because of our lack of info or/n";
		cout<<"there is may some typo during your type. Thank you for choosing us and try again\n\n";
	}
	
	cout<<endl;
	system("pause");
	cout<<"\n\n";	
}
	
	

void Search(vector<Disease> ill, int panj, string sak)
{
	bool x=false, y=false;
	int z=0;
	
	cout<<"What kind of disease do you want to cure?\n"; getline(cin,sak);
			cout<<"\n\n";
			
			
	panj=sak.length();
	do
	{
		for(int i=0;i<ill.size();i++)
		{
			Disease sakitt=ill[i];
			string test=sakitt.getName();
			if(test.find(sak)!=std::string::npos)
			{
				if(y && z==0)
				{
					cout<<"Sorry, we can only find the result for "<<sak<<":\n"<<endl;
					z=1;
					x=true;
				}
				else if(!y && z==0)
				{
					cout<<"Search result:\n\n";
					z=1;
					x=true;
				}
				cout<<sakitt;					
			}
		}
				
		if(!x)
		{
			panj=panj-1;
			sak.erase((panj),1);
			y=true;
		}
	}while(panj>0 && !x);
			
	if(panj==0 && !x)
	{
		cout<<"We're really sorry, we can't find anything. It may because of our lack of info or/n";
		cout<<"there is may some typo during your type. Thank you for choosing us and try again\n\n";
	}
			
	cout<<endl;
	system("pause");
	cout<<"\n\n";
}

int Edit1(vector<Disease> f)
{
	bool x=false, y=false;
	int panj,db=0;
	string sak,accept;
	int z=0;
	
	
	heree:
	cout<<"What disease do you want to edit?\n"; getline(cin,sak);
			cout<<"\n\n";
			
			
	panj=sak.length();
	do
	{
		for(int i=0;i<f.size() && db==0;i++)
		{
			Disease sakitt=f[i];
			string test=sakitt.getName();
			if(test.find(sak)!=std::string::npos)
			{
				if(y && z==0)
				{
					cout<<"Sorry, we can only find the result for "<<sak<<"\n"<<endl;
					z=1;
					x=true;
					db=1;
					
				}
				else if(!y && z==0)
				{
					cout<<"Search result:\n\n";
					z=1;
					x=true;
					db=1;
				}
				cout<<sakitt.getName();
				
				cout<<"\ndo you want to continue? <yes/no>\n";
				cin>>accept;
				if(accept=="yes"||accept=="Yes")
				{
					return i;
				}					
			}
		}
				
		if(!x)
		{
			panj=panj-1;
			sak.erase((panj),1);
			y=true;
		}
	}while(panj>0 && !x);
			
	if(panj==0 && !x)
	{
		cout<<"We're really sorry, we can't find anything. It may because of our lack of info or/n";
		cout<<"there is may some typo during your type. Thank you for choosing us and try again\n\n";
		goto heree;
	}
			
	cout<<endl;
	system("pause");
	cout<<"\n\n";
}

void secondMenu(vector<Disease> i)
{
	int input1=0;
	string input2;
	string pq,qr,rs,st,tu,uv;
	
	int mark;
	string pp,qq,rr,ss,tt,uu;
	
	
	while(input1!=3)
	{
		cout<<"Setting\n\n";
		cout<<"1. Edit data\n";
		cout<<"2. Add data\n";
		cout<<"3. Back to main menu\n";
		cout<<"Input:   ";
		
		here:
		try{
			getline(cin,input2);
			
			for(int i=0;input2[i] != '\0';i++)
			{
				if (isalpha(input2[i]))
				{
        	    	throw 0;
				}
   			}
   			
   			input1= atoi(input2.c_str());
			
		}
		catch(int salah)
		{
			cout<<"\nInvalid input, please try again\n";
			system("pause");
			cout<<"\n\n";
			goto here;	
		}
	
		if(input1==1)
		{
			mark=Edit1(i);
			cin.ignore();
			cout<<"Please enter the data below (type'same' if you don't want to change):\n";
			cout<<"Name: ";
			getline(cin,pp);
			if(pp!="same")
				i[mark].name=pp;
			cout<<"Definition: ";
			getline(cin,qq);
			if(qq!="same")
				i[mark].define=qq;
			cout<<"Symptomps: ";
			getline(cin,rr);
			if(rr!="same")
				i[mark].symptomps=rr;
			cout<<"Medical: ";
			getline(cin,ss);
			if(ss!="same")
				i[mark].med->setObat(ss);
			cout<<"Herbal: ";
			getline(cin,tt);
			if(tt!="same")
				i[mark].Herb->setHerb(tt);
			cout<<"Theraphy: ";
			getline(cin,uu);
			if(uu!="same")
				i[mark].terapi->setTerap(uu);
				
			cout<<"\n\n\nEdit succesfull\n\n";
			system("pause");
			
		}
		else if(input1==2)
		{
			cout<<"Please enter the data below:\n";
			cout<<"Name: ";
			getline(cin,pq);
			cout<<"Definition: ";
			getline(cin,qr);
			cout<<"Symptomps: ";
			getline(cin,rs);
			cout<<"Medical: ";
			getline(cin,st);
			cout<<"Herbal: ";
			getline(cin,tu);
			cout<<"Theraphy: ";
			getline(cin,uv);
		
			i.push_back(Disease(pq,qr,rs,st,tu,uv));
		}
		else if(input1==3)
		{
			out.open("list.txt", ios::out);
			
			for(int j=0;j<i.size();j++)
			{
				out<<i[j].name<<endl;
				out<<i[j].define<<endl;
				out<<i[j].getSymptomps()<<endl;
				out<<i[j].med->getAdv()<<endl;
				out<<i[j].Herb->getAdv()<<endl;
				out<<i[j].terapi->getAdv()<<endl;
			}
		}	
	}
	
	

	
}

int main()
{
	in.open("list.txt", ios::in);
	vector<Disease> sakit2;
	Disease *proto;
	string ab,bc,cd,de,ef,fg;
	
	if(!in)
	{
		cout<<"There is no data, the program will be close\nThank you...."<<endl;
		exit(1);
	}
	else
	{
		for(int i=0;!in.eof();i++)
		{
			
			getline(in, ab);
			getline(in,bc);
			getline(in,cd);
			getline(in,de);
			getline(in,ef);
			getline(in,fg);
			sakit2.push_back(Disease(ab,bc,cd,de,ef,fg));
		}
	}
	
	vector<Patient> one;
	Patient moment;
	string sakiit, password="sTonks project", pass;
	int len=0;
	string choice2;
	int choice=0,pilihan=0;
	
	do
	{	
		cout<<"Welcome :)\nThis is our project from group stonks. We call this project as our tiny doctor.\n";
		cout<<"The aim of this program is to help the user to search for a cure to a disease\nor to check a disease related to the symptomps that ";
		cout<<"they feel like they're\nhaving or just wan to see the probablity of the disease that may occurs.\n\n\n";
		
		cout<<"==========="<<endl;
		cout<<" Main Menu"<<endl;
		cout<<"==========="<<endl<<endl;
		cout<<"1. Find disease and cure according to symptomps\n";
		cout<<"2. Find cure according to disease\n";
		cout<<"3. Edit database\n";
		cout<<"4. Exit\n\n";
		
		
		
		here:
		try{
			cout<<"What we can do for you? (enter a number)\n";
			getline(cin,choice2);
			
			for(int i=0;choice2[i] != '\0';i++)
			{
				if (isalpha(choice2[i]))
				{
        	    	throw 0;
				}
   			}
   			
   			choice= atoi(choice2.c_str());
			
		}
		catch(int salah)
		{
			cout<<"\nInvalid input, please try again\n";
			system("pause");
			cout<<"\n\n";
			goto here;	
		}
		
		
		if(choice==1)
		{
			cout<<"\n\n\n";
			moment.Input();
			moment.findCure(sakit2);
			one.push_back(moment);	
		}
		else if(choice==2)
		{
			Search(sakit2, len, sakiit);
		}
		else if(choice==3)
		{
			cout<<"Password:    "; getline(cin,pass);
			if(pass==password)
			{
				secondMenu(sakit2);
			}
			
			
			cout<<endl;
			system("pause");
			cout<<"\n\n";
		}
	}while(choice!=4);
	
	
	
	return 0;
}


