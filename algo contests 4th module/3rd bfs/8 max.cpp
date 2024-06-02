#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <limits>
#include <algorithm>
#include <unordered_map>

int64_t inf = std::numeric_limits<int64_t>::max();

int main() {
    std::ifstream input("input.txt");
//    std::ifstream input("C:/Users/erbag/CLionProjects/algosi2/input.txt");
    if (input.is_open()) {
        int64_t x,y,z,ans;
        input >> x >> y >> z >> ans;
        std::vector<std::vector<std::vector<int64_t>>> all (x + 1,std::vector<std::vector<int64_t>>(y + 1,std::vector<int64_t>(z + 1, inf)));
        std::vector<std::vector<std::vector<int64_t>>> distance(1, std::vector<std::vector<int64_t>>{{0,0,0}});
        all[0][0][0] = 0;
        int64_t minv = inf;
        for (int i = 0; !distance[i].empty(); ++i) {
            distance.emplace_back();
            for (auto n : distance[i]) {
                ///////////////////////////////////////////////////
                if (all[x][n[1]][n[2]] > i + 1) {
                    all[x][n[1]][n[2]] == i + 1;
                    distance[i + 1].push_back({x,n[1],n[2]});
                    if (x == ans) {
                        minv = i + 1;
                        break;
                    }
                }
                if (all[n[0]][y][n[2]] > i + 1) {
                    all[n[0]][y][n[2]] == i + 1;
                    distance[i + 1].push_back({n[0],y,n[2]});
                    if (y == ans) {
                        minv = i + 1;
                        break;
                    }
                }
                if (all[n[0]][n[1]][z] > i + 1) {
                    all[n[0]][n[1]][z] == i + 1;
                    distance[i + 1].push_back({n[0],n[1],z});
                    if (z == ans) {
                        minv = i + 1;
                        break;
                    }
                }
/////////////////////////////////////////////////////////////////////
                if (all[0][n[1]][n[2]] > i + 1) {
                    all[0][n[1]][n[2]] == i + 1;
                    distance[i + 1].push_back({0,n[1],n[2]});
                }
                if (all[n[0]][0][n[2]] > i + 1) {
                    all[n[0]][0][n[2]] == i + 1;
                    distance[i + 1].push_back({n[0],0,n[2]});
                }
                if (all[n[0]][n[1]][0] > i + 1) {
                    all[n[0]][n[1]][0] == i + 1;
                    distance[i + 1].push_back({n[0],n[1],0});
                }
//////////////////////////////////////////////////////////////////
                if (n[1] + n[0] < x) {
                    if (all[n[1] + n[0]][0][n[2]] > i + 1) {
                        all[n[1] + n[0]][0][n[2]] = i + 1;
                        distance[i + 1].push_back({n[1] + n[0],0,n[2]});
                        if ((n[1] + n[0]) == ans) {
                            minv = i + 1;
                            break;
                        }
                    }
                }
                else if (n[1] + n[0] > x) {
                    if (all[x][n[1] - (x - n[0])][n[2]] > i + 1) {
                        all[x][n[1] - (x - n[0])][n[2]] = i + 1;
                        distance[i + 1].push_back({x,n[1] - (x - n[0]),n[2]});
                        if ((n[1] - (x - n[0])) == ans) {
                            minv = i + 1;
                            break;
                        }
                    }
                }
//////////////////////////////////////////////////////////////////
                if (n[2] + n[0] < x) {
                    if (all[n[2] + n[0]][n[1]][0] > i + 1) {
                        all[n[2] + n[0]][n[1]][0] = i + 1;
                        distance[i + 1].push_back({n[2] + n[0],n[1],0});
                        if ((n[2] + n[0]) == ans) {
                            minv = i + 1;
                            break;
                        }
                    }
                }
                else if (n[2] + n[0] > x) {
                    if (all[x][n[1]][n[2] - (x - n[0])] > i + 1) {
                        all[x][n[1]][n[2] - (x - n[0])] = i + 1;
                        distance[i + 1].push_back({x,n[1],n[2] - (x - n[0])});
                        if ((n[2] - (x - n[0])) == ans) {
                            minv = i + 1;
                            break;
                        }
                    }
                }
//////////////////////////////////////////////////////////////////
                if (n[1] + n[2] < z) {
                    if (all[n[0]][0][n[2] + n[1]] > i + 1) {
                        all[n[0]][0][n[2] + n[1]] = i + 1;
                        distance[i + 1].push_back({n[0],0,n[1] + n[2]});
                        if ((n[1] + n[2]) == ans) {
                            minv = i + 1;
                            break;
                        }
                    }
                }
                else if (n[1] + n[2] > z) {
                    if (all[n[0]][n[1] - (z - n[2])][z] > i + 1) {
                        all[n[0]][n[1] - (z - n[2])][z] = i + 1;
                        distance[i + 1].push_back({n[0],n[1] - (z - n[2]),z});
                        if ((n[1] - (z - n[2])) == ans) {
                            minv = i + 1;
                            break;
                        }
                    }
                }
////////////////////////////////////////////////////////////
                if (n[0] + n[2] < z) {
                    if (all[0][n[1]][n[2] + n[0]] > i + 1) {
                        all[0][n[1]][n[2] + n[0]] = i + 1;
                        distance[i + 1].push_back({0,n[1],n[0] + n[2]});
                        if ((n[2] + n[0]) == ans) {
                            minv = i + 1;
                            break;
                        }
                    }
                }
                else if (n[0] + n[2] > z) {
                    if (all[n[0] - (z - n[2])][n[1]][z] > i + 1) {
                        all[n[0] - (z - n[2])][n[1]][z] = i + 1;
                        distance[i + 1].push_back({n[0] - (z - n[2]),n[1],z});
                        if ((n[0] - (z - n[2])) == ans) {
                            minv = i + 1;
                            break;
                        }
                    }
                }
////////////////////////////////////////////////////////////
                if (n[0] + n[1] < y) {
                    if (all[0][n[1] + n[0]][n[2]] > i + 1) {
                        all[0][n[1] + n[0]][n[2]] = i + 1;
                        distance[i + 1].push_back({0,n[1] + n[0],n[2]});
                        if ((n[1] + n[0]) == ans) {
                            minv = i + 1;
                            break;
                        }
                    }
                }
                else if (n[0] + n[1] > y) {
                    if (all[n[0] - (y - n[1])][y][n[2]] > i + 1) {
                        all[n[0] - (y - n[1])][y][n[2]] = i + 1;
                        distance[i + 1].push_back({n[0] - (y - n[1]),y,n[2]});
                        if ((n[0] - (y - n[1])) == ans) {
                            minv = i + 1;
                            break;
                        }
                    }
                }
/////////////////////////////////////////////////////////////
                if (n[2] + n[1] < y) {
                    if (all[n[0]][n[1] + n[2]][0] > i + 1) {
                        all[n[0]][n[1] + n[2]][0] = i + 1;
                        distance[i + 1].push_back({n[0],n[1] + n[2],0});
                        if ((n[1] + n[2]) == ans) {
                            minv = i + 1;
                            break;
                        }
                    }
                }
                else if (n[2] + n[1] > y) {
                    if (all[n[0]][y][n[2] - (y - n[1])] > i + 1) {
                        all[n[0]][y][n[2] - (y - n[1])] = i + 1;
                        distance[i + 1].push_back({n[0],y,n[2] - (y - n[1])});
                        if ((n[2] - (y - n[1])) == ans) {
                            minv = i + 1;
                            break;
                        }
                    }
                }
            }
            if (minv != inf) {
                break;
            }
        }
        if (minv != inf) {
            std::cout << minv;
        } else {
            std::cout << -1;
        }
    }
}
