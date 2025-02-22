#pragma once
#include <iostream>
#include <array>
#include <cstring>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

class Student {
protected:
    char* name;
    unsigned course;
    unsigned group;
    static int studentsCount;

private:
    unsigned recording;
    int ID;

public:
    Student() = delete;

    Student (const char* _name, unsigned _course, unsigned _group);

    Student (const Student &other);

    ~Student();

    int getID() const;
    char* getName() const;
    unsigned getCourse() const;
    unsigned getGroup() const;
    const unsigned getRecording() const;
    virtual float getAverageMark();

    void setName(const char* &_name);
    void setCourse(unsigned &_course);
    void setGroup(unsigned &_group);
};

std::ofstream& operator<<(std::ofstream &out, const Student &student);
void AverageMarkOfGroup(std::vector<Student*> &students, const unsigned int &group);
float AverageMarkofVector(std::vector<Student*> &students);

