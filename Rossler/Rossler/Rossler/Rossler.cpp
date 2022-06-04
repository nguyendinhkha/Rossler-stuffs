#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;
#define N 1000

// a = 0.2, b = 0.2 and c = 5.7 . "a" was chosen as the bifurcation parameter
// properties of a = 0.1, b = 0.1, and c = 14 have been more commonly used

int main()
{
    random_device random;
    mt19937 rng(random());
    uniform_int_distribution<int> uni(-10, 15);
    auto x0 = uni(rng);

    uniform_int_distribution<int> cast(-20, 10);
    auto y0 = cast(rng);

    uniform_int_distribution<int> inter(0, 25);
    auto z0 = inter(rng);

    double dt = 0.002; 
    double dx, dy, dz;

    float a = 0.2;  // standard parameter value selected by Rossler
    float b = 0.2;
    float c = 5.7;

    double x, y, z; // strange attractor with unidentified variables
    x = x0;
    y = y0;
    z = z0;
    
    for (int i = 0; i < N; i++) 
    {
        // 3 coupled non-linear differential equations: 
        dx = x + (-y - z) * dt;
        dy = y + (x + a * y) * dt;
        dz = z + (b + z * (x - c)) * dt;
        x = dx;
        y = dy;
        z = dz;

        cout << i << "  " << x << "  " << y << "  " << z << endl;
    }
    return 0;
}
