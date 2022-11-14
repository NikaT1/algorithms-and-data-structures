#include <iostream>
#include <set>
using namespace std;

struct number{
    int ind;
    int value;
};

int main() {
  int n, k;
  cin >> n;
  cin >> k;
  auto compare = [](struct number a, struct number b) { return a.value < b.value; };
  multiset<struct number, decltype(compare)> set(compare);
  int min_array[n - k + 1];
  int array[n];
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }
  if (k == 1) {
    for (int j = 0; j < n; j++) {
        cout << array[j] << " ";
    }
    return 0;
  }
  for (int i = 0; i < n; i++) {
    struct number item = {i, array[i]};
    set.insert(item);
    if (i >= k - 1) {
      struct number min = *set.begin();
      while (min.ind <= i - k) {
        set.erase(set.begin());
        min = *set.begin();
      }
      min_array[i - k + 1] = min.value;
    }
  }
  for (int j = 0; j < n - k + 1; j++) {
    cout << min_array[j] << " ";
  }
  return 0; 
}