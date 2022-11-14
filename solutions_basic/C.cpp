#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    map <string, vector <int>> variables;
    vector <vector <string>> modified_variables;
    modified_variables.push_back(vector <string>());
    string s;
    
    while(cin >> s) {
     int i = s.find('=');
      
     if (i > -1) {
       string var1 = s.substr(0, i);
       string var2 = s.substr(i + 1);
       modified_variables.back().push_back(var1);
       
       if (('0' <= var2[0] && var2[0] <= '9') || var2[0] == '-') {
         variables[var1].push_back(stoi(var2));
         continue;
       }
       
       if (variables.find(var2) == variables.end() || variables[var2].size() == 0) {
         variables[var1].push_back(0);
       } else variables[var1].push_back(variables[var2].back());
       cout << variables[var1].back() << endl;
       continue;
     } 
       
     if (s[0] == '{') {
       modified_variables.push_back(vector <string> ());
     } else {
       vector <string> last_vec =  modified_variables.back();
       modified_variables.pop_back();
       for (i = 0; i < last_vec.size(); i++) {         
        variables[last_vec.at(i)].pop_back();
       }
     }
    }
    return 0;
}