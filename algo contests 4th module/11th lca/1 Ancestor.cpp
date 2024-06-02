#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

void dfs(size_t index, std::vector<std::vector<int64_t>>& time, std::vector<std::vector<int64_t>>& graph, int64_t& now) {
  time[index][0] = now;
  for (auto neigh : graph[index]) {
      if (time[neigh][0] == 0) {
        now += 1;
        dfs(neigh, time, graph,now);
      }
  }
  time[index][1] = now;
}



int main() {
  std::ifstream input("ancestor.in");
  int64_t N,M,first,second, root, now;
  input >> N;
  now = 1;
  std::vector<std::vector<int64_t>> time(N + 1, std::vector<int64_t>(2,0));
  std::vector<std::vector<int64_t>> graph(N + 1, std::vector<int64_t>{});

  for (int64_t i = 1; i <= N; ++i) {
      input >> M;
      if (M != 0) {
        graph[M].push_back(i);
        graph[i].push_back(M);
      } else {
        root = i;
      }
  }
  dfs(root, time, graph,now);

  input >> M;

  for (int64_t i = 0; i < M; ++i) {
    input >> first >> second;
    if ((time[first][0] <= time[second][0]) && (time[first][1] >= time[second][0]) ) {
      std::cout << 1 << std::endl;
    } else {
      std::cout << 0 << std::endl;
    }
  }

}

