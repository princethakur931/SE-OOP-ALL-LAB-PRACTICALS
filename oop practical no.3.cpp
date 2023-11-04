#include <iostream>
 #include<string> 
 using namespace std; 
 class publication
{
  protected:
  string title;
  float price;
  public:
  publication()
{
title=" ";
price=0.0;
}
publication(string t,float p)
{
title=t;
price=p;
}
};
class book : public publication
{
int pagecount;
public:
book()
{
  pagecount=0;
}
//After base class constructor is called 
book(string t, float p,int pc):publication(t,p)
{
  pagecount=pc;
}
void display()
{
cout<<"title :"<<title<<endl;
cout<<"Price: "<<price<<endl;
cout<<"Pagecount :"<<pagecount<<endl;
}
};
class CD : public publication
{
float time;
public:
CD()
{
  time=0.0;
}
CD(string t,float p,float tim):publication(t,p)
{
  time =tim;

}
void display()
{

cout<<"title :"<<title<<endl;
cout<<"Price: "<<price<<endl;
cout<<"time in minutes :"<<time<<endl;
}
};
int main()
{
cout<<endl<<"Book data" <<endl;
book b("C++",230,300);
b.display();
cout<<endl<<"CD Data"<<endl;
CD c("programming",100,120.5);
c.display();
return 0;
 }
