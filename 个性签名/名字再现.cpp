#include<iostream>
#include<stdlib.h> 
#include<conio.h>
							//功能：用程序写出自己的名字 ,并能控制其进行上下左右的循环 
using namespace std;
const int row=20;
const int col=40;
char sign1='-';
char sign2='|';
char sign3='/';
char sign4='\\'; 

void print(char word[][col])
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			cout<<word[i][j];
		cout<<endl;
	}
} 

void fuZhi(char word[][col])
{
	int i,j;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			word[i][j]=' ';
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
		{
			if(i==1||i==2||i==3)
			{
				if(j==1||j==3||j==5||j==7)
					if(i!=2) word[i][j]=sign1;
					else if(j==1) word[i][j]=sign4;	
					else word[i][j]=sign2;
				if(i==1)
				{
					if(j==2||j==4||j==6)
						word[i][j]=sign1;
					if(j==14||j==30) word[i][j]=sign4;
				}
				if(i==2)
				{
					if(j==3) word[i][j]=sign4;
					if(j==5||j==7) word[i][j]=sign3;
					if(j==11||j==12||j==13||j==14||j==15||j==16||j==26||j==27||j==28||j==29||j==30||j==31||j==32||j==33||j==34) word[i][j]=sign1;
					
					
				}
					
				if(i==3)
				{
					if(j==2||j==4||j==6)
						word[i][j]=sign1;
					if(j==1||j==7)  word[i][j]=' ';
					if(j==16||j==26||j==30) word[i][j]=sign2;
					if(j==19)
						word[i][j]=sign3;
				}
			}
			if(i==4)
			{
				if(j==4||j==18)
					word[i][j]=sign3;
				if(j==16||j==26||j==30) 
					word[i][j]=sign2;
				if(j==12||j==13||j==14)
					word[i][j]=sign1;
			}
				
			if(i==5)
			{
				if(j==3||j==14||j==26) word[i][j]=sign3; 
				if(j==5||j==4||j==6||j==27||j==28||j==29||j==30||j==31||j==32||j==33||j==34 )
					word[i][j]=sign1;
				if(j==16)
					word[i][j]=sign2;  
				if(j==18)
					word[i][j]=sign4;
				if(j==26)
					word[i][j]='\'';
			}
					
			if(i==6)
			{
				if(j==4||j==31)
					word[i][j]=sign4;
				if(j==2||j==6||j==13||j==25||j==29) 
					word[i][j]=sign3;
				if(j==16)
						word[i][j]=sign2; 
				if(j==19)
						word[i][j]=sign4;
				
			}
			if(i==7)
			{
				if(j==5||j==12||j==24||j==28) 
					word[i][j]=sign3;
				if(j==16)
					word[i][j]=sign2; 
				if(j==15||j==20||j==32)
					word[i][j]=sign4;
			}
			if(i==8)
			{
				if(j==3)
					word[i][j]=sign1;
				if(j==16)
						word[i][j]='\'';
				if(j==23||j==27)
						word[i][j]=sign3;
				if(j==33)
						word[i][j]=sign4;
			}
			
		}
}

void position_left(char word[][col])
{
	int i,j;
	char t[row];
	for(i=0;i<row;i++)
			t[i]=word[i][0];
	
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			word[i][j]=word[i][j+1];
	for(i=0;i<row;i++)	
		word[i][col-1]=t[i];
		
}

void position_right(char word[][col])
{
	int i,j;
	char t[row];
	for(i=0;i<row;i++)
			t[i]=word[i][col-1];
	
	for(i=0;i<row;i++)
		for(j=col-1;j>=1;j--)
			word[i][j]=word[i][j-1];
	for(i=0;i<row;i++)	
		word[i][0]=t[i];
		
}

void position_above(char word[][col])
{
	int i,j;
	char t[col];
	for(i=0;i<col;i++)
			t[i]=word[0][i];
	
	for(i=0;i<row-1;i++)
		for(j=0;j<col;j++)
			word[i][j]=word[i+1][j];
	for(i=0;i<col;i++)	
		word[row-1][i]=t[i];
		
}

void position_below(char word[][col])
{
	int i,j;
	char t[col];
	for(i=0;i<col;i++)
			t[i]=word[row-1][i];
	
	for(i=row-1;i>=1;i--)
		for(j=0;j<col;j++)
			word[i][j]=word[i-1][j];
	for(i=0;i<col;i++)	
		word[0][i]=t[i];
		
}
int main()
{
	char word[row][col],t;
	int i,j;
	int sign=2;
	system("color 0b");
	system("title 我的个性签名");
	fuZhi(word);
	print(word);
	cout<<endl<<"请按任意键开始" ;
	getch(); 
	while(1)
	{
		system("cls");
		switch(sign)
		{
			case 1://上  
				position_above(word); 
				print(word);
				cout<<endl<<endl<<endl<<endl<<"—— 上移中 ——"<<endl; 
				break;
			case 2://下 
				position_below(word); 
				print(word);
				cout<<endl<<endl<<endl<<endl<<"—— 下移中 ——"<<endl; 
				break;
			case 3://左 
				position_left(word); 
				print(word);
				cout<<endl<<endl<<endl<<endl<<"—— 左移中 ——"<<endl; 
				break;
			case 4://右 
				position_right(word); 
				print(word);
				cout<<endl<<endl<<endl<<endl<<"—— 右移中 ——"<<endl; 
				break;
		}
			
		if(kbhit())	
		{
			t=getch();
			if(t=='w') 
			{
				sign=1;
				cout<<"\a"; 
			}
			if(t=='a')
			{
				sign=3;
				cout<<"\a"; 
			}
			if(t=='s')
			{
				sign=2;
				cout<<"\a"; 
			}
			if(t=='d') 
			{
				sign=4;
				cout<<"\a"; 
			}
			if(t==' ')
			{
				cout<<"\a\a\a\a"; 
				break;
			}
			if(t=='p') getch();
		} 
	} 
	cout<<endl<<"观赏结束，欢迎下次再来哦！";
	system("pause"); 
	return 6;
}
