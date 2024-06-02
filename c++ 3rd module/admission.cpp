#include "admission.h"

#include <algorithm>

bool CompareStudents(const Applicant* first_applicant, const Applicant* second_applicant) {
    return std::tie(first_applicant->points, first_applicant->student.birth_date, first_applicant->student.name) <
           std::tie(second_applicant->points, second_applicant->student.birth_date, second_applicant->student.name);
}

bool CompareByNameAndDate(const Student* first_student, const Student* second_student) {
    return std::tie(first_student->birth_date, first_student->name) <
           std::tie(second_student->birth_date, second_student->name);
}

AdmissionTable FillUniversities(const std::vector<University>& universities, const std::vector<Applicant>& applicants) {
    AdmissionTable answer;
    std::unordered_map<std::string, size_t> university_max_students;
    for (const University& university : universities) {
        university_max_students[university.name] = university.max_students;
    }
    std::vector<const Applicant*> applicants_links(applicants.size());
    for (size_t i = 0; i < applicants.size(); ++i) {
        applicants_links[i] = &applicants[i];
    }
    std::sort(applicants_links.rbegin(), applicants_links.rend(), CompareStudents);
    for (const Applicant*& applicant : applicants_links) {
        for (const std::string& desired_university : applicant->wish_list) {
            if (answer[desired_university].size() < university_max_students[desired_university]) {
                answer[desired_university].push_back(&applicant->student);
                break;
            }
        }
    }
    for (auto& [_, university_list] : answer) {
        std::sort(university_list.rbegin(), university_list.rend(), CompareByNameAndDate);
    }
    return answer;
}
