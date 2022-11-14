#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    vector <string> number; 
    string s;
    while(cin >> s) {
        number.push_back(s);
    }
    
    sort(number.begin(), number.end(), 
    [] (string const& a, string const& b) {
        return a + b > b + a;
    });
    for (string s: number) {
        cout << s;
    }

    return 0;
}
