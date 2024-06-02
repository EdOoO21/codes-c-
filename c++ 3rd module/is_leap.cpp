#include "is_leap.h"

namespace is_leap {
const int SMALL_CYCLE = 4;
const int MID_CYCLE = 100;
const int LARGE_CYCLE = 400;
}  // namespace is_leap

bool IsLeap(int year) {
    bool small_check = year % is_leap::SMALL_CYCLE == 0;
    bool large_check = year % is_leap::LARGE_CYCLE == 0;
    bool false_check = year % is_leap::MID_CYCLE != 0;
    return (small_check && false_check) || large_check;
}
