#include<iostream>
#include<fstream>
using namespace std;

class Employee {
	string name;
	int identity;
 	double salary;
 	
	public:
	void accept() {
		cout<<endl<<"Enter name: ";
		cin.ignore();
		getline(cin,name);
		cout<<"Enter ID: ";
		cin>>identity;
		cout<<"Enter salary (in Rs.): ";
		cin>>salary;
	}

	void display() {
		cout<<endl<<"Name is: "<<name<<endl;
		cout<<"ID is: "<<identity<<endl;
		cout<<"Salary is (in Rs.): "<<salary<<endl;
	}
};

void openFun() {
	Employee o[5];
	fstream f;
	int i,n;

	cout<<endl<<"FILE OPERATION USING open() FUNCTION."<<endl;

	f.open("info.txt",ios::out);
	cout<<endl<<"Enter total employees: ";
	cin>>n;
	for(i=0;i<n;i++) {
		cout<<endl<<"Enter information of employee no.:  "<<i+1<<endl;
		o[i].accept();
		f.write((char*)&o[i],sizeof o[i]);
	}

	f.close();

	f.open("info.txt",ios::in);
	cout<<endl<<"Information stored in:\n";
	for(i=0;i<n;i++) {
		cout<<endl<<"Information of employee "<<i+1<<" is:\n";
		f.write((char*)&o[i],sizeof o[i]);
		o[i].display();
	}
	f.close();
}

void constFun() {
	Employee o[5];
	fstream f;
	int i,n;

	cout<<endl<<"FILE OPERATION USING CONSTRUCTOR FUNCTION."<<endl;

	ofstream outf("info.txt");
	cout<<endl<<"Enter total employees: ";
	cin>>n;
	for(i=0;i<n;i++) {
		cout<<endl<<"Enter information of employee no.:  "<<i+1<<endl;
		o[i].accept();
		outf.write((char*)&o, sizeof o[i]);
	}

	ifstream inf("info.txt");
	cout<<endl<<"Information stored is:\n";
	for(i=0;i<n;i++) {
		cout<<endl<<"Information of employee "<<i+1<<" is:\n";
		o[i].display();
	}
	inf.close();
}

int main() {
	openFun();
	constFun();
 cout<<"\n## DESIGNED AND ENGINEERED BY PRINCE THAKUR\n## END OF FILE";
 return 0;
}
