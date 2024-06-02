#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

int inf = std::numeric_limits<int>::max();

void MinValues(std::vector<int>& deepnes, std::ifstream& input, int& n, int& m, std::vector<int>& ind, std::vector<int>& line, int N) {

  std::vector<int> numbers(n + 1);
  int a = 2, a1, a2;
  int counter = 0;
  for (int i = 1; i <= n; i++) {
    if (i == a) {
      a *= 2;
      counter += 1;
    }
    numbers[i] = counter;
  }

  std::vector<std::vector<int>> sparse_table(numbers[n] + 1, std::vector<int>(n, inf));
  for (int i = 0; i < n; i++) {
    sparse_table[0][i] = i;
  }
  int num;
  for (int i = 1; i <= numbers[n]; i++) {
    num = 1 << (i - 1);
    for (int j = 0; j + num < n; j++) {
      if (sparse_table[i - 1][j + num] != inf) {
        if (deepnes[sparse_table[i - 1][j]] < deepnes[sparse_table[i - 1][j + num]]) {
          sparse_table[i][j] = sparse_table[i - 1][j];
        } else {
          sparse_table[i][j] = sparse_table[i - 1][j + num];
        }
      } else {
        break;
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////////////
  int64_t ans,x,y,z,l,r,prev;
  ans = 0;
  input >> a1 >> a2;
  input >> x >> y >> z;
  for (int i = 0; i < m; i++) {
    if (i != 0) {
      a1 = ((x*a1) + (y*a2) + z) % N;
      a2 = ((x*a2) + (y*a1) + z) % N;
      l = std::min(ind[(a1 + prev) % N], ind[a2]);
      r = std::max(ind[(a1 + prev) % N], ind[a2]);
      a = numbers[r - l + 1];

      if (deepnes[sparse_table[a][r - (1 << a) + 1]] > deepnes[sparse_table[a][l]]) {
        prev = line[sparse_table[a][l]];
      } else {
        prev = line[sparse_table[a][r - (1 << a) + 1]];
      }
      ans += prev;

    } else {

      l = std::min(ind[a1], ind[a2]);
      r = std::max(ind[a1], ind[a2]);
      a = numbers[r - l + 1];
      if (deepnes[sparse_table[a][r - (1 << a) + 1]] > deepnes[sparse_table[a][l]]) {
        prev = line[sparse_table[a][l]];
      } else {
        prev = line[sparse_table[a][r - (1 << a) + 1]];
      }
      ans += prev;

    }
  }
  std::cout << ans;
}

////////////////////////////////////////////////////////////////////////////////////



void dfs(int index, std::vector<bool>& peaks, std::vector<std::vector<int>>& graph, int& now, std::vector<int>& ind, int deep, std::vector<int>& deepnes,std::vector<int>& line) {
  peaks[index] = true;
  line.push_back(index);
  deepnes.push_back(deep);
  now += 1;
  if (ind[index] == -1) {
    ind[index] = now;
  }
  for (auto neigh : graph[index]) {
      if (!peaks[neigh]) {
        dfs(neigh, peaks, graph,now,ind,deep + 1, deepnes,line);
        line.push_back(index);
        deepnes.push_back(deep);
        now += 1;
      }
  }
}

////////////////////////////////////////////////////////////////////////////////////

int main() {
  std::ifstream input("input.txt");
  int N,M, num, now, deep;
  input >> N >> M;

  std::vector<bool> peaks(N, false);
  std::vector<std::vector<int>> graph(N, std::vector<int>{});
  std::vector<int> ind(N + 1, -1);
  std::vector<int> deepnes{};
  std::vector<int> line{};
  now = -1;
  deep = 1;
  for (int i = 1; i < N; ++i) {
      input >> num;
      graph[num].push_back(i);
      graph[i].push_back(num);

  }

  dfs(0, peaks, graph, now, ind, deep, deepnes,line);
  num = deepnes.size();

  MinValues(deepnes, input, num, M,ind, line,N);


}

