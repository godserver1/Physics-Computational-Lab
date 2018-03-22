#include<stdio.h>
#include<math.h>
int main()
{
   int i, j, k;
   double x, y, dy, x_i, x_f, y_i, h, dy1, dy2, x_temp;
   scanf("%lf", &x_i);
   scanf("%lf", &x_f);
   x_f = x_f + 0.5;
   scanf("%lf", &h);
   scanf("%lf", &y_i);
   k = (x_f-x_i)/h;
   x = 0.0;
   double soln[6][k];
   //printf("X	yexact	yheun	%%rrorheun	yeuler	%%rroreuler\n");
   for(i=0;i<=k;i++)
   {
     y = -1*0.5*x*x*x*x + 4*x*x*x - 10*x*x + 8.5*x+1;       //exact
     soln[1][i] = y;
     soln[2][0] = y_i;                                  //heun
     soln[3][0] = 0.0;
     if(i>0)
     {
        x_temp = x - h;
        dy1 = -1*2*x*x*x + 12*x*x - 20*x + 8.5;
        dy2 = -1*2*x_temp*x_temp*x_temp + 12*x_temp*x_temp - 20*x_temp + 8.5;
        dy = (dy1 + dy2)/2;
        soln[2][i] = soln[2][i-1] + h*dy;
        soln[3][i] = fabs(((soln[1][i] - soln[2][i])/soln[1][i])*100);
     }
     soln[4][0] = y_i;                                  //eulers
     soln[5][0] = 0.0;
     if(i>0)
      {
        x_temp = x - h;	
        dy = -1*2*x_temp*x_temp*x_temp + 12*x_temp*x_temp - 20*x_temp + 8.5;
        soln[4][i] = soln[4][i-1] + h*dy;
        soln[5][i] = fabs(((soln[1][i] - soln[4][i])/soln[1][i])*100);
      }
     printf("%0.2lf	%0.2lf	 %0.2lf    %0.2lf           %0.2lf	  %0.2lf", x, soln[1][i], soln[2][i], soln[3][i], soln[4][i], soln[5][i]);
     printf("\n");
     x = x + h;
   }
   return 0;
}
