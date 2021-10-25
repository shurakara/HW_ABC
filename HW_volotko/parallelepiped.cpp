#include "parallelepiped.h"
#include "rnd.h"

// создание по заданным сторонам
parallelepiped::parallelepiped(int a, int b, int c, double density) : Shape(density){
    A = a;
    B = b;
    C = c;
    Volume = A*B*C;
}

// создание рандомного
parallelepiped::parallelepiped(double density) : Shape(density){
    A = Random(100);
    B = Random(100);
    C = Random(100);
    Volume = A*B*C;
}

// метод вывода данных
std::ostream &parallelepiped::print(std::ostream &out) {
    return out << "It is parallelepiped: A = " << A << ", B = " << B
               << ", C = " << C << ", Density = " << Density << ", Volume = " << Volume << "\n";
}
