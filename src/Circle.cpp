#include <Circle.h>

Circle::Circle(float _x, float _y, float _radius, Color _color) {
  x = _x;
  y = _y;
  radius = _radius;
  color = _color;
}

void Circle::draw() const {
  glColor3f(color.r, color.g, color.b);
  glBegin(GL_POLYGON);
  float inc = 2 * M_PI / 60;
  for (float theta = 0; theta <= 2 * M_PI; theta += inc)
    glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
  glEnd();
}
void Circle::drawHighlight() const {
  glColor3f(1, 1, 0);
  glBegin(GL_LINE_LOOP);
  float inc = 2 * M_PI / 60;
  for (float theta = 0; theta <= 2 * M_PI; theta += inc)
    glVertex2f(x + (radius + 0.02f) * cos(theta),
               y + (radius + 0.02f) * sin(theta));
  glEnd();
}

bool Circle::contains(float cx, float cy) const {
  float dx = cx - x, dy = cy - y;
  return sqrt(dx * dx + dy * dy) <= radius;
}

void Circle::move(float dx, float dy) {
  x += dx;
  y += dy;
}

Color Circle::getColor() const { return color; }
void Circle::setColor(Color c) { color = c; }
float Circle::getX() const { return x; }
float Circle::getY() const { return y; }
float Circle::getRadius() const { return radius; }
void Circle::setX(float _x) { x = _x; }
void Circle::setY(float _y) { y = _y; }
void Circle::setRadius(float r) { radius = r; }

bool Circle::nearResizeHandle(float cx, float cy) const {
  float hx = x + radius, hy = y;
  float dx = cx - hx, dy = cy - hy;
  return sqrt(dx * dx + dy * dy) < 0.05f;
}

void Circle::resize(float dx, float dy) {
  radius = std::max(0.02f, radius + dx);
}

void Circle::drawResizeHandle() const {
  float hx = x + radius, hy = y;
  float s = 0.025f;
  glColor3f(0, 1, 1);
  glBegin(GL_QUADS);
  glVertex2f(hx - s, hy - s);
  glVertex2f(hx + s, hy - s);
  glVertex2f(hx + s, hy + s);
  glVertex2f(hx - s, hy + s);
  glEnd();
}

Circle::~Circle() {}
