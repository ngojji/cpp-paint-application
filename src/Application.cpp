#include "Application.h"

Application::Application() {
  window = new bobcat::Window(25, 75, 400, 650, "Paint App");

  canvas = new Canvas(50, 0, 350, 350);
  canvas->end();

  toolbar = new Toolbar(0, 0, 50, 650);
  toolbar->end();

  colorSelector = new ColorSelector(50, 350, 350, 300);

  ON_CHANGE(toolbar, Application::onToolbarChange);
  colorSelector->setOnChange([this]() { onColorSelectorChange(); });

  window->show();
}

int Application::run() { return Fl::run(); }

void Application::onToolbarChange(bobcat::Widget *sender) {
  ACTION action = toolbar->getAction();

  if (action == UNDO) {
    canvas->undo();
    return;
  }
  if (action == REDO) {
    canvas->redo();
    return;
  }
  if (action == CLEAR) {
    canvas->clear();
    return;
  }
  if (action == BRING_TO_FRONT) {
    canvas->bringToFront();
    return;
  }
  if (action == SEND_TO_BACK) {
    canvas->sendToBack();
    return;
  }

  canvas->setTool(toolbar->getSelectedTool());
}

void Application::onColorSelectorChange() {
  canvas->setColor(colorSelector->getSelectedColor());
  canvas->setSelectedColor(colorSelector->getSelectedColor());
}

Application::~Application() {}
