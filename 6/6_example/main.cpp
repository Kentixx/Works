#include <iostream>
#include <cstring>
#include <vector>

#include "functions.h"

using namespace std;
template <typename MySuperPuperType>
int sum(MySuperPuperType a, int b){
    return a + b;
}

template <typename Type>
Type sum2(Type a, Type b){
    return a + b;
}

template <>
const char* sum2<const char*>(const char* a, const char* b){
    int len = strlen(a) + strlen(b) + 1;
    char *str = new char[len];
    strcpy(str, a);
    strcat(str, b);
    str[len-1] = '\0';
    return str;
}

/*
template <typename Type>
Type sum3(const Type &a, const Type &b){
    return a + b;
}

template <typename Type>
Type sum4(Type *a, Type *b){
    return *a + *b;
}
*/

template <typename T1, typename T2, typename T3>
T3 sum5(T1 a, T2 b){
    return a + b;
}

template <typename ResultType>
ResultType div(double a, double b){
    return a / b;
}


int main(){
    // templates
    cout << sum(1, 2) << endl;
    cout << sum(1.9, 2) << endl;
    // cout << sum("sdfgnsfg", 2) << endl; error
    cout << sum2(1.9, 2.0) << endl;
    string s1("qwer"), s2("asdf");
    cout << sum2(s1, s2) << endl;

    cout << sum2("1234", "5678") << endl;
    
    // cout << sum3(s1, s2) << endl;
    // cout << sum4(&s1, &s2) << endl;

    int i(4);
    double d(3.7);

    cout << sum5<int, double, int>(i, d) << endl;
    cout << sum5<int, double, double>(i, d) << endl;
    cout << sum5<double, int, double>(d, i) << endl;
    cout << sum5<double, int, double>(i, d) << endl;

    cout << div<double>(5, 8) << endl;
    cout << div<int>(5, 8) << endl;


    
    vector<int> v(4);

    // headers
    // #include "functions.h" can be done here too

    cout << globalA << endl;
    cout << difInt(4, 6) << endl;
    cout << difDouble(14.4, 6.5) << endl;
}
