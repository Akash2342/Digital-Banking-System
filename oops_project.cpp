#include<iostream>
using namespace std;
#include<iomanip>
#include<fstream>
class bank{
    public:
	char name[20];
	int acno;
	char actype[20];
	int bal;
	int password;
	public:
		void details(void);
		void deposit(void);
		void withdraw(void);
		void display(void);
		void create_password(int x){
		    password=x;
		}
};
	void bank :: details(void)
	{
		cout<< "Enter name :-  ";
		cin>> name;
		cout<<" Enter A/c non :-  ";
		cin>> acno;
		cout<<"Enter A/c Type :-  ";
		cin>> actype;
		cout<<"Enter opening Balance:- ";
		cin>> bal;
	}
	void bank :: deposit(void){
		int deposit=0;
		cout<< "Enter deposit amount "<<endl;
		cin>> deposit;
		bal= deposit +bal;
		cout<< " Deposit Balance "<<bal<<endl;
	}
	void bank :: withdraw(void)
	{
		int withdraw;
		cout<<" Balance Amount = "<<bal<<endl;
		cout<<" Enter withdraw amount= "<<endl;
		cin>> withdraw;
		if(bal> withdraw){
			bal= bal-withdraw;
			cout<<"Available balance "<<bal<<endl;
		}
		else{
			cout<<"\n not enough balance"<<endl;
		}
	}
	void bank :: display(void){
		cout<<setw(50)<<"Details"<<endl;
		cout<<setw(50)<<"name "<<name<<endl;
		cout<<setw(50)<<"A/c. no. "<<acno<<endl;
		cout<<setw(50)<<"A/c type"<<actype<<endl;
		cout<<setw(50)<<"Balance"<<bal<<endl;
	} 
	int main()
	{
		bank o1;
		int choice;
			cout<<"\n\n\t Banking system program";
			cout<<"\n\n Choice list\n\n";
			cout<<"1) To assign initial value\n";
			cout<<"2) To deposit\n";
			cout<<"3)To withdraw\n";
			cout<<"4) To display all details\n";
			cout<<"5) EXIT\n";
		
			int a=6;
		do{
		    	cout<<"Enter your choice"<<endl;
			cin>>choice;
		if(choice==1)o1.details();
		else if(choice==2)o1.deposit();
		else if(choice==3)o1.withdraw();
		else if(choice==4)o1.display();
		else if(choice==5)break;
		else cout<<"Invalid Choice "<<endl;
		if(a<3){
		    cout<<"too many number of attempt"<<endl;
		    break;}
		}while(a--);
		//writing into the file
		ofstream fout;
		fout.open("file1.txt");
		int pin;
		cout<<"Enter your password (4 digit pin)"<<endl;
	    cin>>pin;
	    o1.create_password(pin);
		fout<<o1.acno<<endl;
		fout<<pin<<endl;
		fout<<o1.bal<<endl;
		fout.close();
		//reading from the file
		cout<<"If you want to check your balance, print 1 else 0"<<endl;
		int q;
		cin>>q;
		if(q==1){
		ifstream fin;
		fin.open("file1.txt");
		int accno;
		fin>>accno;
		cout<<"Your account no is "<<accno<<endl;
		int pass;
		fin>>pass;
		int account_bal;
		fin>>account_bal;
		int i=3;
	    while(i--){
	    	cout<<"Enter your 4 digit pincode"<<endl;
	   	    int code;
	    	cin>>code;
	    	if(code==pass){
	    	    cout<<"Your account balance is "<<account_bal<<endl;
	    	    break;
	    	}
	    	else {
	    	    cout<<"Invalid Attemt "<<i<<endl;
	    	}
	    	if(i==0)cout<<"No more attemt";
	    }
		fin.close();}
		end:
			return 0;
	}
