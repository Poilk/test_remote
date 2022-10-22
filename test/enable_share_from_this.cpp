//
// Created by poilk on 2022/7/9.
//

#include <memory>

// enable_shared_from_this need public inherit !!
class Base : public std::enable_shared_from_this<Base>{
 public:
  explicit Base(int x) : x_(x){}
 private:
  int x_;
};

int main(int argc, char *argv[]){
  // p need be a shared_ptr
  auto p = std::make_shared<Base>(10);
  return 0;
}
