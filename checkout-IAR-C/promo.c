#include "stdlib.h"
#include "string.h"
#include "slist.h"
#include "item.h"
#include "promo.h"

#define numElem(array) ( sizeof(array) / sizeof(array[0]) )

static void promo1(slist_t head);
static void promo2(slist_t head);


static promo_rule promos[]={
  promo1,   // rule #1
  promo2    // rule #2
};

void initPromoList(slist_t slist){
  int i;
  for(i = 0; i < numElem(promos) ; i++){
     slistNode_t node = newSListFuncNode( (void (*)(void)) promos[i]); 
     slist->insertAtBack(slist,node); 
  }
}

// rule 1: Buy 2 or more "Chocolate Cake" and the price drops to £8.50  
static void promo1(slist_t slist){
   // count the number of "001" items by traversing the list
   int numItems = 0;
	if(slist->head == NULL) return;
	slistNode_t node = slist->head;
	while(node != NULL){
      char *name = (*(row_t*)node->info.obj).item.name; 
      if( strcmp( name, "Chocolate Cake") == 0) numItems++;
	   node = node->rLink; // go to next node
	}   
   if(numItems < 2) return; // no correction
	
   // traverse again for changing the price
   node = slist->head;
	while(node != NULL){
      char *name = (*(row_t*)node->info.obj).item.name; 
      if( strcmp( name, "Chocolate Cake") == 0) (*(row_t*)node->info.obj).item.price = 8.5; 
	   node = node->rLink; // go to next node
	}      
}

static void promo2(slist_t slist){
   float total = 0.;
	if(slist->head == NULL) return;
	slistNode_t node = slist->head;
	while(node != NULL){
      total += (*(row_t*)node->info.obj).item.price; 
	   node = node->rLink; // go to next node
	}
   if(total < 60.0) return;
   // make all prioes 10% cheaper
	node = slist->head;
	while(node != NULL){
      (*(row_t*)node->info.obj).item.price *= 0.9; 
	   node = node->rLink; // go to next node
	}
}


