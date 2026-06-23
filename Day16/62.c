
#include<stdio.h>
int main(){
    int n,i;
    printf("Enter the size of an array:");
    scanf("%d",&n);
 int a[n];
    printf("Enter the element in array:");
    for( i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int maxfreq=0;
    int maxfreqelement=a[0];
    for(i=0;i<n;i++){
        int freq=0;
        for(int j=0;j<n;j++){
            if(a[i]==a[j]){
                freq++;
            }
        }
        if(freq>maxfreq){
            maxfreq=freq;
            maxfreqelement=a[i];
        }
    }
    printf("The element with maximumfrequency is: %d\n",maxfreqelement);
    printf("Its frequency is :%d\n",maxfreq);
    return 0;
}
