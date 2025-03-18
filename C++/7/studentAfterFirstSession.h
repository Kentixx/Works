#pragma once
#include "students.h"

class StAfter1Session : public Student {
protected:
    array<float, 4> marks_after_first;

public:
    StAfter1Session () = delete;
    StAfter1Session (const char* _name, unsigned _course, unsigned _group, array<float, 4> _marks_after_first);
    StAfter1Session (const StAfter1Session &other);

    virtual float getMark(unsigned &i) const;
    array<float, 4> getMarksFirstSession() const;
    virtual array<float, 5> getMarksSecondSession() const;
    virtual void editMark(const unsigned &i, const float &new_mark);
    virtual float getAverageMark() override;
};

std::ofstream& operator<<(std::ofstream &out, const StAfter1Session &student);