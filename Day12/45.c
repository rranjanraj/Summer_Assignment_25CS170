#include<stdio.h>
int palindrome(int num){
    int ognum=num,reverse=0,remainder=0;
    while(num>0){
        remainder=num%10;
        reverse=reverse*10+remainder;
        num/=10;
    }
    return ognum==reverse;
}
int main(){
    int num;
    printf("Enter a number:");
    scanf("%d",&num);
    if(palindrome(num)){
        printf("%d is a palindrome",num);
    }
    else{
        printf("%d is not a palindrome",num);
    }
    return 0;
}