#include <stdio.h>
#include <stdlib.h>

void DrawPlain(int x);  				//画飞机 
void DrawSpace(int isFired,int y,int x);//根据是否开火，在x列输出激光束 或 空格 ,共输出y行
void PrintScore(int score);				//输出得分 
void DrawTarget(int n);					//画靶子 

void DrawPlain(int x)  //画飞机 
{
	int i;
	for(i=0;i<x;i++) putchar(' ');	     printf("*\n");
	for(i=0;i<x-1;i++) putchar(' ');	printf("***\n");
	for(i=0;i<x-4;i++) putchar(' '); printf("*********\n");
	for(i=0;i<x-1;i++) putchar(' ');	printf("***\n");
	for(i=0;i<x-1;i++) putchar(' ');	printf("***\n");
	for(i=0;i<x-3;i++) putchar(' ');  printf("*******\n");	
}

void DrawSpace(int isFired, int y,int x)//输根据是否开火，在x列输出激光束 或 空格 ,共输出y行
{
	int i,j;
	for(i=0;i<y;i++) 
	{
		for(j=0;j<x;j++) 
			putchar(' '); 
		printf("%c\n",isFired?'|':' ');
	}	
} 

void PrintScore(int score) //输出得分 
{
	printf("%-5d",score); 
} 

void DrawTarget(int n)//画靶子 
{
	int i; 
	for(i=1;i<n;i++) 
		putchar(' '); 
	printf("&\n"); 	
} 

int MoveTarget(int iLocation)//移动靶子 
{
	static int GoLeft=0;
	if ( GoLeft==1 )
	{
		if(--iLocation==5) GoLeft=0;
	}
	else
		if(++iLocation==25) GoLeft=1;
	return iLocation;
} 

int main()
{
	int x=10;    		//飞机初始横坐标 
	int y=5;    		//飞机初始纵坐标
	int iRepeat=1;		//是否继续 
	int isFired=0;		//是否开火 
	int iScore =100;	//得分 
	int iLocation;		//靶子的位置 
	
	srand((unsigned)time(NULL));
	iLocation=rand()%21+5; 
	
	while(iRepeat)
	{
		system("cls");
		
		PrintScore(iScore); 
		iLocation=MoveTarget(iLocation);
		DrawTarget(iLocation);
		DrawSpace(isFired,y,x);	
		DrawPlain(x);
		
		if(isFired)  //开火，打中得10分，没打中扣1分 
		{
			isFired=0;
			
			if(x==iLocation+4)   		//打中靶子 
			{
				iScore+=10;
				Beep(220, 160);			//发出声音 
				iLocation=rand()%20+5;  //再随机产生靶子 
			}
			else
				iScore--;
		}
        if(kbhit())
		switch(getch())
		{
			//每次移动1个字符或1行 
			case 'a': 
				x--;
				if(x<5) x=5; //飞机头离左边至少5个字符 
				break;
			case 'd': 
				x++;
				break;
			case 's': 
				y++;
				break;
			case 'w': 
				y--;
				if(y<1) y=1; //飞机头离靶子至少1行距离 
				break;

			//每次移动2个字符或2行 
			case '4': 
				x-=2;
				if(x<5) x=5; //飞机头离左边至少5个字符 
				break;
			case '6': 
				x+=2;
				break;
			case '2': 
				y+=2;
				break;
			case '8': 
				y-=2;
				if(y<1) y=1; //飞机头离靶子至少1行距离 
				break;

			case  27: 
				iRepeat=0;
				break;
			case ' ': 
				isFired=1;
				Beep(294, 200);				//发出声音
		}
	}
}