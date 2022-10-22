//
// Created by 文欣 on 2022/5/10.
//

#include <string>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  struct State{
    int cr;
    int cc;
    int mr;
    int mc;
  };

  bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
    std::pair<int, int> pc, pm, pf;
    int rows = grid.size();
    int cols = grid[0].size();
    for(int i = 0; i < grid.size(); i++){
      auto &row = grid[i];
      for(int j = 0;j < row.size(); j++){
        auto &cell = row[j];
        if(cell == 'C'){
          pc = {i, j};
          cell = '.';
        }
        if(cell == 'M'){
          pm = {i, j};
          cell = '.';
        }
        if(cell == 'F'){
          pf = {i, j};
        }
      }
    }
    std::queue<State> q;
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
        const auto &cell = grid[i][j];
        if(cell == '.'){
          mouse_win[i][j][pf.first][pf.second] = true;
          q.push({i, j, pf.first, pf.second});
        }
      }
    }
    while(!q.empty()){
      const auto st = q.front();q.pop();
      cout << "q " << st.mr << ' ' << st.mc << ' ' << st.mr << ' ' << st.mc << '\t';
      for(int flag = -1; flag < 2; flag++){
        if(flag == 0){
          continue;
        }
        int dst_i = st.mr, dst_j = st.mc;
        auto get_cell = [&]() -> char&{
          return grid[dst_i][dst_j];
        };
        auto get_mouse_win_st = [&]() -> bool &{
          return mouse_win[st.cr][st.cc][dst_i][dst_j];
        };
        dst_j = st.mc;
        for(int i = 1; i <= mouseJump; i++){
          dst_i = st.mr + flag * i;
          if(dst_i < 0 || dst_i >= cols){
            break;
          }
          cout << st.mr << ' ' << st.mc << ' ' << dst_i << ' ' << dst_j << '\t';
          if(get_cell() == '#'){
            break;
          }
          if(get_cell() == '.'){
            if(!mouse_win[st.cr][st.cc][dst_i][dst_j]){
              mouse_win[st.cr][st.cc][dst_i][dst_j] = true;
              q.push(State{st.cr, st.cc, dst_i, dst_j});
            }
            //if(!get_mouse_win_st()){
            //    get_mouse_win_st() = true;
            //    static int count = 0;
            //    //cout << ++count;
            //    q.push(State{st.cr, st.cc, dst_i, dst_j});
            //    //cout << count;
            //}
          }
        }
      }
    }
    return true;
  }
  static const int MAX_RC = 9;
  //cr, cc, mr, mc
  bool vis[MAX_RC][MAX_RC][MAX_RC][MAX_RC] {};
  bool mouse_win[MAX_RC][MAX_RC][MAX_RC][MAX_RC] {};
};


int main(int argc, char *argv[]){
  Solution solution;
  std::vector<std::string> grid{"####F","#C...","M...."};
  solution.canMouseWin(grid, 1, 2);
}