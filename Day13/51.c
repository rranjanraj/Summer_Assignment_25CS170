#include<stdio.h>
int main(){
    int a[100],n,largest,smallest,i;
    printf("Enter the size of an array:");
    scanf("%d",&n);

     printf("Enter the element in array:\n ");
     for( i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    largest=smallest=a[0];
    for(i=1;i<n;i++){
        if(a[i]>largest){
            largest=a[i];
        }
        if(a[i]<smallest){
            smallest=a[i];
        }
        
    }
    printf("The largest element is:%d\n",largest);
    printf("The smallest element is:%d\n",smallest);
    return 0;
}