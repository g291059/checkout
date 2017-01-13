#ifndef _item_h
#define _item_h

#include "assocArray.h"
typedef struct { char *name; float price; } item_t;
typedef struct { const char *key; item_t item;} row_t;
 
// Data base as an associative asrray
asArray_t hashDataBase(void);

#endif   // _item_h
