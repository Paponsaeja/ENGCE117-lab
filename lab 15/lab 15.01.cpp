#include <stdio.h>
#include <math.h>

double f(double x);
double RootOfFunction(double xl, double xr, double epsilon);

int main() {
    double root;
    root = RootOfFunction(-1, 10, 0.1);
    printf("Root = %.1f\n", root);
    return 0;
}

double f(double x) {
    return 2 * x - 5;
}

double RootOfFunction(double xl, double xr, double epsilon) {
    double fxl = f(xl);
    double fxr = f(xr);
    double xm, fxm;
    int iter = 1;
    while (fabs(xr - xl) > epsilon) {
        xm = (xl + xr) / 2;
        fxm = f(xm);
        printf("%.1f %.1f %.1f\n", xl, xm, xr);
        if (fxm == 0) {
            return xm;
        }
        else if (fxm * fxl < 0) {
            xr = xm;
            fxr = fxm;
        }
        else {
            xl = xm;
            fxl = fxm;
        }
        printf("%.1f %.1f %.1f\n", xl, xm, xr);
        iter++;
    }
    printf("%.1f %.1f %.1f\n", xl, xm, xr);
    return (xl + xr) / 2;
}

