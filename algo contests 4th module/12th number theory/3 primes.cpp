#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>


////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////

int main() {
  std::ifstream input("input.txt");
  int64_t N;
  input >> N;
  std::vector<int64_t> values{};
  int64_t i = 2;
  while (i * i <= N) {
    while (N % i == 0) {
      values.push_back(i);
      N /= i;
    }
    ++i;
  }
  if (N > 1) {
    values.push_back(N);
  }

  for (int k = 0; k < values.size(); k++) {
    std::cout << values[k] << " ";
  }

}

