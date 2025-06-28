#include "calculator.h"

int main(int argc, char *argv[]) {
  auto app = Gtk::Application::create("in.piyushxcoder.calculator");
  return app->make_window_and_run<Calculator>(argc, argv);
}
