//
// Created by 文欣 on 2022/4/27.
//

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <queue>

class S{
  int x;
  int y;
};

int main(int argc, char *argv[]){
    std::string sa, sb{"fuck"};
    std::cout << std::min(sa.size(), sb.size()) - 1 << std::endl;
    std::vector<int> va, vb{1, 2};
    std::cout << int(std::min(va.size(), vb.size()) - 1) << std::endl;
    std::cout << UINT64_MAX << std::endl;
    std::regex txt_regex("[A-Za-z]+\\.txt");

    std::priority_queue<int, std::vector<int>, std::less<int>> pq;
    pq.push(1);
    pq.push(2);
    std::cout << pq.top() << std::endl;

}