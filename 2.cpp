// Лаба 2, одномерные массивы
// Вариант 13

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    bool isRand{ 0 };
    int r;
    int maxRand, minRand;
    cout << "Использовать датчик случайных чисел? (1/0)" << endl;
    cin >> r;
    if (r == 1) {
        isRand = 1;
        cout << "Введите диапазон чисел (минимум, максимум)" << endl;
        cin >> minRand >> maxRand;
    }
    else if (r > 1 || r < 0) {
        cout << "Некорректный ответ!" << endl;
        return -1;
    }

    const int MAX_VALUE = 50;
    const int MIN_VALUE = 1;
    int n;
    cout << "Размер массива [1; " << MAX_VALUE << "]: ";
    cin >> n;
    if (!(n <= MAX_VALUE && n >= MIN_VALUE)) {
        cout << "Недопустимый размер!" << endl;
        return -1;
    }
    else {
        int* vect = new int[n];
        if (isRand) {
            for (int i = 0; i != n; i++) {
                vect[i] = rand() % (maxRand - minRand + 1) + minRand;
                cout << vect[i] << " ";
            }
        }
        else {
            cout << "Введите элементы массива:" << endl;
            for (int i = 0; i != n; i++) {
                cin >> vect[i];
            }
        }
        cout << endl;
        // }
         // 1. Количество положительных элементов
        int posNumbers = 0;
        for (int i = 0; i != n; i++) {
            if (vect[i] >= 0) {
                posNumbers++;
            }
        }
        cout << "1. Положительных элементов: " << posNumbers << endl;
        // 2. Сумма элементов, расположенных после последнего нуля
        int sum = 0;
        int lastZero = 0;
        for (int i = 0; i != n; i++) {
            if (vect[i] == 0) {
                lastZero = i;
            }
        }
        for (int i = lastZero; i != n; i++) {
            sum += vect[i];
        }
        cout << "2. Сумма элементов после последнего нуля: " << sum << endl;
        // 3. Сортировка положительных и отрицательных элементов
        for (int m = 0; m < n; m++) {
            for (int i = 0; i < n; i++) {
                if (vect[i] > 0) {
                    for (int j = i - 1; j >= 0; j--) {
                        if ((vect[j] > 0) && (vect[j] >= vect[i])) {
                            swap(vect[j], vect[i]);
                            break;
                        }
                    }
                }
            }
        }
        for (int m = n; m > 0; m--) {
            for (int i = n - 1; i >= 0; i--) {
                if (vect[i] < 0) {
                    for (int j = i + 1; j <= n - 1; j++) {
                        if ((vect[j] < 0) && (vect[j] < vect[i])) {
                            swap(vect[j], vect[i]);
                            break;
                        }
                    }
                }
            }
        }
        cout << "3. Отсортированный массив:" << endl;
        for (int i = 0; i < n; i++) {
            cout << vect[i] << " ";
        }
        cout << endl;
        delete[]vect;
    }

}