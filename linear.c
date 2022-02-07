#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n){
    int i, j, min_idx;
    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

int main(){
    int n;
    printf("Enter the number of elements of the array: ");
    scanf("%i", &n);
    int arr[n], barr[n];
    for (int i = 0; i < n; i++){
        printf("Enter the element %i: ",i+1);
        scanf("%i", &arr[i]);
    }
    for (int i = 0; i < n; i++){
        barr[i] = arr[i];
    }
    selectionSort(barr, n);
    int key;
    int ch;
    while(1){
        int q = 0;
        int first = 0, last = n-1;
        int middle;
        printf("1.LINEAR SEARCH 2.BINARY SEARCH 3.EXIT\n");
        scanf("%i", &ch);
        switch(ch){
            case 1:
                printf("Enter an element to be searched: ");
                scanf("%i", &key);
                for (int x = 0; x < n; x++){
                    if (arr[x] == key){
                        printf("%i found at index %i.\n",key,x);
                        q = 1;
                        break;
                    }
                }
                if (q == 0){
                    printf("%i not found in array.\n",key);
                }
                break;
            case 2:
           
                printf("Enter an element to be searched: ");
                scanf("%i", &key);
                printf("The sorted array is:\n");
                for(int i=0;i<n;i++)
                printf("%i\t",barr[i]);
                printf("\n");
                while (first <= last){
                    middle = (first+last)/2;
                    if (key == barr[middle]){
                        printf("%i found at index %i.\n",key,middle);
                        break;
                    }
                    else if(key < barr[middle]){
                        last = middle - 1;
                    }
                    else{
                        first = middle+1;
                    }
                }
                if (first > last){
                    printf("%i not found in array.\n",key);
                }
                break;
            case 3:
                exit(0);
        }
    }
}