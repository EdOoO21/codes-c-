#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>

#include <vector>
#include <cstdint>

////////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::string a;
    int64_t l = 0;
    int64_t r = 0;
    input >> a;
    const int64_t size = a.size();
    std::vector<int64_t> z(size,-1);
    z[0] = 0;
    int64_t j;
    for (int i = 1; i < size; ++i) {
        if (i > r) {
            j = 0;
            while ((j + i < size) && (a[j] == a[i + j])) {
                ++j;
            }
            z[i] = j;
            l = i;
            if (j != 0) {
                r = i + j - 1;
            } else {
                r = i;
            }
        }
        else {
            if (z[i - l] + i > r) {
                j = 0;
                while ((j + i < size) && (a[j] == a[i + j])) {
                    ++j;
                }
                z[i] = j;
                l = i;
                if (j != 0) {
                    r = i + j - 1;
                } else {
                    r = i;
                }
            } else {
                z[i] = z[i - l];
            }

        }
    }
    for (int i = 0; i < size; ++i) {
        std::cout << z[i] << " ";
    }
}

