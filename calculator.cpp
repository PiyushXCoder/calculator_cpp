#include "calculator.h"
#include <tinyexpr.h>

Calculator::Calculator()
    : Gtk::Window(), m_grid(), m_display(), m_button_0("0"), m_button_1("1"),
      m_button_2("2"), m_button_3("3"), m_button_4("4"), m_button_5("5"),
      m_button_6("6"), m_button_7("7"), m_button_8("8"), m_button_9("9"),
      m_button_add("+"), m_button_subtract("-"), m_button_multiply("*"),
      m_button_divide("/"), m_button_equals("="), m_button_clear("C") {
  set_title("Calculator");
  set_default_size(100, 100);
  set_resizable(false);

  m_display.set_size_request(-1, 25);
  m_display.set_margin(10);

  m_grid.attach(m_display, 0, 0, 4, 1);
  attach_buttons();
  assign_button_signals();

  set_child(m_grid);
}

void Calculator::attach_buttons() {
  m_grid.attach(m_button_7, 0, 1);
  m_grid.attach(m_button_8, 1, 1);
  m_grid.attach(m_button_9, 2, 1);
  m_grid.attach(m_button_add, 3, 1);

  m_grid.attach(m_button_4, 0, 2);
  m_grid.attach(m_button_5, 1, 2);
  m_grid.attach(m_button_6, 2, 2);
  m_grid.attach(m_button_subtract, 3, 2);

  m_grid.attach(m_button_1, 0, 3);
  m_grid.attach(m_button_2, 1, 3);
  m_grid.attach(m_button_3, 2, 3);
  m_grid.attach(m_button_multiply, 3, 3);

  m_grid.attach(m_button_equals, 0, 4, 1, 1);
  m_grid.attach(m_button_clear, 1, 4);
  m_grid.attach(m_button_0, 2, 4);
  m_grid.attach(m_button_divide, 3, 4);
}

void Calculator::assign_button_signals() {
  m_button_0.signal_clicked().connect([this]() {
    int end = m_display.get_text_length();
    m_display.insert_text("0", 1, end);
  });
  m_button_1.signal_clicked().connect([this]() {
    int end = m_display.get_text_length();
    m_display.insert_text("1", 1, end);
  });
  m_button_2.signal_clicked().connect([this]() {
    int end = m_display.get_text_length();
    m_display.insert_text("2", 1, end);
  });
  m_button_3.signal_clicked().connect([this]() {
    int end = m_display.get_text_length();
    m_display.insert_text("3", 1, end);
  });
  m_button_4.signal_clicked().connect([this]() {
    int end = m_display.get_text_length();
    m_display.insert_text("4", 1, end);
  });
  m_button_5.signal_clicked().connect([this]() {
    int end = m_display.get_text_length();
    m_display.insert_text("5", 1, end);
  });
  m_button_6.signal_clicked().connect([this]() {
    int end = m_display.get_text_length();
    m_display.insert_text("6", 1, end);
  });
  m_button_7.signal_clicked().connect([this]() {
    int end = m_display.get_text_length();
    m_display.insert_text("7", 1, end);
  });
  m_button_8.signal_clicked().connect([this]() {
    int end = m_display.get_text_length();
    m_display.insert_text("8", 1, end);
  });
  m_button_9.signal_clicked().connect([this]() {
    int end = m_display.get_text_length();
    m_display.insert_text("9", 1, end);
  });
  m_button_add.signal_clicked().connect([this]() {
    int end = m_display.get_text_length();
    m_display.insert_text("+", 1, end);
  });
  m_button_subtract.signal_clicked().connect([this]() {
    int end = m_display.get_text_length();
    m_display.insert_text("-", 1, end);
  });
  m_button_multiply.signal_clicked().connect([this]() {
    int end = m_display.get_text_length();
    m_display.insert_text("*", 1, end);
  });
  m_button_divide.signal_clicked().connect([this]() {
    int end = m_display.get_text_length();
    m_display.insert_text("/", 1, end);
  });
  m_button_clear.signal_clicked().connect([this]() { m_display.set_text(""); });
  m_button_equals.signal_clicked().connect([this]() {
    te_expr *expr = te_compile(m_display.get_text().c_str(), {}, 0, 0);
    if (!expr)
      return;
    double result = te_eval(expr);
    m_display.set_text(std::to_string(result));
  });
}

Calculator::~Calculator() {}
