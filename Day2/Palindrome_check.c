#include<stdio.h>
int main(){
    int num,original_num,remainder,reversed=0;
    printf("Enter an integer:");
    scanf("%d",&num);

    original_num=num;

    while(num>0){
        remainder=num%10;
        reversed=reversed*10+remainder;
        num=num/10;
    }
    if(original_num==reversed){
        printf(" Number is Palindrome");
    }
    else{
        printf("Number is not a Palindrome");

    }
    return 0;
}