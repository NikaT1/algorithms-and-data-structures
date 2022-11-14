#include <iostream>

using namespace std;

int main() {
    int bacteria_count; //a
    int growth; //b
    int exp_count; //c
    int capacity; //d
    int days_count; //k
    int prev_count = 0;
  
    cin >> bacteria_count >> growth >> exp_count >> capacity >> days_count;
    int current_day = 0;

    while (current_day < days_count && bacteria_count != prev_count) {
      prev_count = bacteria_count;
      bacteria_count = bacteria_count * growth - exp_count;
      if (bacteria_count <= 0) {
        bacteria_count = 0;
        break;
      }

      if (bacteria_count > capacity) bacteria_count = capacity;

      current_day++;
    }
    cout << bacteria_count << endl;
    return 0;
}