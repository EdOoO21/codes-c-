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
  int64_t x1,y1,x2,y2;
  input >> x1 >> y1 >> x2 >> y2;
  int64_t a = std::abs(x1- x2);
  int64_t b = std::abs(y1- y2);
  while (b != 0) {
    a %= b;
    std::swap(a,b);
  }
  std::cout << a + 1 << std::endl;
}

