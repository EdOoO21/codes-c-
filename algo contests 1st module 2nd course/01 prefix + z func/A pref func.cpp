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
    std::string a;
    int k;
    input >> a;
    std::vector<int> pi(a.size(),-1);
    pi[0] = 0;
    for (int i = 1; i < a.size(); ++i) {
        k = pi[i - 1];
        while ((k > 0) && (a[k] != a[i])) {
            k = pi[k - 1];
        }
        if (a[k] == a[i]) {
            pi[i] = k + 1;
        } else {
            pi[i] = 0;
        }
    }
    for (int i = 0; i < a.size(); ++i) {
        std::cout << pi[i] << " ";
    }
}

