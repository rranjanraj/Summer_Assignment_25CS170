#include<stdio.h>
int main(){
    int a[100],n,i,d,j,temp;
    printf("Enter the size of an array:");
    scanf("%d",&n);

    printf("Enter the element in array:");
    for( i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
prinf("Enter the number of position to rotate right :");
scanf("%d",&d);

for(i=0;i<d;i++){
    temp=a[n-1];
    for (j=n-1;j>0;j--){
        a[j]=a[j-1];
    }
    a[0]=temp;
}

printf("The rotated array is.");
    for( i=0;i<n;i++){
        scanf("%d",a[i]);
    }
    return 0;
}    