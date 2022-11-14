#include <iostream>

using namespace std;

int main()
{
    int n;
    int k;
    cin >> n >> k;
    int coords[n];
    for (int i = 0; i < n; i++) cin >> coords[i];
    int l = 0;
    int r = coords[n - 1];
    int min_distance;
    while (l < r) {
        min_distance = (l + r) / 2; 

        int count = 1;
        int current = 0;
        int last = 0;
        while (current < n) {
            if (coords[current] - coords[last] >= min_distance) {
                count++;
                last = current;
            }
            current++;
        }
    
        if (count < k) r = min_distance;
        else l = min_distance + 1;
    }
    cout << l - 1;
    return 0;
}