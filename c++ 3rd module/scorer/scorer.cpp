#include "scorer.h"

#include <algorithm>
#include <unordered_map>
#include <utility>

using EventLinks = std::vector<const Event*>;                    // event's links vector
using CheckAndMergePairCodes = std::pair<EventType, EventType>;  // first: merge request status, second: check status
using TasksCodes = std::unordered_map<TaskName, CheckAndMergePairCodes>;     // first: task name, type: std::string
using UmapStudentsTasksTable = std::unordered_map<StudentName, TasksCodes>;  // first: student name, type std::string

bool CompareEvents(const Event* first_event, const Event* second_event) {
    const size_t first_event_number = static_cast<size_t>(first_event->event_type);
    const size_t second_event_number = static_cast<size_t>(second_event->event_type);
    return std::tie(first_event->time, first_event_number, first_event->student_name, first_event->task_name) <
           std::tie(second_event->time, second_event_number, second_event->student_name, second_event->task_name);
}

ScoreTable GetScoredStudents(const Events& events, time_t score_time) {
    ScoreTable answer;
    EventLinks events_links(events.size());
    UmapStudentsTasksTable score_list;
    for (size_t i = 0; i < events.size(); ++i) {
        events_links[i] = &events[i];
    }
    std::sort(events_links.begin(), events_links.end(), CompareEvents);
    for (const auto& event : events_links) {
        if (event->time > score_time) {
            break;
        } else {
            if (event->event_type == EventType::MergeRequestClosed ||
                event->event_type == EventType::MergeRequestOpen) {
                score_list[event->student_name][event->task_name].second = event->event_type;
            } else {
                score_list[event->student_name][event->task_name].first = event->event_type;
            }
        }
    }
    for (const auto& [student, _] : score_list) {
        for (const auto& [task_name, _] : score_list[student]) {
            if (score_list[student][task_name].first == EventType::CheckSuccess &&
                score_list[student][task_name].second != EventType::MergeRequestOpen) {
                answer[student].emplace(task_name);
            }
        }
    }
    return answer;
}
