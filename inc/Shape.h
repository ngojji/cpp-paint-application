

#ifndef SHAPE_H
#define SHAPE_H

#include <Color.h>

class Shape {
public:
  virtual void draw() const = 0;
  virtual void drawHighlight() const {}
  virtual bool contains(float x, float y) const = 0;
  virtual void move(float dx, float dy) = 0;
  virtual Color getColor() const = 0;
  virtual void setColor(Color c) = 0;

  virtual bool nearResizeHandle(float x, float y) const { return false; }
  virtual void resize(float dx, float dy) {}
  virtual void drawResizeHandle() const {}

  virtual ~Shape() {}
};

#endif
