#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
 
 
typedef struct circular{
   char *name;
   struct circular *next;
} circular;
 
void display(circular *head);
 
void insert_at_start(circular **head_ptr, char *name);
 
void insert_to_empty_list(circular **head_ptr, char *element);
 
int length(circular **head_ptr);
 
void insert_at_end(circular **head_ptr, char *name);
 
void remove_from_start(circular **head_ptr);
 
void delete_by_name(circular **head_ptr, char *element_to_remove);
 
void radish_round(circular **name_list);
