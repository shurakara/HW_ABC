#pragma once

#include <fstream>

class Shape
{
protected:
    // плотность фигуры
    double Density;
    // объем фигуры
    double Volume;

public:
    // базовый конструктор с плотностью фигуры
    explicit Shape(double density);

    // Ввод обобщенной фигуры
    static Shape *In(std::ifstream &ifdt);

    // Случайный ввод обобщенной фигуры
    static Shape *InRnd();

    // свойство получения объема
    double GetVolume();

    // метод вывода данных
    virtual std::ostream& print(std::ostream& out);
};

