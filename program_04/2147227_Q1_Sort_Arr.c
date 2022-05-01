#include <stdio.h>
#include <stdlib.h>

#define max 20

/**
 * Function prototype
 */

 void createArr(int arr[], int n);
 void displayArr(int arr[], int n);
 void selectionSort(int arr[], int n);
 void quickSort(int arr[], int start, int last,int n);
int partition(int array[], int low, int high);

void swap(int *a, int *b);


/**
 * 
 * Main program
 */
int main(){

    int option = 0;
    int n=0;
    int arr[max];

    printf("\nEnter the n value for the Array:\t");
    scanf("%d", &n);

    createArr(arr, n);

    printf("\n\n-----------------------------------------------------------------------\n");
    printf("\nSelect the option:\n1. For Selection sort\n2. For Quick sort\n3. For Display of the Array\n");
    printf("\n\n------------------------------------------------------------------------\n");
    scanf("%d", &option);


    switch(option){
        case 1:
            selectionSort(arr, n);
            break;
        case 2:
            quickSort(arr, 0, n-1, n);
            break;
        case 3:
            displayArr(arr, n);
            break;
        default:
            printf("\nInvalid option selected !");
            break;
    }

    return 0;
}

void createArr(int arr[], int n){

    int i=0;
    printf("\nCreating the Array.....");

    for(i = 0; i<n; i+=1){

        printf("\nEnter the Arr[%d]th element:\t", i);
        scanf("%d", &arr[i]);
    }

    printf("\nThe created Array is\n");
    displayArr(arr, n);
}

void displayArr(int arr[], int n){
    
    int i=0;
    
    printf("\n\n********************************************************************\n");
    for(i=0; i<n; i+=1){
        printf("\nThe Arr[%d]:\t%d", i, arr[i]);
    }
    printf("\n***********************************************************************\n");
    printf("\n");
}

void selectionSort(int arr[], int n){
    
    int i=0, j=0;
    int key_val= arr[0];
    int key = 0;
    int tmp = 0;
    
    
    for ( i = 0; i < n-1; i+=1)
    {
        key = i;
        key_val = arr[i];

        for ( j = i+1; j < n; j+=1)
        {
            if(key_val > arr[j]){
                key_val = arr[j];
                key = j;
            }
        }

        tmp = arr[i];
        arr[i] = key_val;
        arr[key] = tmp;
        
    }
    
    displayArr(arr, n);

    
}


 int partition(int array[], int low, int high) {
  

  int pivot = array[high];
  

  int i = (low - 1);


  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        

      i++;

      swap(&array[i], &array[j]);
    }
  }

swap(&array[i + 1], &array[high]);

  return (i + 1);
}


void quickSort(int array[], int low, int high, int n) {
 
 
  if (low < high) {

    int par = partition(array, low, high);
    
    quickSort(array, low, par - 1, n);
    quickSort(array, par+1, high, n);
  }
   displayArr(array, n);

}


void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

