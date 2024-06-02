#pragma once

#include <string>
#include <tuple>
#include <vector>

struct Date {
    int day = 0;
    int month = 0;
    int year = 0;

    bool operator<(const Date& other) const {
        return std::tie(this->year, this->month, this->day) < std::tie(other.year, other.month, other.day);
    }
};

struct Student {
    std::string name;
    std::string last_name;
    Date birth_date;
};

enum class SortKind {
    Name,
    Date
};

void SortStudents(std::vector<Student>& students, SortKind sort_kind);

