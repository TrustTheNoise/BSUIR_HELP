#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

// 24. Определить класс Четырехугольник на плоскости, вершины которого имеют тип Точка. 
// Определить площадь и периметр четырехугольника. Создать массив / список / множество объектов и
// подсчитать количество четырехугольников разного типа(квадрат, прямоугольник, ромб,
// произвольный).Определить для каждой группы наибольший и наименьший по площади(периметру)
// объект.

class Point {
private:
    double x;
    double y;

public:
    Point(): x(0), y(0) {};
    Point(double x, double y) : x(x), y(y) {}

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    double getX() const { return x; }
    double getY() const { return y; }

    std::string toString() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};

class Quadrilateral {
private:
    Point vertex[4];

public:
    Quadrilateral() {
        vertex[0] = Point(0, 0);
        vertex[1] = Point(0, 0);
        vertex[2] = Point(0, 0);
        vertex[3] = Point(0, 0);
    }
    Quadrilateral(const Point& v1, const Point& v2, const Point& v3, const Point& v4) {
        vertex[0] = v1;
        vertex[1] = v2;
        vertex[2] = v3;
        vertex[3] = v4;
    }

    void setVertex(int index, const Point& v) { vertex[index] = v; }
    Point getVertex(int index) const { return vertex[index]; }

    double triangleArea(const Point& p1, const Point& p2, const Point& p3) const {
        double a, b, c;
        a = length(p1, p2);
        b = length(p2, p3);
        c = length(p1, p3);
        double p = (a + b + c) / 2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }

    double area() const {
        double area1 = triangleArea(vertex[0], vertex[1], vertex[2]);
        double area2 = triangleArea(vertex[0], vertex[2], vertex[3]);

        return area1 + area2;
    }

    double perimeter() const {
        double perimeter = 0;
        for (int i = 0; i < 4; ++i) {
            int next = (i + 1) % 4;
            perimeter += std::sqrt(std::pow(vertex[i].getX() - vertex[next].getX(), 2) +
                std::pow(vertex[i].getY() - vertex[next].getY(), 2));
        }
        return perimeter;
    }

    double length(const Point& p1, const Point& p2) const {
        return std::sqrt(std::pow(p1.getX() - p2.getX(), 2) + std::pow(p1.getY() - p2.getY(), 2));
    }

    double get_cos(const Point& p1, const Point& p2, const Point& p3) const {
        double a = length(p1, p2);
        double b = length(p2, p3);
        double c = length(p1, p3);
        return (a * a + b * b - c * c) / (2 * a * b);
    }

    std::string getType() const {
        bool straight = 0;
        double lengths[4];
        for (int i = 0; i < 4; ++i) {
            int next = (i + 1) % 4;
            lengths[i] = length(vertex[i], vertex[next]);
        }

        double angles[2];
        double cos_of_angle = get_cos(vertex[3], vertex[0], vertex[1]);
        if (cos_of_angle < 0.000001) angles[0] = 0;
        else angles[0] = cos_of_angle;
        
        cos_of_angle = get_cos(vertex[1], vertex[2], vertex[3]);
        if (cos_of_angle < 0.000001) angles[1] = 0;
        else angles[0] = cos_of_angle;

        if ((angles[0] == 0) && (angles[1] == 0)) straight = 1;

        std::sort(lengths, lengths + 4);
        if (lengths[0] == lengths[3]) {
            if (straight)  return "Square";
            else return "Rhombus";
        }
        if ((lengths[0] == lengths[1]) && (lengths[2] == lengths[3]) && straight) return "Rectangle";
        return "Quadrilateral";
    }

    std::string toString() const {
        return "Quadrilateral: {" + vertex[0].toString() + ", " + vertex[1].toString() + ", " +
            vertex[2].toString() + ", " + vertex[3].toString() + "}";
    }
};

void output_obj_info(const Quadrilateral& quad) {
    std::cout << "Area: " << quad.area() << std::endl;
    std::cout << "Perimeter: " << quad.perimeter() << std::endl;
    std::cout << "Type: " << quad.getType() << std::endl;
    std::cout << "Description: " << quad.toString() << std::endl;

    std::cout << "\n\n\n";
}

int main() {
    std::vector<Quadrilateral> quadrilaterals;

    quadrilaterals.push_back(Quadrilateral(Point(0, 0), Point(0, 4), Point(6, 4), Point(6, 0))); // Прямоугольник
    quadrilaterals.push_back(Quadrilateral(Point(0, 0), Point(0, 5), Point(6, 5), Point(6, 0))); // Прямоугольник
    quadrilaterals.push_back(Quadrilateral(Point(0, 0), Point(0, 5), Point(5, 5), Point(5, 0))); // Квадрат
    quadrilaterals.push_back(Quadrilateral(Point(0, 0), Point(2, 4), Point(4, 0), Point(2, 4))); // Ромб
    quadrilaterals.push_back(Quadrilateral(Point(0, 3), Point(3, 4), Point(4, 10), Point(10, 0))); // Произвольный
    quadrilaterals.push_back(Quadrilateral(Point(0, 8), Point(8, 10), Point(10, 5), Point(5, 0))); // Произвольный

    for (int i = 0; i < quadrilaterals.size(); i++) {
        output_obj_info(quadrilaterals[i]);
    }

    // Подсчет количества четырехугольников разного типа
    int squareCount = 0, rectangleCount = 0, rhombusCount = 0, quadrilateralCount = 0;
    for (int i = 0; i < quadrilaterals.size(); i++) {
        std::string type = quadrilaterals[i].getType();
        if (type == "Square") {
            squareCount++;
        }
        else if (type == "Rectangle") {
            rectangleCount++;
        }
        else if (type == "Rhombus") {
            rhombusCount++;
        }
        else {
            quadrilateralCount++;
        }
    }

    // Определение наибольшего и наименьшего по площади объектов для каждой группы
    Quadrilateral maxSquare, minSquare, maxRectangle, minRectangle, maxRhombus, minRhombus, maxQuadrilateral, minQuadrilateral;
    bool firstSquare = true, firstRectangle = true, firstRhombus = true, firstQuadrilateral = true;
    for (int i = 0; i < quadrilaterals.size(); i++) {
        std::string type = quadrilaterals[i].getType();
        if (type == "Square") {
            if (firstSquare || quadrilaterals[i].area() > maxSquare.area()) {
                maxSquare = quadrilaterals[i];
            }
            if (firstSquare || quadrilaterals[i].area() < minSquare.area()) {
                minSquare = quadrilaterals[i];
                firstSquare = false;
            }
        }
        else if (type == "Rectangle") {
            if (firstRectangle || quadrilaterals[i].area() > maxRectangle.area()) {
                maxRectangle = quadrilaterals[i];
            }
            if (firstRectangle || quadrilaterals[i].area() < minRectangle.area()) {
                minRectangle = quadrilaterals[i];
                firstRectangle = false;
            }
        }
        else if (type == "Rhombus") {
            if (firstRhombus || quadrilaterals[i].area() > maxRhombus.area()) {
                maxRhombus = quadrilaterals[i];
            }
            if (firstRhombus || quadrilaterals[i].area() < minRhombus.area()) {
                minRhombus = quadrilaterals[i];
                firstRhombus = false;
            }
        }
        else {
            if (firstQuadrilateral || quadrilaterals[i].area() > maxQuadrilateral.area()) {
                maxQuadrilateral = quadrilaterals[i];
            }
            if (firstQuadrilateral || quadrilaterals[i].area() < minQuadrilateral.area()) {
                minQuadrilateral = quadrilaterals[i];
                firstQuadrilateral = false;
            }
        }
    }

    // Вывод информации
    std::cout << "Square count: " << squareCount << std::endl;
    std::cout << "Rectangle count: " << rectangleCount << std::endl;
    std::cout << "Rhombus count: " << rhombusCount << std::endl;
    std::cout << "Quadrilateral count: " << quadrilateralCount << "\n\n\n";

    std::cout << "Max square area: " << maxSquare.area() << std::endl;
    std::cout << "Min square area: " << minSquare.area() << "\n\n";

    std::cout << "Max rectangle area: " << maxRectangle.area() << std::endl;
    std::cout << "Min rectangle area: " << minRectangle.area() << "\n\n";

    std::cout << "Max rhombus area: " << maxRhombus.area() << std::endl;
    std::cout << "Min rhombus area: " << minRhombus.area() << "\n\n";

    std::cout << "Max quadrilateral area: " << maxQuadrilateral.area() << std::endl;
    std::cout << "Min quadrilateral area: " << minQuadrilateral.area() << "\n\n";

    return 0;
}