#ifndef _LIST_H
#define _LIST_H

/*Header files*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*Symbolic constants*/
enum Status {
    SUCCESS               = 1,
    TRUE                  = 1,
    FALSE                 = 0,
    LIST_DATA_NOT_FOUND   = 2,
    LIST_EMPTY            = 3
};

/*Typedef*/
typedef int              data_t;
typedef int              len_t;
typedef enum Status      status_t;
typedef struct Node      node_t;
typedef node_t           list_t;

/* node layout definition */
struct Node
{
    data_t data;
    struct Node *prev;
    struct Node *next;
};

/* declaration of iterface function */
//create_list() function
list_t* create_list(void);

//insertion function
status_t insert_start(list_t* p_list, data_t new_data);
status_t insert_end(list_t* p_list, data_t new_data);
status_t insert_after(list_t* p_list, data_t existing_data, data_t new_data);
status_t insert_before(list_t* p_list, data_t existing_data, data_t new_data);


/* get and pop function */
status_t get_start(list_t* p_list, data_t* p_start_data);
status_t get_end(list_t* p_list, data_t* p_end_data);
status_t pop_start(list_t* p_list, data_t* p_start_data);
status_t pop_end(list_t* p_list, data_t* p_end_data);

/* remove function */
status_t remove_start(list_p* p_list);
status_t remove_end(list_p* p_list);
status_t remove_data(list_p* p_list, data_t e_data);

/* miscallaneous function */
status_t find(list_p* p_list, data_t search_data);
status_t is_list_empty(list_p* p_list);
len_t get_list_length(list_p* p_list);
void show(list_p* qp_list, const char *msg)

/* destroy function */
status-t destroy_list(list_p** pp_list);

//helper function
void generic_insert(node_t* start_node, node_t* mid_node, node_t* end_node);
void generic_delete(node_t* delete_node);
node_t* search_node(list_t* p_list, data_t search_data);
node_t* get_node(data_t new_data);
void* xmalloc(size_t size);

#endif
