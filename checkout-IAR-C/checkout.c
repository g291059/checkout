#include "stdlib.h"
#include "slist.h"
#include "promo.h"
#include "checkout.h"

struct priv {  
   slist_t checkoutList;
   slist_t promoList;
   asArray_t asArray;
};

static void reset(checkout_t chk){
  delSList(chk->priv->checkoutList, 1);
  chk->priv->checkoutList = newSList();  //wait for new customer
}  

static void scan(checkout_t chk, char *code){
  struct priv *priv = chk->priv;
  void *row = priv->asArray->value(priv->asArray,code);
  void *tmp = malloc(sizeof(row_t));
  *(row_t*)tmp = *(row_t*)row;  // local copy of data base info
  slistNode_t node = newSListObjNode((void *)tmp);
  priv->checkoutList->insertAtBack(priv->checkoutList,node);
}

static float total(checkout_t chk){
  struct priv *priv = chk->priv; 
  if(priv->promoList->head != NULL){ // no promos
	slistNode_t node = priv->promoList->head;
	while(node != NULL){
      ((promo_rule)node->info.func)(priv->checkoutList);
		node = node->rLink;
	}
  }
  // calculate total 
   float total = 0.;
  	slistNode_t node = priv->checkoutList->head;
	while(node != NULL){
      total += (*(row_t*)node->info.obj).item.price; 
	   node = node->rLink; // go to next node
	}
   return total;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
checkout_t newCheckout(void){
	checkout_t chk = (checkout_t)malloc(sizeof(struct checkout_tag));
   struct priv *priv = (struct priv *)malloc(sizeof(struct priv));
	chk->reset = reset;
   chk->scan  = scan;
   chk->total  = total;
   chk->priv   = priv;
   //   
   priv->checkoutList = newSList();
   priv->promoList = newSList();
   initPromoList(priv->promoList);
   priv->asArray = hashDataBase();
	
   return chk;
}

void delCheckout(checkout_t chk){  
  delSList(chk->priv->checkoutList, 1);
  delSList(chk->priv->promoList, 0);
  delAsArray(chk->priv->asArray);
  free(chk->priv);
  free(chk);
}