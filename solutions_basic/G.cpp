#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    map <char, int> alphabet; 
    map <char, int> values;
    string s;
    string first_part_of_answer = "";
    string second_part_of_answer = "";
    cin >> s;
    
    for (char i = 'a'; i <= 'z'; i++) {
        cin >> alphabet[i]; 
    }
    
    for (char i: s) {
        if (values.count(i) == 0) values[i] = 1;
        else values[i]++;
    }
    for(char i = 'a'; i <= 'z'; i++) {
      int max_ind = 'a';
      for(char j = 'b'; j <= 'z' ; j++)
        if (alphabet[j] > alphabet[max_ind] && values[j] > 0 || values[max_ind] == 0) max_ind = j;
      if (values[max_ind] >= 2) {
        first_part_of_answer += max_ind;
        values[max_ind] -= 2;
      } 
      while (values[max_ind] > 0) {
        second_part_of_answer += max_ind;
        values[max_ind]--;
      }
    }
    cout << first_part_of_answer << second_part_of_answer;
	string third_part_of_answer = "";
    for (int i = first_part_of_answer.length() - 1; i >= 0; i--) {
        third_part_of_answer += first_part_of_answer[i];
    }
	cout << third_part_of_answer;
    return 0;
}