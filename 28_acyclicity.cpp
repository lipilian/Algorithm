#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::pair;

bool isCircle(const vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &chain, int N){
  if (visited[N] == false){
    visited[N] = true;
    chain[N] = true;
    for(int i = 0; i < adj[N].size(); i++){
      if (!visited[adj[N][i]] && isCircle(adj,visited,chain,adj[N][i])){
        return true;
      } else if(chain[adj[N][i]]){
        return true;
      }
    }
  }
  chain[N] = false;
  return false;
}

int acyclic(vector<vector<int> > &adj) {
  vector<bool> visited(adj.size(),false);
  vector<bool> chain(adj.size(), false);
  for(int i = 0; i<adj.size();i++){
    if(isCircle(adj,visited,chain,i)){
      return 1;
    }
  }
  return 0; 
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
