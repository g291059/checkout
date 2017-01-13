#ifndef _checkout_h
#define _checkout_h

#include "slist.h"   // single linked list
#include "item.h"

typedef struct checkout_tag *checkout_t;

struct checkout_tag {
  void (*reset)(checkout_t chk);
  void (*scan)(checkout_t chk,char *code);
  float (*total)(checkout_t chk);
  struct priv *priv;
};


checkout_t newCheckout(void);
void delCheckout(checkout_t);

#endif //_checkout_h