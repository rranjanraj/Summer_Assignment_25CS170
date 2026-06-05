#include<stdio.h>
int main(){
    int lower,upper,i,j,prime;
    printf("Enter lower bound");
    scanf("%d",&lower);
    printf("Enter upper bound");
    scanf("%d",&upper);

    printf("Prime number between %d and %d are:\n",lower,upper);

    for(i=lower;i<=upper;i++){
        if(i<2){
            continue;
        }
        prime=1;
    
    for(j=2;j<=i/2;j++){
        if(i%j==0){
            prime=0;
            break;
        }
    }
    if(prime==1){
        printf("%d\n",i);
    }
    
}
    return 0;
}