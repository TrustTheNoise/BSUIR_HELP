#include "Triangle.h"
#include <cmath>
#include <iostream>

bool Triangle::isValid()
{
  return (side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1);
}

int Triangle::perimeter()
{
  return side1 + side2 + side3;
}

void Triangle::viewInfo()
{
  std::cout << side1 << " | " << side2 << " | " << side3;
}

double Triangle::area()
{
  double s = perimeter() / 2.0;
  return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

double RightTriangle::area()
{
  if(side1 * side1 + side2 * side2 == side3 * side3) {
    return side1 * side2;
  }
  if(side1 * side1 + side3 * side3 == side2 * side2) {
    return side1 * side3;
  }
  if(side2 * side2 + side3 * side3 == side1 * side1) {
    return side2 * side3;
  }
}

double RightTriangle::findHypotenuse()
{
  if(side1 * side1 + side2 * side2 == side3 * side3) {
    return side3;
  }
  if(side1 * side1 + side3 * side3 == side2 * side2) {
    return side2;
  }
  if(side2 * side2 + side3 * side3 == side1 * side1) {
    return side1;
  }
}

bool RightTriangle::isRightTriangle()
{
  return (side1 * side1 + side2 * side2 == side3 * side3) ||
    (side1 * side1 + side3 * side3 == side2 * side2) ||
    (side2 * side2 + side3 * side3 == side1 * side1);
}