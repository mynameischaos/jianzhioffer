#include <iostream>

using namespace std;

double PowerWithUnsignedExponent(double base, unsigned int exponent) {
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if (exponent & 0x1 == 1)
        result *= base;

    return result;
}

bool g_InvalidInput = false;

double Power(double base, int exponent) {
    g_InvalidInput = false;

    if ((base - 0.0) < 0.00001 && exponent < 0) {
        g_InvalidInput = true;
        return 0.0;
    }
    unsigned  int absExponent = (unsigned int)abs(exponent);

    double result = PowerWithUnsignedExponent(base, absExponent);
    if (exponent < 0) {
        result = 1.0 / result;
    }
    return result;
}


int main() {
    cout << Power(2, 10) << endl;
    return 0;
}