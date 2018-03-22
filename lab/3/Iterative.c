#include<stdio.h>
#include<math.h>
int main()
{
  int n,i,j,k,l,solve,type;
  double sum,error;
    FILE *fp;
  fp=fopen("/home/godserver/Documents/lab/3/test1.txt","r");
  fscanf(fp,"%d",&n);
  printf("\nsize=%d",n);
  printf("\n");
  double A[n+1][n+1], B[n+1], X[n+1], Xt[n+1];
  while(!feof(fp))
  {
      for(i=1;i<=n+1;i++)
      {
        if(i<=n)
        {
         for(j=1;j<=n;j++)
         {
           fscanf(fp,"%6lf",&A[i][j]);
         }
        }
        else
        {
           for(j=1;j<=n;j++)
           fscanf(fp,"%6lf",&B[j]);
        }
      }
  }
  fclose(fp);
//expression for X
  sum=0;
  solve=0;
  l=0;
  printf("\nPress 1 for Gauss-seidel and 2 for Jacobi : \n\n");
  scanf("%d", &type);
  if(type==2)
  {
    printf("\nEnter Initial assumption : \n");
    for(i=1;i<=n;i++)
    {
      printf("X[%d] : ",i);
      scanf("%lf",&X[i]);
    }
    printf("\nerror: \n");
    scanf("%lf", &error);
    for(j=1;j<=1000;j++)
    {
      for(i=1;i<=n;i++)
      {
        Xt[i] = X[i];
      }
      for(i=1;i<=n;i++)
      {
        sum = 0.0;
        for(k=1;k<=n;k++)
        {
          if(i!=k)
          {
           sum = sum + A[i][k]*Xt[k];
          }
        }
        X[i] = (B[i] - sum)/A[i][i];
        if(fabs(X[i]-Xt[i])<error)
        {
          j=1000;
          solve=1;
        }
      }
      l++;
  printf("\nX[i]   X[final]   X[final-1]\n");
  printf("\n");
  for(i=1;i<=3;i++)
  {
   printf("X[%d] : %lf   %lf\n", i,X[i],Xt[i]);
  }
    }
  }
  else if(type==1)
  {
    printf("\nEnter Initial assumption : \n");
    for(i=2;i<=n;i++)
    {
      printf("X[%d] : ",i);
      scanf("%lf",&X[i]);
    }
    printf("\nerror: \n");
    scanf("%lf", &error);
    for(j=1;j<=1000;j++)
    {
      for(i=1;i<=3;i++)
      {
        sum = 0.0;
        for(k=1;k<=n;k++)
        {
          if(i!=k)
          {
            sum = sum + A[i][k]*X[k];
          }
        }
        Xt[i] = X[i];
        X[i] = (B[i] - sum)/A[i][i];
        if(fabs(X[i]-Xt[i])<error)
        {
          j=1000;
          solve=1;
        }
      }
      l++;
  printf("\nX[i]   X[final]   X[final-1]\n");
  printf("\n");
  for(i=1;i<=3;i++)
  {
   printf("X[%d] : %lf   %lf\n", i,X[i],Xt[i]);
  }
    }
  }
  else
  printf("\nInvalid Response!\n");
  printf("\nNo of iterations : %d\n",l);
  if(solve==1)
  printf("\nIt Converges!\n");
  else if(type==1 || type==2)
  printf("\nIt does not converge!\n");
return 0;
}
