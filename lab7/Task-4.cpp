#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};
class Quadrilateral {
private:
    Point points[4];
    double distance(const Point& p1, const Point& p2) const {
        return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    }
    double crossProduct(const Point& p1, const Point& p2, const Point& p3) const {
        return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    }
public:
    Quadrilateral(const Point& a, const Point& b, const Point& c, const Point& d) {
        points[0] = a;
        points[1] = b;
        points[2] = c;
        points[3] = d;
    }
    bool isValid() const {
        double cp1 = crossProduct(points[0], points[1], points[2]);
        double cp2 = crossProduct(points[1], points[2], points[3]);
        double cp3 = crossProduct(points[2], points[3], points[0]);
        double cp4 = crossProduct(points[3], points[0], points[1]);
        return (cp1 != 0 || cp2 != 0 || cp3 != 0 || cp4 != 0) && (cp1 * cp2 < 0 && cp3 * cp4 < 0);
    }
    double sideLength(int index) const {
        return distance(points[index], points[(index + 1) % 4]);
    }
    double diagonalLength(int index) const {
        return distance(points[index], points[(index + 2) % 4]);
    }
    double per() const {
        double p = 0;
        for (int i = 0; i < 4; ++i) {
            p += sideLength(i);
        }
        return p;
    }
    double area() const {
        double s1 = sideLength(0);
        double s2 = sideLength(1);
        double s3 = sideLength(2);
        double s4 = sideLength(3);
        double diag1 = diagonalLength(0);
        double diag2 = diagonalLength(1);
        double semiPer = per() / 2;
        return sqrt((semiPer - s1) * (semiPer - s2) * (semiPer - s3) * (semiPer - s4) - 
                    0.25 * (diag1 * diag2) * (diag1 * diag2));
    }
    bool isParallelogram() const {
        double s1 = sideLength(0);
        double s2 = sideLength(1);
        double s3 = sideLength(2);
        double s4 = sideLength(3);
        double diag1 = diagonalLength(0);
        double diag2 = diagonalLength(1);
        return (s1 == s3 && s2 == s4 && (diag1 * diag1 + diag2 * diag2) == 2 * (s1 * s1 + s2 * s2));
    }
    void displayInfo() const {
        cout << "Стороны: ";
        for (int i = 0; i < 4; ++i) {
            cout << sideLength(i) << " ";
        }
        cout << "\nДиагонали: " << diagonalLength(0) << ", " << diagonalLength(1);
        cout << "\nПериметр: " << perimeter();
        cout << "\nПлощадь: " << area();
        cout << "\nПараллелограмм: " << (isParallelogram() ? "Да" : "Нет") << endl;
    }
};
int main() {
	setlocale (LC_ALL, "Russian");
    int N;
    cout << "Введите количество четырехугольников: ";
    cin >> N;
    double totalArea = 0;
    for (int i = 0; i < N; ++i) {
        Point a, b, c, d;
        cout << "Введите координаты точек A, B, C, D для четырехугольника " << i + 1 << ": ";
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        
        Quadrilateral quad(a, b, c, d);
        if (quad.isValid()) {
            totalArea += quad.area();
            quad.displayInfo();
        } else {
            cout << "Четырехугольник не существует." << endl;
        }
    }
    double averageArea = (N > 0) ? (totalArea / N) : 0;
    cout << "Средняя площадь: " << averageArea << endl;
    return 0;
}


