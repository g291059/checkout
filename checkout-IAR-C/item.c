#include "item.h"

#define numElem(array) ( sizeof(array) / sizeof(array[0]) )

//define the items data base

static row_t db[]={
  {"001",{"Chocolate Cake",9.25}},
  {"002",{"Whisky",45.00}},
  {"003",{"T-shirt",19.95}}
};

asArray_t hashDataBase(){
  return newAsArray((void *)db, numElem(db), sizeof(db[0]));
}