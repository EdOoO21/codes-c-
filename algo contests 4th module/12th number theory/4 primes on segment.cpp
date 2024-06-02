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
  int64_t s,f;
  input >> s >> f;
  std::vector<bool> sieve(f+1, true);
  int64_t i = 2,j;
  while (i * i <= f) {
    j = i;
    while (j * i <= f) {
      if (sieve[j * i]) {
        sieve[j * i] = false;
      }
      ++j;
    }
    ++i;
  }
  bool ok = true;
  for (int64_t k = s; k <= f; ++k) {
    if (sieve[k]) {
      ok = false;
      std::cout << k << "\n";
    }
  }
  if (ok) {
    std::cout << "Absent" << std::endl;
  }

}

