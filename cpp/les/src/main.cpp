#include "FileRaii.h"
#include "Shape.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Data {
public:
  Data(int v) : value(v) { std::cout << "Data created: " << value << "\n"; }
  ~Data() { std::cout << "Data destroyed: " << value << "\n"; }

  int value;
};

int main() {
  // std::vector<std::unique_ptr<Shape>> shapes;
  //
  // shapes.push_back(std::make_unique<Circle>(10));
  // shapes.push_back(std::make_unique<Sphere>(5));
  // shapes.push_back(std::make_unique<Circle>(7));
  //
  // std::cout << "--- Расчет площадей фигур (полиморфизм) ---\n";
  //
  // for (size_t i = 0; i < shapes.size(); ++i) {
  //   std::cout << i + 1 << ". Площадь фигуры (радиус " << shapes[i]->getR()
  //             << "): " << shapes[i]->getSquare() << std::endl;
  // }
  //
  // std::cout << "\n--- Память автоматически освобождена std::unique_ptr
  // ---\n";

  // auto p1 = std::make_shared<std::vector<int>>();
  // auto p2 = p1;
  //
  // *p1 = {1, 2, 3, 5, 67};
  //
  // for (auto i : *p1) {
  //   std::cout << i << " ";
  // }
  //
  // std::cout << p1 << " " << &p1;

  auto p = std::make_shared<Data>(21);

  auto p2 = p;
  auto p3 = p2;

  cout << p.use_count() << endl;

  return 0;
}
