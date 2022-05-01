/**
 * @file q2_arr.c
 * @author Rajesh S
 * @brief Generate a Structure of index, data 'Using ARRAY'
 * @version 0.1
 * @date 2022-04-30
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
 * header Files
 */

#include <stdio.h>
#include <stdlib.h>

#define max_ele 50
#define gen_len 8


#ifndef MAX
#define MAX 10
#endif

/**
 * Structure
 */

struct std_info
{

    int index;
    char data;
};
typedef struct std_info std;

/**
 * Fucntion Delcaration
 *
 */

int get_arr_usr(std arr[]);
void dis_arr(std *arr, int arr_size);

/**
 * main function
 *
 */

int main()
{

    // n- totoal number of elements
    // arr - array
    int n = 0;
    std arr[max_ele];
    int opt = 0;

    printf("\n\n------------------------------------------------------------------------\n");
    printf("\nSelect the option");
    printf("\n____________________\n");
    printf("\n0. To exit");
    printf("\n1. Enter values manually");
    printf("\n2. Display the contents");
    printf("\n\n------------------------------------------------------------------------\n");

    scanf("%d", &opt);

    switch (opt)
    {

    case 0:
        printf("\nExiting ...");
        break;

    case 1:
        n = get_arr_usr(arr);
        break;
    case 2:
        dis_arr(arr, n);
        break;

    default:
        printf("\nInvalid option!!");
        break;
    }

    printf("\n\n********************************************************************\n\n");

    return 0;
}

/**
 *  get input from user
 * 
 */
int get_arr_usr(std arr[])
{

    int i, arr_size, j=0;

    printf("\n\nEnter the size of the Array Size:\t");
    scanf("%d", &arr_size);

    for (i = 0; i < arr_size; i += 1)
    {

        printf("\nArray[%d]:", (i + 1));
        printf("\n_________________\n");

        printf("\nEnter your index:\t");
        scanf("%d", &arr[i].index);

        // To remove newline from input stream, 
        while(getchar()!= '\n');
        printf("\nEnter your data:\t");
        scanf("%c", &arr[i].data);
    }

    dis_arr(arr, arr_size);
    return arr_size;
}

/**
 *  Display the contents in a tabular column 
 * 
 */

void dis_arr(std *arr, int arr_size){

    char *prt_det[] = {"INDEX", "DATA"};
    char *und[] = {"______", "_______"};
    int i=0;

    if(arr_size == 0){
        printf("\nThe Array is Empty, enter something and try again\n");
        return;
    }

   // printf("\n_______________________________________________________\n");
      
    printf("\n\t%*s___%*s\n", -0, und[0], -0, und[1]);
    printf("\n\t%*s | %*s\n", -3, prt_det[0], -MAX, prt_det[1]);
    printf("\t%*s___%*s\n", -0, und[0], -0, und[1]);
    //printf("\t__________________________________\n\n");

    for(i=0; i<arr_size; i+=1){

        printf("\n\t%*d | %*c \n", -5, arr[i].index, -MAX, arr[i].data);
    }
    
   // printf("\n_______________________________________________________\n");
}
