#pragma once

#include <fstream>
#include "Shape.h"

using namespace std;

class sphere : public Shape
{
private:
    int R;

public:
    // создание по заданному радиусу
    sphere(int R, double density);

    // создание рандомного
    explicit sphere(double density);

    // метод вывода данных
    virtual std::ostream& print(std::ostream& out) override;
};
