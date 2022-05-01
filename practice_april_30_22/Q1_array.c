/**
 * @file Q1_array.c
 * @author Rajesh S
 * @brief Generate a Structure of Age, gender and area code 'Using ARRAY'
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

    int age;
    char gender[gen_len];
    int area_code;
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

        printf("\nEnter your Age:\t");
        scanf("%d", &arr[i].age);

        // To remove newline from input stream, 
        while(getchar()!= '\n');

        printf("\nEnter your Gender\t");
        fgets(arr[i].gender, gen_len, stdin);

        // to remove new line in the gen
        while(arr[i].gender[j] != '\n'){
            j+=1;
        }
        arr[i].gender[j] = '\0';
        // reset to 0, so for nxt iteration it'll from 00
        j=0;

        printf("\nEnter your Area code:\t");
        scanf("%d", &arr[i].area_code);
    }

    dis_arr(arr, arr_size);
    return arr_size;
}

/**
 *  Display the contents in a tabular column 
 * 
 */

void dis_arr(std *arr, int arr_size){

    char *prt_det[] = {"Age", "Gender", "Area Code"};
    char *und[] = {"______", "_______", "_________"};
    int i=0;

    if(arr_size == 0){
        printf("\nThe Array is Empty, enter something and try again\n");
        return;
    }

   // printf("\n_______________________________________________________\n");
      
    printf("\n\t%*s___%*s___%*s\n", -0, und[0], -0, und[1], 0, und[2]);
    printf("\n\t%*s | %*s | %*s\n", -3, prt_det[0], -MAX, prt_det[1], MAX, prt_det[2]);
    printf("\t%*s___%*s___%*s\n", -0, und[0], -0, und[1], 0, und[2]);
    //printf("\t__________________________________\n\n");

    for(i=0; i<arr_size; i+=1){
        //printf("\t%*s___%*s___%*s\n", -0, und[0], -0, und[1], 0, und[2]);
        printf("\n\t%*d | %*s | %*d\n", -3, arr[i].age, -MAX, arr[i].gender, MAX, arr[i].area_code);
        //printf("\t%*s___%*s___%*s\n", -0, und[0], -0, und[1], 0, und[2]);
    }
    
   // printf("\n_______________________________________________________\n");
}
