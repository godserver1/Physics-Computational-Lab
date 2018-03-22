#include<stdio.h>
#include<math.h>
int main()
{
  int n,d,i,j,k,l,solve,t,m;
//taking input from file
  FILE *fp;
  fp=fopen("/home/godserver/Documents/lab/4/test1.txt","r");
  fscanf(fp,"%d",&n);
  printf("\nsize=%d\n",n);
  printf("\n");
  double A[n+1][n+1], Ap[n+1][n+1], G[n+1],Gp[n+1],temp[n+1],tempp[n+1], error[n+1],errorp[n+1], I[n+1][n+1], Ai[n+1][n+1], tempAp[n+1][n+1];
  double sum, biggest, er,erp,error1,temp1,smallest,min, templ[n+1], L[n+1][n+1], X[n+1][n+1], Y[n+1][n+1],temp2,B[n+1][n+1],biggest1,smallest1;
  while(!feof(fp))
  {
      for(i=1;i<=n;i++)
      {
         for(j=1;j<=n;j++)
         {
           fscanf(fp,"%6lf",&A[i][j]);
         }
      }
  }
  fclose(fp);
//file closed
  d=n;
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
       printf("%lf ", A[i][j]);
    }
    printf("\n");
  }
//taking guess
  printf("\nGive Guess Eigenvector : \n");
  for(i=1;i<=n;i++)
  {
    scanf("%lf", &G[i]);
  }
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      Ap[i][j] = A[i][j];
    }
    Gp[i] = G[i];
  }
//taking error
  printf("\nError : \n");
  scanf("%lf", &error1);
//for B
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      if(i==j)
      B[i][j] = 1;
      else
      B[i][j] = 0;
    }
  }
//converting to upper triangular 
  t=1;
  for(k=1; k<=d-1; k++)
  {
    for(i=k+1; i<=d; i++)
    {
      temp1 = Ap[i][k]/Ap[k][k];
      for(j=1; j<=d; j++)
      {
        Ap[i][j] = Ap[i][j] - Ap[k][j]*temp1;
      }
      templ[t] = temp1;
      t++;
    }
  }
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      printf("%lf", Ap[i][j]);
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
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      printf("%lf", L[i][j]);
    }
  }
//calculating Y
  for(m=1;m<=n;m++)
  {
   Y[1][m] = B[1][m];
   for(i=2;i<=d;i++)
   {
     temp1 = 0.0;
     for(j=1;j<=i-1;j++)
     {
       temp1 = temp1 + L[i][j]*Y[j][m];
     }
     Y[i][m] = B[i][m] - temp1;
   }
  }
//backsubstitution
  for(m=1;m<=n;m++)
  {
   X[d][m]=Y[d][m]/Ap[d][d];
   for(i=d-1; i>=1; i--)
   {
     temp2=0.0;
     for(j=i+1; j<=d;j++)
     { 
     temp2=temp2+Ap[i][j]*X[j][m];
     }
     X[i][m]=(Y[i][m]-temp2)/Ap[i][i];
   }
  }
//Final ans
  printf("\n");
  for(m=1;m<=d;m++)
  {
   for(i=1; i<=d; i++)
   {
     printf("%lf ",X[i][m]);
   }
   printf("\n");
  }
//for largest and smallest
  for(l=1;l<=1000;l++)
  {
    for(i=1; i<=n; i++)
    {
       temp[i]=0;
       tempp[i]=0;
       for(j=1; j<=n; j++)
       {
         temp[i]=temp[i]+A[i][j]*G[j];
         tempp[i]=tempp[i]+X[i][j]*Gp[j];
       }
    }
    biggest=fabs(temp[1]);
    biggest1=temp[1];
    smallest=fabs(tempp[1]);
    smallest1=tempp[1];
    for(i=2; i<=n; i++)
    {
       if((fabs(temp[i]))>biggest)
       {
        biggest=fabs(temp[i]);
        biggest1=temp[i];
       }
       if((fabs(tempp[i]))>smallest)
       {
        smallest=fabs(tempp[i]);
        smallest1=tempp[i];
       }
    }
    for(i=1; i<=n; i++)
    {
       temp[i]=temp[i]/biggest1;
       tempp[i]=tempp[i]/smallest1;
    }
    for(i=1; i<=n; i++)
    {
       error[i]=0.0;
       error[i]=fabs((fabs(temp[i]))-(fabs(G[i])));
       errorp[i]=0.0;
       errorp[i]=fabs((fabs(tempp[i]))-(fabs(Gp[i])));
    }
    er=error[1];
    erp=errorp[1];
    for(i=2; i<=n; i++)
    {
       if(error[i]>er)
       er=error[i];
       if(errorp[i]>erp)
       erp=error[i];
    }
    for(i=1; i<=n; i++)
    {
       G[i]=temp[i];
       Gp[i]=tempp[i];
    }
    min=erp;
    if(er>erp)
    {
     min=er;
    }
    if(min<error1)
    {
     solve=1;
     l=1000;
    }
    smallest1 = 1/smallest1;
    printf("\nLargest Eigenvalue after %d iterations : ", l);
    printf("%lf\n", biggest1);
    printf("\nSmallest Eigenvalue after %d iterations : ", l);
    printf("%lf\n", smallest1);
  }
  if(solve == 1)
  {
   printf("\nIt converges!\n");
   printf("\nLargest Eigenvalue : ");
   printf("%lf\n", biggest1);
   printf("\nSmallest Eigenvalue : ");
   printf("%lf\n", smallest1);
  }
  else
  printf("\nDoes not converge!\n");
return 0;
}
