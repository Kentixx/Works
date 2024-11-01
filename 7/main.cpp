#include <iostream>
#include <string>
using namespace std;

struct SquashBall
{
    unsigned int ball_color;
    unsigned int radius_mm;
    unsigned int dot_color;
    unsigned int dot_number;
    string brand;
};

int main() {
    SquashBall ball1;
    ball1.ball_color = 0xFF121415;
    ball1.radius_mm = 15;
    ball1.dot_color = 0xFFFFFF00;
    ball1.dot_number = 2;
    ball1.brand = "Dunlop";

    SquashBall ball2 = ball1;
    ball2.dot_number = 1;

    SquashBall ball3 = ball2;
    ball3.dot_color = 0xFFFF00FF;

    cout << "ball2.dot_number: " << ball2.dot_number << endl << "ball3.brand: " << ball3.brand << endl;
}