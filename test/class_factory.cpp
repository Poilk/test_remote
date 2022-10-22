//
// Created by 文欣 on 2022/6/6.
//

#include <memory>
#include <iostream>
#include <unordered_map>
#include <map>

class Frame{
 public:
  typedef std::shared_ptr<Frame> Ptr;
  Frame(): class_name("Frame"){
    print("Constructor");
  }
  virtual ~Frame(){
    print("Destructor");
  }
  void print(const std::string& func_name){
    std::cout << class_name << " " << func_name << std::endl;
  }
 protected:
  std::string class_name;
};

class ShellFrame: public Frame{
 public:
  ShellFrame() {
    class_name = "ShellFrame";
    print("Constructor");
  }
  ~ShellFrame() override{
    print("Destructor");
  }
};

class HwFrame: public Frame{
 public:
  HwFrame() {
    class_name = "HwFrame";
    print("Constructor");
  }
  ~HwFrame() override{
    print("Destructor");
  }
};

class Base{
 public:
  virtual ~Base()= default;;
};

class Derived: public Base{
 public:
  ~Derived() override = default;
};

template<class T>
class DynamicObjectFactor{
 public:
  template<class Derived>
  void register_class(const std::string &name){
    assert(!creator_mp_.count(name));
    static_assert(std::is_convertible<Derived, T>::value, "DynamicObjeectFactor register_class type not match");
    auto func = []() -> std::shared_ptr<T>{
      return std::shared_ptr<T>(new Derived());
    };
    creator_mp_.insert({name, func});
  }
  std::shared_ptr<T> creator_object(const std::string &name){
    std::cout << &creator_mp_ << std::endl;
    if(!creator_mp_.count(name)){
      return {};
    } else{
      return creator_mp_.at(name)();
    }
  }
 private:
  typedef std::function<std::shared_ptr<T>()> creator_func;

  std::map<std::string, creator_func> creator_mp_;
};

DynamicObjectFactor<Frame> frame_factor;
DynamicObjectFactor<Base> base_factor;

int main(int argc, char * argv[]){
  frame_factor.register_class<Frame>("base_frame");
  frame_factor.register_class<ShellFrame>("shell_frame");
  frame_factor.register_class<HwFrame>("hw_frame");
  base_factor.register_class<Base>("base");
  //base_factor.register_class<Frame>("frame");
  base_factor.register_class<Derived>("derived");
  auto fream_1 = frame_factor.creator_object("base_frame");
  auto fream_2 = frame_factor.creator_object("hw_frame");
  auto fream_3 = frame_factor.creator_object("shell_frame");
  std::cout << fream_1 << ' ' << fream_2 << ' ' << fream_3 << std::endl;
  base_factor.creator_object("derived");
  return 0;
}