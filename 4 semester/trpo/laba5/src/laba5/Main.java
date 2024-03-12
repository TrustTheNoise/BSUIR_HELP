package laba5;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Задаем отрезки на плоскости
        LineSegment s1 = new LineSegment(1, 2, 3, 4);
        LineSegment s2 = new LineSegment(2, 3, 5, 7);
        LineSegment s3 = new LineSegment(4, 5, 6, 8);
        LineSegment s4 = new LineSegment(5, 6, 7, 9);

        // Добавляем отрезки в TreeMap
        TreeMap<Double, List<LineSegment>> map = new TreeMap<>();
        addIntersectionPoint(map, s1, s2);
        addIntersectionPoint(map, s1, s3);
        addIntersectionPoint(map, s1, s4);
        addIntersectionPoint(map, s2, s3);
        addIntersectionPoint(map, s2, s4);
        addIntersectionPoint(map, s3, s4);

        // Находим точку пересечения с минимальной абсциссой
        Double minX = map.firstKey();
        List<LineSegment> segments = map.get(minX);

        // Выводим результат
        System.out.println("Minimal intersection point: (" + minX + ", " + calculateY(segments.get(0), segments.get(1), minX) + ")");
    }

    // Метод для добавления точки пересечения двух отрезков в TreeMap
    private static void addIntersectionPoint(TreeMap<Double, List<LineSegment>> map, LineSegment s1, LineSegment s2) {
        double x = calculateX(s1, s2);
        if (x != Double.POSITIVE_INFINITY) {
            List<LineSegment> segments = map.getOrDefault(x, new ArrayList<>());
            segments.add(s1);
            segments.add(s2);
            map.put(x, segments);
        }
    }

    // Метод для расчета абсциссы точки пересечения двух отрезков
    private static double calculateX(LineSegment s1, LineSegment s2) {
        double m1 = (s1.y2 - s1.y1) / (s1.x2 - s1.x1);
        double m2 = (s2.y2 - s2.y1) / (s2.x2 - s2.x1);
        if (m1 == m2) {
            return Double.POSITIVE_INFINITY;
        }
        double x = (s1.x1 * m2 - s2.x1 * m1 + s2.y1 - s1.y1) / (m2 - m1);
        return x;
    }

    // Метод для расчета ординаты точки пересечения двух отрезков по абсциссе
    private static double calculateY(LineSegment s1, LineSegment s2, double x) {
        double m1 = (s1.y2 - s1.y1) / (s1.x2 - s1.x1);
        double y = m1 * (x - s1.x1) + s1.y1;
        return y;
    }

    // Класс для представления отрезка на плоскости
    private static class LineSegment {
        double x1, y1, x2, y2;

        public LineSegment(double x1, double y1, double x2, double y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }
    }
}
