
/********************************************************************** 
 * test.c -- sample code
 * @author  M. Samek
 * @version 1.00, 03/06/97
 */
#include "shapes.h"

#include <stdio.h>
#include <assert.h>

void testShape(Shape s) {
   assert(IS_RUNTIME_CLASS(s, Shape));
   printf("Shape.name=\"%s\", Shape.Area()=%.2f\n",
          StringToChar(&s->name),         /* static binding */
          VCALL(s, Shape, Area)END_CALL); /* dynamic binding */
}

void testScaleable(Scaleable s) {
   assert(IS_RUNTIME_CLASS(I_TO_OBJ(s), Object)); 
   printf("Scaleable.Scale(), ");
   ICALL(s, Scale) ,2.0 END_CALL; /* dynamic binding */
}

#define NRECT 10

int main(void) {
   struct Circle circle;  /* Circle instance on the stack frame */
   Circle c;
   Rect r; 
   int i;

   /* construct objects... */
   c = CircleCon(&circle, "Circle", 0.5); /* construct a Circle */
   r = ALLOC_ARR(Rect, NRECT); /* allocate Rectangles */ 
   for (i = 0; i < NRECT; i++) {
      char name[20];
      sprintf(name, "Rectangle-%d", i); /* prepare the name */
      RectCon(&r[i], name, (double)i, 0.5); /* construct a Rect */
   }

   /* test each object... */
   testScaleable(&c->super.Scaleable);
   testShape((Shape)c);
   for (i = 0; i < NRECT; i++) {
      testScaleable(&r[i].super.Scaleable);
      testShape((Shape)&r[i]);
   }

   /* detstroy objects... */
   VCALL(c, Object, Des)END_CALL;  /* dynamic binding */
   DELETE_ARR(r);

   return 0;
}
    


#if 0

Listing 1
Declaration of String class.

#include 3object.h2
/** Character String class */
CLASS(String, Object)
   char *__buffer; /* private buffer */
VTABLE(String, Object)
METHODS
   /* public constructors */
   String StringCon1(String this,
                const char *str);
   String StringCon2(String this,
                String other);

   /* public destructor * /
   void StringDes(String this);

   /* public to char conversion */
   const char *StringToChar(String this);
END_CLASS


Listing 2
Definition of class String.

#include <stdlib.h>
#include <string.h>
#include 3string.h2
/** implementation of String class */
BEGIN_VTABLE(String, Object)
   VMETHOD(Object, Des) = (void (*)(Object))StringDes;
END_VTABLE
String StringCon1(String this, const char *str) {
   Object_Con(&this->super); /* construct superclass */
   VHOOK(this, String);   /* hook String VPTR */
   /* allocate and initialize the buffer */
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
   free(this->__buffer);   /* release buffer */
   Object_Des(&this->super); /* destroy superclass */
}


 
#endif
