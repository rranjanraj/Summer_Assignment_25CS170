#include<stdio.h>
int main(){
    int num,remainder,product=1;
    printf("Enter an Integer:");
    scanf("%d",&num);
     if(num==0){
        product=0;
     }
     else{
        if(num<0){
            num=-num;
        }
        while(num>0){
            remainder=num%10;
            product=product*remainder;
            num=num/10;
        }
     }
     printf("Product of Digit=%d\n",product);
     return 0;
}
