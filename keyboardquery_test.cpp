#include "keyboardquery.hpp"

#include <iomanip>

void print(const char* t, const char* u) {
  std::cout << std::left << std::setw(10) << t << u << std::endl;
}

int main(int argc, char **argv) {
  KeyboardQuery query;

  print("rules:", query.GetRules());
  print("model:", query.GetModel());
  print("Layout:", query.GetLayout());
  print("variant:", query.GetVariant());
  print("options:", query.GetOptions());

  return 0;
}
