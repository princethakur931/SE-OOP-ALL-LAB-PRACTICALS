#include<iostream>
using namespace std;
class complex
{
	double real;
	double img;
	public:
		complex();
		friend istream & operator>>(istream &, complex &);
		friend ostream & operator<<(ostream &,const complex &);
		complex operator +(complex);
		complex operator * (complex);
};
complex::complex()
{
	real=0;
	img=0;
}
istream & operator>>(istream &, complex &i)
{
	cin>>i.real>>i.img;
	return cin;
}
ostream & operator<<(ostream &, const complex & d)
{
	cout<<d.real<<"+"<<d.img<<"i"<<endl;
	return cout;
}
complex complex::operator + (complex c1)
{
	complex temp;
	temp.real=real+c1.real;
	temp.img=img+c1.img;
	return temp;
}
complex complex::operator *(complex c2)
{
	complex tmp;
	tmp.real=real*c2.real-img*c2.img;
	tmp.img=real*c2.img+img*c2.real;
	return tmp;
} 
int main()
{
	complex c1,c2,c3,c4;
	int flag=1;
	char b;
	while (flag==1)
	{
		cout<<"enter real and imaginary part of the complex number 1: \n";
		cin>>c1;
		cout<<"enter real and imaginary part of the coplex number 2:";
		cin>>c2;
		int f=1;
		while(f==1)	
		{
			cout<<"complex number 1:"<<c1<<endl;
			cout<<"complex number 2:"<<c2<<endl;
			cout<<"**********menu********"<<endl;
			cout<<"1.  addition of complex numbers"<<endl;
			cout<<"2.  multiplication of copmplex numbers"<<endl;
			cout<<"3.  exit\n";
			int a;
			cout<<"enter yur choice from above menu(1 to 3 ):" ;
			cin>>a;
			if (a==1)
			{
				c3=c1+c2;
				cout<<"addiition:"<<c3<<endl;
				cout<<"do you want to perform another operation (y/n) :\n";
				cin>>b;
				if (b=='y' || b=='y')	
				{
					f=1;
						}
						else
						{
							cout<<"thanks for using this program!!\n";
							flag=0;
							f=0;
						}	
				}
				else if (a==2)
				{
					c4=c1*c2;
					cout<<"multiplication :"<<c4<<endl;
					cout<<"do you want to perform another operation (y/n):\n";
					cin>>b;
					if (b=='y'||b=='y')
					{
						f=1;
					}
					else
					{
						cout<<"thanks for using this program!!\n";
						flag=0;
						f=0;
					}
				}
				else
				{
					cout<<"thanks for using this program!!\n";
					flag=0;
					f=0;
				}
		}
	}
	return 0;
}
