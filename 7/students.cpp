#include "students.h"

int Student::studentsCount = 1;

Student::Student (const char* _name, unsigned _course, unsigned _group, unsigned _recording) :
course(_course), group(_group), recording(_recording) {
    ID = rand() % 100000;
    name = new char[40];
    strcpy(name, _name);
};

Student::Student (const Student &other) {
    strcpy(name, other.name);
    course = other.course;
    group = other.group;
    recording = other.recording;
};

int Student::getID() const {
    return ID;
}
    
char* Student::getName() const {
    return (char*)name;
}

unsigned Student::getCourse() const {
    return course;
}

unsigned Student::getGroup() const {
    return group;
}

const unsigned Student::getRecording() const {
    return recording;
}
    
void Student::setName(const char* &_name) {
    strcpy(name, _name);
}

void Student::setCourse(unsigned &_course) {
    course = _course;
}

void Student::setGroup(unsigned &_group) {
    group = _group;
}

std::ostream& operator<<(std::ostream &out, const Student &student) {
    out << "ID: " << student.getID() << std::endl;
    out << "Имя: " << student.getName() << std::endl;
    out << "Курс: " << student.getCourse() << std::endl;
    out << "Группа: " << student.getGroup() << std::endl;
    out << "Номер зачётки: " << student.getRecording() << std::endl;
    return out;
}
