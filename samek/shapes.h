/********************************************************************** 
 * shapes.h -- sample code
 * @author  M. Samek
 * @version 1.00, 03/06/97
 */
#ifndef __SHAPES__

#include "object.h"
#include "string.h"

/** Interface Scaleable */
INTERFACE(Scaleable)
   void (*Scale)(Object, double); 
END_INTERFACE

/** Class Shape extends Object, implements Scaleable */
CLASS(Shape, Object) IMPLEMENTS(Scaleable);
   struct String name;     /* public shape's name */
VTABLE(Shape, Object) EXTENDS(Scaleable);
   double (*Area)(Shape);  /* pure virtual! */
METHODS
   Shape Shape_Con(Shape this, char *name);
   void Shape_Des(Shape this);
END_CLASS

/** Class Rect extends Shape */
CLASS(Rect, Shape)
   double __w; /* private width  */
   double __h; /* private height */
VTABLE(Rect, Shape)
METHODS
   Rect RectCon(Rect this, char *name, double w, double h);
   double RectArea(Rect this);
   void RectScale(Rect this, double mag);
END_CLASS

/** Class Circle extends Shape */
CLASS(Circle, Shape)
   double __r; /* private radius */
VTABLE(Circle, Shape)
METHODS
   Circle CircleCon(Circle this, char* name, double r);
   double CircleArea(Circle this);
   void CircleScale(Circle this, double mag);
END_CLASS

#define __SHAPES__
#endif
