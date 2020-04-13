#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 81
void main()
{
  int N;
  printf("请输入正偶数(输入其他表示退出),表示N阶矩阵\n");
  scanf("%d",&N);
  while(N!=-1)
    {
      if(N%2)break;
      int arr[N][N];

      //输入
      int k=1;
      for (int i=0;i<N;++i)
	for(int j=0;j<N;++j)
	  {
	    arr[i][j]=k++;
	  } 

      //中间
      int mid=0;
      mid=N/2;
      //第一分区
      int temp_1=0;
      temp_1=mid-1;
      for(int i=0;i<mid;++i)
	{	  
	  arr[i][i]=0;
	  arr[temp_1][i]=0;
	  --temp_1;
	}
      //第二分区
      int begin_y=mid;
      int temp_2;
      temp_2=mid-1;
      int i=0;
      	for(begin_y;begin_y<N;++begin_y)
      	{
      	  arr[i][begin_y]=0;
      	  arr[temp_2][begin_y]=0;
      	  --temp_2;
      	  ++i;
      	}
      //第三分区
	int begin_x=mid;
	int temp_3;
	temp_3=mid-1;
	int colm=0;
	for(begin_x;begin_x<N;++begin_x)
	  {
	    arr[begin_x][colm]=0;
	    arr[begin_x][temp_3]=0;
	    --temp_3;
	    ++colm;
	  }

	//第四分区
	int temp_4;
	temp_4=mid-1;
	  for(int colm_row=mid;colm_row<N;colm_row++)
	  {
	    arr[colm_row][colm_row]=0;
	    arr[colm_row][mid+temp_4]=0;
	    --temp_4;
	  }
      //填充数组
      int M=0;
      M=(N/2%2)?N-1:N;
      M=M*4;
      int TempArr[M];
      int flag=0;
      int YUAN[N][N];
      int YUN_K=1;
	  for(int i=0;i<N;i++)
	    {
	      for(int j=0;j<N;j++)
		{
		  YUAN[i][j]=YUN_K++;
		}
	    }

	  for(int i=0;i<N;i++)
	    {
	      for(int j=0;j<N;j++)
		{
		  if (!arr[i][j])
		    TempArr[flag++]=YUAN[i][j];
		}
	    }
      //输出
	  for(int p_i=0;p_i<N;p_i++)
	{
	for (int p_j=0;p_j<N;p_j++)
	  {
	    if(!arr[p_i][p_j])arr[p_i][p_j]=TempArr[--M];
	    printf("%-8d ",arr[p_i][p_j]);
	    if(p_j==N/2-1)
	      printf("    ");
	    if(p_j==N-1&&p_i==N/2-1)
	      printf("\n\n");
	  }
	printf("\n\n\n");
	}

      printf("Do you want to save?(y|n)\n");
      char ch;
      scanf(" %c",&ch);
      if (ch=='y')
	{
	  char str[LEN];
	  printf("请输入路径,e.g.:/home/yan/Documents/mofang.txt.\n");
	  getchar();
	  scanf("%s",str);
	  
	  FILE *fp;
	  fp=fopen(str,"a");
	  fprintf(fp,"\n\n-------------------------------------------------------\n输入的偶数为:%d\n",N);
	  for(int p_i=0;p_i<N;p_i++)
	{
	for (int p_j=0;p_j<N;p_j++)
	  {
	    if(!arr[p_i][p_j])arr[p_i][p_j]=TempArr[--M];
	    fprintf(fp,"%-8d ",arr[p_i][p_j]);
	    if(p_j==N/2-1)
	      fprintf(fp,"    ");
	    if(p_j==N-1&&p_i==N/2-1)
	      fprintf(fp,"\n\n");
	  }
	fprintf(fp,"\n\n\n");
	}
	  fclose(fp);
	}
      
      printf("请输入正偶数N(输入其他退出),表示N阶矩阵\n");
      scanf("%d",&N);
    }
}
