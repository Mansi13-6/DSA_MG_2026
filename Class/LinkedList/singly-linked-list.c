// Header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// symbolic constant
#define SUCCESS                     1
#define TRUE                        1
#define FALSE                       0
#define LIST_DATA_NOT_FOUND         2
#define LIST_EMPTY                  3    

// Node layout definition
struct node{
    int data;
    struct node *next;
};

/*Interface functions declaration*/

// List creation function
struct node *create_list(void);

/*Data insertion/addition function*/ 
int insert_start(struct node* p_list, int new_data);
int insert_end(struct node* p_list, int new_data);
int insert_after(struct node* p_list, int existing_data, int new_data);
int insert_before(struct node* p_list, int existing_data, int new_data);

/*Get Functions*/
int get_start(struct node* p_list, int* p_start_data);
int get_end(struct node* p_list, int* p_end_data);

/*Pop functions*/
int pop_start(struct node* p_list, int* p_start_data);
int pop_end(struct node* p_list, int* p_end_data);

/*Remove functions*/
int remove_start(struct node* p_list);
int remove_end(struct node* p_list);
int remove_data(struct node* p_list, int r_data);

/*Miscallaneous functions*/
int find(struct node* p_list, int f_data);
int get_list_length(struct node* p_list);
int is_list_empty(struct node* p_list);
void show_list(struct node* p_list, const char* msg);

/*List destruction function*/
int destroy_list(struct node *p_list);

/* Client side of Linked List,
   Entry point function,
   Main-starting function */
int main(void)
{
    struct node* p_list = NULL;

    int status;
    int data, start_data, end_data;
    int length;

    static const char* line = "----------------------------------------";
    
    p_list = create_list();
    assert(p_list != NULL);
    printf("List created successfully\n");
    puts(line);
    return (0);
}

/*Server side of linked list,
interface functions definitions*/

/*List creation function*/
struct node* create_list(void)
{
    struct node* head_node = NULL;
    head_node = (struct node*) malloc(sizeof(sruct node));   //since typedef is not done, we have used struct node as it is 
    if(head_node==NULL)
    {
        puts("Out of memory\n");
        exit(EXIT_FAILURE);
    }
    head_node->data = 0;
    head_node->next = NULL;
    return head_node;
}

/*Data addition functions*/
int insert_start(struct node* p_list, int new_data)
{
    struct node* new_node = NULL;
    new_node = (struct node*) malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        puts("Out of memory\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = new_data;
    new_node->next = p_list->next;
    p_list->next = new_node;

    return (SUCCESS);
}

int insert_end(struct node* p_list, int new_data)
{
    //step 1: allocate and initialize memory
    struct node* new_node = NULL;
    struct node* run = NULL;

    new_node = (struct node*) malloc(sizeof(struct node));  
    if(new_node==NULL)
    {
        puts("Out of memory\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = new_data;
    new_node->next = NULL;

    //step 2: locate last node
    run = p_list;
    while(run->next != NULL)
    {
        run = run->next;
    }
    //step 3: link the new node at the end
    run->next = new_node;
    
    return (SUCCESS);
}

int insert_after(struct node* p_list, int existing_data, int new_data)
{
    struct node* existing_node = NULL;
    struct node* new_node = NULL;
    struct node* run = NULL;
    
    //step 1: search for the node which contains the first occurrence of the existing data
    run = p_list->next;
    while(run != NULL)
    {
        if(run->data==existing_data)
        {
            break;
        }
        run = run->next;
    }
    //if existing data is not there, 
    if(run==NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }
    //allocate and initialize a new node
    existing_node = run;
    new_node = (struct node*) malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        puts("Out of memory\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = new_data;

    //insert the node at appropriate position
    new_node->next = existing_node->next;
    existing_node->next = new_node;

    return (SUCCESS);
}

int insert_before(struct node* p_list, int existing_data, int new_data)
{
    struct node* existing_node = NULL;
    struct node* 
}

