#include <iostream>
#include <cmath>

using namespace std;

class Tree {
private:
double side1, side2, side3;
public:
Tree(double s1, double s2, double s3) {
side1 = s1;
side2 = s2;
side3 = s3;
}
~Tree() {}
bool CheckTree() {
    if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
        return true;
    }
    return false;
}
double Per() {
    return side1 + side2 + side3;
}
double Square() {
    double p = Per() / 2;
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}
void Info() {
    cout << "Стороны: " << side1 << ", " << side2 << ", " << side3 << endl;
    cout << "Периметр: " << Per() << endl;
    cout << "Площадь: " << Square() << endl;
}
bool bedr() {
    if (side1 == side2 || side1 == side3 || side2 == side3) {
        return true;
    }
    return false;
}
double findangle() {
    double maxAngle = 0;
    double angles[3];
    angles[0] = acos((side1*side1 + side2*side2 - side3*side3) / (2 * side1 * side2)) * 180 / M_PI;
    angles[1] = acos((side1*side1 + side3*side3 - side2*side2) / (2 * side1 * side3)) * 180 / M_PI;
    angles[2] = acos((side2*side2 + side3*side3 - side1*side1) / (2 * side2 * side3)) * 180 / M_PI;
    for(int i = 0; i < 3; i++) {
        if(angles[i] > maxAngle) {
            maxAngle = angles[i];
        }
    }
    return maxAngle;
}
};

int main() {
setlocale (LC_ALL, "Russian");
int N;
cout << "Введите количество треугольников:";
cin >> N;
Treyg *Treey[N];
double maxAngle = 0;
int maxAngles = -1;
for (int i = 0; i < N; i++) {
    double s1, s2, s3;
    cout << "Введите стороны треугольника " << i+1 << ": ";
    cin >> s1 >> s2 >> s3;
    Tree Treetemp(s1, s2, s3);
    Tree[i] = &Treetemp;

    if (Treetemp.CheckTree()) {
        Treetemp.Info();
        cout << "Является равнобедренным: " << (Treetemp.bedr() ? "Да" : "Нет") << endl;

        double angle = Treetemp.findangle();
        if (angle > maxAngle) {
            maxAngle = angle;
            maxAngles = i;
        }
    } else {
        cout << "Треугольника не существует!" << endl;
    }
}
if (maxAngles != -1) {
    cout << "Треугольник с максимальным тупым углом: ";
    Treygs[maxAngles]->Info();
} else {
    cout << "Допустимых треугольников не найдено." << endl;
}
return 0;
}