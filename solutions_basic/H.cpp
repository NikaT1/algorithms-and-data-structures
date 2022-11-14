#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> costs;
    
    for (int i = 0; i < n; i++) {
        int cost;
        cin >> cost;
        costs.push_back(cost);
    }
    
    sort(costs.begin(), costs.end());
    
    for (int i = n - k; i >= 0; i -= k) {
        costs[i] = 0;
    }
    
    int sum = 0;
    for (int i: costs) {
        sum += i;
    }
    cout << sum;
    return 0;
}