#include<stdio.h>
int main(){
    int num1,num2,a,b,gcd,lcm;

    printf("Enter a two integer:");

    if (scanf("%d %d",&num1,&num2)!=2){
        printf("Invalid input\n");
        return 1;
    }
    a=(num1<0)?-num1:num1;
     b=(num2<0)?-num2:num2;

     if(a==0||b==0){
        lcm=0;
        printf("The LCM of %d and %d is :%d\n",num1,num2,lcm);
        return 0;
     }
     while(a!=b){
        if (a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
     }
       gcd=a;
       
       lcm=(num1*num2/gcd);

       if (lcm<0){
        lcm=-lcm;
       }
       printf("The Lcm of %d and %d is :%d\n",num1,num2,lcm);
       return 0;
    }