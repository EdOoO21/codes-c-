#include "reduce_fraction.h"

int64_t EuclidAlgorithm(int64_t d1, int64_t d2) {
    while (d1 > 0 && d2 > 0) {
        if (d1 > d2) {
            d1 = d1 % d2;
        } else {
            d2 = d2 % d1;
        }
    }
    return d1 + d2;
}

int64_t ReduceFraction(int64_t numerator, int64_t denominator) {
    int64_t gcd = EuclidAlgorithm(numerator, denominator);
    return denominator / gcd + numerator / gcd;
}
