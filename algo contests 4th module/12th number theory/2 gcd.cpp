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
  int64_t a,b;
  input >> a >> b;
  while (b != 0) {
    a %= b;
    std::swap(a,b);
  }
  std::cout << a << std::endl;
}

