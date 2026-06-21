#include<stdio.h>

    int sum (int a,int b){
        return a+b;
    }
    int main(){
        int x,y,result;
        printf("Enter the two number:");
        scanf("%d %d",&x,&y);
        result=sum(x,y);
        printf("sum=%d",result);
        return 0;
    }