#include "password.h"

namespace limits {
const char ASCII_LOWER_VALUE = 33;
const char ASCII_UPPER_VALUE = 126;
const size_t LENGTH_LOWER_VALUE = 8;
const size_t LENGTH_UPPER_VALUE = 14;
}  // namespace limits

bool ValidatePassword(const std::string& password) {
    bool lower_letters = false;
    bool numbers = false;
    bool other_signs = false;
    bool upper_letters = false;
    size_t string_length = password.size();
    if (limits::LENGTH_LOWER_VALUE > string_length || string_length > limits::LENGTH_UPPER_VALUE) {
        return false;
    }
    for (size_t i = 0; i < string_length; ++i) {
        if (limits::ASCII_LOWER_VALUE <= password[i] && password[i] <= limits::ASCII_UPPER_VALUE) {
            if (islower(password[i])) {
                lower_letters = true;
            } else if (isupper(password[i])) {
                upper_letters = true;
            } else if (isdigit(password[i])) {
                numbers = true;
            } else {
                other_signs = true;
            }
        } else {
            return false;
        }
    }
    return lower_letters + numbers + other_signs + upper_letters >= 3;
}
