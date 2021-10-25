#pragma once

#include <fstream>
#include "Shape.h"

using namespace std;

class regularTetrahedron : public Shape
{
private:
    // сторона тетраэдра
    int A;
public:
    // создание по заданной стороне
    regularTetrahedron(int A, double density);

    // создание рандомного
    explicit regularTetrahedron(double density);

    // метод вывода данных
    virtual std::ostream& print(std::ostream& out);
};
