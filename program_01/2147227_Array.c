/*
 *  ----> Non Dynamic memory <-----
 *  Rajesh S - MCA-B
 *  2147227 
 *  Question 01:  Implement Stack using Array 
 *  Question 02:  Implement Stack using Linked List
 * 
 */


/*
*   Header files
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 3


// defining structure
struct stack{
    
    float val1;
    float val2;

};


// alias name as node for struct
typedef struct stack node;


/**
 * Function prototype
 */

    // push new ele to the stack
    void push(node arr[], int *top);
    int is_overflow(int top);
    int is_empty(int top);
    void pop(node arr[], int *top);
    void dis_stack(node arr[], int *top);
    //


/*
 *  main program 
 */

int main(){

    // var declaration
    int top = -1;
    int option = -1;
    node arr[MAX];
    int cont = 1;

    //*top = -1;

    // get options from user

    while(cont){
        
        printf("\nEnter \n1. For push\n2. For pop\n3. For display of stack\n");
        scanf("%d", &option);

        switch(option){

            case 1:
                push(arr, &top);
                break;
            case 2:
                pop(arr, &top);
                break;
            case 3:
                //printf("\nSelected display stack top val is-> %d", top);
                dis_stack(arr, &top);
                break;
            default:
                printf("\nInvalid option\tTry again :(");
        }

        printf("\nEnter \n0 to exit \n1. to continue\n");
        scanf("%d", &cont);
    }

    printf("\nThank you :)\n\n");
    return 0;
}

/**
 * push funtion: Push to the stack 
 */
void push(node arr[], int *top){

   // int tmp = 0;
    float val_one = 0;
    float val_two = 0;

    *top = (*top) + 1;

    if(is_overflow(*top)){

        printf("\nEnter val one data\t");
        scanf("%f", &val_one);
        printf("\nEnter val two data\t");
        scanf("%f", &val_two);

        arr[*top].val1 = val_one;
        arr[*top].val2 = val_two;
    }
    else{
        *top = (*top) - 1;
        printf("\ncan't insert values because");
        printf("\nStack overflow :(\n");
    }
    
}

/**
 *  pop: delete the top of the stack if the top is not empty
 */
void pop(node arr[], int *top){
    
    *top= (*top) -1 ;

    //printf("\ninside pop function --> %d", *top);
    if(is_empty(*top)){
        printf("\npop operation is successful\n");
    }
    else{
        *top= (*top) +1 ;
        printf("\npop operation is unsuccessful as\nStack is empty\n");
    }
}

/**
 * is_overflow: check the overflow of the stack
 * return 0 if stack overflows else return 1
 */
   int is_overflow(int top){
       return MAX == top? 0: 1;
   }

/**
 * is_empty: check if the stack is empty or not
 * return 0 if stack is empty
 */

    int is_empty(int top){
        return -1 > top? 0: 1;
    }

/**
 * 
 */
    void dis_stack(node arr[], int *top){

        int tmp = *top;
        int i = 0;

        printf("\nThe Stack contents are\n");
        printf("\n------------------------------------------------------------------\n");

        if(-1 == *top){
            
            printf("-\t  The Stack is Empty :(, push something in stack \t-");
            printf("\n------------------------------------------------------------------\n");
            return;
        }

           for(i = *top; i>=0; i-=1){
            printf("\n-------  stack[%d] = val1: %f, val2: %f  --------\n", i, arr[i].val1, arr[i].val2);
        }

        printf("\n------------------------------------------------------------------\n");
    }

