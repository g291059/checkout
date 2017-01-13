/***************************************************************
 * Compiled and Executed on IAR Embedded Workbench IDE (for ARM) 
 */
#include "stdio.h"
#include "assocArray.h"
#include "slist.h"
#include "checkout.h"
#include "promo.h"
#include "item.h"

#define numElem(array) ( sizeof(array) / sizeof(array[0]) )

// Tests

char *test1[] ={"001","002","003"};
char *test2[] ={"001","003","001"};
char *test3[] ={"001","002","001","003"};

void main(void){
  int i; 
  checkout_t chk = newCheckout();
 // test 1 
  for( i = 0 ; i < numElem(test1) ; i++){
      chk->scan(chk, test1[i]); 
  }
  float total = chk->total(chk);
  printf("\n%5.2f",total); 

 // test 2
  chk->reset(chk);
  for( i = 0 ; i < numElem(test2) ; i++){
      chk->scan(chk, test2[i]); 
  }
  total = chk->total(chk);
  printf("\n%5.2f",total); 
 
// test 3
  chk->reset(chk);
  for( i = 0 ; i < numElem(test3) ; i++){
      chk->scan(chk, test3[i]); 
  }
  total = chk->total(chk);
  printf("\n%5.2f",total); 
   
}