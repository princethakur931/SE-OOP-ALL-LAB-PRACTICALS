#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class person
{
private:
char name[40], dob[15], bdg[15];
int h,w;
public:
static int count;
friend class personal;
person()
{
	char * name=new char[40];
    char *dob=new char [80];
    char *bdg=new char[15];
	 h=w=0;
}
static void recordcount()
{
   cout<<"\n Total no of records :"<<count;
}
};
class personal{
private:
char add[70], telephone [15],policy_no[10];
 public:
  personal(){
  
     strcpy(add, "");
     strcpy(telephone,"");
     strcpy(policy_no, "");
}
void getdata(person *obj);
void displaydata(person *obj);
friend class person;
};
int person::count=0;
void personal::getdata (person *obj)
{
cout<<"\n Enter Name of Person=";
cin>>obj->name;
cout<<"\n Enter date of birth of person=";
cin>>obj->dob;
cout<<"\n Enter blood group of person=";
cin>>obj->bdg;
cout<<"\n Enter height and weigth of person=";
cin>>obj->h>>obj->w;
cout<<"\n Enter Contact no of person=";
cin>>this->telephone;
cout<<"\n Enter addreass of person=";
cin>>this->add;
cout<<"\n Enter the insurance policy no=";
cin>>this->policy_no;
obj->count++;
}
void personal::displaydata (person *obj)
{
cout<<obj->name<<"\t"<<obj->dob<<"\t\t" <<obj->bdg<<"\t"<<obj->h<<"\t\t" <<obj->w<<"\t" <<this->telephone<<"\t"<<this->policy_no<<"\t" <<this->add;
}
int main()
{
personal *p1[30];
person *p2[30];
int n=0,ch, i;
do
{
cout<<"\n Menu";
cout<<"\n 1.Information of Person \n 2. Display Information \n 3.Exit";
cout<<"\n Enter your choice : ";
cin>>ch;
switch(ch)
{
case 1:
cout<<"\n Enter The Information ";
cout<<"\n";
p1[n]=new personal;
p2[n]=new person;
 p1[n]->getdata(p2[n]);
n++;
person::recordcount();
break;
case 2:
cout<<"\n";
cout<<"\n*****************************************************************************************************\n";
cout<<"NAME"<<"\t" << "DATE OF BIRTH" <<"\t" << "BLOOD GROUP"<<"\t"<<"HEIGHT" <<"\t" << "WEIGHT"<<"\t"<<"TELEPHONE NO" <<"\t" << "INSU.POLICYNO"<<"\t"<<"ADDRESS \n"; cout<<"\n";
for(i=0;i<n;i++)
{
p1[i]->displaydata (p2[i]);

}
person::recordcount();
break; 
}
} while(ch!=3);
return 0;
}
