#include <iostream>
#include <memory>
#include <vector>

class Logger {
public:
  Logger() { std::cout << "Logger created" << std::endl; }

  ~Logger() { std::cout << "Logger deleted" << std::endl; }

  void log(const std::string &massage) {
    std::cout << "[LOG]: " << massage << std::endl;
  }
};

void process_log(std::unique_ptr<Logger> logger) {
  std::cout << "Entered process log" << std::endl;
  if (logger) {
    logger->log("Processing");
  }
  std::cout << "Exeting process log" << std::endl;
}

std::unique_ptr<int[]> create_buffer(int size) {
  std::cout << "Allocating buffer of size " << size << std::endl;
  auto buffer = std::unique_ptr<int[]>(new int[size]{});
  return buffer;
}

int main() {
  const int buffer_size = 10;

  auto buffer = create_buffer(buffer_size);

  for (int i = 0; i < buffer_size; ++i) {
    buffer[i] = i * 2;
  }

  std::cout << "Buffer contents:" << std::endl;
  for (int i = 0; i < buffer_size; ++i) {

    std::cout << "buffer[" << i << "] = " << buffer[i] << std::endl;
  }

  std::cout << "Exiting main..." << std::endl;

  std::vector<int> v{1, 2, 35, 6, 1};

  std::cout << &v << std::endl;

  return 0;
}
