#include <cstdio>
#include <exception>
#include <string>

class CannotOpenFileException {};

class FileRaii {
private:
  std::FILE *f;

public:
  FileRaii(const std::string &name) {
    if (f = std::fopen(name.c_str(), "r"); f == nullptr) {
      throw CannotOpenFileException();
    }
  }

  ~FileRaii() noexcept { std::fclose(f); }

  std::string Read() const {
    char buff[100];
    std::fscanf(f, "%99s", buff);
    return buff;
  }
};
