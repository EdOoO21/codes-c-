#include "tests_checking.h"

#include <deque>
#include <string_view>

std::vector<std::string> StudentsOrder(const std::vector<StudentAction>& student_actions,
                                       const std::vector<size_t>& queries) {
    std::deque<std::string_view> final_sequence;
    std::vector<std::string> answer;
    for (const StudentAction& student : student_actions) {
        if (student.side == Side::Top) {
            final_sequence.emplace_front(student.name);
        } else {
            final_sequence.emplace_back(student.name);
        }
    }
    for (const size_t& position : queries) {
        answer.emplace_back(final_sequence[position - 1]);
    }
    return answer;
}
