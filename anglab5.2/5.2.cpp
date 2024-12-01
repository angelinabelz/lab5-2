#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void calculateSeries(const double x, const double eps, int& n, double& s);
void calculateTerm(const double x, const int n, double& term);

int main() {
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(10) << "log(x)" << " |"
        << setw(10) << "S" << " |"
        << setw(5) << "n" << " |" << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk) {
        calculateSeries(x, eps, n, s);
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << log((x + 1) / (x - 1)) << " |"
            << setw(10) << setprecision(5) << s << " |"
            << setw(5) << n << " |" << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}

void calculateSeries(const double x, const double eps, int& n, double& s) {
    n = 0;
    double term = 2.0 / (x * (2 * n + 1));
    s = term;

    do {
        n++;
        calculateTerm(x, n, term);
        s += term;
    } while (abs(term) >= eps);
}

void calculateTerm(const double x, const int n, double& term) {
    double ratio = -1.0 / (x * x) * (2 * n - 1) / (2 * n + 1);
    term *= ratio;
}
