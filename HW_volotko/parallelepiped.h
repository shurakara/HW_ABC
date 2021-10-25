#pragma once

#include <fstream>
#include "Shape.h"

using namespace std;

class parallelepiped : public Shape
{
private:
    // стороны параллелепипеда
    int A;
    int B;
    int C;
public:
    // создание по заданным сторонам
    parallelepiped(int a, int b, int c, double density);

    // создание рандомного
    explicit parallelepiped(double density);

    // метод вывода данных
    virtual std::ostream& print(std::ostream& out);
};


