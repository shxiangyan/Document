#include<stdio.h>
int IsLeap(int year)
{
  return ((year%4==0&&year%100!=0)||year%400==0);
}

int panduan_xingqi(int y,int m)
{
  int d=1;
     if(m==1||m==2) {
        m+=12;
        y--;
    }
  return (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
}

int count(int year,int month)
{
  int tab[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
  int a[42];
  int begin;
  begin=panduan_xingqi(year,month);

    a[begin]=1;

    for(int i=0 ;i<begin;i++)
      a[i]=-1;
    int index=0;
    for(int i=1 ;i<tab[IsLeap(year)][month];i++)
      {
	index=begin+i;
	a[index]=i+1;
      }
    for(int j=index+1;j<42;j++)
      a[j]=-1;
    printf("   星期一  星期二  星期三  星期四  星期五  星期六   星期日 \n");
    for(int j=0;j<42;j++)
      {if(a[j]==-1)
	  printf("        ");
	else
	printf("      %02d",a[j]);
	if ((j+1)%7==0)
	  printf("\n");
      }
    return 0;
}

void main()
{
  int year,month;
  printf("请输入年份,输入0表示退出\n");
  while(scanf("%d",&year)&&year!=0){
    printf("请输入月份\n");
  scanf("%d",&month);  
  count(year,month);
  printf("请输入年份,输入0表示退出\n");
    }
}
