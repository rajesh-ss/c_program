/*
 *  ----> Non Dynamic memory <-----
 *  Rajesh S - MCA-B
 *  2147227 
 * Question 01:  Implement Queue using Linked List with ADTs [Use section 4.3 of textbook for reference]
 * Question 02:  Generate a function to delete all nodes with values having multiples of 10 without changing the order of the
 * remaining elements in the queue.
 * 
 */


/*
*   Header files
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 3


// defining structure
struct queue{
    
    float val1;
    float val2;
    struct queue *next;
};


// alias name as node for struct
typedef struct queue node;


/**
 * Function prototype
 */

    // enqueue new ele to the queue
    node *enqueue(node *rear, int *count, node *front);
    int is_overflow(int top);
    node *dequeue(node *rear, int *top, node *front);
    void dis_queue(node *rear, int *top, node *front);
    //


/*
 *  main program 
 */

int main(){

    // var declaration
    int count = 0;
    int option = -1;
    node *rear = NULL;
    node *front = NULL;
    int cont = 1;


    //*top = -1;

    // get options from user

    while(cont){
        
        printf("\nEnter \n1. For enqueue\n2. For dequeue\n3. For display of queue\n4. Number of elements\n");
        scanf("%d", &option);

        switch(option){

            case 1:

                if(count == 0){
                    rear = enqueue(rear, &count, front);
                    front = rear;
                }
                else{
                    rear = enqueue(rear, &count, front);
                }
                break;
            case 2:
                front = dequeue(rear, &count, front);
                break;
            case 3:
                //printf("\nSelected display queue top val is-> %d", top);
                dis_queue(rear, &count, front);
                break;
            case 4: 
                printf("\nThe Count is:\t%d", count);
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
 * enqueue funtion: enqueue to the queue 
 */
node *enqueue(node *rear, int *count, node *front){

    node * new_node = (node *) malloc(sizeof(node));

    // if memory is not allocated from the heap
    if(NULL == new_node){
        printf("\nSomething went wrong! :(\nTry again\n");
    }
    else if(!is_overflow(*count)){
        printf("\nQueue Overflow! :(\nCan't enter further more\n");
        return rear;
    }
    else{
    printf("\nEnter first Value:\t");
    scanf("%f", &new_node->val1);
    printf("\nEnter second value:\t");
    scanf("%f", &new_node->val2);

    // for the first node
    if(NULL == rear || NULL == front){

        new_node->next = NULL;
        rear = new_node;
        front = new_node;

    }

    // for the other nodes
    else{

        rear->next = new_node;
        rear = new_node;
        //rear->next = NULL;
    }
    }
    printf("\nEnqueue successful\n");
    *count+=1;
    return rear;
}

/**
 *  dequeue: delete the 1st of the queue
 */
node *dequeue(node *rear, int *count, node *front){
    
    node *ptr;  

    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return front;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  

    *count-=1;
    return front;
}

/**
 * is_overflow: check the overflow of the queue
 * return 0 if queue overflows else return 1
 */
   int is_overflow(int count){
       return MAX == count? 0: 1;
   }


/**
 *  Display the contents of the queue
 */
    void dis_queue(node *rear, int *count, node *front){

        int tmp = *count;
        int i = 1;
        node *que_tmp = front;


        printf("\nThe queue contents are\n");
        printf("\n------------------------------------------------------------------\n");

        if(NULL == rear || NULL == front){
            
            printf("-\t  The queue is Empty :(, enqueue something to queue \t-");
            printf("\n------------------------------------------------------------------\n");
            return;
        }

            while(que_tmp != NULL){
                printf("\n\tqueue-%d:  val1: %f, val2: %f\n\t", i, que_tmp->val1, que_tmp->val2);
                que_tmp = que_tmp->next;
                i+=1;
            }

        

        printf("\n------------------------------------------------------------------\n");
    }