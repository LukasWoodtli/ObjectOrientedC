/********************************************************************** 
 * string.c -- sample code
 * @author  M. Samek
 * @version 1.00, 03/06/97
 */
#include "string.h"

#include <stdlib.h>
#include <string.h>

/** implementation of String */
BEGIN_VTABLE(String, Object)
   VMETHOD(Object, Des) = (void (*)(Object))StringDes;
END_VTABLE

String StringCon1(String this, const char *str) {
   Object_Con(&this->super); /* construct superclass  */
   VHOOK(this, String); /* hook on the String class */
   
   /* allocate and initialize the character buffer */                   
   this->__buffer = (char*)malloc(strlen(str) + 1);
   if (!this->__buffer)
      return NULL;      /* failure */
   strcpy(this->__buffer, str);
   return this;
}

String StringCon2(String this, String other) {
   return StringCon1(this, StringToChar(other));
}

const char *StringToChar(String this) {
   return this->__buffer;
}

void StringDes(String this) {
   free(this->__buffer);     /* release buffer */ 
   Object_Des(&this->super); /* destroy superclass */
}
