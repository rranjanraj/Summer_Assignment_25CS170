#include<stdio.h>
int main(){
    int n,i=2,c=0;
    printf("Enter the number");
    scanf("%d",&n);
    
    if(n==0||n==1){
        printf("Not Prime");
    }
    while(i<n){
        if(n%i==0){
            c=c+1;
            break;
        }
        i=i+1;
    }
    if(c==0){
        printf("Prime");
    }
    else{
        printf("Not a Prime");
    }
}