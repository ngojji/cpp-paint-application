#include <Scribble.h>

Scribble::Scribble(Color _color) : color(_color) {}

void Scribble::addPoint(float x, float y) {
  xs.push_back(x);
  ys.push_back(y);
}

void Scribble::draw() const {
  glColor3f(color.r, color.g, color.b);
  glPointSize(7);
  glBegin(GL_POINTS);
  for (size_t i = 0; i < xs.size(); i++) {
    glVertex2f(xs[i], ys[i]);
  }
  glEnd();
}

void Scribble::drawHighlight() const {
  if (xs.empty())
    return;
  float minX = xs[0], maxX = xs[0], minY = ys[0], maxY = ys[0];
  for (size_t i = 1; i < xs.size(); i++) {
    if (xs[i] < minX)
      minX = xs[i];
    if (xs[i] > maxX)
      maxX = xs[i];
    if (ys[i] < minY)
      minY = ys[i];
    if (ys[i] > maxY)
      maxY = ys[i];
  }
  glColor3f(1, 1, 0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(minX - 0.02f, maxY + 0.02f);
  glVertex2f(maxX + 0.02f, maxY + 0.02f);
  glVertex2f(maxX + 0.02f, minY - 0.02f);
  glVertex2f(minX - 0.02f, minY - 0.02f);
  glEnd();
}

bool Scribble::contains(float x, float y) const {
  for (size_t i = 0; i < xs.size(); i++) {
    float dx = xs[i] - x;
    float dy = ys[i] - y;
    if (sqrt(dx * dx + dy * dy) < 0.05f)
      return true;
  }
  return false;
}

void Scribble::move(float dx, float dy) {
  for (size_t i = 0; i < xs.size(); i++) {
    xs[i] += dx;
    ys[i] += dy;
  }
}

Color Scribble::getColor() const { return color; }
void Scribble::setColor(Color c) { color = c; }

Scribble::~Scribble() {}
