#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <GL/freeglut.h>
#include <Shape.h>

class Rectangle : public Shape {
  float x, y, width, height;
  Color color;

public:
  Rectangle(float x, float y, float width, float height, Color color);
  void draw() const;
  void drawHighlight() const;
  bool contains(float px, float py) const;
  void move(float dx, float dy);
  Color getColor() const;
  void setColor(Color c);
  float getX() const;
  float getY() const;
  float getWidth() const;
  float getHeight() const;
  void setX(float x);
  void setY(float y);
  void setWidth(float w);
  void setHeight(float h);

  bool nearResizeHandle(float px, float py) const;
  void resize(float dx, float dy);
  void drawResizeHandle() const;

  ~Rectangle();
};

#endif
