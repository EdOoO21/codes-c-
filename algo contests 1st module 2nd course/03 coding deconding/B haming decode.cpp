#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <cstdint>
#include <map>
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::string num;
    input >> num;
    int64_t size = num.size();
    std::vector<char> line(size + 1,'0');
    int pow = 0,pr = 1;

    pow = ceil(log2(size));

    std::vector<int> pows(pow,1);
    for (int64_t i = 1; i < pow; ++i) {
        pows[i] = pows[i-1] * 2;
    }

    int64_t pointer = 0;
    for (int64_t i = 1; i < size + 1; ++i) {
        line[i] = num[i - 1];
    }

    int64_t sum,prev,ind = 0;

    for (auto i : pows) {
        pointer = i;
        sum = 0;
        prev = 1;
        if (line[pointer] == '1') {
            --sum;
        }
        while (pointer <= size) {
            while (((pointer / i) == prev) && (pointer <= size)) {
                sum += line[pointer] - '0';
                ++pointer;
            }
            pointer += i;
            prev = pointer / i;
        }
        if ((sum  % 2) != ( line[i] - '0')) {
            ind += i;
        }
    }
    pointer = 0;
    for (int64_t i = 1; i < line.size(); ++i) {
        if (pows[pointer] == i) {
            ++pointer;
        } else {
            if (i == ind) {
                if (line[i] == '0') {
                    std::cout << 1;
                } else {
                    std::cout << 0;
                }
            } else {
                std::cout << line[i];
            }
        }
    }














}

