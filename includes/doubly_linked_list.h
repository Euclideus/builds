#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <arb.h>
#include <stdint.h>

typedef struct dl_node{

  struct dl_node *next;
  struct dl_node *prev;
  char *key;
  void *value;
}dl_node;

typedef struct dl_list{

  dl_node *first;
  dl_node *last;
  dl_node *sentry;
  void (*free_value)(void *);
  void *(*read_value)(void *,stream_type);
  void (*write_value)(void *,void *,stream_type);
  void *(*copy_value)(void *);
  int32_t size;
}dl_list;

void removeDLPosition(dl_list *dll,int32_t pos);
dl_node *initializeDLNode(char *key,void *val);
dl_list initializeDLList(void (*freeDLNodeValueNull)(void *),
  void *(*readDLNodeValue)(void *,stream_type),
  void (*writeDLNodeValue)(void *,void *,stream_type),
  void *(copyDLNodeValue)(void *));
void insertAfter(dl_list *dll,dl_node *node,char *key,void *val);
void insertBefore(dl_list *head,dl_node *node,char *key,void *val);
dl_node *findDLNode(dl_list *head,char *key);
void freeDLNode(dl_list *dll,dl_node *node,int32_t v);
void freeDLList(dl_list *root,int32_t v);
void deallocDLList(void *dll);
void freeDLNodeValue(void *val);
dl_node *deleteDLNode(dl_list *dll,dl_node *dln);
dl_list copyDLList(dl_list *source,
  dl_node *first,
  dl_node *last);
void swapKeyVal(dl_node **source,dl_node **dest);
void reverseDLList(dl_list *dll);
void readDLListFromFile(dl_list *dll,char *fname);
void readDLListFromStream(dl_list *dll,void *f1,stream_type st);
void writeDLListToFile(dl_list *dll,dl_node *start,dl_node *end,int32_t num,
  char *fname);
void writeDLListToStream(dl_list *dll,dl_node *start,dl_node *end,int32_t num,
  void *f1,stream_type st);

#endif
