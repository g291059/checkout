/******************************************************************************
 * associative array in C 
 * 
 ******************************************************************************/
#include "string.h"
#include "stdlib.h"
#include "assocArray.h"


//~~~~~~~~~~~~~~~~~~~~~ .c file ~~~~~~~~~~~~~~~~~~~~~~~~
// private 
struct priv_tag {
	size_t num,size;
	void *base;
};

// Compare 2 strings
int cmp1(const void *s1, const void *s2){
	return strcmp(*(const char **)s1,*(const char **)s2);
}
// Compare 
int cmp2(const void *pkey, const void *pelem){
	return strcmp((const char *)pkey,*(const char **)pelem);
}

// global methods - implementation
void *asArray_value(asArray_t asArray, void *key){
   struct priv_tag *priv = asArray->priv;
	return bsearch(key, priv->base, priv->num, priv->size,cmp2);
}

// constructor & destructor
asArray_t newAsArray(void *base, size_t num, size_t size){
	asArray_t asArray = (asArray_t)malloc(sizeof(struct asArray));
	struct priv_tag *priv =(struct priv_tag *)malloc(sizeof(struct priv_tag));
	priv->base   = base;
	priv->num	= num;
	priv->size	= size;
   asArray->priv  = priv;
	qsort(base,num,size,cmp1);
   asArray->value = asArray_value;
	return asArray;
}

void delAsArray(asArray_t asArray){
   free(asArray->priv); 
	free(asArray);
};


//*************************  end of file ***************************************
