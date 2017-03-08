/** Code from: http://onestepback.org/articles/poly/gp-c.html */

#include <stdio.h>
#include <stdlib.h>


/* Abstract interface declaration */

struct Shape {
  struct shapeFuncTable *funcTable;
  void *privateData;
};

struct shapeFuncTable {
  void (*Draw)(struct Shape *obj);
  void (*MoveTo)(struct Shape *obj, int newX, int newY);
  void (*RMoveTo)(struct Shape *obj, int dX, int dY);
};


/* Class Rectangle */
struct RectanglePrivateData {
  int x, y;
  int width;
  int height;
};

void RectangleDraw (struct Shape *obj) {
  struct RectanglePrivateData *rdata = (struct RectanglePrivateData*)obj->privateData;
  printf ("Drawing a Rectangle at (%d, %d), width %d, height %d\n", rdata->x, rdata->y, rdata->width, rdata->height);
}

void RectangleMoveTo(struct Shape *obj, int newX, int newY) {
  struct RectanglePrivateData *rdata = (struct RectanglePrivateData*)obj->privateData;
  rdata->x = newX;
  rdata->y = newY;
}

void RectangleRMoveTo(struct Shape * obj, int dX, int dY) {
  struct RectanglePrivateData *rdata = (struct RectanglePrivateData*)obj->privateData;
  rdata->x += dX;
  rdata->y += dY;
}

void RectangleSetWidth(struct Shape * obj, int newWidth) {
  struct RectanglePrivateData *rdata = (struct RectanglePrivateData*)obj->privateData;
  rdata->width = newWidth;
}

void RectangleSetHeight(struct Shape * obj, int newHeight) {
  struct RectanglePrivateData *rdata = (struct RectanglePrivateData*)obj->privateData;
  rdata->height = newHeight;
}

/* Function table */
struct RectangleFuncTable {
  void (*Draw)(struct Shape *obj);
  void (*MoveTo)(struct Shape *obj, int newX, int newY);
  void (*RMoveTo)(struct Shape *obj, int dX, int dY);
  void (*SetWidth)(struct Shape *obj, int newWidth);
  void (*SetHeight)(struct Shape *obj, int newHeight);
} rectangleFuncTable = {
  RectangleDraw,
  RectangleMoveTo,
  RectangleRMoveTo,
  RectangleSetWidth,
  RectangleSetHeight
};

/* Constructor */
struct Shape * MakeRectangle (int initX, int initY, int initWidth, int initHeight) {
  struct Shape * obj = malloc(sizeof *obj);
  struct RectanglePrivateData * rdata = malloc(sizeof *rdata);

  obj->funcTable = (struct shapeFuncTable*) &rectangleFuncTable;
  obj->privateData = rdata;

  rdata->x = initX;
  rdata->y = initY;
  rdata->width = initWidth;
  rdata->height = initHeight;

  return obj;
}

/// @todo Destructor



/* ====================================================== */


/* Class Circle */
struct CirclePrivateData {
  int x, y;
  int radius;
};

void CircleDraw(struct Shape * obj) {
  struct CirclePrivateData * cdata = (struct CirclePrivateData *)obj->privateData;
  printf("Drawing a Circle at (%d, %d), radius %d\n", cdata->x, cdata->y, cdata->radius);
}

void CircleMoveTo(struct Shape * obj, int newX, int newY) {
  struct CirclePrivateData * cdata = (struct CirclePrivateData *)obj->privateData;

  cdata->x = newX;
  cdata->y = newY;
}

void CircleRMoveTo(struct Shape * obj, int dX, int dY) {
  struct CirclePrivateData * cdata = (struct CirclePrivateData *)obj->privateData;

  cdata->x += dX;
  cdata->y += dY;
}

void CircleSetRadius(struct Shape * obj, int newRadius) {
  struct CirclePrivateData * cdata = (struct CirclePrivateData *)obj->privateData;

  cdata->radius = newRadius;
}

/* Fuction Table */
struct CircleFuncTable {
  void (*Draw)(struct Shape *obj);
  void (*MoveTo)(struct Shape *obj, int newX, int newY);
  void (*RMoveTo)(struct Shape *obj, int dX, int dY);
  void (*SetRadius)(struct Shape * obj, int radius);
} circleFuncTable = {
  CircleDraw,
  CircleMoveTo,
  CircleRMoveTo,
  CircleSetRadius
};

/* Constructor */
struct Shape * MakeCircle(int initX, int initY, int initRadius) {
  struct Shape * obj = malloc(sizeof *obj);
  struct CirclePrivateData * cdata = malloc(sizeof *cdata);
  obj->funcTable = (struct shapeFuncTable*) &circleFuncTable;
  obj->privateData = cdata;

  cdata->x = initX;
  cdata->y = initY;
  cdata->radius = initRadius;

  return obj;
}




/* ============================================= */

void DoSomethingWithShape(struct Shape *s) {
  s->funcTable->Draw(s);
  s->funcTable->RMoveTo(s, 100, 20);
  s->funcTable->Draw(s);
}



int main(int argc, char** argv) {
  int i;
  struct Shape * shapes[2];
  //struct Shape * rect;

  /* using shapes polymorphically */
  shapes[0] = MakeRectangle(10, 20, 5, 6);
  shapes[1] = MakeCircle(15, 25, 8);

  for (i=0; i<2; ++i) {
    DoSomethingWithShape(shapes[i]);
  }

  /* access rectangle specific functions */
  ((struct RectangleFuncTable*)shapes[0]->funcTable)->SetWidth(shapes[0], 30);
  shapes[0]->funcTable->Draw(shapes[0]);

  return 0;
}
