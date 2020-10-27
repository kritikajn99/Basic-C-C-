#include<iostream.h>
#include<conio.h>
#include<process.h>
void main()
{  clrscr();
int ch,r,l,b,base,h;
float const pi=3.14;
float area;

do
{
 cout<< "1. AREA OF CIRCLE \n";
 cout<< "2. AREA OF RECTANGLE \n";
 cout<< "3. AREA OF TRIANGLE \n";
 cout<< "4. EXIT      \n"     ;
 cout<< " ENTER YOUR CHOICE ";
 cin>>ch;
 switch(ch)
 { case 1:
	  cout<<"enter radius";
	  cin>>r;
	  area=pi*r*r;
	  cout<<" area is "<<area<<"\n";
	  break;
   case 2:
	 cout<<"enter length and breadth";
	 cin>>l>>b;
	 area=l*b;
	 cout<<area<<"area is"<<"\n";
	 break;
   case 3:
	cout<<"enter base and height";
	cin>>base>>h;
	area=0.5*base*h;
	cout<<"area is  "<<area<<"\n";
	break;
   case 4:
	exit(0);
	break;
default: cout<< "enter a valid choice";     }
}
while (ch=4);
getch();   }
