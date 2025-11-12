#include <cstddef>
#include <iostream>
#include <memory>

class MyObject {
public:
  MyObject() { std::cout << "MyObject создан"; }

  ~MyObject() { std::cout << "MyObject удалён"; }

  void process() { std::cout << "Work"; }

private:
  void doWork(std::unique_ptr<MyObject> obj) { obj->process(); }
};

class Data{
private:
  int* data;
  size_t size;

public:
  Data(size_t s) : size(s){
    data = new int[size];
    std::cout << "Память выделена" << "\n";
  }

  ~Data() {
    if (data != nullptr) {
      delete data;
      std::cout << "Память освобождена" << "\n";
    }
  }
};

class ModernData{
private:
  std::unique_ptr<int[]> data;
  size_t size;

public:
  ModernData(size_t s) : size(s) {
        data = std::make_unique<int[]>(size); 
  }
};


