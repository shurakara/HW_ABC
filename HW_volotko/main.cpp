#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <cstring>

#include "container.h"

void errMessage1() {
    std::cout << "incorrect command line!\n"
                 "  Waited:\n"
                 "     command -f infile outfile\n"
                 "  Or:\n"
                 "     command -n number outfile\n";
}

void errMessage2() {
    std::cout << "incorrect qualifier value!\n"
                 "  Waited:\n"
                 "     command -f infile outfile1 outfile2\n"
                 "  Or:\n"
                 "     command -n number outfile1 outfile2\n";
}

int main(int argc, char* argv[]) {
    // время начала программы
    unsigned int start = clock();
    // системные часы в качестве инициализатора рандомных чисел
    srand(static_cast<unsigned int>(time(0)));

    // проверка программных аргументов
    if(argc != 5) {
        errMessage1();
        return 1;
    }

    std::cout << "Start"<< std::endl;

    // создание контейнера
    container c;

    if(!strcmp(argv[1], "-f")) {
        // ввод фигур из тестового файла
        std::ifstream ifst(argv[2]);
        c.In(ifst);
    }
    else if(!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) {
            std::cout << "incorrect numer of figures = "
                 << size
                 << ". Set 0 < number <= 10000\n";
            return 3;
        }
        // Заполнение контейнера генератором случайных чисел
        c.InRnd(size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    std::ofstream ofst1(argv[3]);
    ofst1 << c;

    // сортировка данных в контейнере
    c.ShakerSort();

    // вывод отсортированного содержимого контейнера в файл
    std::ofstream ofst2(argv[4]);
    ofst2 << c;

    // отчистка контейнера
    c.~container();
    unsigned int end = clock();
    std::cout << "Stop time: " << end - start << std::endl;
    return 0;
}
