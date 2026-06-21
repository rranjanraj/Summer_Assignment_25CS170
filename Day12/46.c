#include<stdio.h>
int armstrong(int num){
    int ognum=num,sum=0,remainder=0;
    while(num>0){
        remainder=num%10;
        sum=sum+remainder*remainder*remainder;
        num/=10;
    }
    return ognum==sum;
}
int main(){
    int num;
    printf("Enter a number:");
    scanf("%d",&num);
    if(armstrong(num)){
        printf("%d is an armstrong number",num );
    }
    else{
        printf("%d is not an armstrong number",num);
    }
    return 0;

}