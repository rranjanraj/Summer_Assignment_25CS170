#include<stdio.h>
int main(){
     int n,t1=0,t2=1,next=0;
    printf("Enter the number of term ");
    scanf("%d",&n);

    if(n==1){
        printf("The %dth fibonacci term is :%d\n",n,t1);
    }
    else if (n==2){
        printf("The %dth fibonacci term is :%d\n",n,t2);
    }
    else{
        for(int i=3;i<=n;i++){
            next=t1+t2;
            t1=t2;
            t2=next;
        }
        printf("The %dth fibonacci term is :%d\n",n,next);
    }
    return 0;
}