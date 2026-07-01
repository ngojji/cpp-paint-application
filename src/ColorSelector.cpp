#include <ColorSelector.h>
#include <FL/Fl_Group.H>

ColorSelector::ColorSelector(int x, int y, int w, int h)
    : bobcat::Group(x, y, w, h) {
  previewBox = new Fl_Box(x + 2, y + 5, 46, 80);
  previewBox->box(FL_FLAT_BOX);
  previewBox->color(fl_rgb_color(0, 0, 0));

  rSlider = new Fl_Value_Slider(x + 80, y + 5, w - 80, 25, "R");
  gSlider = new Fl_Value_Slider(x + 80, y + 35, w - 80, 25, "G");
  bSlider = new Fl_Value_Slider(x + 80, y + 65, w - 80, 25, "B");

  rSlider->type(FL_HORIZONTAL);
  gSlider->type(FL_HORIZONTAL);
  bSlider->type(FL_HORIZONTAL);

  rSlider->range(0, 255);
  gSlider->range(0, 255);
  bSlider->range(0, 255);

  rSlider->step(1);
  gSlider->step(1);
  bSlider->step(1);

  rSlider->value(0);
  gSlider->value(0);
  bSlider->value(0);

  rSlider->align(FL_ALIGN_LEFT);
  gSlider->align(FL_ALIGN_LEFT);
  bSlider->align(FL_ALIGN_LEFT);

  rSlider->when(FL_WHEN_CHANGED);
  gSlider->when(FL_WHEN_CHANGED);

  rSlider->callback(onSliderChange, this);
  gSlider->callback(onSliderChange, this);
  bSlider->callback(onSliderChange, this);

  end();
}

int ColorSelector::handle(int event) { return Fl_Group::handle(event); }

void ColorSelector::setOnChange(std::function<void()> cb) {
  changeCallback = cb;
}

void ColorSelector::onSliderChange(Fl_Widget *w, void *data) {
  ColorSelector *cs = (ColorSelector *)data;
  cs->updatePreview();
  if (cs->changeCallback)
    cs->changeCallback();
}

void ColorSelector::updatePreview() {
  int r = (int)rSlider->value();
  int g = (int)gSlider->value();
  int b = (int)bSlider->value();
  previewBox->color(fl_rgb_color(r, g, b));
  previewBox->redraw();
}

Color ColorSelector::getSelectedColor() const {
  return {(float)(rSlider->value() / 255.0), (float)(gSlider->value() / 255.0),
          (float)(bSlider->value() / 255.0)};
}

ColorSelector::~ColorSelector() {
  delete rSlider;
  delete gSlider;
  delete bSlider;
  delete previewBox;
}
