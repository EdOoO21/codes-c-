#include "sort_students.h"

#include <algorithm>

bool ComparatedByDate(const Student& first_student, const Student& second_student) {
    return std::tie(first_student.birth_date, first_student.last_name, first_student.name) <
           std::tie(second_student.birth_date, second_student.last_name, second_student.name);
}

bool ComparatedByName(const Student& first_student, const Student& second_student) {
    return std::tie(first_student.last_name, first_student.name, first_student.birth_date) <
           std::tie(second_student.last_name, second_student.name, second_student.birth_date);
}

void SortStudents(std::vector<Student>& students, SortKind sort_kind) {
    if (sort_kind == SortKind::Date) {
        std::sort(students.begin(), students.end(), ComparatedByDate);
    } else {
        std::sort(students.begin(), students.end(), ComparatedByName);
    }
}
