#ifndef _assocArray_h
#define _assocArray_h

#include "stdlib.h"

typedef struct asArray  *asArray_t;

struct asArray{
  void * (*value)(asArray_t a, void *b);
  struct priv_tag *priv;
};

asArray_t newAsArray(void *base, size_t num, size_t size);
void delAsArray(asArray_t asArray);

#endif // _assocArray_h
