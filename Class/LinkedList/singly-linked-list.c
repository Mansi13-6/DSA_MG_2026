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

    printf("Testing assertions on the empty list\n");
    assert(is_list_empty(p_list) == TRUE);
    assert(get_list_length(p_list) == 0);
    assert(get_start(p_list, &start_data) == LIST_EMPTY);
    assert(get_end(p_list, &end_data) == LIST_EMPTY);
    assert(pop_start(p_list, &start_data) == LIST_EMPTY);
    assert(pop_end(p_list, &end_data) == LIST_EMPTY);
    assert(remove_start(p_list) == LIST_EMPTY);
    assert(remove_end(p_list) == LIST_EMPTY);
    printf("All assertions on the empty list are successful\n");
    puts(line);

    show_list(p_list, "Showing empty list immediately after creation:");
    puts(line);

    for(data = 0; data < 5; ++data)
    {
        status = insert_start(p_list, data * 10);
        assert(status == SUCCESS);
        printf("%d inserted successfully at the start of the list\n", data * 10);
    }
    show_list(p_list, "Showing list after inserting 5 data elements at the start:");
    puts(line);

    for(data = 1; data <= 5; ++data)
    {
        status = insert_end(p_list, data * 5);
        assert(status == SUCCESS);
        printf("%d inserted successfully at the end of the list\n", data * 5);
    }
    show_list(p_list, "Showing list after inserting 5 data elements at the end:");
    puts(line);

    status = insert_after(p_list, -5, 100);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Expected failure to insert data 100 after non-existent data -5\n");
    puts(line);

    status = insert_after(p_list, 0, 100);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after successfully inserting 100 after 0:");

    status = insert_before(p_list, 43, 200);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Expected failure to insert data 200 after non-existent data 43\n");
    puts(line);

    status = insert_before(p_list, 0, 200);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after successfully inserting data 200 before 0:");
    puts(line);

    status = get_start(p_list, &start_data);
    assert(status == SUCCESS);
    printf("Data at the start:%d\n", start_data);
    show_list(p_list, "Showing list to demonstrate that get_start() returns start data without removing it:");
    puts(line);

    status = get_end(p_list, &end_data);
    assert(status == SUCCESS);
    printf("Data at the end:%d\n", end_data);
    show_list(p_list, "Showing list to demonstrate that get_end() returns the end data without removing it:");
    puts(line);

    status = pop_start(p_list, &start_data);
    assert(status == SUCCESS);
    printf("Data at the start = %d\n", start_data);
    show_list(p_list, "Showing list to demonstrate that pop_start() removes and returns the start data:");
    puts(line);

    status = pop_end(p_list, &end_data);
    assert(status == SUCCESS);
    printf("Data at the end = %d\n", end_data);
    show_list(p_list, "Showing list to demonstrate that pop_end() removes and returns the end data:");
    puts(line);

    status = remove_start(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after remove_start():");
    puts(line);

    status = remove_end(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after remove_end():");
    puts(line);

    status = remove_data(p_list, 78);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Expected error in removing non-existent data 78\n");
    puts(line);

    status = remove_data(p_list, 0);
    assert(status == SUCCESS);
    show_list(p_list, "Showing list after removing existing data 0:");
    puts(line);

    status = find(p_list, 91);
    assert(status == FALSE);
    printf("Expected return value FALSE from find() for non-existent data 91\n");
    puts(line);

    status = find(p_list, 100);
    assert(status == TRUE);
    printf("Expected return value TRUE from find() for existing data 30\n");
    puts(line);

    status = is_list_empty(p_list);
    assert(status == FALSE);
    printf("Expected return value FALSE from is_list_empty()\n");
    puts(line);

    length = get_list_length(p_list);
    printf("Length of the list = %d\n", length);
    puts(line);

    status = destroy_list(p_list);
    assert(status == SUCCESS);
    p_list = NULL;
    printf("List is destroyed successfully\n");
    puts(line);

    return (0);
}

/*Server side of linked list,
interface functions definitions*/

/*List creation function*/
struct node* create_list(void)
{
    struct node* head_node = NULL;
    head_node = (struct node*) malloc(sizeof(struct node));   //since typedef is not done, we have used struct node as it is 
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
    struct node* new_node = NULL;
    struct node* run = NULL;
    struct node* run_previous = NULL;

    //search for the first occurrence of the existing data with maintaining the bad pointer
    run_previous = p_list;
    run = p_list->next;
    while(run!=NULL)
    {
        if(run->data==existing_data)
        {
            break;
        }
        run_previous=run;
        run=run->next;
    }
    //if the existing data is not found then return error msg 
    if(run==NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }
    //step 2: allocate and initialize new node
    new_node = (struct node *) malloc(sizeof(struct node));

    if(new_node==NULL)
    {
        puts("Out of memory");
        exit (EXIT_FAILURE);
    }

    new_node->data=new_data;
    new_node->next=run;
    run_previous->next=new_node;
    return (SUCCESS);
}

/*Get Functions*/
int get_start(struct node* p_list, int* p_start_data)
{
    if(p_list->next==NULL)   //p_list->next=head node
    {
        return (LIST_EMPTY);
    }
    *p_start_data=p_list->next->data;
    return (SUCCESS);
}

int get_end(struct node* p_list, int* p_end_data)
{
    struct node* run = NULL;

    if(p_list->next == NULL)
    {
        return (LIST_EMPTY);
    }

    run = p_list->next;
    while(run->next!=NULL)
    {
        run=run->next;
    }

    *p_end_data=run->data;
    return (SUCCESS);
}

/*Pop Functions*/
int pop_start(struct node* p_list, int* p_start_data)
{
    struct node* delete_node = NULL;
    struct node* delete_previous = NULL;
    struct node* delete_next = NULL;

    if(p_list->next==NULL)
    {
        return (LIST_EMPTY);
    }
    *p_start_data = p_list->next->data;

    delete_previous = p_list;
    delete_node = p_list->next;
    delete_next = p_list->next->next;

    delete_previous->next = delete_next;
    free(delete_node);
    delete_node = NULL;
    return (SUCCESS);
}

int pop_end(struct node* p_list, int* p_end_data)
{
    struct node* run = NULL;
    struct node* run_previous = NULL;

    if(p_list->next==NULL)
    {
        return (LIST_EMPTY);
    }

    run_previous = p_list;
    run = p_list->next;

    while(run->next!=NULL)
    {
        run_previous = run;
        run = run->next;
    }

    *p_end_data = run->data;
    free(run);
    run = NULL;
    run_previous->next = NULL;
    return (SUCCESS);
}

/*Remove functions*/
int remove_start(struct node* p_list)
{
    struct node* delete_node = NULL;
    struct node* delete_previous = NULL;
    struct node* delete_next = NULL;

    if(p_list->next==NULL)
    {
        return (LIST_EMPTY);
    }

    delete_previous = p_list;
    delete_node = p_list->next;
    delete_next = p_list->next->next;

    delete_previous->next = delete_next;
    free(delete_node);
    delete_node = NULL;
    return (SUCCESS);
}

int remove_end(struct node* p_list)
{
    struct node* run = NULL;
    struct node* run_previous = NULL;

    if(p_list->next==NULL)
    {
        return (LIST_EMPTY);
    }

    run_previous = p_list;
    run = p_list->next;

    while(run->next!=NULL)
    {
        run_previous = run;
        run = run->next;
    }

    free(run);
    run = NULL;
    run_previous->next = NULL;
    return (SUCCESS);
}

int remove_data(struct node* p_list, int r_data)
{
    struct node* run = NULL;
    struct node* run_previous = NULL;

    run_previous = p_list;
    run = p_list->next;

    while(run!=NULL)
    {
        if(run->data == r_data)
        {
            break;
        }

        run_previous = run;
        run = run->next;
    }

    if(run==NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }

    run_previous->next = run->next;
    free(run);
    run = NULL;
    return (SUCCESS);
}

/*Miscallaneous functions*/
int find(struct node* p_list, int f_data)
{
    struct node* run = NULL;

    run = p_list->next;
    while(run!=NULL)
    {
        if(run->data==f_data)
        {
            return (TRUE);
        }
        run = run->next;
    }

    return (FALSE);
}

int get_list_length(struct node* p_list)
{
    int length = 0;
    struct node* run = NULL;

    run = p_list->next;
    while(run!=NULL)
    {
        length+=1;
        run = run->next;  
    }
    return (length);
}

int is_list_empty(struct node* p_list)
{
    if(p_list->next == NULL)
    {
        return TRUE; 
    }
    return FALSE; 
}

void show_list(struct node* p_list, const char* msg)
{
    struct node* run = NULL;

    if(msg!=NULL)
    {
        puts(msg);
    }
    printf("[START]->");
    run = p_list->next;

    while(run!=NULL)
    {
        printf("[%d]->",run->data);
        run=run->next;
    }
    printf("[END]->");
}

/*Destroy list function*/
int destroy_list(struct node *p_list)
{
    struct node* run = NULL;
    struct node* run_next = NULL;

    run = p_list;

    while(run!=NULL)
    {
        run_next=run->next;
        free(run);
        run=run_next;
    }
    return (SUCCESS);
}


