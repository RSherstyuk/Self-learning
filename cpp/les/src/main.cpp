#include "FileRaii.h"
#include <iostream>

int main() {
  std::string file_name = "file.txt";
  try {
    FileRaii f(file_name);
    auto ss = f.Read();
    std::cout << ss << "\n";
  } catch (const CannotOpenFileException&){
    std::cout << "FIle not found";
  }
}
