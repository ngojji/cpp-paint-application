#include "Canvas.h"
#include <algorithm>

Canvas::Canvas(int x, int y, int w, int h)
    : bobcat::Canvas_(x, y, w, h), selectedIndex(-1), isResizing(false),
      currentScribble(nullptr), lastDragX(0), lastDragY(0), currentTool(PENCIL),
      currentColor({0, 0, 0}) {}

float Canvas::getGLX() const { return Fl::event_x() * 2.0f / w() - 1.0f; }

float Canvas::getGLY() const { return 1.0f - Fl::event_y() * 2.0f / h(); }

int Canvas::handle(int event) {
  int ex = Fl::event_x();
  int ey = Fl::event_y();
  bool inBounds = (ex >= 0 && ex < w() && ey >= 0 && ey < h());

  if (event == FL_PUSH) {
    if (!inBounds)
      return 0;
    float gx = getGLX();
    float gy = getGLY();

    if (currentTool == PENCIL) {
      beginScribble(currentColor);
      addToScribble(gx, gy);
      redraw();
    } else if (currentTool == ERASER) {
      beginScribble({1, 1, 1});
      addToScribble(gx, gy);
      redraw();
    } else if (currentTool == CIRCLE) {
      addCircle(gx, gy, 0.1f, currentColor);
    } else if (currentTool == TRIANGLE) {
      addTriangle(gx, gy, 0.2f, 0.2f, currentColor);
    } else if (currentTool == RECTANGLE) {
      addRectangle(gx, gy, 0.2f, 0.15f, currentColor);
    } else if (currentTool == LINE) {
      addLine(gx, gy, gx + 0.2f, gy, currentColor);
    } else if (currentTool == PENTAGON) {
      addPentagon(gx, gy, 0.1f, currentColor);
    } else if (currentTool == MOUSE) {
      selectAt(gx, gy);
      startDrag(gx, gy);
    }
    return 1;
  }

  if (event == FL_DRAG) {
    if (currentScribble != nullptr) {
      addToScribble(getGLX(), getGLY());
      redraw();
      return 1;
    }
    if (currentTool == MOUSE && inBounds) {
      moveSelected(getGLX(), getGLY());
      return 1;
    }
    return 0;
  }

  if (event == FL_RELEASE) {
    currentScribble = nullptr;
    return 0;
  }

  return bobcat::Canvas_::handle(event);
}

void Canvas::render() {
  for (int i = 0; i < (int)shapes.size(); i++) {
    shapes[i]->draw();
    if (i == selectedIndex) {
      shapes[i]->drawHighlight();
      shapes[i]->drawResizeHandle();
    }
  }
}

void Canvas::setTool(TOOL t) { currentTool = t; }
void Canvas::setColor(Color c) { currentColor = c; }

void Canvas::addCircle(float x, float y, float radius, Color color) {
  redoStack.clear();
  shapes.push_back(new Circle(x, y, radius, color));
  redraw();
}

void Canvas::addTriangle(float x, float y, float base, float height,
                         Color color) {
  redoStack.clear();
  shapes.push_back(new Triangle(x, y, base, height, color));
  redraw();
}

void Canvas::addRectangle(float x, float y, float width, float height,
                          Color color) {
  redoStack.clear();
  shapes.push_back(new Rectangle(x, y, width, height, color));
  redraw();
}

void Canvas::addLine(float x1, float y1, float x2, float y2, Color color) {
  redoStack.clear();
  shapes.push_back(new Line(x1, y1, x2, y2, color));
  redraw();
}

void Canvas::addPentagon(float x, float y, float radius, Color color) {
  redoStack.clear();
  shapes.push_back(new Pentagon(x, y, radius, color));
  redraw();
}

void Canvas::beginScribble(Color color) {
  redoStack.clear();
  currentScribble = new Scribble(color);
  shapes.push_back(currentScribble);
}

void Canvas::addToScribble(float x, float y) {
  if (currentScribble != nullptr) {
    currentScribble->addPoint(x, y);
    redraw();
  }
}

void Canvas::selectAt(float x, float y) {
  selectedIndex = -1;
  for (int i = (int)shapes.size() - 1; i >= 0; i--) {
    if (shapes[i]->contains(x, y)) {
      selectedIndex = i;
      break;
    }
  }
  redraw();
}

void Canvas::startDrag(float x, float y) {
  lastDragX = x;
  lastDragY = y;
  isResizing = false;
  if (selectedIndex >= 0 && shapes[selectedIndex]->nearResizeHandle(x, y)) {
    isResizing = true;
  }
}

void Canvas::moveSelected(float x, float y) {
  if (selectedIndex >= 0) {
    float dx = x - lastDragX;
    float dy = y - lastDragY;
    if (isResizing)
      shapes[selectedIndex]->resize(dx, dy);
    else
      shapes[selectedIndex]->move(dx, dy);
  }
  lastDragX = x;
  lastDragY = y;
  redraw();
}

void Canvas::undo() {
  if (!shapes.empty()) {
    redoStack.push_back(shapes.back());
    shapes.pop_back();
    selectedIndex = -1;
    redraw();
  }
}

void Canvas::redo() {
  if (!redoStack.empty()) {
    shapes.push_back(redoStack.back());
    redoStack.pop_back();
    redraw();
  }
}

void Canvas::clear() {
  shapes.clear();
  redoStack.clear();
  selectedIndex = -1;
  redraw();
}

void Canvas::bringToFront() {
  if (selectedIndex >= 0 && selectedIndex < (int)shapes.size() - 1) {
    std::rotate(shapes.begin() + selectedIndex,
                shapes.begin() + selectedIndex + 1, shapes.end());
    selectedIndex = (int)shapes.size() - 1;
    redraw();
  }
}

void Canvas::sendToBack() {
  if (selectedIndex > 0) {
    std::rotate(shapes.begin(), shapes.begin() + selectedIndex,
                shapes.begin() + selectedIndex + 1);
    selectedIndex = 0;
    redraw();
  }
}

void Canvas::setSelectedColor(Color c) {
  if (selectedIndex >= 0) {
    shapes[selectedIndex]->setColor(c);
    redraw();
  }
}

Canvas::~Canvas() {
  for (Shape *s : shapes)
    delete s;
  for (Shape *s : redoStack)
    delete s;
}
