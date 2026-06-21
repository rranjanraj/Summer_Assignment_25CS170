#include<stdio.h>
int main(){
    int a[100],n,i,x,flag=0;
    printf("Enter the size of an array:");
    scanf("%d",&n);

    printf("Enter the elemnt in array:");
    for( i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("Enter the element to be searched:");
    scanf("%d",&x);

    for(i=0;i<n;i++){
        if(a[i]==x){
            flag=1;
            break;
        }

    }
    if(flag==1){
        printf("Element found at %d position",i+1);
       }
    else{
        printf("Element does'nt exist in array");
    }   
    return 0;
}
