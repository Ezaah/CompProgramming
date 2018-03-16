#include <bits/stdc++.h>

int main() {
  size_t students, classes;
  std::cin >> students >> classes;
  std::vector<size_t> class_taken(classes);
  for (size_t i = 0; i < students; i++) {
    size_t student;
    std::cin >> student;
    class_taken[student]++;
  }
  for (size_t i = 0; i < classes; i++) {
    std::cout << class_taken[i];
    if (i < classes - 1) {
      std::cout << " ";
    }
  }
}
