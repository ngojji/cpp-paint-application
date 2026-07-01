#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include <GL/freeglut.h>
#include <Shape.h>
#include <cmath>
#include <vector>

class Scribble : public Shape {
  std::vector<float> xs;
  std::vector<float> ys;
  Color color;

public:
  Scribble(Color color);
  void addPoint(float x, float y);
  void draw() const;
  void drawHighlight() const;
  bool contains(float x, float y) const;
  void move(float dx, float dy);
  Color getColor() const;
  void setColor(Color c);
  ~Scribble();
};

#endif
