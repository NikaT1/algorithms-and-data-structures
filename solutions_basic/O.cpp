#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  int color; //0 - white, 1 - grey, 2 - black
  int predecessor;
  int side;
  
  Node(){
      predecessor = 0;
      color = 0;
      side = 0;
  };
};


int DFS_visit(vector <vector<int>>& graph, int i, vector <struct Node>& nodes) {
    nodes[i].color = 1;
    for (int j: graph[i]) {
        if (!nodes[j].color) {
            nodes[j].predecessor = i;
            nodes[j].side = (nodes[i].side + 1) % 2;
            int result = DFS_visit(graph, j, nodes);
            if (!result) return result;
        } else {
            if (nodes[j].side != (nodes[i].side + 1) % 2) {
                return 0;
            }
        } 
    }
    nodes[i].color = 2;
    return 1;
}

int main() {
    vector <vector<int>> graph;
    vector <struct Node> nodes;
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        graph.push_back(vector<int>());
        nodes.push_back(Node());
    }
    for (int i = 0; i < m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tmp1--; tmp2--;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }
    int isOk = 1;
    for (int i = 0; i < n; i++) {
        if (!nodes[i].color) isOk = DFS_visit(graph, i, nodes);
        if (!isOk) break;
    }
        
    if (isOk) cout << "YES";
    else cout << "NO";
    return 0;
}
