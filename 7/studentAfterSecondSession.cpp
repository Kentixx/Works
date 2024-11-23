#include "studentAfterSecondSession.h"

StAfter2Session::StAfter2Session (const char* _name, unsigned _course, unsigned _group, array<float, 4> _marks_after_first, array<float, 5> _marks_after_second) :
StAfter1Session(_name, _course, _group, _marks_after_first), marks_after_second(_marks_after_second) {}

StAfter2Session::StAfter2Session (const StAfter2Session &other) : 
StAfter1Session(other), marks_after_second(other.marks_after_second) {}

StAfter2Session::~StAfter2Session() {
    delete[] name;
}

float StAfter2Session::getMark(unsigned &i) const {
        if (i >= 1 && i <= 4) {
            return marks_after_first[i-1];
        }
        else if (i > 4 && i <= 9) {
            return marks_after_second[i-5];
        }
        else 
            return -1;
} // 1-4 - оценки первой сессии, 5-9 - оценки второй сессии 

array<float, 5> StAfter2Session::getMarksSecondSession() const {
    return marks_after_second;
}

void StAfter2Session::editMark(unsigned &i, float &new_mark) {
    if (i >= 1 && i <= 4) {
        marks_after_first[i-1] = new_mark;
    }
    else if (i > 4 && i <= 9) {
        marks_after_second[i-5] = new_mark;
    }
}

float StAfter2Session::getAverageMark() {
    float sum;
    for (size_t i = 0; i < 4; i++) {
        sum += marks_after_first[i];
    }
    for (size_t i = 0; i < 5; i++) {
        sum += marks_after_second[i];
    }
    sum /= 9*1.;
    return sum;
} 

std::ostream& operator<<(std::ostream &out, const StAfter2Session &student) {
    out << "ID: " << student.getID() << std::endl;
    out << "Имя: " << student.getName() << std::endl;
    out << "Курс: " << student.getCourse() << std::endl;
    out << "Группа: " << student.getGroup() << std::endl;
    out << "Номер зачётки: " << student.getRecording() << std::endl;

    out << "Оценки за первый семестр: ";
    for (const auto& mark : student.getMarksFirstSession()) {
        out << mark << " ";
    }
    out << std::endl;

    out << "Оценки за второй семестр: ";
    for (const auto& mark : student.getMarksSecondSession()) {
        out << mark << " ";
    }
    out << std::endl;
    return out;
}