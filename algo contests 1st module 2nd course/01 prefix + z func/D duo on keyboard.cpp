#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <cstdint>
#include <map>


int64_t inf = std::numeric_limits<int64_t>::min();

////////////////////////////////////////////////////////////////////////////////////
int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int64_t n,a,k;
    input >> n >> a >> k;
    std::string word;
    input >> word;

    ////////////////////////////////////

    std::vector<int64_t > pi(n,-1);
    pi[0] = 0;
    int64_t k1;
    for (int i = 1; i < word.size(); ++i) {
        k1 = pi[i - 1];
        while ((k1 > 0) && (word[k1] != word[i])) {
            k1 = pi[k1 - 1];
        }
        if (word[k1] == word[i]) {
            pi[i] = k1 + 1;
        } else {
            pi[i] = 0;
        }
    }
    int64_t maxv = *std::max_element(pi.begin(), pi.end());
    std::vector<std::vector<int64_t>> table (a,std::vector<int64_t >(n + 1,0));
    ////////////////////////////////////
    table[word[0] - 'a'][0] = 1;

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 0; j < a; ++j) {
            if (j + 'a' == word[i]) {
                table[j][i] = i + 1;
            } else {
                table[j][i] = table[j][pi[i - 1]];
            }
        }
    }

    int64_t ans = inf;
    int64_t from,to;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a; ++j) {
            if (ans < i - table[j][i]) {
                ans = i - table[j][i];
                from = i;
                to = table[j][i];
            }

        }
    }
    if ((k * (ans)) + n < n) {
        std::cout << n;
    } else {
        std::cout << (k * (ans)) + n;
    }

}

