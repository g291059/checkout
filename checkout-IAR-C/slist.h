#ifndef SLIST_H
#define SLIST_H

typedef struct slistNode *slistNode_t;
typedef struct slist *slist_t;

struct slistNode {
	slistNode_t rLink;
   union {
      void *obj;
      void (*func)(void);
   }info;
};

struct slist {
	slistNode_t head;
	slistNode_t (*insertAtFront)( slist_t slist, slistNode_t node);
	slistNode_t (*insertAtBack)( slist_t slist, slistNode_t node);
	slistNode_t (*erase)( slist_t slist, slistNode_t node);
	void (*traverse)(slist_t slist);	
};

slist_t newSList(void);
void    delSList(slist_t sl,int delInfo);

slistNode_t newSListObjNode(void *info);

slistNode_t newSListFuncNode(void (*info)(void));

#endif

