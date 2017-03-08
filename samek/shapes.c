/********************************************************************** 
 * shapes.c -- sample code
 * @author  M. Samek
 * @version 1.00, 03/06/97
 */
#include "shapes.h"

/** implementation of Shape */
BEGIN_VTABLE(Shape, Object)
   VMETHOD(Object, Des) = (void (*)(Object))Shape_Des;
   VMETHOD(Shape, Area) = (double (*)(Shape))Object_NoIm;
   IMETHOD(Scaleable, Scale) = (void (*)(Object, double))Object_NoIm;
END_VTABLE

Shape Shape_Con(Shape this, char *name) {
   Object_Con(&this->super);      /* construct superclass */
   VHOOK(this, Shape);            /* hook Shape class */
   IHOOK(this, Shape, Scaleable); /* hook Scaleable interface */
   if (!StringCon1(&this->name, name)) /* construct member */
      return NULL;                /* report failure */
   return this;
}

void Shape_Des(Shape this) {
   StringDes(&this->name);   /* destroy member     */
   Object_Des(&this->super); /* destroy superclass */
}

/** implementation of Rect  */
BEGIN_VTABLE(Rect, Shape)
   VMETHOD(Shape, Area) = (double (*)(Shape))RectArea;
   IMETHOD(super.Scaleable, Scale) = (void (*)(Object,
double))RectScale;
END_VTABLE

Rect RectCon(Rect this, char *name, double w, double h) {
   if (!Shape_Con(&this->super, name)) /* construct superclass */
      return NULL;                     /* report failure */
   VHOOK(this, Rect);                  /* hook Rect class */
   IHOOK(this, Rect, super.Scaleable); /* hook Scaleable interface */
   this->__h = h;                      /* initialise member(s) */
   this->__w = w;
   return this;
}

double RectArea(Rect this) {
   return this->__w  *this->__h;
}

void RectScale(Rect this, double mag){
   this->__w *= mag;
   this->__h *= mag;
}

/* implementation of Circle */
BEGIN_VTABLE(Circle, Shape)
   VMETHOD(Shape, Area) = (double (*)(Shape))CircleArea;
   IMETHOD(super.Scaleable, Scale) = (void (*)(Object,
double))CircleScale;
END_VTABLE

Circle CircleCon(Circle this, char *name, double r) {
   if (!Shape_Con(&this->super, name))/* construct superclass */
      return NULL;                    /* report failure */
   VHOOK(this, Circle);               /* hook Circle class */
   IHOOK(this, Circle, super.Scaleable); /* hook Scaleable interface */
   this->__r = r;                     /* initialise member(s) */
   return this;
}

double CircleArea(Circle this) {
   return 3.14 * this->__r * this->__r;
}

void CircleScale(Circle this, double mag) {
   this->__r *= mag;
}
