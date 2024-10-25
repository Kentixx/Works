#include <iostream>
#include <vector>
#include <cstring>
#include "header.h"
using namespace std;

template <typename T> // шаблоны исп-ся для того, чтобы один и тот же набор команд исп-ть с разными типами данных
int sum(T a, int b) { 
    return a + b;
}

template <typename T> 
T sum2(T a, T b) { 
    return a + b;
}

//  спецификация шаблона sum2:
template<>
const char* sum2<const char*>(const char* a, const char* b) {
    int len = strlen(a) + strlen(b)  + 1;
    char *str = new char[len];
    strcpy(str, a);
    strcpy(str, b);
    return str;
}
/* зачем это нужно? мы не можем использовать операцию + с типом const char*,
поэтому мы хотим написать отдельную реализацию шаблона sum2 для случая с типом const char* */

template <typename T> 
const T &sum3(const T &a, const T &b) {  // так тоже можно (как с обычными функциями)
    return a + b;
}

template <typename T> 
T *sum4(T *a, T *b) {  // так тоже можно (аргументы это указатели)
    return *a + *b;
}

template <typename T1, typename T2, typename T3> 
T3 sum5(T1 a, T2 b) { 
    return a + b;
}


int main() {
    // templates
    cout << sum(1, 2) << endl; 

    cout << sum(1.9, 2) << endl; // будет 3 (преобразованіе в int)

    //cout << sum(1, 2) << endl; - ошибка (нельзя сложить строку и число)

    std::string str1 = "hello";
    std::string str2 = " world";
    cout << sum2(str1, str2) << endl;

    int i(4);
    double j(3.7);
    // cout << sum5(i, j) << endl; - ошибка, так как Т3 не определен
    cout << sum5<int, double, int>(i, j) << endl; //в угловых скобках можно явно определить типы из template 
    // это используется, когда компилятор сам не может подставить какой-то тип

    //нужно быть внимательным с преобразованиями типов (они будут неявными при несоответствии типов в < > с типами фактическими)
    
    std::vector<int> v(4); // вектор - это шаблон!


    // многомодульный проект

    /*  для создания многомодульного проекта в той же папке, где наша основная программа (эта), создаем файл с расширением .h - так называемый заголовочник
    подключаем его в основной файл через директиву #include "header.h" (у меня тут сверху прописано) -  там будут объявлены функции
    потом создаём файл header.cpp (название должно совпадать с заголовочником)  - там будут реализованы функции, объявленные в заголовнике.
    в header.cpp также пропишем #include "header.h"
    */

 
    cout << globalA << endl;
    cout << dif(4,5) << endl;
    cout << B + globalA;

    // в идеале в основном файле не должно быть подключено никаких библиотек, кроме твоего заголовочника. у меня плохой пример, так как я здесь же
    // работала с шаблонами. в идеале у тебя шаблоны объявлены и реализованы в заголовочнике. 

    //также в main() в идеале должен быть только вызов функций, которые ты объявила и реализовала в header.h и header.cpp и минимум какого-либо другого кода

}