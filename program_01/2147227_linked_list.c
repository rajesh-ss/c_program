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
    struct stack *next;
};


// alias name as node for struct
typedef struct stack node;


/**
 * Function prototype
 */

    // push new ele to the stack
    node* push(node *st_top, int *top);
    int is_overflow(int top);
    int is_empty(int top);
    node* pop(node *st_top, int *top);
    void dis_stack(node *st_top, int *top);
    //


/*
 *  main program 
 */

int main(){

    // var declaration
    int top = -1;
    int option = -1;
    node *st_top = NULL;
    int cont = 1;


    //*top = -1;

    // get options from user

    while(cont){
        
        printf("\nEnter \n1. For push\n2. For pop\n3. For display of stack\n");
        scanf("%d", &option);

        switch(option){

            case 1:
                st_top = push(st_top, &top);
                break;
            case 2:
                st_top = pop(st_top, &top);
                break;
            case 3:
                //printf("\nSelected display stack top val is-> %d", top);
                dis_stack(st_top, &top);
                break;
            default:
                printf("\nInvalid option\tTry again :(");
        }

        //clrscr();
        printf("\nEnter \n0 to exit \n1. to continue\n");
        scanf("%d", &cont);
    }

    printf("\nThank you :)\n\n");
    return 0;
}

/**
 * push funtion: Push to the stack 
 */
node* push(node *st_top, int *top){

   // int tmp = 0;
    float val_one = 0;
    float val_two = 0;

    *top = (*top) + 1;

    node *tmp = st_top;

    st_top = (node *) malloc(sizeof(node));
    st_top->next = NULL;

    if(is_overflow(*top)){

        printf("\nEnter val one data\t");
        scanf("%f", &val_one);
        printf("\nEnter val two data\t");
        scanf("%f", &val_two);

        st_top->val1 = val_one;
        st_top->val2 = val_two;
        st_top->next = tmp;

        //printf("\nINSIDE PUSH FUNCTION:\t%f, %f", st_top->val2, st_top->val2);
        return st_top;
    }
    else{
        *top = (*top) - 1;
        st_top = tmp;
        printf("\ncan't insert values because");
        printf("\nStack overflow :(");
        return st_top;
    }
    
}

/**
 *  pop: delete the top of the stack if the top is not empty
 */
node* pop(node *st_top, int *top){
    
    *top= (*top) -1 ;
    
    //printf("\ninside pop function --> %d", *top);
    if(is_empty(*top)){
        st_top = st_top->next;
        printf("\npop operation is successful\n");
        return st_top;
    }
    else{
        *top= (*top) +1 ;
        printf("\npop operation is unsuccessful as\nStack is empty");
        return st_top;
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
    void dis_stack(node *st_top, int *top){

 /*        int tmp = *top;
        node *st_tmp = st_top;
        //printf("\nin display stack the passed ptr is: \t%f", st_top->val1);
        while(st_tmp != NULL){
                printf("\nStack:  val1-%f, val2-%f", st_tmp->val1, st_tmp->val2);
                st_tmp = st_tmp->next;
            } */



        int tmp = *top;
        int i = 0;
        node *st_tmp = st_top;


        printf("\nThe Stack contents are\n");
        printf("\n------------------------------------------------------------------\n");

        if(NULL == st_tmp){
            
            printf("-\t  The Stack is Empty :(, push something in stack \t-");
            printf("\n------------------------------------------------------------------\n");
            return;
        }

        for(i = *top; i>=0; i-=1){
            if(st_tmp != NULL){
                printf("\n\tStack-%d:  val1: %f, val2: %f\n\t", i, st_tmp->val1, st_tmp->val2);
                st_tmp = st_tmp->next;
            }

        }

        printf("\n------------------------------------------------------------------\n");
    }