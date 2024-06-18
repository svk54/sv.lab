#include <iostream>
using namespace std;

class Circle {
private:
    double R; 
public:
    Circle() : R(0) {}
    Circle(double radius) : R(radius) {}
    ~Circle() {}
    double square() const {
        return 3.14159265358979323846 * R * R;
    }
    double dlina() const {
        return 2 * 3.14159265358979323846 * R;
    }
    void Info() const {
        cout << "Радиус: " << R << ", Площадь: " << square() << ", Длина окружности: " << dlina() << endl;
    }
    double getRadius() const {
        return R;
    }
};
int main() {
	setlocale (LC_ALL, "Russian");
    int N;
    cout << "Введите количество окружностей: ";
    cin >> N;
    Circle* circles = new Circle[N];
    double radius, maxsquare = 0;
    int maxsq = -1;

    for (int i = 0; i < N; ++i) {
        cout << "Введите радиус окружности " << i + 1 << ": ";
        cin >> radius;
        circles[i] = Circle(radius);

        double square1 = circles[i].square();
        if (square1 > maxsquare) {
            maxsquare = square1;
            maxsq = i;
        }
    }
    if (maxsq != -1) {
        cout << "Окружность с максимальной площадью:" << endl;
        circles[maxsq].Info();
    } 
    delete[] circles;
    return 0;
}



