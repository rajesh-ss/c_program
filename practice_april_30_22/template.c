/**
 * @file Q1_array.c
 * @author Rajesh S
 * @brief Generate a Structure of Age, gender and area code 'Using LINKED LIST'
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

    int age;
    char gender[gen_len];
    int area_code;
    struct std_info* next;
};

typedef struct std_info std;

/**
 * Fucntion Delcaration
 *
 */

//int get_usr(std **ln);
//void pushlink(std ** ln, int age, char gender[], int area_code);
//void copy_str(char src[], char *des);
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
    int opt;

    while(opt){
    printf("\n\n------------------------------------------------------------------------\n");
    printf("\nSelect the option");
    printf("\n____________________\n");
    printf("\n1. Enter values manually");
    printf("\n2. Display the contents");
    printf("\n\n------------------------------------------------------------------------\n");

    scanf("%d", &opt);

    switch (opt)
    {

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

    //printf("\n\n********************************************************************\n\n");
    }
    return 0;
}

/**
 *  get input from user
 * 
 */

/*
int get_usr(std **ln)
{

    int i = 1, j=0;
    int cnt = 1;
    int age;
    int area_code;
    char gender[gen_len];

    while(cnt){

      
        printf("\nLinked List %d:", i );
        printf("\n_________________\n");

        printf("\nEnter your Age:\t");
        scanf("%d", &age);

        // To remove newline from input stream, 
        while(getchar()!= '\n');

        printf("\nEnter your Gender\t");
        fgets(gender, gen_len, stdin);

        // to remove new line in the gen

        while(gender[j] != '\n'){
            j+=1;
        }
        gender[j] = '\0';
        // reset to 0, so for nxt iteration it'll from 00
        j=0;
        
        printf("\nEnter your Area code:\t");
        scanf("%d", &area_code);

        pushlink(ln, age, gender, area_code);
        i += 1;


        printf("\n\nPress 0 to exit:\t");
        scanf("%d", &cnt);
    }

    
    dis(*ln);
    return i;
}

*/

/**
 *  Display the contents in a tabular column 
 * 
 */

void dis(std *ln){

    char *prt_det[] = {"Age", "Gender", "Area Code"};
    char *und[] = {"______", "_______", "_________"};
    int i=0;
    std *tmp = ln;

    if(ln == NULL){
        printf("\nThe Linked List is Empty, enter something and try again\n");
        return;
    }

   // printf("\n_______________________________________________________\n");
      
    printf("\n\t%*s___%*s___%*s\n", -0, und[0], -0, und[1], 0, und[2]);
    printf("\n\t%*s | %*s | %*s\n", -3, prt_det[0], -MAX, prt_det[1], MAX, prt_det[2]);
    printf("\t%*s___%*s___%*s\n", -0, und[0], -0, und[1], 0, und[2]);
    //printf("\t__________________________________\n\n");

    while(tmp != NULL){


          //printf("\n%s\n", tmp->gender);
          printf("\n\t%*d | %*s | %*d\n", -3, tmp->age, -MAX, tmp->gender, MAX, tmp->area_code);
          tmp = tmp->next;

    }
    
   // printf("\n_______________________________________________________\n");
}

/*
void pushlink(std ** ln, int age, char gender[], int area_code){
	
	std * tmp = *ln;
	std * nnode = NULL;
    int i=0;
	
    printf("\n%s\n", gender);
	if(*ln == NULL){
		
		tmp = (std *) malloc (sizeof(std));
		tmp-> age = age;

        //tmp->gender = (char *) malloc(sizeof(gen_len));
        //printf("\n--> inside linked list push _ start node\n");
        //tmp->gender = gender;
       
       copy_str(gender, tmp->gender);
        //strcpy(gender, tmp->gender);

        printf("\n%s\n", tmp->gender);
        tmp-> area_code = area_code;

		tmp-> next = NULL;

		*ln = tmp;
		
	}
	else{
	
	//printf("\nmore than one ele ins\n");
	// traversing to the end of the linked list
	while(tmp-> next != NULL){
		
		tmp = tmp-> next;
	}
	
	nnode = (std *) malloc(sizeof(std));
	nnode -> age = age;

    //tmp->gender = (char *) malloc(sizeof(gen_len));

    copy_str(gender, tmp->gender);
    //strcpy(gender, tmp->gender);
    printf("\n%s\n", tmp->gender);


    nnode ->area_code = area_code;

	nnode -> next = NULL; 
	
	tmp-> next = nnode;
    }
}

*/

/*
void copy_str(char src[], char *des)
{

    int i=0;

    //des = src;
   
    //printf("\nHey there\n");
    for(i=0; i<gen_len && src[i] != '\0'; i+=1){
        //printf("\nHappened copy str%d\t%c\t%c", i, *(des+i), src[i]);

        printf("\nbefore copy str%d\t%c\t%c", i, *(des+i), src[i]);
        *(des+i) = src[i];
        printf("\nafter copy str%d\t%c\t%c", i, *(des+i), src[i]);

    } 

}

*/


/**
 *  get input from user
 * 
 */
int usr_fr_ins(std **ln)
{

    int i = 1, j=0;
    int cnt = 1;
    int age;
    int area_code;
    char gender[gen_len];
    std *tmp = NULL;

    while(cnt){

        	
		tmp = (std *) malloc (sizeof(std));

        printf("\nLinked List %d:", i );
        printf("\n_________________\n");

        printf("\nEnter your Age:\t");
        scanf("%d", &tmp->age);

        // To remove newline from input stream, 
        while(getchar()!= '\n');

        printf("\nEnter your Gender\t");
        fgets(tmp->gender, gen_len, stdin);

        // to remove new line in the gen

        while(tmp->gender[j] != '\n'){
            j+=1;
        }
        tmp->gender[j] = '\0';
        // reset to 0, so for nxt iteration it'll from 00
        j=0;
        
        printf("\nEnter your Area code:\t");
        scanf("%d", &tmp->area_code);

        //pushlink(ln, age, gender, area_code);
        i += 1;

        tmp->next = *ln;
        *ln = tmp;


        printf("\n\nPress 0 to exit:\t");
        scanf("%d", &cnt);
    }

    
    dis(*ln);
    return i;
}
