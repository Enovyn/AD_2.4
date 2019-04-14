#include <iostream>
#include <stdio.h>

void Merge (int a[], int f, int l, int m) {
int i, n = l - f + 1;
int a1f = f, a1l = m-1;
int a2f = m, a2l = l;
int *anew = new int[n];

for(i = 0; i < n; i++){

    if(a1f <= a1l){

        if(a2f <= a2l){

            if(a[a1f] <= a[a2f])

                anew[i]=a[a1f++];

            else anew[i]=a[a2f++];}

        else anew[i]=a[a1f++];}

     else anew[i]=a[a2f++];}

for(i = 0; i < n; i++){
    a[f + i]=anew[i];
}

delete[] anew;
}


void MergeSort(int a[], int f, int l){
    if(f < l){
        int m = (f + l + l)/2;

        MergeSort(a,f,m-1);
        MergeSort(a,m,l);
        Merge(a,f,l,m);
    }
}


void CheckSum(int a[], int sum, int n){
MergeSort(a, 0, n-1);

for(int i = 0; i < n; i++){
    printf("%d ", a[i]);
}

int i = 0, j = n-1;
while(i<j){
        int current = a[i]+a[j];
    if(current==sum){
        printf("\ntrue");
        return;
    }else if(current<sum){
        i++;
    }else if(current>sum){
        j--;
    }
}
printf("\nfalse");
}


int main(){

int nmbrs[] = {4, 8, 2, 15, 9, 10, 7, 1};
int n = sizeof(nmbrs)/sizeof(*nmbrs);

CheckSum(nmbrs, 8, n);

return 0;
}
