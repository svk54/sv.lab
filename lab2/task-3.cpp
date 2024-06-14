#include<iostream>
#include<math.h>
#include<locale.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    float E, y, S;
    cout << "Циклический алгоритм\n";
    cout << "Введите точность Е"; cin >> E;
    n = 1;
    S = 0;
    y = 1.5;
    while (y >= E);
    {
        y = (n + 5) / (pow(2, n) + 2);
        S = S + y;
        n = n + 1;
    } 
    printf("S= %f\n", S);
    return 0;
}
