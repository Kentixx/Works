#pragma once
#include "studentAfterFirstSession.h"

class StAfter2Session : public StAfter1Session {
    protected: 
        array<float, 5> marks_after_second;

    public:
        StAfter2Session () = delete;

        StAfter2Session (const char* _name, unsigned _course, unsigned _group,
         array<float, 4> _marks_after_first, array<float, 5> _marks_after_second);

        StAfter2Session (const StAfter2Session &other);

        ~StAfter2Session();

        float getMark(unsigned &i) const override;
        array<float, 5> getMarksSecondSession() const;
        void editMark(unsigned &i, float &new_mark);
        float getAverageMark() override;
};

std::ostream& operator<<(std::ostream &out, const StAfter2Session &student);
