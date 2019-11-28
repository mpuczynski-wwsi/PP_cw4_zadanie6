#include<cstdio>
#include <iostream>

using namespace std;

typedef double (*vFunctionCall)(double args);

double f1(double x) {
	return x * x;
}

double f2(double x) {
	return f1(x) * x;
}

double f3(double x) {
	return f2(x) - 3 * f1(x) + x + 5;
}

double oblicz_calke(vFunctionCall f, double a, double b) {
	double dx = 0.01;
	int n = (b - a) / dx;
	double calka = 0;
	for (int i = 0; i < n; i++) {
		double kawalek = (f(a + i * dx) + f(a + (i + 1) * dx)) * dx / 2;
		calka += kawalek;
	}
	return calka;
}

int main() {
	double c1 = oblicz_calke(f1, 1, 5);
	cout << "Calka dla funkcji f(x) = x^2 w przedziale [1,5]: " << c1 << "\n";

	double c2 = oblicz_calke(f2, -10, 15);
	cout << "Calka dla funkcji f(x) = x^3 w przedziale [-10,15]: " << c2 << "\n";

	double c3 = oblicz_calke(f3, -1, 4);
	cout << "Calka dla funkcji f(x) = x^2 w przedziale [-1,4]: " << c3 << "\n";
}
