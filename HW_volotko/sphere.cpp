#include "sphere.h"
#include "rnd.h"
#include <cmath>

// создание по заданному радиусу
sphere::sphere(int R, double density) : Shape(density) {
    this->R = R;
    Volume = pow(R, 3) * M_PI * 4 / 3;
}

// создание рандомного
sphere::sphere(double density) : Shape(density) {
    R = Random(100);
    Volume = pow(R, 3) * M_PI * 4 / 3;
}

// метод вывода данных
std::ostream &sphere::print(std::ostream &out) {
    return out << "It is sphere: R = " << R << ", Density = " << Density
               << ", Volume = " << Volume << "\n";
}
