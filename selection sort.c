//
// Created by Pratik Giri on 05-04-2025.
//
#include <stdio.h>

int main() {
    printf("Hello World!\n");
    int arr[4]={2,1,10,0} ;
    int n=sizeof (arr)/sizeof (arr[0]);
    printf("%d\n",n);
    for(int i=0;i<n;i++){
        int min=i;
        for (int j = i+1; j <n ; ++j) {
            if(arr[min]>arr[j]){
                min=j;

            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;

    }

    for (int i = 0; i <n ; ++i) {
        printf("%d\n",arr[i]);
    }


    return 0;
}