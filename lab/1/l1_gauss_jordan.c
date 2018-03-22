#include<stdio.h>
int main()
{
  int d,i,j,k,t,m,n;
  float temp2,temp;
//taking dimension
  printf("provide no of unknowns\n");
  scanf("%d", &d);
//end
  float A[d+1][d+1];float I[d+1][d+1]; float tempA[d+1][d+1];float tempI[d+1][d+1];
//taking elements (start)
  printf("provide elements in matrix\n");
  for(i=1; i<=d; i++)
  {
    for(j=1; j<=d; j++)
    {
      scanf("%f", &A[i][j]);
    }
    printf("\n");
  }
//printing matrix (start)
  printf("\n");
  printf("Given matrix: \n");
  for(i=1; i<=d; i++)
  {
    for(j=1; j<=d; j++)
    {
      printf("%.2f ", A[i][j]);
    }
    printf("\n");
  }
  printf("\n");
//end
//converting to upper triangular (start)
  for(k=1; k<=d-1; k++)
  {
//pivioting
    for(t=k+1; t<=d; t++)
    {
      if(A[t][k]>A[k][k])
      {
       for(n=1; n<=d; n++)
       {
         tempA[k][n] = A[t][n];
         tempI[k][n] = I[k][n];
         A[t][n] = A[k][n];
         I[t][n] = I[k][n];
         A[k][n] = tempA[k][n];
         I[k][n] = tempI[k][n];
       }
      }
    }
    for(i=k+1; i<=d; i++)
    {
      temp = A[i][k]/A[k][k];
      for(j=1; j<=d; j++)
      {
        A[i][j] = A[i][j] - A[k][j]*temp;
        I[i][j] = I[i][j] - I[k][j]*temp;
      }
    }
  }
//end
//converting to identity matrix
  for(k=1; k<=d; k++)  //first made all diagonals one
  {
    temp = A[k][k];
    for(j=1; j<=d; j++)
    {
      A[k][j] = A[k][j]/temp;
      I[k][j] = I[k][j]/temp;
    }
  }
  for(k=1; k<=d-1; k++)
  {
    for(i=d-1; i>=1; i--)
    {
      temp=A[i][i+k];
      for(j=1; j<=d; j++)
      {
        A[i][j]=A[i][j]-A[i+k][j]*temp;
        I[i][j]=I[i][j]-I[i+k][j]*temp;
      }
    }
  }
  for(i=1;i<=d;i++)
  {
    for(j=1;j<=d;j++)
    {
      printf("%f ", I[i][j]);
    }
    printf("\n");
  }
//end
return 0;
}
