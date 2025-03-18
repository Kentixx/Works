#include "students.h"
#include "studentAfterFirstSession.h"
#include "studentAfterSecondSession.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    ofstream fout("files/students");
    array<float, 4> marks1 = {5.7, 8.9, 3.5, 9};
    array<float, 5> marks2 = {3.5, 7.8, 5.0, 9.4, 6.3};
    array<float, 4> marks3 = {7.1, 4.8, 5.2, 10};
    array<float, 5> marks4 = {1.4, 1.7, 8.6, 5, 7.3};

    Student s1{"Андрей", 2, 1};
    Student s2{"Вероника", 1, 3};
    StAfter1Session s3{"Матвей", 3, 6, marks1};
    StAfter1Session s4{"Иван", 2, 1, marks3};
    StAfter1Session s5{"Аня", 4, 1, {6.7, 5, 9.8, 7.2}};
    StAfter2Session s6{"Константин", 1, 6, marks3, marks2};
    StAfter2Session s7{"Александр", 1, 3, marks1, marks4};

    vector<Student*> stud;
    Student *stud1 = &s1;
    Student *stud2 = &s2;
    Student *stud3 = &s3;
    Student *stud4 = &s4;
    Student *stud5 = &s5;
    Student *stud6 = &s6;
    Student *stud7 = &s7;
    stud.push_back(stud1); stud.push_back(stud2); stud.push_back(stud3); stud.push_back(stud4);
    stud.push_back(stud5); stud.push_back(stud6); stud.push_back(stud7);

    s4.editMark(2, 9.24);
    fout << "Stud's average: " << AverageMarkofVector(stud) << std::endl;
    //AverageMarkOfGroup(stud, 6); // пофиксить методы подсчёта средних баллов

    fout << s1 << std::endl;
    fout << s2 << std::endl;
    fout << s3;
    fout << "Средний балл: " << s3.getAverageMark() << std::endl << std::endl;
    fout << s4 << std::endl;
    fout << s5 << std::endl;
    fout << s6 << std::endl;
    fout << s7;
    fout << "Средний балл: " << s7.getAverageMark() << std::endl;
    fout.close();
}
