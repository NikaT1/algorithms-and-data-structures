#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  int color; //0 - white, 1 - grey, 2 - black
  int predecessor;
  
  Node(){
      predecessor = 0;
      color = 0;
  };
};


int DFS_visit(vector <vector<int>>& graph, int i, vector <struct Node>& nodes) {
    nodes[i].color = 1;
    for (int j: graph[i]) {
        if (!nodes[j].color) {
            nodes[j].predecessor = i;
            int result = DFS_visit(graph, j, nodes);
            if (result) return result;
        } else {
            if (nodes[j].color == 1) {
                return 1;
                nodes[i].color = 2;
            }
        } 
    }
    nodes[i].color = 2;
    return 0;
}

int main() {
    vector <vector<int>> graph;
    vector <struct Node> nodes;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        graph.push_back(vector<int>());
    }
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        tmp--;
        graph[tmp].push_back(i);
        nodes.push_back(Node());
    }
    int circles = 0;
    for (int i = 0; i < n; i++)
        if (!nodes[i].color) circles += DFS_visit(graph, i, nodes);
        
    cout << circles;
    return 0;
}
