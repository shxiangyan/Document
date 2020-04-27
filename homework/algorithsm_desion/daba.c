#include <stdio.h>
#include <stdlib.h>

void DrawPlain(int x);  				//���ɻ� 
void DrawSpace(int isFired,int y,int x);//�����Ƿ񿪻���x����������� �� �ո� ,�����y��
void PrintScore(int score);				//����÷� 
void DrawTarget(int n);					//������ 

void DrawPlain(int x)  //���ɻ� 
{
	int i;
	for(i=0;i<x;i++) putchar(' ');	     printf("*\n");
	for(i=0;i<x-1;i++) putchar(' ');	printf("***\n");
	for(i=0;i<x-4;i++) putchar(' '); printf("*********\n");
	for(i=0;i<x-1;i++) putchar(' ');	printf("***\n");
	for(i=0;i<x-1;i++) putchar(' ');	printf("***\n");
	for(i=0;i<x-3;i++) putchar(' ');  printf("*******\n");	
}

void DrawSpace(int isFired, int y,int x)//������Ƿ񿪻���x����������� �� �ո� ,�����y��
{
	int i,j;
	for(i=0;i<y;i++) 
	{
		for(j=0;j<x;j++) 
			putchar(' '); 
		printf("%c\n",isFired?'|':' ');
	}	
} 

void PrintScore(int score) //����÷� 
{
	printf("%-5d",score); 
} 

void DrawTarget(int n)//������ 
{
	int i; 
	for(i=1;i<n;i++) 
		putchar(' '); 
	printf("&\n"); 	
} 

int MoveTarget(int iLocation)//�ƶ����� 
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
	int x=10;    		//�ɻ���ʼ������ 
	int y=5;    		//�ɻ���ʼ������
	int iRepeat=1;		//�Ƿ���� 
	int isFired=0;		//�Ƿ񿪻� 
	int iScore =100;	//�÷� 
	int iLocation;		//���ӵ�λ�� 
	
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
		
		if(isFired)  //���𣬴��е�10�֣�û���п�1�� 
		{
			isFired=0;
			
			if(x==iLocation+4)   		//���а��� 
			{
				iScore+=10;
				Beep(220, 160);			//�������� 
				iLocation=rand()%20+5;  //������������� 
			}
			else
				iScore--;
		}
        if(kbhit())
		switch(getch())
		{
			//ÿ���ƶ�1���ַ���1�� 
			case 'a': 
				x--;
				if(x<5) x=5; //�ɻ�ͷ���������5���ַ� 
				break;
			case 'd': 
				x++;
				break;
			case 's': 
				y++;
				break;
			case 'w': 
				y--;
				if(y<1) y=1; //�ɻ�ͷ���������1�о��� 
				break;

			//ÿ���ƶ�2���ַ���2�� 
			case '4': 
				x-=2;
				if(x<5) x=5; //�ɻ�ͷ���������5���ַ� 
				break;
			case '6': 
				x+=2;
				break;
			case '2': 
				y+=2;
				break;
			case '8': 
				y-=2;
				if(y<1) y=1; //�ɻ�ͷ���������1�о��� 
				break;

			case  27: 
				iRepeat=0;
				break;
			case ' ': 
				isFired=1;
				Beep(294, 200);				//��������
		}
	}
}