#include <iostream>
#include <cmath>

using namespace std;

class Tree {
private:
    double side1, side2, side3;
public:
    Tree(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}
    ~Tree() {}
    bool ThTree() {
        return (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1);
    }
    double Per() {
        return side1 + side2 + side3;
    }
    double Square() {
        double s = Per() / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    bool PmTree() {
        return (pow(side1, 2) + pow(side2, 2) == pow(side3, 2) ||
                pow(side1, 2) + pow(side3, 2) == pow(side2, 2) ||
                pow(side2, 2) + pow(side3, 2) == pow(side1, 2));
    }
    void Info() {
        cout << "Стороны: " << side1 << ", " << side2 << ", " << side3 << endl;
        cout << "Периметр: " << Per() << endl;
        cout << "Площадь: " << Square() << endl;
        cout << "Прямоугольный треугольник? " << (PmTree() ? "Да":"Нет") << endl;
    }
};
int main() {
	setlocale (LC_ALL, "Russian");
    int M;
    cout << "Введите количество треугольников: ";
    cin >> M;
    double Square1 = 0;
    for (int i = 0; i < M; ++i) {
        double s1, s2, s3;
        cout << "Введите стороны треугольника " << i + 1 << ": ";
        cin >> s1 >> s2 >> s3;
        Tree tree(s1, s2, s3);
        if (tree.ThTree()) {
            Square1 += tree.Square();
            cout << "Треугольник " << i + 1 << " информация:" << endl;
            tree.Info();
        } else {
            cout << "Недопустимый треугольник." << endl;
            --i;
        }
    }
    cout << "Средняя площадь " << M << " треугольников: " << Square1 / M << endl;
    return 0;
}