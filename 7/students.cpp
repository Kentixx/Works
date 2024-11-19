#include <iostream>
#include <cstring>
#include <array>

using namespace std;

class Student {
    static inline long int ID = 10000;
    char* name;
    unsigned course;
    unsigned group;

protected:
    const unsigned recording;

public:
    Student (const char* _name, unsigned _course, unsigned _group, unsigned _recording) :
    course(_course), group(_group), recording(_recording) {
        ++ID;
        name = new char[20];
        strcpy(name, _name);
    };

    Student::Student (const Student &other) {
        
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
    
    void setName(const char* &_name) {
        name = new char[20];
        strcpy(name, _name);
    }

    void setCourse(unsigned &_course) {
        course = _course;
    }

    void setGroup(unsigned &_group) {
        group = _group;
    }
};

//-------------------------------------------------------------------

class StAfter1Session : public Student {
    char* name;

protected: 
    array<float, 4> marks_after_first;

public:
    StAfter1Session (const char* _name, unsigned _course, unsigned _group, unsigned _recording, array<float, 4> _marks_after_first) :
    Student(".", _course, _group, _recording) {
        name = new char[20];
        strcpy(name, _name);

        for (size_t i = 0; i < 4; i++) {
            marks_after_first[i] = _marks_after_first[i];
        }
    }

    StAfter1Session::StAfter1Session (const StAfter1Session&);

    float getMark(unsigned &i) const {
        return marks_after_first[i-1];
    }

    void editMark(unsigned &i, float &new_mark) {
        marks_after_first[i-1] = new_mark;
    }

    float getAverageMark() {
        float sum;
        for (size_t i = 0; i < 4; i++) {
            sum += marks_after_first[i];
        }
        sum /= 4*1.;
        return sum;
    } 
};

//-------------------------------------------------------------------

class StAfter2Session : public StAfter1Session {
    char* name;

protected: 
    array<float, 5> marks_after_second;

public:
    StAfter2Session (const char* _name, unsigned _course, unsigned _group, 
    unsigned _recording, array<float, 4> _marks_after_first, array<float, 5> _marks_after_second) :
    StAfter1Session(".", _course, _group, _recording, _marks_after_first) {
        name = new char[20];
        strcpy(name, _name);

        for (size_t i = 0; i < 4; i++) {
            marks_after_first[i] = _marks_after_first[i];
        }
        for (size_t i = 0; i < 5; i++) {
            marks_after_second[i] = _marks_after_second[i];
        }
    }

    StAfter2Session::StAfter2Session (const StAfter2Session&);

    float getMark(unsigned &i) const {
        if (i >= 1 && i <= 4) {
            return marks_after_first[i-1];
        }
        else if (i > 4 && i <= 9) {
            return marks_after_second[i-5];
        }
        else 
            return -1;
    } // 1-4 - оценки первой сессии, 5-9 - оценки второй сессии

    void editMark(unsigned &i, float &new_mark) {
        if (i >= 1 && i <= 4) {
            marks_after_first[i-1] = new_mark;
        }
        else if (i > 4 && i <= 9) {
            marks_after_second[i-5] = new_mark;
        }
    }

    float getAverageMark() {
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
};