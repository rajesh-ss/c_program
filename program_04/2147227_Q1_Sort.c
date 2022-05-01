/**
 * ------------------------------------------------------------------------
 * - Name:        Rajesh S
 * - Class:       3MCA B
 * - Roll no:     2147227
 * - LAB:         4
 * - QN:          Sorting (Insertion, selection and quick sort)
 * -------------------------------------------------------------------------
 * 
 * Question 01: Write a program that sorts a list of random numbers, 
 * using the selection sort/ insertion sort,  and quick sort.
 * 
 * Question 02: 
 *      Complex: Generate N students record as structure input and 
 *      sort the record based on marks and then price in ascending order. 
 *      Display the result in a neat tabulated format.
 * 
 */

//Header files

#include <stdio.h>
#include <stdlib.h>

// structure of student
struct student
{
    int rollno;
    char *name;
    int marks;
    struct student *next;
};

typedef struct student node;

/**************************************************
 *****          Function Prototype             ****       
***************************************************/

void insert_last(node **head);
void search(node **head);
void dis(node *head);
int count_nodes(node **head);
void swapTwoNodes(node *tmp_one, node *tmp_Two, node **head);
void selection_Sort(node **head);

/***************************************************
 ********        Main Program                *******
 ***************************************************/

int main()
{

    // var declaration
    int option = -1;
    node *head = NULL;
    int cont = 1;

    // get options from user
    // continue the loop until the user enters 0 as the input
    while (cont)
    {
        printf("\n-----------------------------------------------------------------------------\n");
        printf("Enter: \n\t1. Insert\n\t2. Display\n\t3. count the number of nodes created\n\t5. Search fo element");
        printf("\n-----------------------------------------------------------------------------\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            insert_last(&head);
            break;
        case 2:
            dis(head);
            break;
        case 3:
            printf("\nThe number of nodes created are: %d\n", count_nodes(&head));
            break;
        case 4:
            search(&head);
            break;
        case 5:
            selection_Sort(&head);
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

/***************************************************
 **** insert a node at last in the linked list ****
****************************************************/

void insert_last(node **head)
{
    // temp pointer for traversal
    node *tmp = *head;
    //char *name = NULL;
    size_t inp_name_val = 0;
    size_t max_name = 32;

    //allocating space from heap
    node *new_node = (node *)malloc(sizeof(node));

    new_node->name = NULL;

    // if it's null then return
    if (NULL == new_node)
    {
        printf("\nSomething went wrong! :(");
        return;
    }
    else
    {

        // getting input from user and assigning to the new node
        printf("\nEnter the Roll NO of the Student:\t");
        scanf("%d", &new_node->rollno);

        printf("\nEnter the marks of the Student:\t");
        scanf("%d", &new_node->marks);

        while (getchar() != '\n')
            ;

        // --> Note: May prompt Error <--
        printf("\nEnter your name:\t");
        /* scanf("\n%s", name); */

        inp_name_val = getline(&new_node->name, &max_name, stdin);
        //printf("\n\nInside insert last(): Before:val ");
        // validation of the array of string input
        if (inp_name_val == -1)
        {
            printf("\n ooPs... Something went wrong!! :(\nTry Again");
            return;
        }
        /*         else{
            printf("\n(*Val*)The Entered name is: %s", name);
        } */

        // since it's last node next will be null
        new_node->next = NULL;

        if (NULL == *head)
        {
            // for the 1st node
            *head = new_node;
        }
        else
        {
            // traverse to last node
            while (NULL != tmp->next)
            {
                tmp = tmp->next;
            }
            tmp->next = new_node;
            new_node->next = NULL;
        }
    }
}

/**
 *  Search for a element in linked list 
 */

void search(node **head)
{

    int ele_ser = 0;
    int pos = 1;
    node *tmp = *head;

    if (tmp == NULL)
    {
        printf("\nNo Student data is entered\n");
    }
    else
    {
        printf("\nEnter the Roll no that you want to search:\t");
        scanf("%d", &ele_ser);

        while (NULL != tmp)
        {
            if (tmp->rollno == ele_ser)
            {
                printf("\n-----------------------------------------------------------------------------\n");
                printf("Element %d found in the position %d", ele_ser, pos);
                printf("\n-----------------------------------------------------------------------------\n");
                return;
            }
            else
            {
                tmp = tmp->next;
                pos += 1;
            }
        }
        printf("\nElement not found !!");
    }
}

/**
 *  Display the contents of the linked List 
 */
void dis(node *head)
{

    node *tmp = head;
    printf("\n");

    if (tmp == NULL)
    {
        printf("\nThe linked list is empty");
    }
    else
    {
        printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
        while (NULL != tmp)
        {
            printf("\nRoll No:\t%d", tmp->rollno);
            printf("\nName:\t%s", tmp->name);
            printf("Marks:\t%d", tmp->marks);
            tmp = tmp->next;
            printf("\n------------------------------------------------------------------");
        }
        printf("\n\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
    }
}

// count number of nodes created
int count_nodes(node **head)
{

    node *tmp = *head;
    int count = 0;
    //printf("\n count nodes: before while()");

    while (NULL != tmp)
    {
        //printf("\n%f", tmp->val);
        tmp = tmp->next;
        count += 1;
    }

    return count;
}

void swapTwoNodes(node *tmp_one, node *tmp_two, node **head)
{

    node *pre_one = *head;
    node *pre_two = *head;
    node *tmp_pre_one = NULL;
    node *tmp_pre_two = NULL;
    node *tmp_nxt = NULL;
    int count = 0;

    if (tmp_two == tmp_one)
    {
        printf("\nNo element to swap!\thurray");
        return;
    }
    // if the 1st element needs to be swaped with the other elements
    if (*head == tmp_one)
    {

        while (pre_two->next != NULL || pre_two->next != tmp_two)
        {
            if (pre_two->next == tmp_two)
            {
                break;
            }
            printf("\nThe pre_two 1st ele swapper is %d", pre_two->marks);
            pre_two = pre_two->next;
        }

        *head = pre_two->next;
        tmp_pre_two = tmp_two->next;
        tmp_two->next = tmp_one->next;
        tmp_one->next = tmp_pre_two;
        pre_two->next = tmp_one;

        printf("\nsuccesfully swapped !!!!");
        printf("\nDisplay of the nodes\n");
        dis(*head);
        return;
    }
    /*       else if(*head == tmp_two){
            
            while(pre_two->next != NULL){

            if(pre_two->next == tmp_two){
                break;
            }
            printf("\nThe pre_two is %d", pre_two->marks);
            pre_two = pre_two->next;
            }

         *head = pre_one->next;
         tmp_pre_one  = pre_one->next;
         pre_one->next = pre_two->next;
         pre_two->next = tmp_pre_one;
         return;

        } */
    // else{

    // Iterate through the linked list to find the prev to swap loc for 1st
    while (pre_one->next != NULL)
    {

        if (pre_one->next == tmp_one)
        {
            break;
        }
        printf("\nThe pre_one is %d", pre_one->marks);
        pre_one = pre_one->next;
    }

    // Iterate through the linked list to find the prev to swap loc for 2nd
    while (pre_two->next != NULL)
    {

        if (pre_two->next == tmp_two)
        {
            break;
        }
        printf("\nThe pre_two is %d", pre_two->marks);
        pre_two = pre_two->next;
    }

    tmp_pre_one = pre_one->next;
    //tmp_pre_two = pre_two->next;
    tmp_nxt = tmp_one->next;

    pre_one->next = pre_two->next;
    pre_two->next = tmp_pre_one;

    tmp_one->next = tmp_two->next;
    tmp_two->next = tmp_nxt;

    //  }
}

/*******_____________Selection sort()_____________***************** 
 *  
 * validations: 
 *          1. check if the linked list is empty or not
 */

void selection_Sort(node **head)
{

    node *tmphead = *head;
    node *current = NULL;
    node *key_ptr = NULL;

    int key_val = 0;

    if (tmphead != NULL)
    {
        while (NULL != tmphead)
        {

            key_val = tmphead->marks;
            key_ptr = tmphead;
            current = tmphead;

            while (current != NULL)
            {
                if (current->marks < key_ptr->marks)
                {
                    key_val = current->marks;
                    key_ptr = current;
                }
                printf("\nFinding key val:\t%d", key_ptr->marks);
                current = current->next;
            }
            printf("\nSmallest one is:\t%d", key_ptr->marks);



            swapTwoNodes(tmphead, key_ptr, head);



            printf("\nIterative check %d", tmphead->marks);
            
            
            tmphead = tmphead->next;

        }
    }
    else
    {
        printf("\nyour linked list is empty, Insert something and try again,try again :(");
    }
}