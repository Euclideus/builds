#ifndef STACK_H
#define STACK_H

#include <doubly_linked_list.h>

void push(dl_list *dll,char *key,void *v);
dl_node *pop(dl_list *dll);
int32_t isEmptyStack(dl_list *dll);
void flushStack(dl_list *dll);
dl_node *peek(dl_list *dll);

#endif
