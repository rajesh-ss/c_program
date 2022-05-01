/**
 *  Name   : Rajesh S
 *  RollNo : 2147227
 *  Question 01: Implement and compare searching algorithms (linear, binary, Hashing)
 */

#include <stdio.h>
#include <stdlib.h>

#define max 100

struct nd
{
    int data;
    struct nd *nxt;
};

typedef struct nd node;

/**************************************************
******          Function Prototype            *****       
***************************************************/

int getInpUsr(int arr[]);
int ranEle(int arr[]);
void dis(int arr[], int n);
int lin_ser(int arr[], int n, int ele_ser);
void ad_li_ser(int arr[], int n, int ele_ser);
void pus_li(node **head, int ind, int ele);
void dis_lk(node **head);
void selectionSort(int arr[], int n);
int binSrc(int arr[], int start, int end, int key, int count);
void hashser(int arr[], int n);

/***************************************************
 ********        Main Program                *******
****************************************************/

int main()
{

    int n = 0, arr[max];
    int i, toser = 0;
    int opt = 0;
    int ind = -1;
    //int key;
    //int cont = 1;

    //printf("\nEnter the element to search:\t");
    //scanf("%d", &toser);

    while (opt != 8)
    {

        printf("\n\n\nEnter the option that you want to perform\n1. Enter elements manually\n2. To generate random numbers between 1 to 100\n");
        printf("3. Normal linear search\n4. Advanced linear search\n5. Binary search\n6. To display the array\n7. Hashing \n8. To exit\n");
        scanf("%d", &opt);

        switch (opt)
        {

        case 1:
            // get ele of array from usr
            n = getInpUsr(arr);
            break;
        case 2:
            // get random num from 0 to 100 as ele of array
            n = ranEle(arr);
            break;
        case 3:

            printf("\nEnter the element that you want to search\n");
            scanf("%d", &toser);

            ind = lin_ser(arr, n, toser);

            if (-1 == ind)
            {
                printf("\nThe element doesn't exist in the array :(\n");
            }
            else
                printf("\nFound at arr[%d]: %d", ind, arr[ind]);

            break;

        case 4:
            printf("\nselected advanced linear search\n");
            printf("\nEnter the element that you want to search\n");
            scanf("%d", &toser);
            ad_li_ser(arr, n, toser);
            break;

        case 5:
            printf("\nselected binary search\n");

            if (n == 0)
            {
                printf("\nEmpty Array fill and then try again");
                break;
            }
            printf("\nEnter the element that you want to search\n");
            scanf("%d", &toser);

            // sort the array before doing binary searching
            // here selection sort is done
            selectionSort(arr, n);
            binSrc(arr, 0, n, toser, 0);
            break;
        case 6:
            dis(arr, n);
            break;
        case 7:
            hashser(arr, n);
            break;
        case 8:
            printf("\nExiting ......\n\n");
            break;
        default:
            printf("\nInvalid option selected, try again :-( \n");
        }
        //lin_ser(arr, n, toser);
    }
}

/*
 *  ranEle :
 *  ````````
 *        -->  get the size of array val from usr and return 
 *        -->  get random num from 0 to 100 as ele of array
 */

int ranEle(int arr[])
{

    //int rand = rand() % 100 + 1;
    int i, n;

    printf("\nEnter the n value:\t");
    scanf("%d", &n);

    //printf("\nEnter the array elements:\n");

    for (i = 0; i < n; i += 1)
    {

        arr[i] = rand() % 100 + 1;
    }

    dis(arr, n);
    return n;
}

/*
 *  getInpUsr:
 *  ``````````
 *         -->  get the size of array val from usr and return 
 *         -->  get each ele of array input from user
 */

int getInpUsr(int arr[])
{

    int i, n;

    printf("\nEnter the n value:\t");
    scanf("%d", &n);

    printf("\nEnter the array elements:\n");

    for (i = 0; i < n; i += 1)
    {
        printf("\nEnter the value of arr[%d]:\t", i);
        scanf("%d", &arr[i]);
    }
    return n;
}

/*****************************************************
 * dis(): Display the contents of the array 
 *****************************************************/

void dis(int arr[], int n)
{

    int i = 0;

    // condition for empty array check
    if (n == 0)
    {
        printf("\nThe array is empty\nNothing to display..... :-( \n");
        return;
    }

    printf("\n-------------------------------------------");
    for (i = 0; i < n; i += 1)
    {
        printf("\narr[%d] = %d", i, arr[i]);
    }
    printf("\n-------------------------------------------");
}

/************************************************
 * lin_ser(): 
 *          search for the element 
 *          linearly through array till end
 *************************************************/

int lin_ser(int arr[], int n, int ele_ser)
{

    int i = 0;
    int count = 0;

    // condition for empty array check
    if (n == 0)
    {
        printf("\nEmpty array enter something and try again\n");
        return -1;
    }

    for (i = 0; i < n; i += 1)
    {

        if (arr[i] == ele_ser)
        {
            printf("\nThe number of iteration for linear search is: %d\n", count);
            return i;
        }
        count += 1;
    }

    return -1;
}

/************************************************
 * ad_lin_ser (): 
 *      Linear search the elements in array
 *      And push the match ele to linked list
 *      diplay the indexes in which the ele are there.
 *************************************************/

void ad_li_ser(int arr[], int n, int ele_ser)
{

    int i = 0;
    node *head = NULL;

    for (i = 0; i < n; i += 1)
    {

        if (arr[i] == ele_ser)
        {
            pus_li(&head, i, ele_ser);
        }
    }
    dis_lk(&head);
}

/*******************************************************
 * pus_li:
 * ```````
 *        push the indexes of the searched 
 *        element to the linked list 
 *******************************************************/

void pus_li(node **head, int ind, int ele)
{

    node *new_node = NULL;
    node *temp = *head;
    new_node = malloc(sizeof(node));

    if (*head == NULL)
    {
        new_node->data;
        new_node->nxt = NULL;
        *head = new_node;
        //dis_lk(head);
        return;
    }

    // iterate to last node

    while (temp->nxt != NULL)
    {

        temp = temp->nxt;
    }

    new_node->data = ind;
    new_node->nxt = NULL;
    temp->nxt = new_node;
}

/*******************************************************
 * dis_lk:
 * ```````
 *      --> Display the liked list that contains the indexes
 *******************************************************/

void dis_lk(node **head)
{

    node *temp = *head;
    int count = 1;

    if (*head == NULL)
    {
        printf("\nNo elements are there");
        return;
    }

    printf("\nThe elements with the indexes are\n");

    while (temp != NULL)
    {

        printf("\n%d: %d", count, temp->data);
        temp = temp->nxt;
        count += 1;
    }

    printf("\n\n");
}

/**
 * selection sort: 
 *               
 */

void selectionSort(int arr[], int n)
{

    int i = 0, j = 0;
    int key_val = arr[0];
    int key = 0;
    int tmp = 0;

    for (i = 0; i < n - 1; i += 1)
    {
        key = i;
        key_val = arr[i];

        for (j = i + 1; j < n; j += 1)
        {
            if (key_val > arr[j])
            {
                key_val = arr[j];
                key = j;
            }
        }

        tmp = arr[i];
        arr[i] = key_val;
        arr[key] = tmp;
    }

    //displayArr(arr, n);
}

/*****************************************************
 ************** Binary searching fun *****************
 *****************************************************/

int binSrc(int arr[], int start, int last, int key, int count)
{

    if (start <= last)
    {

        int mid = start + (last - start) / 2;
        printf("\nstart -> %d\tlast -> %d\tmid -> %d", start, last, mid);

        if (arr[mid] == key)
        {
            printf("\nFound the element at arr[%d] = %d", mid, key);
            printf("\nThe number of iterations are:\t%d", count);
            return arr[mid];
        }

        else if (arr[mid] > key)
        {
            return binSrc(arr, start, mid - 1, key, count + 1);
        }

        else
        {
            return binSrc(arr, mid + 1, last, key, count + 1);
        }
    }
    return -1;
}

/*********************************************************
 Hash search function:
            1. By modules store the array ele val
            2. If repeated then move to nxt pos
            3. search the ele using the mod in new_arr
            4. If not eq then mov to nxt pos 
 *********************************************************/

void hashser(int arr[], int n)
{

    int i = 0, flag = 0;
    int inter = 0;
    int j = 0, mod;
    int new_arr[max];
    int ser_ele = -1;

    // val if the length is empty
    if (n == 0)
    {
        printf("\nThe array is empty enter something and try again\n");
        return;
    }

    // giving default values of -1 to all ele of arr
    for (i = 0; i < n; i += 1)
    {
        new_arr[i] = -1;
    }

    printf("\nHashing into the new array");
    printf("\n_________________________________________________________\n\n");
    // 1st iteration for the iterating arr
    for (i = 0; i < n; i += 1)
    {

        mod = arr[i] % n;
        inter = mod;

        //printf();
        if (new_arr[mod] == -1)
        {

            printf("\nIth value is: %d\nThe value of mod val:%d\tnew_arr[%d]: %d\n", i, mod, mod, arr[i]);
            new_arr[mod] = arr[i];
            //continue;
        }

        else
        {

            // 2nd iteration for the mod jump
            for (j = inter + 1; j < n; j += 1)
            {

                if (new_arr[j] == -1)
                {

                    printf("\nIth value is: %d\nThe value of j val:%d\tnew_arr[%d]: %d\n", i, j, j, arr[i]);
                    new_arr[j] = arr[i];
                    break;
                }

                // if greater than 'n' start from start
                if (j == n - 1)
                {
                    inter = -1;
                }
            }
        }
    }

    printf("\n_________________________________________________________\n\n");

    // serach operation happens here
    printf("\nEnter the element that you want to search:\t");
    scanf("%d", &ser_ele);

    mod = ser_ele % n;
    inter = mod;

    if (new_arr[mod] == ser_ele)
    {

        printf("The element exist in array at new_arr[%d]: %d\n", mod, new_arr[mod]);
    }

    else
    {

        for (i = inter + 1; i < n; i += 1)
        {

            if (new_arr[i] == ser_ele)
            {

                printf("The element exist in array at new_arr[%d]: %d\n", i, new_arr[i]);
                break;
            }

            // if greater than 'n' start from start
            else if (arr[i] == n - 1)
            {
                inter = -1;
            }
        }
    }
}