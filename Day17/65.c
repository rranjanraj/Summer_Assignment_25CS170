#include<stdio.h>
int main(){
    int n1,n2,i;

    printf("Enter the size of n1 array:");
    scanf("%d",&n1);

 int a1[n1];
    printf("Enter the element in array:");
    for( i=0;i<n1;i++){
        scanf("%d",&a1[i]);
    }
    printf("Enter the size of n2 array:");
    scanf("%d",&n2);

 int a2[n2];
    printf("Enter the element in array:");
    for( i=0;i<n2;i++){
        scanf("%d",&a2[i]);
    }
    int mergedarray[n1+n2];
    for(i=0;i<n1;i++){
        mergedarray[i]=a1[i];
    }
    
    for(i=0;i<n2;i++){
        mergedarray[n1+i]=a2[i];
    }
    printf("Merged array:");
    for(i=0;i<n1+n2;i++){
        printf("%d",mergedarray[i]);
    }
    return 0;
}
