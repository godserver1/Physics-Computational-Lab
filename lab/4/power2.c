#include<stdio.h>
#include<math.h>
#define e 0.00000001
int i,j,k;

double eigenvalue_loop(double mat[100][100],double x[100],int n,double temp)
{
  int count;
  double sum,a[100],diff,large_diff;
  count=0;
  while(1)
  {
    count++;
    large_diff=0;
    for(i=1;i<=n;i++)
    {
       sum=0;
       for(j=1;j<=n;j++)
       {
          sum=sum+mat[i][j]*x[j];
       }
       a[i]=sum;
    }
    temp=a[1];
    for(i=1;i<=n;i++)
    {
       if(fabs(a[i])>fabs(temp))
       {
          temp=a[i];
       }
    }
    for(i=1;i<=n;i++)
    {
       a[i]=a[i]/temp;
       diff=fabs(x[i]-a[i]);
       if(diff>large_diff)
       {
          large_diff=diff;
       }
    }
    printf("\n%d iteration : Eigenvalue : %lf\n",count,temp);
    for(i=1;i<=n;i++)
    {
       x[i]=a[i];
    }
    if(large_diff<e)
    {
      break;
    }
  }
  return temp;
}
void elemination(double mat[100][100],int n, double L[100][100])         //function to create multiplication factors and to do elimination
{
   for(k=1;k<=n-1;k++)
   {
      for(i=k+1;i<=n;i++)
      {
         L[i][k]=mat[i][k]/mat[k][k];     //factors
         for(j=1;j<=n;j++)
         {
            mat[i][j]=mat[i][j]-L[i][k]*mat[k][j];                //elimination
         }
      }
    }
}
void copy(double a[100][100],double b[100][100],int n)      //function to copy matrix
{
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
       {
          b[i][j]=a[i][j];
       }
    }
}
void Lower_triangular(double mat[100][100],int n,double L[100][100])       //function to create lower triangular matrix
{
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
         if(i>j)
         {
           L[i][j]=L[i][j];
         }
         else if(i==j)
         {
            L[i][j]=1;
         }
         else  
         {
            L[i][j]=0;
         }
      }
    }
}
void Upper_triangular(double mat[100][100],int n, double U[100][100])      //function to create upper triangular matrix
{
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
         U[i][j]=mat[i][j];
      }
   }
}
void Identity_matrix(double mat[100][100],int n)   //function to create identity matrix
{
    for(i=1;i<=n;i++)
    {
        for(j=n+1;j<=2*n;j++)
        {
            mat[i][j]=0;
        }
        mat[i][n+i]=1;
    }
}
void forward_substitution(double a[100][100],double x[100][100],double b[100][100],int n )   
  //function to calculate D in LD=I
{
    float sum;
    for(k=1;k<=n;k++)
    {
       x[1][k]=b[1][n+k];
       for(i=2;i<=n;i++)
       {
          sum=0;
          for(j=1;j<=i-1;j++)
          {
             sum=sum+a[i][j]*x[j][k];
             x[i][k]=b[i][n+k]-sum;
          }
       }
    }
}
void backward_substitution(double a[100][100],double x[100][100],double b[100][100],int n)   
//function to calculate X(elements of inverse matrix) in UX=D
{
    double sum;
    for(k=1;k<=n;k++)
    {
       x[n][k]=b[n][n+k]/a[n][n];
       for(i=n-1;i>=1;i--)
       {
          sum=0;
          for(j=i+1;j<=n;j++)
          {
             sum=sum+a[i][j]*x[j][k];
          }
          x[i][k]=(b[i][n+k]-sum)/a[i][i];
       }
    }
}
int main()
{
    int n;
    double mat[100][100],x[100],L[100][100],mat1[100][100],U[100][100];
    double d[100],r[100][100],y[100],large,big,small;

    FILE *fp;
    fp=fopen("/home/godserver/Desktop/codes/4/test2.txt","r");
    fscanf(fp,"%d",&n);
    printf("size=%d",n);
    printf("\n\n");
    while(!feof(fp))
    {
        for(i=1;i<=n+1;i++)
        {
           for(j=1;j<=n;j++)
           {
              fscanf(fp,"%lf",&mat[i][j]);
           }
        }
    }
    fclose(fp);
    printf("the entered matrix is:\n");
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
       {
          printf("%lf ",mat[i][j]);
       }
       printf("\n");
    }      
    printf("enter the guess eigenvector:\n");
    for(i=1;i<=n;i++)
    {
       scanf("%lf",&x[i]);
    }
    for(i=1;i<=n;i++)
    {
       y[i]=x[i];
    }
    large=eigenvalue_loop(mat,x,n,large);
    printf("\nlargest eigenvalue of A is : %lf\n",large);
    copy(mat,mat1,n);
    elemination(mat,n,L);
    Lower_triangular(mat,n,L);
    Upper_triangular(mat,n,U);
    Identity_matrix(mat1,n);
    forward_substitution(L,r,mat1,n);
    for(i=1;i<=n;i++)
    {
       for(j=n+1;j<2*n+1;j++)
       {
          mat1[i][j]=r[i][j-n];
       }
    }
    backward_substitution(U,r,mat1,n);
    big=eigenvalue_loop(r,y,n,big);
    printf("\nlargest eigenvalue of A inverse is : %lf\n",big);
    small=1/big;
    printf("largest eigenvalue of A is : %lf\n",large);
    printf("smallest eigenvalue of A is : %lf\n",small);
return 0;
}
