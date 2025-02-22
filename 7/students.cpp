#include "students.h"
#include "studentAfterFirstSession.h"
#include "studentAfterSecondSession.h"

int Student::studentsCount = 1;

Student::Student (const char* _name, unsigned _course, unsigned _group) :
course(_course), group(_group) {
    ID = rand() % 1000000;
    name = new char[40];
    recording = 100 + studentsCount;
    studentsCount++;
    strcpy(name, _name);
};

Student::Student (const Student &other) {
    name = new char[40];
    strcpy(name, other.name);
    course = other.course;
    group = other.group;
    recording = other.recording;
}

Student::~Student() {
    delete[] name;
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

float Student::getAverageMark() {
    return -1;
}

std::ofstream& operator<<(std::ofstream &out, const Student &student) {
    out << "ID: " << student.getID() << std::endl;
    out << "Имя: " << student.getName() << std::endl;
    out << "Курс: " << student.getCourse() << std::endl;
    out << "Группа: " << student.getGroup() << std::endl;
    out << "Номер зачётки: " << student.getRecording() << std::endl;
    return out;
}

void AverageMarkOfGroup(std::vector<Student*> &students, const unsigned int &group) {
    int c1, c2;
    float average_score1, average_score2;
    for (Student* s : students) {
        if (s->getGroup() == group) {
            if (s->getAverageMark() != -1) {
                if (typeid(*s) == typeid(StAfter1Session)) {
                    average_score1 += s->getAverageMark();
                    average_score1 *= 4;
                }
                else if (typeid(*s) == typeid(StAfter2Session)) {
                    average_score2 += s->getAverageMark();
                    average_score2 *= 9;
                }
            }
            continue;
        }
    }
    cout << "Средний балл в " << group << " группе" << std::endl;
    cout << "После 1 сессии: " << average_score1/4 << std::endl;
    cout << "После 2 сессии: " << average_score2/9 << std::endl;
}

float AverageMarkofVector(std::vector<Student*> &students) {
    int count;
    float average_vector_mark;
    for (Student* s : students) {
        if (typeid(*s) == typeid(Student)) {
            continue;
        }
        else {
            average_vector_mark += s->getAverageMark();
            count++;
        }
    }
    return average_vector_mark/count*1.;
}

