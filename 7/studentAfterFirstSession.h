#pragma once
#include "students.h"

class StAfter1Session : public Student {
    protected: 
        array<float, 4> marks_after_first;

    public:
        StAfter1Session () = delete;
        StAfter1Session (const char* _name, unsigned _course, unsigned _group, array<float, 4> _marks_after_first);
        StAfter1Session (const StAfter1Session &other);
        ~StAfter1Session();

        virtual float getMark(unsigned &i) const;
        array<float, 4> getMarksFirstSession() const;
        void editMark(unsigned &i, float &new_mark);
        float getAverageMark() override;
};

std::ostream& operator<<(std::ostream &out, const StAfter1Session &student);