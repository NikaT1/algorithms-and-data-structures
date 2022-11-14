#include <iostream>
#include <string>
#include <vector>
using namespace std;

 
struct letter
{ 
    int ind;
    int name;
};

int main() {
    string s;
    vector <letter> stack;
   
    cin >> s;
    vector <int> answer(s.size() / 2 + 1);

    int count_small = 0;
    int count_big = 0;
  
    for (int i = 0; i < s.size(); i++) {
      letter current;
      if ('a' <= s[i] && s[i] <='z') {
        count_small++;
        current = {count_small, s[i]};
      } else {
        count_big++;
         current = {count_big, s[i]};
      }
      
      if (stack.empty()) {
        stack.push_back(current);
        continue;
      }
  
      if (s[i] - 32 == stack.back().name || s[i] + 32 == stack.back().name) {
        if ('a' <= s[i] && s[i] <='z') {
          answer[stack.back().ind] = current.ind;
        } else answer[current.ind] = stack.back().ind;
        stack.pop_back();
      }
      else stack.push_back(current);
    }
  
    if (stack.empty()) {
      cout << "Possible" <<endl;
      for (int i = 0; i < answer.size(); i++) {
        if (answer[i] != 0) cout << answer[i] <<" "; 
      }
      cout << endl;
    } else cout << "Impossible" <<endl;
    return 0;
}