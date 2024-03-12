#pragma once

class Triangle {
protected:
  int side1;
  int side2;
  int side3;

public:
  Triangle(int a, int b, int c) : side1(a), side2(b), side3(c) {}
  void viewInfo();
  bool isValid();
  int perimeter();
  virtual double area();
};

class RightTriangle : public Triangle {
public:
  RightTriangle(int a, int b, int c) : Triangle(a, b, c) {}
  double area() override;
  bool isRightTriangle();
  double findHypotenuse();
};