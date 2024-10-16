#include "fibonacci.h"

#include <utility>

int64_t CalculateNthFibonacci(int64_t n) {
    int64_t f1 = 0;
    int64_t f2 = 1;
    int64_t res = 0;
    for (int64_t i = 0; i < n; ++i) {
        res = f2 + f1;
        std::swap(f1, f2);
        f2 = res;
    }
    return f1;
}
