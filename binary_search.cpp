#include<stdio.h>
#include<conio.h>
int main()
{
	int a[100],i,count,n;
	int j;
	printf("n:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j=2i+1;j<n;j+=1)
	{
		count++;
	
	}
	printf("height=%d",count);
	getch();
}
