/********************************************************************** 
 * object.c -- implementation file for Object class and utilities
 * @author  M. Samek
 * @version 1.01, 03/20/97
 */
#include "object.h"

#include <assert.h>

/** implementation of Object class */
struct ObjectClass __Object = { 
   sizeof(struct Object),        /* size of Object attributes */
   NULL,                         /* no superclass */
   (void (*)(Object))Object_NoIm /* purely virtual destructor */
};

int Object__IsKindOf(Object this, void *class) {
   ObjectClass c;
   for (c = this->__vptr; c; c = c->__super)
      if (c == class)
         return 1;
   return 0;
}

Object Object__AllocArr(size_t size, short dim) {
   short *a = (short*)malloc(sizeof(short)+dim*size);
   if (a == NULL)
      return NULL;
   *a = dim; /* store the array dimension */
   return (Object)(a + 1); /* return loaction of the first object */
}

void Object__DeleteArr(Object pobj) {
   short *a = (short*)pobj - 1; /* start of allocated memory */
   size_t s = ((ObjectClass)pobj->__vptr)->__size;
   char *p; /* location of an object */
   short i; /* index into the array */
   for (i = 0, p = (char*)pobj; i < *a; i++, p += s)
      VCALL(p, Object, Des)END_CALL;
   free((void*)a); /* free up memory */
}

void Object_NoIm(void) {
   assert(0); /* break the execution */
}




  