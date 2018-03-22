#include<stdio.h>
#include<math.h>
int main()
{
  int n, i, j, k;
  printf("Enter dimension: \n");
  scanf("%d", &n);
  float A[n][n], L[n][n], Lt[n][n], An[n][n];
  float sum1;
  printf("\nEnter elements: \n");
  for(i=1; i<=n; i++)
  {
    for(j=1; j<=n; j++)
    {
      scanf("%f", &A[i][j]);  
    }
    printf("\n");
  }//
  printf("! Lab No: 2\n");
  printf("! Title: Cholesky\n");
  printf("! Date: 17/8/2017\n");
  printf("! Name: Oksiya Ayush Puranlal\n");
  printf("! Roll No: 150121028\n");
  printf("! Email: p.oksiya@iitg.ernet.in\n");
//printing given matrix
  printf("supplied matrix: \n");
  for(i=1; i<=n; i++)
  {
    for(j=1; j<=n; j++)
    {
      printf("%f ", A[i][j]);
    }
    printf("\n");
  }
//solving for L
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      if(i==j)
      {
       sum1 = 0.0;
       if(i>=2)
       {
         for(k=1;k<=i-1;k++)
         {
           sum1 = sum1 + L[i][k]*L[i][k];
         }
       }
       L[i][j] = sqrt(A[i][j] - sum1);
      }
      else if(j>=i+1)
      {
          L[i][j] = 0.0;
      }
      else 
      {
         sum1 = 0.0;
         if(j>=2)
         {
           for(k=1;k<=j-1;k++)
           {
             sum1 = sum1 + L[j][k]*L[i][k];
           }
         }
         L[i][j] = (A[i][j] - sum1)/L[j][j];
      }
    }
  }
//for L transpose
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      if(j>=i)
      {
         Lt[i][j] = L[j][i];
      }
      else
      {
         Lt[i][j] = 0.0;
      }
    }
  }
//printing L
  printf("\nL matrix: \n"); 
  for(i=1; i<=n; i++)
  {
    for(j=1; j<=n; j++)
    {
      printf("%f ", L[i][j]);
    }
    printf("\n");
  }
//printing transpose
  printf("\nL transpose matrix: \n"); 
  for(i=1; i<=n; i++)
  {
    for(j=1; j<=n; j++)
    {
      printf("%f ", Lt[i][j]);
    }
    printf("\n");
  }
//for multiplication
  for(i=1;i<=n;i++)
  {
     for(j=1;j<=n;j++)
     {
        An[i][j] = 0.0;
        for(k=0;k<=n;k++)
        An[i][j] += L[i][k]*Lt[k][j];
      }
  }
//printing results
  printf("New A matrix: \n");
  for(i=1; i<=n; i++)
  {
    for(j=1; j<=n; j++)
    {
      printf("%f ", An[i][j]);
    }
    printf("\n");
  }
  return 0;
}
