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
  int64_t n,ans;
  ans = 0;
  input >> n;
  int64_t i = 1;
  while (i * i <= n) {
    if (n % i == 0) {
      if (i != 1) {
        ans = n / i;
        break;
      }
    }
    ++i;
  }
  if (ans == 0) {
    std::cout << 1 << " " << n - 1;
  } else {
    std::cout << ans << " " << n - ans;
  }
}

