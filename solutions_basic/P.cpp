#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  int color; //0 - white, 1 - grey, 2 - black
  
  Node(){
      color = 0;
  };
};


int DFS(vector <vector<int>>& graph, int i, vector <struct Node>& nodes, int min_value, int inverse) {
    nodes[i].color = 1;
    int count = 1;
    for (int j = 0; j < nodes.size(); j++) {
        int value = graph[i][j];
        if (inverse) value = graph[j][i];
        if (!nodes[j].color && value <= min_value) {
            count += DFS(graph, j, nodes, min_value, inverse);
        }
    }
    nodes[i].color = 2;
    return count;
}

int main() {
    int n;
    cin >> n;
    vector <vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
           int tmp;
           cin >> tmp;
           graph[i][j] = tmp;
        }
    }
    int l = 0;
    int r = 2147483647;
    int min_value;
    while (l < r) {
        min_value = (l + r) / 2; 
        vector <struct Node> nodes(n, Node());
        vector <struct Node> reverse_nodes(n, Node());
        
        int isOk = 0;
        isOk = (DFS(graph, 0, nodes, min_value, 0) == n);
        if (isOk) {
            isOk = (DFS(graph, 0, reverse_nodes, min_value, 1) == n);
        }
        if (isOk) r = min_value;
        else l = min_value + 1;
    }
    cout << (l + r) / 2;
    return 0;
}
