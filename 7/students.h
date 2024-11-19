#pragma once
#include <iostream>
#include <cstring>
#include <array>
#include <vector>
#include <ctime>
#include <cstdlib>

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

        Student (const char* _name, unsigned _course, unsigned _group, unsigned _recording);

        Student (const Student &other);

        int getID() const;
        char* getName() const;
        unsigned getCourse() const;
        unsigned getGroup() const;
        const unsigned getRecording() const;

        void setName(const char* &_name);
        void setCourse(unsigned &_course);
        void setGroup(unsigned &_group);
};

std::ostream& operator<<(std::ostream &out, const Student &student);
