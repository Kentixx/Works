#include "studentAfterFirstSession.h"

StAfter1Session::StAfter1Session (const char* _name, unsigned _course, unsigned _group, array<float, 4> _marks_after_first) :
        Student(_name, _course, _group), marks_after_first(_marks_after_first) {}

StAfter1Session::StAfter1Session (const StAfter1Session &other) : Student(other), marks_after_first(other.marks_after_first) {}

float StAfter1Session::getMark(unsigned &i) const {
    return marks_after_first[i-1];
}

array<float, 4> StAfter1Session::getMarksFirstSession() const {
    return marks_after_first;
}

array<float, 5> StAfter1Session::getMarksSecondSession() const {
    array<float, 5> emptyArray;
    return emptyArray;
}


void StAfter1Session::editMark(const unsigned &i, const float &new_mark) {
    marks_after_first[i-1] = new_mark;
}

float StAfter1Session::getAverageMark() {
    float sum;
    for (size_t i = 0; i < 4; i++) {
        sum += marks_after_first[i];
    }
    sum /= 4*1.;
    return sum;
}

std::ofstream& operator<<(std::ofstream &out, const StAfter1Session &student) {
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
    return out;
}
