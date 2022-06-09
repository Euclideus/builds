#ifndef DOUBLY_LINKED_LIST_TT_H
#define DOUBLY_LINKED_LIST_TT_H

#include <arb.h>
#include <stdlib.h>


typedef struct dlnode_tt{

  struct dlnode_tt *next;
  struct dlnode_tt *prev;
  int32_t key;
  void *value;
}dlnode_tt;

typedef struct dllist_tt{

  dlnode_tt *first;
  dlnode_tt *last;
  dlnode_tt *sentry;
  void (*free_value)(void *);
  void *(*read_value)(void *,stream_type);
  void (*write_value)(void *,void *,stream_type);
  int32_t size;
}dllist_tt;


dlnode_tt *dll_initializeNode(int32_t key,void *val);
dllist_tt dll_initialize(void (*freeDLNodeValueNull)(void *),
  void *(*readDLNodeValue)(void *,stream_type),
  void (*writeDLNodeValue)(void *,void *,stream_type));
void dll_insertAfter(dllist_tt *dll,dlnode_tt *node,int32_t key,void *val);
void dll_insertBefore(dllist_tt *head,dlnode_tt *node,int32_t key,void *val);
void dll_freeNode(dllist_tt *dll,dlnode_tt *node,int32_t v);
void dll_free(dllist_tt *root,int32_t v);
dlnode_tt *dll_deleteNode(dllist_tt *dll,dlnode_tt *dln);

#endif
