#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>

enum class EventType {
    CheckFailed,
    CheckSuccess,
    MergeRequestOpen,
    MergeRequestClosed,
};

using StudentName = std::string;
using TaskName = std::string;

struct Event {
    StudentName student_name;
    TaskName task_name;
    time_t time;
    EventType event_type;
    bool operator=(const Event& other) const {
        const size_t this_event_type_number = static_cast<size_t>(this->event_type);
        const size_t other_event_type_number = static_cast<size_t>(other.event_type);
        return std::tie(this->time, this_event_type_number, this->student_name, this->task_name) ==
               std::tie(other.time, other_event_type_number, other.student_name, other.task_name);
    }
};

using Events = std::vector<Event>;
using ScoreTable = std::map<StudentName, std::set<TaskName>>;

ScoreTable GetScoredStudents(const Events& events, time_t score_time);
