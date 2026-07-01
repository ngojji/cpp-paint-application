#include <Line.h>

Line::Line(float _x1, float _y1, float _x2, float _y2, Color _color) {
  x1 = _x1;
  y1 = _y1;
  x2 = _x2;
  y2 = _y2;
  color = _color;
}

void Line::draw() const {
  glColor3f(color.r, color.g, color.b);
  glLineWidth(3);
  glBegin(GL_LINES);
  glVertex2f(x1, y1);
  glVertex2f(x2, y2);
  glEnd();
  glLineWidth(1);
}
void Line::drawHighlight() const {
  glColor3f(1, 1, 0);
  glLineWidth(7);
  glBegin(GL_LINES);
  glVertex2f(x1, y1);
  glVertex2f(x2, y2);
  glEnd();
  glColor3f(color.r, color.g, color.b);
  glBegin(GL_LINES);
  glVertex2f(x1, y1);
  glVertex2f(x2, y2);
  glEnd();
  glLineWidth(1);
}

bool Line::contains(float px, float py) const {
  float dx = x2 - x1, dy = y2 - y1;
  float len2 = dx * dx + dy * dy;
  if (len2 == 0)
    return sqrt((px - x1) * (px - x1) + (py - y1) * (py - y1)) < 0.03f;
  float t = ((px - x1) * dx + (py - y1) * dy) / len2;
  t = std::max(0.0f, std::min(1.0f, t));
  float cx = x1 + t * dx;
  float cy = y1 + t * dy;
  return sqrt((px - cx) * (px - cx) + (py - cy) * (py - cy)) < 0.03f;
}

void Line::move(float dx, float dy) {
  x1 += dx;
  y1 += dy;
  x2 += dx;
  y2 += dy;
}

Color Line::getColor() const { return color; }
void Line::setColor(Color c) { color = c; }

bool Line::nearResizeHandle(float px, float py) const {
  float dx = px - x2, dy = py - y2;
  return sqrt(dx * dx + dy * dy) < 0.05f;
}

void Line::resize(float dx, float dy) {
  x2 += dx;
  y2 += dy;
}

void Line::drawResizeHandle() const {
  float s = 0.025f;
  glColor3f(0, 1, 1);
  glBegin(GL_QUADS);
  glVertex2f(x2 - s, y2 - s);
  glVertex2f(x2 + s, y2 - s);
  glVertex2f(x2 + s, y2 + s);
  glVertex2f(x2 - s, y2 + s);
  glEnd();
}

Line::~Line() {}
