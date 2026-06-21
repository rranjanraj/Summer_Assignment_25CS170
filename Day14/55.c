#include<stdio.h>
int main(){
    int a[100],n,i,largest,secondlargest;
    printf("Enter the size of an array:");
    scanf("%d",&n);

    printf("Enter the element in array:");
    for( i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    if(n<2){
        printf("Not enough element to find the second largest \n");
    }
    largest=secondlargest=a[0];

    for(i=1;i<n;i++){
        if(a[i]>largest){
            secondlargest=largest;
            largest=a[i];

        }
        else if (a[i]>secondlargest&&a[i]!=largest){
            secondlargest=a[i];
        }
    }
    if(largest==secondlargest){
        printf("There is no second largest elemnt \n");
    }
    else{
        printf("The second largest element is:%d\n",secondlargest);
    }
    return 0;
}    