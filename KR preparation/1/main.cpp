#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include <string>

using namespace std;

/*int Dec_to_Bin(int& num) {
    vector<int> bin;
    int bin_num;
    while (num) {
        num % 2 == 0 ? bin.push_back(1) : bin.push_back(0);
        num /= 2;
    }
    for (int i = bin.size(); i > 0; i--) {
        cout << bin[i];
    }
    for (int i = bin.size(); i > 0; i--) {
        bin_num += bin[i];
        bin_num *= 10;
    }
    return bin_num;
}*/

void decToBinary(int& n)
{
    // array to store binary number
    int* binaryNum = new int[32];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
    delete[]binaryNum;
}

vector<int> Parse_Num(int& n) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    return digits;
}

bool K11_in_bin (vector<int>& digits, const int& k) {
    int amount;
    //deque<int>::iterator iter = digits.begin();
    for (int i = digits.size(); i > 1; i--) {
        if (digits[i] == 1 && digits[i-1] == 1) {
            amount++;
        }
    }
    return amount == k;
}

int main() {
    ifstream fin("input", ios::in);
    int k, num;
    const int MAX_k = 31;
    string str;
    vector<int> numbers;
    fin >> k;
    if (k < 0 || k > MAX_k) {
        cout << "Not correct k";
    }
    else {
        while (fin >> num) {
            numbers.push_back(num);
        }
        fin.close();
        ofstream fout("output", ios::out);
        for (int number : numbers) {
            decToBinary(number);
            fout << number << " ";
            vector<int> num_digits = Parse_Num(number);
            if (K11_in_bin(num_digits, k)) {
                //fout << number << " ";
            }
        }
        fout.close();
        /*for (int elem : numbers) {
            cout << elem << " ";
        }*/
    }
}