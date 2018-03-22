#include<stdio.h>
int main()
{
  int d,i,j,k,t;
  float temp2,temp;
  printf("provide no of unknowns\n");
  scanf("%d", &d);
  float A[d][d], B[d], X[d], Y[d], templ[d], L[d][d];
  float I[d][d];
  for(i=1;i<=d;i++)
  {
    for(j=1;j<=d;j++)
    {
      if(i==j)
      I[i][j] = 1.0;
      else
      I[i][j] = 0.0;
    }
  }
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
  printf("provide elements in B: \n");
  for(i=1;i<=d;i++)
    scanf("%f", &B[i]);
//converting to upper triangular (start)
  t=1;
  for(k=1; k<=d-1; k++)
  {
    for(i=k+1; i<=d; i++)
    {
      temp = A[i][k]/A[k][k];
      for(j=1; j<=d; j++)
      {
        A[i][j] = A[i][j] - A[k][j]*temp;
        I[i][j] = I[i][j] - I[k][j]*temp;
      }
      templ[t] = temp;
      t++;
    }
  }
//for lower matrix
  k=1;
  for(i=1;i<=d;i++)
  {
    for(j=1;j<=d;j++)
    { 
      if(i==j)
      {
        L[i][j] = 1.0;
      }
      else if(j>=i+1)
      {
         L[i][j] = 0.0;
      }
      else
      {
         L[i][j] = templ[k];
         k++;
      }      
    }
  }
//calculating Y
  Y[1] = B[1];
  for(i=2;i<=d;i++)
  {
    temp = 0.0;
    for(j=1;j<=i-1;j++)
    {
      temp = temp + L[i][j]*Y[j];
    }
    Y[i] = B[i] - temp;
  }
//backsubstitution
  X[d]=Y[d]/A[d][d];
  for(i=d-1; i>=1; i--)
  {
    temp2=0.0;
    for(j=i+1; j<=d;j++)
    { 
    temp2=temp2+A[i][j]*X[j];
    }
  X[i]=(Y[i]-temp2)/A[i][i];
  }
//for identity
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
      for(j=1; j<=d+1; j++)
      {
        A[i][j]=A[i][j]-A[i+k][j]*temp;
        I[i][j]=I[i][j]-I[i+k][j]*temp;
      }
    }
  }
//printing inverse
  printf("\nInverse matrix: \n");
  for(i=1; i<=d; i++)
  {
    for(j=1; j<=d; j++)
    {
      printf("%f ", I[i][j]);
    }
    printf("\n");
  }
return 0;
}
