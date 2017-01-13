#ifndef _promo_h
#define _promo_h

#include "slist.h"

typedef void (*promo_rule)(slist_t list);
void initPromoList(slist_t slist);
  
#endif   // _promo_h
