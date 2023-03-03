#include <stdio.h>
#include <math.h>

double f( double x );
double RootOfFunction( double xl, double xr, double epsilon );

int main() {
    double root;
    root = RootOfFunction(-1, 10, 0.1);
    printf("Root = %.1f", root);
    return 0;
}

double f( double x ) {
    return 2 * x - 5;
}

double RootOfFunction( double xl, double xr, double epsilon ) {
    double xm;
    do {
        xm = (xl + xr) / 2;
        if (f(xm) == 0) {
            return xm;
        } else if (f(xl) * f(xm) < 0) {
            xr = xm;
        } else {
            xl = xm;
        }
    } while (fabs(xr - xl) >= epsilon);
    return xm;
}

