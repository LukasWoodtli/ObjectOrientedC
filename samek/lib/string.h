/********************************************************************** 
 * string.h -- sample code
 * @author  M. Samek
 * @version 1.00, 03/06/97
 */
#ifndef __STRING__

#include "object.h"

/** String class extends Object */
CLASS(String, Object)
   char *__buffer; /* private character buffer */
VTABLE(String, Object)
METHODS
   /* public constructors */
   String StringCon1(String this, const char *str);
   String StringCon2(String this, String other);

   /* public destructor */
   void StringDes(String this);

   /* public to char conversion */
   const char *StringToChar(String this);

END_CLASS

#define __STRING__
#endif
