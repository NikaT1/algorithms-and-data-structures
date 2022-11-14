#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct car{
    int ind;
    int number;
};

int main() {
    auto compare = [](struct car a, struct car b) { return a.number < b.number; };
    set<struct car, decltype(compare)> set(compare);
    vector<vector<int>> numbers; 
    vector<int> order;
    int n, k, p;
    cin >> n >> k >> p;
    bool in_set[n];
    for (int i = 0; i < n; i++) {
        numbers.push_back(vector<int>()); 
        in_set[i] = false;
    }
    for (int i = 0; i < p; i++) {
        int el;
        cin >> el;
        el--;
        numbers[el].push_back(i);
        order.push_back(el);
    }
     for (int i = 0; i < n; i++) {
        numbers[i].push_back(p+1); 
    }
    int answer = 0;
    for (int i = 0; i < p; i++) {
        numbers[order[i]].erase(numbers[order[i]].begin());
        if (!in_set[order[i]]) {
            if (set.size() == k) {
                struct car el = *set.rbegin();
                in_set[el.ind] = false;
                set.erase(prev(set.end()));
            }
            struct car el = {order[i], numbers[order[i]].front()};
            set.insert(el);
            in_set[order[i]] = true;
            answer++;
        } else {
            set.erase(set.begin());
            struct car el;
            el = {order[i], numbers[order[i]].front()};
            set.insert(el);
        }
    }

    cout << answer;
    return 0;
}