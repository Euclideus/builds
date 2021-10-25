#ifndef QUEUE_H
#define QUEUE_H

#include <doubly_linked_list.h>

void enqueue(dl_list *dll,char *key,void *v);
dl_node *dequeue(dl_list *dll);
int32_t isEmptyQueue(dl_list dll);
void flushQueue(dl_list *dll);

#endif