#ifndef POINT_H
#define POINT_H

#include <Color.h>
#include <GL/freeglut.h>

class Point {
  float x;
  float y;
  int size;
  Color color;

public:
  Point();
  Point(float _x, float _y, Color color);

  void draw() const;

  float getX() const;
  float getY() const;
  Color getColor() const;
  int getSize() const;

  void setX(float _x);
  void setY(float _y);
  void setColor(Color _color);
  void setSize(int _size);

  ~Point();
};

#endif
