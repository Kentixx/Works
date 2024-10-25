#include <iostream>
#include <queue>
#include <string>
#include <map>

#include "func.h"

using namespace std;

int KSFJGHLSKFNGN = 42;
int counter(0);

int static process(int a){
    counter++;
    cout << counter << endl;

    return a + 5;
}


int main(){

    process(3);
    process(3);
    process(3);
    process(3);
    process(3);




    cout << sum(1, 4) << endl;
    cout << a << endl;
    cout << B << endl;
    cout << div<int>(14, 5) << endl;

    // коллекции https://metanit.com/cpp/tutorial/7.14.php
    priority_queue<int> q;
    q.push(3);
    q.push(2);
    q.push(4);
    q.push(1);
    q.push(5);
    while (!q.empty())
    {
        cout << q.top() << "  ";
        q.pop();
    }
    cout << endl;

    map<string, int> m;
    m["one"] = 1;
    m["two"] = 2;

    pair<string, int> three("three", 3);
    m.insert(three);
    
    cout << m["two"] << endl;
    cout << three.first << "  " << three.second << endl;

    pair<string, int> p = *m.find("two");

    cout << p.first << "  " << p.second << endl;
}