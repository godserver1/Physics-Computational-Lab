#include<stdio.h>
int main()
{
  int d,i,j,k,t,m,n;
  float temp2,temp;
//taking dimension
  printf("provide no of unknowns\n");
  scanf("%d", &d);
//end
  float A[d][d+1]; float X[d]; float tempA[d][d+1];
//taking elements (start)
  printf("provide elements in matrix\n");
  for(i=1; i<=d; i++)
  {
    for(j=1; j<=d+1; j++)
    {
      scanf("%f", &A[i][j]);
    }
    printf("\n");
  }
//(end)
  printf("! Lab No: 1\n");
  printf("! Title: Gaussian elemination\n");
  printf("! Date: 8/8/2017\n");
  printf("! Name: Oksiya Ayush Puranlal\n");
  printf("! Roll No: 150121028\n");
  printf("! Email: p.oksiya@iitg.ernet.in\n");
//printing matrix (start)
  printf("\n");
  printf("Given matrix: \n");
  for(i=1; i<=d; i++)
  {
    for(j=1; j<=d+1; j=j+1)
    {
      printf("%f ", A[i][j]);
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
       for(n=1; n<=d+1; n++)
       {
         tempA[k][n] = A[t][n];
         A[t][n] = A[k][n];
         A[k][n] = tempA[k][n];
       }
      }
    }
    for(i=k+1; i<=d; i++)
    {
      temp = A[i][k]/A[k][k];
      for(j=1; j<=d+1; j++)
      {
        A[i][j] = A[i][j] - A[k][j]*temp;
      }
    }
  }
//end
//printing upper triangular matrix
  printf("upper triangular matrix: \n");
  for(i=1; i<=d; i++)
  {
    for(j=1; j<=d+1; j++)
    {
      printf("%.2f ", A[i][j]);
    }
    printf("\n");
  }
//end
//backsubstitution
  X[d]=A[d][d+1]/A[d][d];
  for(i=d-1; i>=1; i--)
  {
    temp2=0.0;
    for(j=i+1; j<=d;j++)
    { 
    temp2=temp2+A[i][j]*X[j];
    }
  X[i]=(A[i][d+1]-temp2)/A[i][i];
  }
//end
  printf("\n");
  for(i=1; i<=d; i++)
  {
    printf("X[%d] = %.2f\n", i,X[i]);
  }
return 0;
}
