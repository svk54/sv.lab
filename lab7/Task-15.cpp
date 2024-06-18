#include <iostream>
#include <cmath>

using namespace std;

class Tree {
private:
    double side1, side2, side3;
public:
    Tree(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}
    ~Tree() {}
    bool check() {
        return (side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1);
    }
    bool rside() {
        return (side1 == side2) && (side2 == side3);
    }
    double Per() {
        return side1 + side2 + side3;
    }
    double Square() {
        double s = Per() / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    void Info() {
        cout << "Стороны треугольника: " << side1 << ", " << side2 << ", " << side3 << endl;
        if (rside()) {
            cout << "Треугольник равносторонний." << endl;
        }
        cout << "Периметр треугольника: " << Per() << endl;
        cout << "Площадь треугольника: " << Square() << endl;
    }
};
int main() {
	setlocale (LC_ALL, "Russian");
    int N;
    cout << "Введите количество треугольников: ";
    cin >> N;
    double minPer = 1e308;
    double Square1 = 0;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        double s1, s2, s3;
        cout << "Введите длины сторон треугольника " << i + 1 << ": ";
        cin >> s1 >> s2 >> s3;
        Tree tree(s1, s2, s3);
        if (tree.check()) {
            tree.Info();
            double per = tree.Per();
            if (per < minPer) {
                minPer = per;
            }
            Square1 += tree.Square();
            ++count;
        } else {
            cout << "Треугольник с такими сторонами не существует." << endl;
        }
    }
    double avgSquare = (count > 0) ? (Square1 / count) : 0;
    cout << "Средняя площадь треугольников: " << avgSquare << endl;
    cout << "Минимальный периметр среди треугольников: " << minPer << endl;
    return 0;
}
