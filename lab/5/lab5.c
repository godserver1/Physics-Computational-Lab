#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
   int n,i,j,k,l,kdelta,power,p,q,f;
   scanf("%d", &n);
   scanf("%d", &power);
   double X[n+1][n+1],Xpower[n+1][n+1],X2[n+1][n+1],sum,Ho[n+1][n+1],temp;
   double H[n+1][n+1],lambda,Hn[n+1][n+1],Hp[n+1][n+1], R[n+1][n+1], Rt[n+1][n+1],En[n+1], sum1, largest, theta, sign, T, C, S;
//X Matrix of basis "n" creation
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
       kdelta = abs(i-j);
       if(kdelta==1)
       {
         X[i][j] = sqrt(i+j-1)/2;           // X=squareroot(n+m+1)/2hw, hw==1
       }
       else
       {
         X[i][j] = 0.0;
       }
     }
   }
//Ho Matrix of basis "n" creation
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
       if(i==j)
       {
         Ho[i][j] = (i-0.5);               // Ho=(n+1/2)hw, hw==1
       }
       else
       {
         Ho[i][j]=0.0;
       }
     }
   }
//Multiplication of X
   if(power!=1)
   {
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
      {
        sum=0.0;
        for(k=1;k<=n;k++)
        {
          sum = sum + X[i][k]*X[k][j];
        }
        X2[i][j]=sum;
      }
    }
   }
   else
   {
     for(i=1;i<=n;i++)
     {
       for(j=1;j<=n;j++)
       {
         Xpower[i][j]=X[i][j];
       }
     }
   }
   if(power>=3)
   {
    for(l=3;l<=power;l++)
    {
      for(i=1;i<=n;i++)
      {
        for(j=1;j<=n;j++)
        {
          sum=0.0;
          for(k=1;k<=n;k++)
          {
            sum = sum + X[i][k]*X2[k][j];
          }
          Xpower[i][j]=sum;
        }
      }
      for(i=1;i<=n;i++)
      {
        for(j=1;j<=n;j++)
        {
          X2[i][j]=Xpower[i][j];
        }
      }
    }
   }
// first row i.e lambda=0 i.e no perturb
   printf("0.0 ");
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
       if(i==j)
       {
        printf("%lf ", Ho[i][j]);
       }
     }
   }
   printf("\n");
// for lambda=0.1 to 1.0 in 1000 steps
   for(l=1;l<=10000000;l++)
   {
     lambda = 0.0000001*l;
     for(i=1;i<=n;i++)
     {
       for(j=1;j<=n;j++)
       {
         H[i][j] = (Ho[i][j] + (lambda*Xpower[i][j]));
       }
     }
//Jacobi method to diagonalize H, (Diagonal elements are eigenvalues)
     for(f=1;f<=1000000;f++)
     {
   //biggest element
     largest = 0.0;
     for(i=1;i<=n;i++)
     {
       for(j=1;j<=n;j++)
       {
         if(i!=j)
         {
           if(fabs(H[i][j])>largest)
           {
            largest = fabs(H[i][j]);
            if(largest<0.0000001)    //convergencs condition
            {
              f=1000000;
            }
            p = i;   //coordinates
            q = j;   //coordinates
           }
         }
       }
     }
   //Rotation Matrix of basis "n" creation
     theta = (H[q][q]-H[p][p])/(2*H[p][q]);
     sign = fabs(theta)/theta;
     T = (sign/(fabs(theta)-sqrt(theta*theta+1)));
     C = 1/sqrt(1+T*T);
     S = C*T;
     for(i=1;i<=n;i++)
     {
       for(j=1;j<=n;j++)
       {
         if(i==j)
         {
           R[i][j] = 1.0;
         }
         else
         {
           R[i][j] = 0.0;
         }
       }
     }
     R[p][p] = C;
     R[p][q] = S;
     R[q][p] = (-1)*S;
     R[q][q] = C;
   //Rotation Matrix transpose of basis "n" creation
     for(i=1;i<=n;i++)
     {
       for(j=1;j<=n;j++)
       {
         Rt[i][j] = R[j][i];
       }
     }
     for(i=1;i<=n;i++)
     {
       for(j=1;j<=n;j++)
       {
         sum1 = 0.0;
         for(k=1;k<=n;k++)
         {
           sum1 = sum1 + Rt[i][k]*H[k][j];
         }
         Hn[i][j] = sum1;
       }
     }
     for(i=1;i<=n;i++)
     {
       for(j=1;j<=n;j++)
       {
         sum1 = 0.0;
         for(k=1;k<=n;k++)
         {
           sum1 = sum1 + Hn[i][k]*R[k][j];
         }
         Hp[i][j] = sum1;
       }
     }
     for(i=1;i<=n;i++)
     {
       for(j=1;j<=n;j++)
       {
         H[i][j] = Hp[i][j];
       }
     }
   }
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
       if(i==j)
       En[i] = H[i][j];
     }
   }
   for(j=1;j<=n;j++)
   {
     for(i=1;i<=n-1;i++)
     {
       if(En[i+1]>En[i])
       {
        temp = En[i];
        En[i] = En[i+1];
        En[i+1] = temp;
       }
     }
   }
   //printing results for lambda = 0.1 to 1.0
   printf("%lf ", lambda);
   for(i=n;i>=1;i--)
   {
     printf("%lf ", En[i]);
   }
   printf("\n");
  }
return 0;
}
