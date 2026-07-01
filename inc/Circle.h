#ifndef CIRCLE_H
#define CIRCLE_H

#include <GL/freeglut.h>
#include <Shape.h>
#include <cmath>

class Circle : public Shape {
  float x, y, radius;
  Color color;

public:
  Circle(float x, float y, float radius, Color color);
  void draw() const;
  void drawHighlight() const;
  bool contains(float cx, float cy) const;
  void move(float dx, float dy);
  Color getColor() const;
  void setColor(Color c);
  float getX() const;
  float getY() const;
  float getRadius() const;
  void setX(float x);
  void setY(float y);
  void setRadius(float r);

  bool nearResizeHandle(float cx, float cy) const;
  void resize(float dx, float dy);
  void drawResizeHandle() const;

  ~Circle();
};

#endif
