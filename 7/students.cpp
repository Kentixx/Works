#include <iostream>
#include <cstring>
#include <vector>

class Student {
    static long int ID;
    char* name;
    unsigned course;
    unsigned group;
    const unsigned recording;

public:
    Student (const char* _name, unsigned _course, unsigned _group, const unsigned _recording) :
    course(_course), group(_group), recording(_recording) {
        name = new char[20];
        strcpy(name, _name);
    };

    long int getID() const {
        return ID;
    }
    
    char getName() const {
        return *name;
    }

    unsigned getCourse() const {
        return course;
    }

    unsigned getGroup() const {
        return group;
    }

    const unsigned getRecording() const {
        return recording;
    }
    
    char setName() const {
        return *name;
    }

    unsigned getCourse() const {
        return course;
    }

    unsigned getGroup() const {
        return group;
    }

    const unsigned getRecording() const {
        return recording;
    }
};