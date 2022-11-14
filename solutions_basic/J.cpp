#include <iostream>
#include <deque>
#include <queue>
using namespace std;

deque<string> queue1;
queue<string> queue2;
int size1 = 0, size2 = 0;

void push_priority(string i) {
    if (size1 >= size2) {
        size2++;
        queue2.push(i);
    } else if (size1 < size2) {
        size1++;
        queue1.push_front(i);
    }
}

void push(string i) {
    size1++;
    queue1.push_back(i);
    if (size2 < size1) {
        size1--;
        size2++;
        queue2.push(queue1.front());
        queue1.pop_front();
    }
}

void pop() {
    size2--;
    cout << queue2.front() << endl;
    queue2.pop();
    if (size2 < size1) {
        size1--;
        size2++;
        queue2.push(queue1.front());
        queue1.pop_front();
    }
}

int main() {
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    char s;
    string ind;
    cin >> s;
    if (s == '+') {
      cin >> ind; 
      push(ind);
    }
    if (s == '*') {
      cin >> ind;
      push_priority(ind);
    }
    if (s == '-') {
      pop();
    }
  }
}