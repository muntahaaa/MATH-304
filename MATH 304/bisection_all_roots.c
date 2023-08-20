#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define epsilon 10.0e-6
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)

int main(){
  int n=100,i;
  //printf("a");
  double a1=-5.0,b1=5.0,c,a,b,h;
   //a=a1;
   //b=b1/6; 
  h=(fabs(a1)+fabs(b1))/6;

   a=a1;
 // while(!fabs(b-b1)<epsilon){
    for(int i=0;i<6;i++){
  
   b=a+h;
  if(f(a)*f(b)>0){ 
     printf("%3d %0.5lf %0.5lf %.5lf %.5lf %.5lf %.5lf\n ",i,a,b,c,f(a),f(b),f(c));
    printf("no root\n");
  
  }
  else
  {printf("i     a     b     c     f(a)     f(b)     f(c)\n");
  for(i=0;i<n;i++){
    c=(a+b)/2;
    
 
    if(fabs(f(c)) < epsilon){
    printf("Root : %lf\n",c);
    break;
    }
    printf("%3d %0.5lf %0.5lf %.5lf %.5lf %.5lf %.5lf\n ",i,a,b,c,f(a),f(b),f(c));
  if(f(a)*f(c)<0) b=c;
  else a=c;
  }
  }
  
  a=b;
  //printf("\n%lf",a);
  } 

}

