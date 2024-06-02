#include "provinces.h"

int64_t CountPassports(const std::vector<int>& provinces) {
    std::multiset<int64_t> provinces_set;
    int64_t answer = 0;
    int64_t least_province_value = 0;
    for (const auto& province_value : provinces) {
        provinces_set.insert(province_value);
    }
    while (provinces_set.size() >= 2) {
        least_province_value = *provinces_set.begin() + *(++provinces_set.begin());
        provinces_set.erase(provinces_set.begin());
        provinces_set.erase(provinces_set.begin());
        provinces_set.insert(least_province_value);
        answer += least_province_value;
    }
    return answer;
}
