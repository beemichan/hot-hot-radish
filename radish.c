#include "radish.h"
 
void display(circular *head){
   circular *current = head;
   if(current != NULL){
        do{
            printf("\n{ %s }\n", current->name);
            current = current->next;
        }while(current != head);
   }else{
       printf("\nLIST EMPTY\n");
   }
   
}
 
void insert_at_start(circular **head_ptr, char *name){
   circular  *node_ptr = malloc(sizeof(circular));
   node_ptr->name = name;
   node_ptr->next = *head_ptr;
   *head_ptr = node_ptr;
}
 
void insert_to_empty_list(circular **head_ptr, char *element){
    circular *node_ptr = malloc(sizeof(circular));
    node_ptr->name = malloc((strlen(element))*sizeof(char));
    strcpy(node_ptr->name, element);
    node_ptr->next = node_ptr;
    *head_ptr = node_ptr;
   
}
 
int length(circular **head_ptr){
    circular *current = *head_ptr;
    int count = 0;
    do{
        current = current->next;
        count++;
    }while(current != *head_ptr);
    return count;
}
 
void insert_at_end(circular **head_ptr, char *name){
   if (*head_ptr == NULL){
      insert_to_empty_list(head_ptr, name);
      printf("\nadding to empty list\n");
  }
  else{
      circular *current = *head_ptr;
      while(current->next != *head_ptr){
          current = current->next;
      }
      circular *new_node_ptr = malloc(sizeof(circular));
      new_node_ptr->name = malloc((strlen(name))*sizeof(char));
      strcpy(new_node_ptr->name, name);
      current->next = new_node_ptr;
      new_node_ptr->next = *head_ptr;
  }
}
 
void remove_from_start(circular **head_ptr){
   if (*head_ptr == NULL) {
       printf("Nothing to remove\n");
   } else if(*head_ptr == (*head_ptr)->next){
       free(*head_ptr);
       *head_ptr = NULL;
       return;
   }else{
        circular *current = *head_ptr;
        while(current->next != *head_ptr){
            current = current->next;
        }
        current->next = (*head_ptr)->next;
        circular *removed_ptr = *head_ptr;
        *head_ptr = removed_ptr->next;
        free(removed_ptr);
   }
}
 
void delete_by_name(circular **head_ptr, char *element_to_remove){
   if (*head_ptr == NULL) {
       printf("Nothing to remove\n");
   } else if(strcmp(((*head_ptr)->next)->name, element_to_remove)){
       remove_from_start(head_ptr);
   }else{
       circular *current_node_ptr = *head_ptr;
       while (strcmp(current_node_ptr->name, element_to_remove) == 0){
           if (current_node_ptr != *head_ptr) {
               current_node_ptr = current_node_ptr->next;
           } else {
               printf("Index is invalid, removal not performed\n");
               return;
           }
           
       }
       circular *removed_node_ptr = current_node_ptr->next;
       current_node_ptr->next = removed_node_ptr->next;
       free(removed_node_ptr);
   }
}
 
void radish_round(circular **name_list){
    int radish = (rand()%((30-1+1))+1);
    display(*name_list);
    circular *current = *name_list;
    while(radish != 0){
            printf("\nCURRENT PLAYER IS: %s\n", current->name);
            printf("\nCHOOSE: \n");
            printf("\n1: PASS NOW (1 second)\n");
            printf("\n2: WAIT 1 SECOND THEN PASS (2 seconds)\n");
            printf("\n3: WAIT 2 SECONDS THEN PASS (3 seconds)\n");
            printf("\nENTER CHOICE: ");
            int choice;
            scanf("%d", &choice);
            
            if(choice == 1){
                radish = radish - 1;
                printf("\n1 SECOND PASSES\n");
                if(radish <= 0){
                    printf("\n%s DIED.\n", current->name);
                    delete_by_name(name_list, (current->name));
                    printf("\nPLAYER REMOVED.\n");
                    radish = 0;
                    display(*name_list);
                }
                current = current->next;
            }else if(choice == 2){
                radish = radish - 2;
                printf("\n2 SECONDS PASS\n");
                if(radish <= 0){
                    printf("\n%s DIED.\n", current->name);
                    delete_by_name(name_list, (current->name));
                    printf("\nPLAYER REMOVED.\n");
                    radish = 0;
                    display(*name_list);
                }
                current = current->next;
            }else if(choice == 3){
                radish = radish - 3;
                printf("\n3 SECONDS PASS\n");
                if(radish <= 0){
                    printf("\n%s DIED.\n", current->name);
                    delete_by_name(name_list, (current->name));
                    printf("\nPLAYER REMOVED.\n");
                    radish = 0;
                    display(*name_list);
                }
            current = current->next;
            }else{
                printf("bad\n");
            }
             
        }
}
