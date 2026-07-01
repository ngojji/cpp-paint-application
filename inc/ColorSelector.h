#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include <Color.h>
#include <FL/Fl_Box.H>
#include <FL/Fl_Value_Slider.H>
#include <bobcat_ui/all.h>
#include <functional>

class ColorSelector : public bobcat::Group {
  Fl_Value_Slider *rSlider;
  Fl_Value_Slider *gSlider;
  Fl_Value_Slider *bSlider;
  Fl_Box *previewBox;

  std::function<void()> changeCallback;

  static void onSliderChange(Fl_Widget *w, void *data);
  void updatePreview();

public:
  ColorSelector(int x, int y, int w, int h);
  int handle(int event) override;
  void setOnChange(std::function<void()> cb);
  Color getSelectedColor() const;
  ~ColorSelector();
};

#endif
