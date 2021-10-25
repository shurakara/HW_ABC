#include "regularTetrahedron.h"
#include "rnd.h"
#include <cmath>

// создание по заданной стороне
regularTetrahedron::regularTetrahedron(int A, double density) : Shape(density) {
    this->A = A;
    Volume = sqrt(2) * pow(A, 3) / 12;
}

// создание рандомного
regularTetrahedron::regularTetrahedron(double density) : Shape(density) {
    A = Random(100);
    Volume = sqrt(2) * pow(A, 3) / 12;
}

std::ostream &regularTetrahedron::print(std::ostream &out) {
    return out << "It is regular tetrahedron: A = " << A
               << ", Density = " << Density << ", Volume = " << Volume << "\n";
}
