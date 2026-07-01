#ifndef LINE_H
#define LINE_H

#include <GL/freeglut.h>
#include <Shape.h>
#include <cmath>

class Line : public Shape {
  float x1, y1, x2, y2;
  Color color;

public:
  Line(float x1, float y1, float x2, float y2, Color color);
  void draw() const;
  void drawHighlight() const;
  bool contains(float px, float py) const;
  void move(float dx, float dy);
  Color getColor() const;
  void setColor(Color c);

  bool nearResizeHandle(float px, float py) const;
  void resize(float dx, float dy);
  void drawResizeHandle() const;

  ~Line();
};

#endif
