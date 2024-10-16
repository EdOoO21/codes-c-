#include "unixpath.h"

namespace delimiters {
const char SLASH = '/';
const char SINGLEPOINT = '.';
}  // namespace delimiters

std::string NormalizePath(std::string_view current_working_dir, std::string_view path) {
    std::string answer;
    size_t len = 1;
    if (path[0] == delimiters::SLASH) {
        answer = path;
    } else {
        answer = std::string(current_working_dir) + delimiters::SLASH + std::string(path) + delimiters::SLASH;
    }
    for (size_t i = 1; i < answer.size(); ++i) {
        if (answer[i] == delimiters::SLASH && answer[i - 1] == delimiters::SLASH) {
            continue;
        } else if (answer[i - 1] == delimiters::SINGLEPOINT) {
            if (answer[i] == delimiters::SINGLEPOINT) {
                --len;
                while (len > 1 && answer[len - 2] != delimiters::SLASH) {
                    --len;
                }
                if (len > 1 && answer[len - 1] != delimiters::SLASH) {
                    --len;
                }
                ++i;
                continue;
            } else if (answer[i] == delimiters::SLASH) {
                --len;
                continue;
            }
        }
        answer[len] = answer[i];
        ++len;
    }
    if (len > 1 && answer[len - 1] == delimiters::SLASH) {
        --len;
    }
    answer.resize(len);
    return answer;
}
