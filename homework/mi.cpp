#include<stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
int year , month , day ;
int day_of_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
//char wek[7]={'����','��һ','�ܶ�','����','����','����','����'};
int current_year,current_month,current_day;
/************************************ͨ�ùؼ�����**************************************************/
void cls_screen()
{
    printf("�밴���������!\n");
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
��ʽ:w=(y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1)%7
    */
    int w ,k;   //��¼�ܼ�
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
    w = (year_last + year_last/4 + c/4 - 2*c +26*(m+1)/10+day-1); // abs  ����ֵ
    if (w<0)
    {
        k=(w%7+7)%7;
    }
    else k=w%7;
    return k ;
}
/************************************��һ����**************************************************/
void print_year (int year)
{
    int i , k ,x ,first_week;
    printf ("��������Ҫ��ѯ������(��ʽ��2012):");
    scanf ("%d",&year);
    printf("=======================%d��===========================\n",year);
    printf("\n");
    if (judgement(year))
    {
        day_of_month[1]=29;
    }
    else day_of_month[1]=28;
    for (i=1 ; i <13 ; i++)
    {
        first_week = show_week(year,i,1);
        printf("=====================%d����������========================\n",i);
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
/************************************�ڶ�����**************************************************/
void print_year_month ()
{
    int k ,x ,first_week;
    printf ("��������Ҫ��ѯ������(��ʽ��2012 12):");
    do
    {
        scanf ("%d %d",&year,&month);
        if (month<1||month>12)
        {
            printf("��������·�����Ŷ~��������ȷ���·�\n");
            printf ("��������Ҫ��ѯ������(��ʽ��2012 12):");
        }
    }while(1>month||month>12);
    printf("=====================%d��%d��======================\n",year,month);
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
