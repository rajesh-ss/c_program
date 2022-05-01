/*
* 2147227 Rajesh S
*/

#include <stdio.h>
#include <stdlib.h>

#define max 50

/*
*   Function declaration(prototype)
*/
void ins_arr_val(int * arr_tmp, int n);
void dup_arr(int arr[], int n);
void shift_del(int arr[], int n);
void print_arr(int arr[], int n);
void free_mem(int *arr, int n);

/*
*   Main Function
*/

int main(){

    // var declaration
    int n = 0;
    int arr[max];
    int *arr_dy;
    int option =  0;

    printf("\n\nEnter the size of array: ");
    scanf("%d", &n);

    printf("\nSelect your option\n1. For Dynamic array\n2. For normal array\n");
    scanf("%d", &option);

    switch(option){
        case 1:
            // Dynamic array 
            arr_dy = (int*)malloc(n * sizeof(int));
            // get values arr val from user
            ins_arr_val(arr_dy, n);
            // print the array elements
            print_arr(arr_dy, n);
            //duplicate array
            dup_arr(arr_dy, n);
            shift_del(arr_dy, n);
            // print the array elements
            print_arr(arr, n);
            // free memory
            free_mem(arr, n);
            // print the array elements
            print_arr(arr, n);
            break;
        case 2:
            // get values arr val from user
            ins_arr_val(arr, n);
            // print the array elements
            print_arr(arr, n);
            //duplicate array
            dup_arr(arr, n);
            shift_del(arr, n);
            // print the array elements
            print_arr(arr, n);
            break;
            
    }
}

/*
 * inserting array values from the user
 */

void ins_arr_val(int * arr_tmp, int n){

    // local var decla
    int i = 0;

    printf("\nEnter the Array elements\n");
    for(i=0; i<n; i+=1){
        printf("\narr[%d]: ", i);
        scanf("%d", (arr_tmp+i));
    }
    printf("\n");
}

/*
*   Printing the Array Elements
*/

void print_arr(int arr[], int n){

    // local var declaration
    int i=0;


    printf("\nThe array is \n");

    for(i=0; i<n; i+=1){
        printf("\nArr[%d]: %d", i, arr[i]);
    }
    
    printf("\n");
}

/*
*   Duplicate elements replace with zero
*/

void dup_arr(int arr[], int n){

    // local var
    int i=0, j=0;


    printf("\nReplacing Duplicate elements with zero\n");

    for(i=0; i<n-1; i+=1){
        for(j=i+1; j<n; j++){

            // if duplicate exist replace by zero
            if(arr[i] == arr[j]){
                printf("Duplicate element: arr[%d]: %d and arr[%d]: %d\n", i, arr[i], j, arr[j]);
                arr[j] = 0;
            }
        }
    }
}

/*
*   Shift the zero at last
*/
void shift_del(int arr[], int n){

    // local var
    int i=0;
    int j=0;
    int tmp=0;


    printf("\nShifting the zero elements to last indexes\n");
    for(i=0; i<=n; i+=1){
        if(0 == arr[i]){
            for(j=i+1; j<=n-1 ;j+=1){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

/**
 * Free memory space 
 */
void free_mem(int *arr, int n){

       // loc var
        int i=0;
        int j=0;

        printf("\nFree the array memory space\n");
        for(i=0; i<n; i+=1){
            if(0 == *(arr+i)){
                free(arr+i);
            }
        }

}