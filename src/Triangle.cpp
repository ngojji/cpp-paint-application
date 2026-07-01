#include <Triangle.h>
#include <cmath>

Triangle::Triangle(float _x, float _y, float _base, float _height,
                   Color _color) {
  x = _x;
  y = _y;
  base = _base;
  height = _height;
  color = _color;
}

void Triangle::draw() const {
  glColor3f(color.r, color.g, color.b);
  glBegin(GL_POLYGON);
  glVertex2f(x - base / 2, y - height / 2);
  glVertex2f(x, y + height / 2);
  glVertex2f(x + base / 2, y - height / 2);
  glEnd();
}

void Triangle::drawHighlight() const {
  glColor3f(1, 1, 0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(x - base / 2 - 0.02f, y - height / 2 - 0.02f);
  glVertex2f(x, y + height / 2 + 0.02f);
  glVertex2f(x + base / 2 + 0.02f, y - height / 2 - 0.02f);
  glEnd();
}
bool Triangle::contains(float px, float py) const {
  float x1 = x - base / 2, y1 = y - height / 2;
  float x2 = x, y2 = y + height / 2;
  float x3 = x + base / 2, y3 = y - height / 2;
  float d1 = (px - x2) * (y1 - y2) - (x1 - x2) * (py - y2);
  float d2 = (px - x3) * (y2 - y3) - (x2 - x3) * (py - y3);
  float d3 = (px - x1) * (y3 - y1) - (x3 - x1) * (py - y1);
  bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
  bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
  return !(has_neg && has_pos);
}

void Triangle::move(float dx, float dy) {
  x += dx;
  y += dy;
}

Color Triangle::getColor() const { return color; }
void Triangle::setColor(Color c) { color = c; }
float Triangle::getX() const { return x; }
float Triangle::getY() const { return y; }
float Triangle::getBase() const { return base; }
float Triangle::getHeight() const { return height; }
void Triangle::setX(float _x) { x = _x; }
void Triangle::setY(float _y) { y = _y; }
void Triangle::setBase(float b) { base = b; }
void Triangle::setHeight(float h) { height = h; }

bool Triangle::nearResizeHandle(float px, float py) const {
  float hx = x + base / 2, hy = y - height / 2;
  float dx = px - hx, dy = py - hy;
  return sqrt(dx * dx + dy * dy) < 0.05f;
}

void Triangle::resize(float dx, float dy) {
  base = std::max(0.02f, base + dx);
  height = std::max(0.02f, height - dy);
}

void Triangle::drawResizeHandle() const {
  float hx = x + base / 2, hy = y - height / 2;
  float s = 0.025f;
  glColor3f(0, 1, 1);
  glBegin(GL_QUADS);
  glVertex2f(hx - s, hy - s);
  glVertex2f(hx + s, hy - s);
  glVertex2f(hx + s, hy + s);
  glVertex2f(hx - s, hy + s);
  glEnd();
}

Triangle::~Triangle() {}
