#include "palindrome.h"

bool IsPalindrome(const std::string& str) {
    size_t length_str = str.size();
    if (length_str == 0) {
        return true;
    }
    size_t left = 0;
    size_t right = length_str - 1;
    while (left < right) {
        if (str[left] == ' ') {
            ++left;
        } else if (str[right] == ' ') {
            --right;
        } else if (str[right] == str[left]) {
            --right;
            ++left;
        } else {
            return false;
        }
    }
    return true;
}
