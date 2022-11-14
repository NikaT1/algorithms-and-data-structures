#include <stdio.h>

int main() {
  size_t size = 0;
  scanf("%zu", &size);
  int array[size];
  
  for (size_t i = 0; i < size; i ++) {
    scanf("%d", &array[i]);
  }
  
  size_t max_size = 0;
  size_t curr_size = 0;
  size_t last = 1;
  int count = 1;
  
  for (size_t i = 0; i < size; i++) {
    curr_size++;
    if (i < size - 1) {
      
      if (array[i] == array[i + 1]) { count ++; }
      else count = 1;
      
      if (count == 3) {
        count = 1;
        if (curr_size > max_size) {
          max_size = curr_size;
          last = i + 1;
        }
        curr_size = 1;
        if (array[i] == array[i + 1]) { count ++; }
      }
      
    } else {
      if (curr_size > max_size) {
        max_size = curr_size;
        last = i + 1;
      }
    }
  }
  
  printf("%zu %zu", last + 1 - max_size, last);
  return 0;
}