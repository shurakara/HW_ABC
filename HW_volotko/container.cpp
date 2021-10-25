#include "container.h"

container::container() {
    cont = new Shape *[10000];
}

// заполнение контейнера
void container::In(std::ifstream &ifst) {
    while(!ifst.eof()) {
        Shape *sp = Shape::In(ifst);
        if(sp != nullptr){
            cont[len] = sp;
            len++;
        }
    }
}

// рандомное заполнение контейнера
void container::InRnd(int size) {
    while(len < size) {
        if((cont[len] = Shape::InRnd()) != nullptr) {
            len++;
        }
    }
}

// шейкерная сортировка
void container::ShakerSort() const {
    int left = 0;
    int right = len - 1;
    int add = right;
    while (left < right)
    {
        for (int i = left; i < right; i++) {
            if (cont[i]->GetVolume() > cont[i + 1]->GetVolume()) {
                Shape *a = cont[i + 1];
                cont[i + 1] = cont[i];
                cont[i] = a;
                add = i;
            }
        }
        right = add;

        for (int i = right; i > left; i--){
            if (cont[i]->GetVolume() < cont[i - 1]->GetVolume()){
                Shape *a = cont[i - 1];
                cont[i - 1] = cont[i];
                cont[i] = a;
                add = i;
            }
        }
        left = add;
    }
}

// переопределение << для вывода контейнера
std::ostream &operator<<(std::ostream &out, container &c) {
    out << "Filled container:\n" << "Container contains " << c.len << " elements.\n";
    for (int i = 0; i < c.len; ++i) {
        out << i << ": ";
        c.cont[i]->print(out);
    }
    return out;
}

container::~container(){
    for (int i = 0; i < len; ++i) {
        delete cont[i];
    }
    len = 0;
}
