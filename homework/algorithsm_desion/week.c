#include "stdio.h"

void CaculateWeekDay(int y,int m, int d)
{
    if(m==1||m==2) {
        m+=12;
        y--;
    }
    int iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    printf("\n%d\n",iWeek);
    switch(iWeek)
    {
    case 0: printf("星期一\n"); break;
    case 1: printf("星期二\n"); break;
    case 2: printf("星期三\n"); break;
    case 3: printf("星期四\n"); break;
    case 4: printf("星期五\n"); break;
    case 5: printf("星期六\n"); break;
    case 6: printf("星期日\n"); break;
    }
}
void main()
{
    int year=0,month=0,day=0;
    printf("请输入日期：\n格式为：1900,1,1\n");
    char temp = '1';
    while (temp != '0')
    {
        scanf("%d,%d,%d",&year,&month,&day);

        CaculateWeekDay(year,month,day);
        printf("输入0退出,其他继续:");

    }
}
