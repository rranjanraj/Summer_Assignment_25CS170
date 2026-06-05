
#include<stdio.h>
int main(){
    int num1,num2,a,b;

    printf("Enter a two integer:");

    if (scanf("%d %d",&num1,&num2)!=2){
        printf("Invalid input\n");
        return 1;
    }
     a=(num1<0)?-num1:num1;
     b=(num2<0)?-num2:num2;

     while(a!=b){
        if (a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
     }
     printf("The GCD of %d and %d is :%d\n",num1,num2,a);
     return 0;
}