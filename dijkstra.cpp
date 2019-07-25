#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  vector <int> dist (adj.size(), std::numeric_limits<int>::max());
  dist[s] = 0;
  vector <int> prev (adj.size(), -1);
  auto cmp = [&dist](int a, int b){ return a > b;};
  priority_queue <int, vector<int>, decltype(cmp)> pq(cmp);
  pq.push(s);
  while (!pq.empty()){
    auto u = pq.top();
    pq.pop();
    for (int i = 0; i < adj[u].size(); i++){
      auto next = adj[u][i];
      if (dist[next] > dist[u] + cost[u][i]){
        dist[next] = dist[u] + cost[u][i];
        prev[next] = u;
        pq.push(next);
      }
    }
  }
  if (dist[t] == std::numeric_limits<int>::max())
    return -1;
  return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
