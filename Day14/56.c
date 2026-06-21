#include<stdio.h>
int main(){
    int a[100],n,i,j,count;
    printf("Enter the size of an array");
    scanf("%d",&n);

    printf("Enter the element in array:");
    for( i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("Duplicate element in the array are :");
    for(i=0;i<n;i++){
        count=1;
        for(j=i+1;j<n;j++){
            if(a[i]==a[j]){
                count++;
                a[j]=-1;
            }
        }
        if (count>1 && a[i]!=-1){
            printf("%d",a[i]);
        }
    }
    return 0;
}   