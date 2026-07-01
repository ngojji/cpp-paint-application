

#include <Point.h>

Point::Point() {
  x = 0.0;
  y = 0.0;
  color = {0, 0, 0};
  size = 7;
}

Point::Point(float _x, float _y, Color _color) {
  x = _x;
  y = _y;
  color = _color;
  size = 7;
}

void Point::draw() const {
  glColor3f(color.r, color.g, color.b);
  glPointSize(size);
  glBegin(GL_POINTS);
  glVertex2f(x, y);
  glEnd();
}

float Point::getX() const { return x; }
float Point::getY() const { return y; }
int Point::getSize() const { return size; }
Color Point::getColor() const { return color; }

void Point::setX(float _x) { x = _x; }
void Point::setY(float _y) { y = _y; }
void Point::setSize(int _size) { size = _size; }
void Point::setColor(Color _color) { color = _color; }

Point::~Point() {
  //
}
