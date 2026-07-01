#ifndef PENTAGON_H
#define PENTAGON_H

#include <GL/freeglut.h>
#include <Shape.h>
#include <cmath>

class Pentagon : public Shape {
  float x, y, radius;
  Color color;

public:
  Pentagon(float x, float y, float radius, Color color);
  void draw() const;
  void drawHighlight() const;
  bool contains(float px, float py) const;
  void move(float dx, float dy);
  Color getColor() const;
  void setColor(Color c);

  bool nearResizeHandle(float px, float py) const;
  void resize(float dx, float dy);
  void drawResizeHandle() const;

  ~Pentagon();
};

#endif
