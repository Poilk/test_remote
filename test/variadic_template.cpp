//
// Created by 文欣 on 2022/6/15.
//
#include <string>
#include <iostream>


template<typename T>
void foo(const T &t){
  std::cout << "~~" << std::endl;
}

template <typename T, typename ... Args>
void foo(const T &t, const Args& ... rest){
  std::cout << "sizeof ...Args " << sizeof...(Args) << std::endl;
  std::cout << "sizeof ...rest " << sizeof...(rest) << std::endl;
  foo(rest...);
}

class Struct{
    explicit Struct(int x){
      
    };
  };

int main(int argc, char *argv[]){
  int i = 0; double d = 3.14;
  std::string s = "how now brown cow";

  foo(i, s, 42, d);
  foo(d, s);
  foo("hi");
  return 0;
}
