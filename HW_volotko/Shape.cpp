#include "Shape.h"
#include "rnd.h"
#include "sphere.h"
#include "regularTetrahedron.h"
#include "parallelepiped.h"

// базовый конструктор с плотностью фигуры
Shape::Shape(double density) {
    Density = density;
}

// Ввод обобщенной фигуры
Shape *Shape::In(ifstream &ifdt) {
    int k;
    ifdt >> k;
    switch(k) {
        case 1:
        {
            int r, d;
            ifdt >> r >> d;
            auto *s = new sphere(r,d);
            return dynamic_cast<Shape *>(s);
        }
        case 2:
        {
            int a, d;
            ifdt >> a >> d;
            auto *t = new regularTetrahedron(a, d);
            return dynamic_cast<Shape *>(t);
        }
        case 3:
        {
            int a, b, c, d;
            ifdt >> a >> b >> c >> d;
            auto *p = new parallelepiped(a, b, c, d);
            return dynamic_cast<Shape *>(p);
        }
        default:
            return nullptr;
    }
}

// Случайный ввод обобщенной фигуры
Shape *Shape::InRnd() {
    int d;
    d = Random(100);
    auto k = Random(3);
    switch(k) {
        case 1:
        {
            auto *s = new sphere(d);
            return dynamic_cast<Shape *>(s);
        }
        case 2:
        {
            auto *t = new regularTetrahedron(d);
            return dynamic_cast<Shape *>(t);
        }
        case 3:
        {
            auto *p = new parallelepiped(d);
            return dynamic_cast<Shape *>(p);
        }
        default:
            return nullptr;
    }
}

// метод вывода данных
ostream &Shape::print(ostream &out) {
    return out;
}

// свойство получения объема
double Shape::GetVolume() {
    return Volume;
}
