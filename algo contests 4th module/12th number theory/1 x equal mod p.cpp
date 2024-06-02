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
  int64_t x,n,p;
  int64_t ans = 1;
  input >> x >> n >> p;
  while (n > 1) {
    if (n % 2 == 1) {
      ans = (ans * x) % p;
    }
    x = (x * x) % p;
    n /= 2;
  }
  x = (x * ans) % p;
  std::cout << x;
}

