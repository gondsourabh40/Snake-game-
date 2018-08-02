#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
void runf();
void runb();
void rund();
void runu();
void rectangle(int,int,int,int);
struct snake
{
	int x,y;
};
struct snake s[1000]={3,3,4,3,5,3,6,3,7,3};
int length=4,egg[2]={7,3};
char ch=12;
void main()
{
void runsnake();
textmode(64);
_setcursortype(_NOCURSOR);
textbackground(BLUE);
clrscr();
textbackground(BLUE);
textcolor(WHITE);
rectangle(2,2,80,50);
gotoxy(35,1);
printf("==SNAKE==");
gotoxy(65,1);
printf("Score=");
gotoxy(10,1);
printf("Length=");
gotoxy(32,50);
printf("Press ESC to Exit");
runsnake();
}
void runsnake()
{

       runf();
       /*	do
	{
		switch(ch)
		{
			case 77:
			runf();
			break;
		      //	case 80:
		      //	rund();
		       //	break;
		       f	case 72:
			runu();
			break;
			case 75:
			runb();
			break;
		};
	}while(!kbhit());*/
}
void print()
{
	int j,i;
	textcolor(10);
	gotoxy(17,1);
	printf("%d",length);
		for(j=0;j<length;j++)
		{
			gotoxy(s[j].x,s[j].y);
			if(j<length-1)
			cprintf("O");
			else
			{
			textcolor(YELLOW);
			cprintf("\2");
			}
		}
		for(j=0;j<length-1;j++)
		{
			if(s[length-1].x==s[j].x&&s[length-1].y==s[j].y)
			{
				int count=12;
				gotoxy(36,25);
				textcolor(RED);
				cprintf("Game Over");
				gotoxy(33,27);
				cprintf("Press any button");
				while(count--)
				{
				sound(6*random(70));
				delay(75);
				nosound();
				}
				getch();
				exit(0);
			}
		}
		delay(120-length*2);
		if(s[length-1].x==egg[0]&&s[length-1].y==egg[1])
		{
		sound(500);
		delay(40);
		nosound();
		gotoxy(71,1);
		printf("%d",j-3);
		s[length].x=s[length-1].x;
		s[length].y=s[length-1].y;
		length++;
		while(1)
		{
		int i;
		randomize();
		egg[0]=rand()%76+3;
		for(i=0;i<length;i++)
		{
			if(egg[0]==s[i].x)
			break;
		}
		if(i==length)
		break;
		}
		while(1)
		{
		int i;
		randomize();
		egg[1]=rand()%46+3;
		for(i=0;i<length;i++)
		{
			if(egg[1]==s[i].y)
			break;
		}
		if(i==length)
		break;
		}
		gotoxy(egg[0],egg[1]);
		textcolor(14);
		cprintf("\4");
		}
		gotoxy(s[0].x,s[0].y);
		printf(" ");
		for(j=1;j<length;j++)
		s[j-1]=s[j];
}
void rund()
{
	do
	{
		print();
		if(s[length-1].y==48)
		s[length-1].y=2;
		s[length-1].y++;
		if(kbhit())
		{
			if(!(ch=getch()))
			ch=getch();
			if(ch==75)
			runb();
			else if(ch==77)
			runf();
		}
	}while(ch!=27);
}
void runu()
{
	do
	{
		print();
		if(s[length-1].y==3)
		s[length-1].y=49;
		s[length-1].y--;
		if(kbhit())
		{
			if(!(ch=getch()))
			ch=getch();
			if(ch==75)
			runb();
			else if(ch==77)
			runf();
		}
	}while(ch!=27);
}
void runf()
{
	do
	{
		print();
		if(s[length-1].x==78)
		s[length-1].x=2;
		s[length-1].x++;
		if(kbhit())
		{
			if(!(ch=getch()))
			ch=getch();
			if(ch==80)
			rund();
			else if(ch==72)
			runu();
		}
	}while(ch!=27);
}
void runb()
{
	do
	{
		print();
		if(s[length-1].x==3)
		s[length-1].x=79;
		s[length-1].x--;
	if(kbhit())
	{
		if(!(ch=getch()))
		ch=getch();
		if(ch==80)
		rund();
		else if(ch==72)
		runu();
	}
	}while(ch!=27);
}
void rectangle(int l,int lt,int r,int rb)
{
	int i;
	clrscr();
	gotoxy(l,lt);
	printf("%c",218);
	for(i=0;i<r-l-2;i++)
	cprintf("%c",196);
	cprintf("%c",191);
	for(i=0;i<rb-lt-2;i++)
	cprintf("\n\b%c",179);
	gotoxy(l,lt+1);
	for(i=0;i<rb-lt-2;i++)
	cprintf("%c\n\b",179);
	cprintf("%c",192);
	for(i=0;i<r-l-2;i++)
	cprintf("%c",196);
	cprintf("%c",217);
	/*printf("%c%c%c",218,196,191);
	printf("\n%c %c",179,179);
	printf("\n%c%c%c",192,196,217);*/
}
