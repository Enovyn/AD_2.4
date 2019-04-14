#include <iostream>
#include <stdio.h>

//f -> first element, l -> last element, m -> middle element
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


//regular recursive MergeSort
void MergeSort(int a[], int f, int l){
    if(f < l){
        int m = (f + l + l)/2;

        MergeSort(a,f,m-1);
        MergeSort(a,m,l);
        Merge(a,f,l,m);
    }
}


//iterative MergeSort
void MergeSortIterative(int a[], int n){
    int curr_size;  // For current size of subarrays to be merged, varies from 1 to n/2 -> 1, 2, 4, 8, 16, ...
    int left_start; // For picking starting index of left subarray to be merged

   // First merge subarrays of size 1 to create sorted subarrays of size 2, then merge subarrays
   // of size 2 to create sorted subarrays of size 4, ...
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
   {
       // Pick starting point of different subarrays of current size
       for (left_start = 0; left_start < n - 1; left_start = left_start + curr_size * 2)
       {
           //find last index of array
           int right_end = left_start + (curr_size * 2) - 1;
           
           //find middle index of array
           int m = (left_start + right_end + 1)/2;
            
           
           //adjusts index of the last array since it might be not filled completely
           if(right_end >= n){
            right_end = n-1;
           }


           // Merge subarrays with regular merge function
            Merge(a, left_start, right_end, m);
       }
   }
}


void CheckSum(int a[], int sum, int n){
MergeSort(a, 0, n-1);

for(int i = 0; i < n; i++){
    printf("%d ", a[i]);
}

int i = 0, j = n-1;
while(i < j){
        int current = a[i] + a[j];
    if(current==sum){
        printf("\ntrue");
        return;
    }else if(current < sum){
        i++;
    }else if(current > sum){
        j--;
    }
}
printf("\nfalse");
}


int main(){
int nmbrs[] = {23, 5, 15, 7, 91, 14, 21, 2, 1, 9, 13, 5, 3, 81, 17};
int n = sizeof(nmbrs)/sizeof(*nmbrs);

CheckSum(nmbrs, 8, n);

return 0;
}
