#include "point.h"
#include <iostream>
#include "tools.h"

void Point::Print() const {
  SetCursorPosition(x, y);
  std::cout << "w";
}
void Point::PrintCircular() const {
  SetCursorPosition(x, y);
  std::cout << "s";
}

void Point::Clear() const {
  SetCursorPosition(x, y);
  std::cout << " ";
}

void Point::ChangePosition(const int a, const int b) {
  this->x = a;
  this->y = b;
}