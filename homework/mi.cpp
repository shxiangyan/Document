#include<stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
int year , month , day ;
int day_of_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
//char wek[7]={'周日','周一','周二','周三','周四','周五','周六'};
int current_year,current_month,current_day;
/************************************通用关键函数**************************************************/
void cls_screen()
{
    printf("请按任意键返回!\n");
    getchar();
    getchar();
    system("cls");
}

int judgement (int y)
{
    if (y % 400 == 0 || (y % 100 !=0 && y %4 ==0))
        return 1 ;
    else return 0 ;
}
int show_week (int year , int month , int day)
{
/*
公式:w=(y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1)%7
    */
    int w ,k;   //记录周几
    int year_last=year %100,c=year/100 , m = month;
    if (month==1 )
    {
        year_last-=1 ;
        m=13 ;
    }
    else if (month==2)
    {
        year_last-=1;
        m=14;
    }
    w = (year_last + year_last/4 + c/4 - 2*c +26*(m+1)/10+day-1); // abs  绝对值
    if (w<0)
    {
        k=(w%7+7)%7;
    }
    else k=w%7;
    return k ;
}
/************************************第一部分**************************************************/
void print_year (int year)
{
    int i , k ,x ,first_week;
    printf ("请输入想要查询的年月(格式如2012):");
    scanf ("%d",&year);
    printf("=======================%d年===========================\n",year);
    printf("\n");
    if (judgement(year))
    {
        day_of_month[1]=29;
    }
    else day_of_month[1]=28;
    for (i=1 ; i <13 ; i++)
    {
        first_week = show_week(year,i,1);
        printf("=====================%d月日历如下========================\n",i);
        printf ("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
        for (x=1;x<=first_week;x++)
        {
            printf("\t");
            if (x%7==0) printf ("\n");
        }
        for (k=1;k<=day_of_month[i-1];k++)
        {
            printf("%d\t",k);
            if (x%7==0) printf ("\n");
            x++;
        }
        printf("\n");
        printf("\n");
        printf("\n");
    }
}
/*
/************************************第二部分**************************************************/
void print_year_month ()
{
    int k ,x ,first_week;
    printf ("请输入想要查询的年月(格式如2012 12):");
    do
    {
        scanf ("%d %d",&year,&month);
        if (month<1||month>12)
        {
            printf("您输入的月份有误哦~请输入正确的月份\n");
            printf ("请输入想要查询的年月(格式如2012 12):");
        }
    }while(1>month||month>12);
    printf("=====================%d年%d月======================\n",year,month);
    if (judgement(year))
    {
        day_of_month[1]=29;
    }
    else day_of_month[1]=28;
    first_week = show_week(year,month,1);
    printf ("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    for (x=1;x<=first_week;x++)
    {
        printf("\t");
        if (x%7==0) printf ("\n");
    }
    for (k=1;k<=day_of_month[month-1];k++)
    {
        printf("%d\t",k);
        if (x%7==0) printf ("\n");
        x++;
    }
    printf("\n");
}
int main()
{
  print_year_month();
  return 0;
}
