package laba2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Point {
    private double x;
    private double y;

    public Point() {
        this.x = 0;
        this.y = 0;
    }

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }
}

class Quadrilateral {
    private Point[] vertex = new Point[4];

    public Quadrilateral(Point v1, Point v2, Point v3, Point v4) {
        this.vertex[0] = v1;
        this.vertex[1] = v2;
        this.vertex[2] = v3;
        this.vertex[3] = v4;
    }

    public double triangleArea(Point p1, Point p2, Point p3) {
        double a, b, c;
        a = length(p1, p2);
        b = length(p2, p3);
        c = length(p1, p3);
        double p = (a + b + c) / 2;
        return Math.sqrt(p * (p - a) * (p - b) * (p - c));
    }

    public double area() {
        double area1 = triangleArea(vertex[0], vertex[1], vertex[2]);
        double area2 = triangleArea(vertex[0], vertex[2], vertex[3]);

        return area1 + area2;
    }

    public double perimeter() {
        double perimeter = 0;
        for (int i = 0; i < 4; ++i) {
            int next = (i + 1) % 4;
            perimeter += Math.sqrt(Math.pow(vertex[i].getX() - vertex[next].getX(), 2)
                    + Math.pow(vertex[i].getY() - vertex[next].getY(), 2));
        }
        return perimeter;
    }

    public double length(Point p1, Point p2) {
        return Math.sqrt(Math.pow(p1.getX() - p2.getX(), 2) + Math.pow(p1.getY() - p2.getY(), 2));
    }

    public double getCos(Point p1, Point p2, Point p3) {
        double a = length(p1, p2);
        double b = length(p2, p3);
        double c = length(p1, p3);
        return (a * a + b * b - c * c) / (2 * a * b);
    }

    public String getType() {
        boolean straight = false;
        double[] lengths = new double[4];
        for (int i = 0; i < 4; ++i) {
            int next = (i + 1) % 4;
            lengths[i] = length(vertex[i], vertex[next]);
        }

        double[] angles = new double[2];
        double cos_of_angle = getCos(vertex[3], vertex[0], vertex[1]);
        if (cos_of_angle < 0.000001)
            angles[0] = 0;
        else
            angles[0] = cos_of_angle;

        cos_of_angle = getCos(vertex[1], vertex[2], vertex[3]);
        if (cos_of_angle < 0.000001)
            angles[1] = 0;
        else
            angles[0] = cos_of_angle;

        if ((angles[0] == 0) && (angles[1] == 0))
            straight = true;

        List<Double> list = new ArrayList<>();
        for (double length : lengths) {
            list.add(length);
        }
        Collections.sort(list);

        if (list.get(0).equals(list.get(3))) {
            if (straight)
                return "Square";
            else
                return "Rhombus";
        }
        if (list.get(0).equals(list.get(1)) && list.get(2).equals(list.get(3)) && straight)
            return "Rectangle";
        return "Quadrilateral";
    }

    public String toString() {
        return "Quadrilateral: {" + vertex[0].toString() + ", " + vertex[1].toString() + ", " + vertex[2].toString()
                + ", " + vertex[3].toString() + "}";
    }
}

public class main {
    public static void main(String[] args) {
        List<Quadrilateral> quadrilaterals = new ArrayList<>();

        quadrilaterals.add(new Quadrilateral(new Point(0, 0), new Point(0, 4), new Point(6, 4), new Point(6, 0))); // Rectangle
        quadrilaterals.add(new Quadrilateral(new Point(0, 0), new Point(0, 5), new Point(6, 5), new Point(6, 0))); // Rectangle
        quadrilaterals.add(new Quadrilateral(new Point(0, 0), new Point(0, 5), new Point(5, 5), new Point(5, 0))); // Square
        quadrilaterals.add(new Quadrilateral(new Point(0, 0), new Point(2, 4), new Point(4, 0), new Point(2, 4))); // Rhombus
        quadrilaterals.add(new Quadrilateral(new Point(0, 3), new Point(3, 4), new Point(4, 10), new Point(10, 0))); // Quadrilateral
        quadrilaterals.add(new Quadrilateral(new Point(0, 8), new Point(8, 10), new Point(10, 5), new Point(5, 0))); // Quadrilateral

        for (Quadrilateral quad : quadrilaterals) {
            outputObjInfo(quad);
        }

        // Count the number of different types of quadrilaterals
        int squareCount = 0, rectangleCount = 0, rhombusCount = 0, quadrilateralCount = 0;
        for (Quadrilateral quad : quadrilaterals) {
            String type = quad.getType();
            switch (type) {
                case "Square":
                    squareCount++;
                    break;
                case "Rectangle":
                    rectangleCount++;
                    break;
                case "Rhombus":
                    rhombusCount++;
                    break;
                default:
                    quadrilateralCount++;
                    break;
            }
        }

        // Finding the largest and smallest objects by area for each group
        Quadrilateral maxSquare = null, minSquare = null, maxRectangle = null, minRectangle = null, maxRhombus = null,
                minRhombus = null, maxQuadrilateral = null, minQuadrilateral = null;
        boolean firstSquare = true, firstRectangle = true, firstRhombus = true, firstQuadrilateral = true;
        for (Quadrilateral quad : quadrilaterals) {
            String type = quad.getType();
            switch (type) {
                case "Square":
                    if (firstSquare || quad.area() > maxSquare.area()) {
                        maxSquare = quad;
                    }
                    if (firstSquare || quad.area() < minSquare.area()) {
                        minSquare = quad;
                        firstSquare = false;
                    }
                    break;
                case "Rectangle":
                    if (firstRectangle || quad.area() > maxRectangle.area()) {
                        maxRectangle = quad;
                    }
                    if (firstRectangle || quad.area() < minRectangle.area()) {
                        minRectangle = quad;
                        firstRectangle = false;
                    }
                    break;
                case "Rhombus":
                    if (firstRhombus || quad.area() > maxRhombus.area()) {
                        maxRhombus = quad;
                    }
                    if (firstRhombus || quad.area() < minRhombus.area()) {
                        minRhombus = quad;
                        firstRhombus = false;
                    }
                    break;
                default:
                    if (firstQuadrilateral || quad.area() > maxQuadrilateral.area()) {
                        maxQuadrilateral = quad;
                    }
                    if (firstQuadrilateral || quad.area() < minQuadrilateral.area()) {
                        minQuadrilateral = quad;
                        firstQuadrilateral = false;
                    }
                    break;
            }
        }

        // Output information
        System.out.println("Square count: " + squareCount);
        System.out.println("Rectangle count: " + rectangleCount);
        System.out.println("Rhombus count: " + rhombusCount);
        System.out.println("Quadrilateral count: " + quadrilateralCount);
        System.out.println("\n\n\n");

        System.out.println("Max square area: " + maxSquare.area());
        System.out.println("Min square area: " + minSquare.area());
        System.out.println("\n");

        System.out.println("Max rectangle area: " + maxRectangle.area());
        System.out.println("Min rectangle area: " + minRectangle.area());
        System.out.println("\n");

        System.out.println("Max rhombus area: " + maxRhombus.area());
        System.out.println("Min rhombus area: " + minRhombus.area());
        System.out.println("\n");

        System.out.println("Max quadrilateral area: " + maxQuadrilateral.area());
        System.out.println("Min quadrilateral area: " + minQuadrilateral.area());
        System.out.println("\n");
    }

    public static void outputObjInfo(Quadrilateral quad) {
        System.out.println("Area: " + quad.area());
        System.out.println("Perimeter: " + quad.perimeter());
        System.out.println("Type: " + quad.getType());
        System.out.println("Description: " + quad.toString());
        System.out.println("\n\n\n");
    }
}
