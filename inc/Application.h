#ifndef APPLICATION_H
#define APPLICATION_H

#include <Canvas.h>
#include <ColorSelector.h>
#include <Toolbar.h>
#include <bobcat_ui/all.h>

class Application {
  bobcat::Window *window;
  Canvas *canvas;
  Toolbar *toolbar;
  ColorSelector *colorSelector;

  void onToolbarChange(bobcat::Widget *sender);
  void onColorSelectorChange();

public:
  Application();
  int run();
  ~Application();
};

#endif
