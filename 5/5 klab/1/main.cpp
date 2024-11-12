#include <iostream>
#include <fstream>
#include <set>

using std::ofstream;
using std::ifstream;
using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::ios;

void SetEnter(std::multiset<int> multiset, const int& size) {
    int elem;
    for (int i = 0; i < size; i++) {
        cin >> elem;
        multiset.insert(elem);    
    }
}

void SetPrint(const std::multiset<int>& set) {
    for (const auto& elem : set) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    int a, b;
    std::multiset<int> A, B;
    cout << "Размер A: ";
    cin >> a;
    cout << "Размер B: ";
    cin >> b;
    SetEnter(A, a), SetEnter(B, b);
    SetPrint(B), SetPrint(A);
}