#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<graphics.h>
#include "a.c"
extern char*a[12][50];
int maxx,maxy;
     welcome()
{
 setfillstyle(1,DARKGRAY);
 bar(maxx/2-350,maxy/2-280,maxx/2+350,maxy/2+280);
 setcolor(RED);
 outtextxy(maxx/2-100,maxy/2-150,"   ANAGRAM");
 outtextxy(maxx/2-120,maxy/2+80,"PRESS ANY KEY TO CONTINUE..!");
 setcolor(2);
 outtextxy(maxx/2-120,maxy/2-100,"Instructions:");
 outtextxy(maxx/2-120,maxy/2-80,"You will recieve jumbled words");
  outtextxy(maxx/2-120,maxy/2-60,"Try to solve as many as you can");

 setcolor(BLUE);
  outtextxy(maxx/2-120,maxy/2-40,"Points are as follows:-");
  outtextxy(maxx/2-120,maxy/2-20,"Score is multiplied with 10 and the level");
 setcolor(YELLOW);
 outtextxy(maxx/2-120,maxy/2-0,"EG: Level 1--> score is 10*1");

 getch();
 setfillstyle(1,0);
 setcolor(0);
 bar(maxx/2-350,maxy/2-280,maxx/2+350,maxy/2+280);

 return 0;
}


     int rand_int(int n) {

	int limit = RAND_MAX - RAND_MAX % n;

	int rnd;
			time_t t;


		srand((unsigned) time(&t));
	do {

	    rnd = rand();

	}

	while (rnd >= limit);

	return rnd % n;

    }



    void swap(char *array) {

	int i, j,n;
		char tmp;
			n=strlen(array);


	for (i = n - 1; i > 0; i--) {

	    j = rand_int(i + 1);

	    tmp = array[j];

	    array[j] = array[i];

	    array[i] = tmp;

       }


    }

int randNoGen()
{
   int y;
   time_t t;
   srand((unsigned) time(&t));
   y=rand()%50;

   return y;
}
gaover()
{
int gm=0,gd=DETECT,i,j;
initgraph(&gd,&gm," ");

for(i=1;i<=51;i+=4)
{
setcolor(i);
sound(400-i);
outtextxy(260-i,340-i*10,"GAME OVER");
nosound();
go(0,60,20,80,random(15),random(15));
delay(3);
go(400,460,420,480,random(15),random(15));
}

//getch();
}

go(int sy1,int ey1,int sy2,int ey2,int k,int h)
{
int i,j;
for(j=sy1;j<=ey1;j+=40)        //120
{

for(i=0;i<=640;i+=40)
{

setcolor(k);
rectangle(i,1+j,20+i,21+j);
setfillstyle(SOLID_FILL,k);
floodfill(10+i,10+j,k);
setcolor(h);
rectangle(20+i,1+j,40+i,21+j);
setfillstyle(SOLID_FILL,h);
floodfill(25+i,10+j,h);
}
}
for(j=sy2;j<=ey2;j+=40)
{

for(i=0;i<=640;i+=40)
{

setcolor(h);
rectangle(i,1+j,20+i,21+j);
setfillstyle(SOLID_FILL,h);
floodfill(10+i,10+j,h);
setcolor(k);
rectangle(20+i,1+j,40+i,21+j);
setfillstyle(SOLID_FILL,k);
floodfill(25+i,10+j,k);
}
}
//
}


void main()
{
	int i,level=1,c1=1,score=0;
	 int gd=DETECT,gm;
	char tit[7]={"ANAGRAM"},game[8]={"GAMEOVER"},b[15],c[15],d[15];
	clrscr();
	for(i=0;i<7;i++)
	printf("\t\t\t\t\t%c\n",tit[i]);

 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 maxx=getmaxx();
 maxy=getmaxy();
 welcome();
while(level<=10)
	{        setfillstyle(1,0);
 setcolor(0);

 bar(maxx/2-350,maxy/2-280,maxx/2+350,maxy/2+280);

		if(c1<=8)
		{
			int x=randNoGen();

			 printf("\n\n\n\t\t\tLEVEL%d\n\n\n",level);

			 strcpy(b,a[c1-1][x]);
			 strcpy(c,b);
			 h:swap(b);
			 if(strcmp(b,c)==0)
			 goto h;
			 for(i=0;i<strlen(b);i++)
			 printf("%c ",b[i]);
			 printf("\n");
			 scanf("%s",d);
			 if((strcmp(d,c))==0)
			 {
				printf("\n\nCongratulations!!!Correct answer\n\n\n\n");
				delay(1000);
				clrscr();
				score=score+10*level;
				level++;
			 }
			 else
			 {

			  printf("Correct answer is:%s\n Score is:%d",c,score);
			  break;
			 }
		}
		else
		{
			int x=randNoGen();
			int y;
			  printf("\n\n\n\t\t\tLEVEL%d\n",level);
			 printf("Enter the word length between12 to 14:");
			 scanf("%d",&y);
			 printf("\n\n");
			 strcpy(b,a[y-4][x]);
			 strcpy(c,b);
			 h1:swap(b);
			 if(strcmp(b,c)==0)
			 goto h1;
			 for(i=0;i<strlen(b);i++)
			 printf("%c ",b[i]);
			 printf("\n");
			 scanf("%s",d);
			 if((strcmp(d,c))==0)
			 {
			   if(c1==10)
			   {
				printf("Congratulations!!!Correct Answer\nScore is:%d\n\n\n",score);
				for(i=0;i<8;i++)
				  printf("\t\t\t\t\t%c\n",game[i]);
				  gaover();
				}
				else
				{
				printf("\n\nCongratulations!!!Correct answer\n\n\n\n");
				delay(1000);
				clrscr();
				score=score+10*level;
				level++; }
			 }
			 else
			 {

			  printf("Correct answer is:%s\n Score is:%d",c,score);
			  break;

			 }
		}
		c1++;
	}
	delay(2000);
	gaover();
	getch();
}
