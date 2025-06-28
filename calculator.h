#pragma once

#include <gtkmm.h>

class Calculator : public Gtk::Window {
public:
  Calculator();
  ~Calculator();

private:
  void attach_buttons();
  void assign_button_signals();

  Gtk::Grid m_grid;

  Gtk::Text m_display;

  Gtk::Button m_button_0;
  Gtk::Button m_button_1;
  Gtk::Button m_button_2;
  Gtk::Button m_button_3;
  Gtk::Button m_button_4;
  Gtk::Button m_button_5;
  Gtk::Button m_button_6;
  Gtk::Button m_button_7;
  Gtk::Button m_button_8;
  Gtk::Button m_button_9;
  Gtk::Button m_button_add;
  Gtk::Button m_button_subtract;
  Gtk::Button m_button_multiply;
  Gtk::Button m_button_divide;
  Gtk::Button m_button_equals;
  Gtk::Button m_button_clear;
};
