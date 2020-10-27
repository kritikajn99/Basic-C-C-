#include<iostream.h>
#include<conio.h>
#include<process.h>
struct complex

{
	int real;
	int img;
};
void sum (complex c1,complex c2)
{
	complex c3;
	c3.real=c1.real+c2.real;
	c3.img=c1.img+c2.img;
	cout<<" sum is  "<<c3.real<<"  "<<c3.img<<"\n" ;

}
void diff (complex c1,complex c2)
{
	complex c3;
	c3.real=c2.real-c1.real;
	c3.img=c2.real-c1.real;
	cout<<" DIFFERENCE IS "<<c3.real<<"  "<<c3.img<<"\n";

}
void prod (complex c1,complex c2)
{
	complex c3;
	c3.real=(c1.real*c2.real)-(c1.img*c2.img);
	c3.img=(c1.img*c2.real)+(c1.real*c2.img);
	cout<<" PRODUCT IS "<<c3.real<<"  "<<c3.img<<"\n";
}
void div (complex c1,complex c2)

{
	complex c3;
	c3.real=((c1.real*c2.real)+(c1.img*c2.img))/((c2.real*c2.real)+(c2.img*c2.img));
	c3.img=((c1.img*c2.real)-(c1.real*c2.img))/((c2.real*c2.real)+(c2.img*c2.img));
	cout<<" QUOTIENT  IS "<<c3.real<<"  "<<c3.img<<"\n";
}

void main()
{
	clrscr();
	complex p1,p2;
	int ch;
	char ch1;
	cout<<" enter real parts  \n";
	cin>>p1.real;
	cin>>p2.real;
	cout<<" enter img parts  \n";
	cin>>p1.img;
	cin>>p2.img;
	cout<<"              MENU              \n ";
	cout<<"1.ADDITION \n";
	cout<<"2.SUBTRACTION  \n";
	cout<<"3.PRODUCT  \n";
	cout<<"4.DIVISION \n";
	cout<<"5.EXIT  \n";
	cout<<"\n" ;
	do

	 {	cin>>ch;


		switch(ch)
	{
		 case 1 : sum(p1,p2);
			 break;
		 case 2 : diff(p1,p2) ;
			 break;
		 case 3 : prod(p1,p2);
			 break;
		 case 4 : div(p1,p2) ;
			 break;
		 case 5 : exit(0) ;


	}
	cout<<"  WANT TO CONTINUE (y/n) ";
	cin>>ch1;
       } while (ch1=='y'|| ch1=='Y')  ;

	getch();
}