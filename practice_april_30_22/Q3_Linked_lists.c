/**
 * @file q2_ln.c
 * @author Rajesh S
 * @brief Generate a Structure of coefficent, degree 'Using LINKED LIST'
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
#include <string.h>

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

    int coefficent;
    int degree;
    struct std_info* next;
};

typedef struct std_info std;

/**
 * Fucntion Delcaration
 *
 */

void dis(std *ln);
int usr_fr_ins(std **ln);

/**
 * main function
 *
 */

int main()
{

    // n- totoal number of elements
    // arr - array
    int n = 0;
    std *ln = NULL;
    int opt = 1;

    while(opt){
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
        n = usr_fr_ins(&ln);
        break;
    case 2:
        dis(ln);
        break;

    default:
        printf("\nInvalid option!!");
        break;
    }

    
    }

    printf("\n\n********************************************************************\n\n");
    return 0;
}

/**
 *  Display the contents in a tabular column 
 * 
 */

void dis(std *ln){

    char *prt_det[] = {"coefficent", "degree"};
    char *und[] = {"______", "_______"};
    int i=0;
    std *tmp = ln;

    if(ln == NULL){
        printf("\nThe Linked List is Empty, enter something and try again\n");
        return;
    }
      
    printf("\n\t%*s___%*s___\n", -0, und[0], -0, und[1]);
    printf("\n\t%*s | %*s  \n", -3, prt_det[0], -MAX, prt_det[1]);
    printf("\t%*s___%*s___\n", -0, und[0], -0, und[1]);
    //printf("\t__________________________________\n\n");

    while(tmp != NULL){

          printf("\n\t%*d | %*c \n", -5, tmp->coefficent, -MAX, tmp->degree);
          tmp = tmp->next;

    }

}

/**
 *  get input from user and instert it in fron of linked list
 * 
 */
int usr_fr_ins(std **ln)
{

    int i = 1, j=0;
    int cnt = 1;
    std *tmp = NULL;

    while(cnt){

        	
		tmp = (std *) malloc (sizeof(std));

        if(tmp == NULL){
            printf("\nOops Something went wrong\n");
            break;
        }


        printf("\nLinked List %d:", i );
        printf("\n_________________\n");

        printf("\nEnter your coefficent:\t");
        scanf("%d", &tmp->coefficent);

        // To remove newline from input stream, 
        while(getchar()!= '\n');

        printf("\nEnter your degree\t");
        scanf("%d", &tmp->degree);

        i += 1;

        tmp->next = *ln;
        *ln = tmp;


        printf("\n\nPress 0 to exit:\t");
        scanf("%d", &cnt);
    }

    
    dis(*ln);
    return i;
}
