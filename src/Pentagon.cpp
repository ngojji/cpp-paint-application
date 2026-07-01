#include <Pentagon.h>

Pentagon::Pentagon(float _x, float _y, float _radius, Color _color) {
  x = _x;
  y = _y;
  radius = _radius;
  color = _color;
}

void Pentagon::draw() const {
  glColor3f(color.r, color.g, color.b);
  glBegin(GL_POLYGON);
  for (int i = 0; i < 5; i++) {
    float theta = 2 * M_PI * i / 5 - M_PI / 2;
    glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
  }
  glEnd();
}

void Pentagon::drawHighlight() const {
  glColor3f(1, 1, 0);
  glBegin(GL_LINE_LOOP);
  for (int i = 0; i < 5; i++) {
    float theta = 2 * M_PI * i / 5 - M_PI / 2;
    glVertex2f(x + (radius + 0.02f) * cos(theta),
               y + (radius + 0.02f) * sin(theta));
  }
  glEnd();
}

bool Pentagon::contains(float px, float py) const {
  float dx = px - x, dy = py - y;
  return sqrt(dx * dx + dy * dy) <= radius;
}

void Pentagon::move(float dx, float dy) {
  x += dx;
  y += dy;
}

Color Pentagon::getColor() const { return color; }
void Pentagon::setColor(Color c) { color = c; }

bool Pentagon::nearResizeHandle(float px, float py) const {
  float hx = x + radius, hy = y;
  float dx = px - hx, dy = py - hy;
  return sqrt(dx * dx + dy * dy) < 0.05f;
}

void Pentagon::resize(float dx, float dy) {
  radius = std::max(0.02f, radius + dx);
}

void Pentagon::drawResizeHandle() const {
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

Pentagon::~Pentagon() {}
