#include "slist.h"
#include "stdlib.h"
#include "stdio.h"

static slistNode_t insertAtFront( slist_t slist, slistNode_t node){
  if(slist->head == NULL){
     slist->head = node;
	  node->rLink = NULL;
  }
  else{
     slistNode_t tmp = slist->head;
     slist->head = node;
     node->rLink = tmp;
  }    
	return node;
};

static slistNode_t insertAtBack( slist_t slist, slistNode_t node){
  if(slist->head == NULL){
     slist->head = node;
	  node->rLink = NULL;
  }
  else{
	slistNode_t n = slist->head;
	while(n->rLink != NULL) n = n->rLink ;
	n->rLink = node;
   node->rLink = NULL;
  }
	return slist->head;
};

static void traverse(slist_t slist){
	if(slist->head == NULL) return;
	slistNode_t node = slist->head;
	while(node != NULL){
		printf("%d ", *(int*)node->info.obj);
		node = node->rLink;
	}
	printf("\n");
};	

static slistNode_t erase( slist_t slist, slistNode_t node){
	if( slist->head == NULL ) return NULL;
	if( slist->head == node ) {/* free() */ return slist->head->rLink;}
	slistNode_t n = slist->head;
	while(n->rLink != NULL){
		if(n->rLink == node){
			n->rLink = n->rLink->rLink;
			// free()
			break;
		}
		n = n->rLink;
	}
	return slist->head;
};

//##############################################################################
slist_t newSList(void){
	slist_t sl = (slist_t)malloc(sizeof(struct slist));
	sl->head = NULL;
	sl->insertAtFront = insertAtFront;
	sl->insertAtBack  = insertAtBack;
	sl->erase         = erase;
	sl->traverse      = traverse;
	return sl;
}

void delSList(slist_t sl, int delInfo){ 
  if(sl->head != NULL){
      slistNode_t node = sl->head;
      while(node != NULL){
         slistNode_t tmp = node;
         node = node->rLink;
         if(delInfo) free(tmp->info.obj);
         free(tmp);
      }
  }
  free( (void*)sl); 
}

slistNode_t  newSListObjNode(void *info){
	slistNode_t node = (slistNode_t)malloc(sizeof(struct slistNode));
	node->info.obj  = info;
	node->rLink     = NULL;
	return node;
}

slistNode_t  newSListFuncNode(void (*info)(void)){
	slistNode_t node = (slistNode_t)malloc(sizeof(struct slistNode));
	node->info.func  = info;
	node->rLink      = NULL;
	return node;
}


