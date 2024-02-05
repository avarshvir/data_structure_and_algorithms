#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of arrays : ");
    scanf("%d",&n);

    int arr[n];
    
    printf("Enter the elements of arrays :");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    for(int j = 0; j < n; j++){
        printf("%d",arr[j]);
    }
}
