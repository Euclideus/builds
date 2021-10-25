#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <arb.h>
#include <doubly_linked_list.h>

typedef enum{red,black,dblack}color;

typedef enum{left,right,root}child_type;

typedef struct rbnode{

  color node_color;
  struct rbnode *lchild;
  struct rbnode *rchild;
  struct rbnode *parent;
  char *key;
  void *value;
}rbnode;

typedef struct rbtree{

  rbnode *root;
  void (*free_value)(void *);
  void (*write_value)(void *,void *,stream_type);
  void *(*read_value)(void *,stream_type);
  void *(*copy_value)(void *);
  int32_t size;
}rbtree;

int32_t isLeaf(rbnode *root);
int32_t isRoot(rbnode *root);
rbnode *rotate_left(rbnode **root,rbnode *pivot);
rbnode *rotate_right(rbnode **root,rbnode *pivot);
rbnode *initializeRBNode(char *strval,void *val,color ncol,rbnode *parent);
rbtree initializeRBTree(void (*func)(void *),
                        void *(*funcRead)(void *,stream_type),
                        void (*funcWrite)(void *,void *,stream_type),
                        void *(*funcCopy)(void *));
int32_t isEmpty(rbnode *root);
rbnode *grandParent(rbnode *rt);
rbnode *uncle(rbnode *rt);
rbnode *insertBinary(rbtree *rbt,rbnode *root,char *d,void *v);
char *printRBTreeToString(rbtree *rbt,rbnode *subtree,int32_t depth);
char *printRBNodeToString(rbnode *node);
int32_t testRBTree(rbnode *root);
int32_t isWhatChildType(rbnode *rbn);
void insertRBNode(rbtree *rbt,rbnode *root,char *d,void *v);
void recolor(rbnode **root,rbnode *inserted,rbnode *gp,rbnode *unc);
void restructure(rbnode **root,rbnode *inserted,rbnode *gp,rbnode *unc);
rbnode *sibling(rbnode *n);
rbnode *findRBNode(rbnode *root, char *d);
rbnode *findRBNodeVal(void *val,rbnode *curr);
void freeRBNode(rbtree *rbt,rbnode *node,int32_t v);
rbnode *deleteBinary(rbtree *rbt, rbnode *ins_pos, char *d1);
int32_t numChildren(rbnode *parent);
int32_t deleteRBNode(rbtree *rbt, rbnode *root, char *d1);
void recurDeletion(rbnode **root,rbnode *u,rbnode *s);
void transferKeyVal(rbtree *rbt,rbnode **source, rbnode **dest);
void freeRBTreeValues(rbtree *rbt,rbnode *curr);
void freeRBTreeNodes(rbtree *rbt,rbnode *curr);
void freeRBTree(rbtree *rbt,rbnode *st,int32_t v);
rbnode *predecessor(rbnode *root);
int32_t testEquivalentKeySets(rbtree *t1,rbtree *t2);
void testEquivalentKeySetsSub(rbnode *curr,rbtree *t2,int32_t *test);
char *printRBNodeToStringVS(rbnode *node);
char *printRBTreeToStringVS(rbnode *root,int32_t depth);
rbnode *fillRBDummyTree(int32_t maxd,char *keys,color tc,int32_t currd,
                         rbnode *parent);
int32_t maxDepth(rbnode *root,int32_t count);
void *keyVal(rbtree *rbt,char *key);
void layers(rbtree *rbt,rbnode *pos,dl_list *layersll,int32_t currdep,
            int32_t node_width);
char *NumSpaces(int32_t n);
void PadString(char **ss,char pad,int32_t nleft,int32_t nright);
void fillRBTreeWithDummyNodes(rbtree *rbt,rbnode **pos,int32_t depth,int32_t maxd);
void fixSpacing(dl_list *layers,int32_t dlev,int32_t maxd,int32_t node_width);
char *prettyPrintRBTreeToString(rbtree *rbt);
int32_t largestKeySize(rbnode *current);
rbtree copyRBTree(rbtree *rbt);
void copyRBTreeSub(rbnode **node,rbnode *source,rbnode *par,
                   void * (*cpy_func)(void *));
void writeRBTreeToStream(rbtree *rbt,rbnode *current,void *fs,stream_type st);
void writeRBTreeToFile(rbtree *rbt,char *fname);
rbnode *readRBNode(rbtree *rbt, void *fs, stream_type st);
void readRBTreeFromFile(rbtree *rbt,char *fname);
void readRBTreeFromStream(rbtree *rbt, void *fs, stream_type st);
void mergeRBTrees(rbtree *t1, rbtree *t2, int32_t ow, int32_t addnew);
void mergeRBTreesSub(rbtree *t1, rbtree *t2, rbnode *start, int32_t ow, int32_t addnew);
child_type childType(rbnode *rbn);

#endif
