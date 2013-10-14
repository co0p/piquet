
#include <stdlib.h>
#include <stdio.h>

/******************************************
* vars
*******************************************/
struct entry {
  struct entry *prev;
  struct entry *next;
  int  value;
};
typedef struct entry entry_t;

struct dllist {
  entry_t *head;
  entry_t *tail;
  size_t size;
};
typedef struct dllist dllist_t;


/******************************************
* functions
*******************************************/

/* init the dllist */
int dll_init(dllist_t *list) {
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  return EXIT_SUCCESS;
}

/* print list */
void dll_print(dllist_t *list) {
  entry_t *current = list->head;
  int pos = 0;
  while (current != NULL) {
    printf("[%d] = %d\n", pos, current->value);
    current = current->next;
    pos++;
  }
}


/* add entry to linked list */
int dll_add(dllist_t *list, int value) {
  entry_t *newEntry = (entry_t*) malloc(sizeof(entry_t*));
  if (list->size > 0) {
  }
  return EXIT_SUCCESS;
}

/* remove all entries */
void dll_delete(dllist_t *list) {
  entry_t *last = list->tail;
  entry_t *current = last;
  while (current != NULL) {
    last = current->prev;
    free(last);
  }
}

/* remove entry with values */
int dll_remove(dllist_t *list, int value) {
  return EXIT_SUCCESS;
}


int main(int argc, char *argv[]) {

  dllist_t *list = (dllist_t*) malloc(sizeof(dllist_t));
  dll_init(list);
  dll_print(list);

  dll_add(list, 12);
  dll_print(list);

  dll_add(list, 12);
  dll_add(list, 13);
  dll_add(list, 14);
  dll_print(list);
  
  dll_remove(list, 12);
  dll_print(list);

  dll_delete(list);
  free(list);
  return 0;
}