#pragma once

#include "Shape.h"
#include <fstream>

class container {
protected:
    int len = 0; // текущая длина

public:
    // массив фигур
    Shape **cont;

    container();

    // заполнение контейнера
    void In(std::ifstream &ifst);

    // рандомное заполнение контейнера
    void InRnd(int size);

    // шейкерная сортировка
    void ShakerSort() const;

    // переопределение << для вывода контейнера
    friend std::ostream& operator<<(std::ostream &out, container &c);

    ~container();
};
