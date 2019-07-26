#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>
#include <queue>
#include <set>
#include <numeric>
#include <map>

using std::vector;

struct Vertex{
  Vertex():isinf(true), val(0.0){}
  explicit Vertex(double val): isinf(false),val(val){}
  bool isinf;
  double val;
};

bool operator>(const Vertex &l, const Vertex &r){
  if (!l.isinf && !r.isinf){
    return l.val > r.val;
  } else if (l.isinf && !r.isinf){
    return true;
  } else{
    return false;
  }
}

Vertex distance (double z, double v, const vector <int> &x, const vector <int> &y){
  double xDiff = static_cast <double>(x[z]) - x[v];
  double yDiff = static_cast <double>(y[z]) - y[v];
  return Vertex(std::sqrt(xDiff * xDiff + yDiff * yDiff));
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  std::map <int, Vertex> cost;
  cost[0] = Vertex(0.0);
  auto cmp = [&cost](int a, int b){return cost[a] > cost[b];};
  std::priority_queue <int, vector<int>, decltype(cmp)> pq(cmp);
  std::set <int> unfixed;
  for (int i = 0; i < x.size(); i++){
    unfixed.insert(i);
  }
  pq.push(0);
  while(!unfixed.empty()){
    int v = pq.top();
    pq.pop();
    unfixed.erase(v);
    result = result + cost[v].val;
    while(!pq.empty()){
      pq.pop();
    }
    for(int i = 0; i < x.size(); i++){
      if(unfixed.find(i) != unfixed.end()){
        if(cost[i] > distance(i,v,x,y)){
          cost[i] = distance(i,v,x,y);
        }
        pq.push(i);
      }
    }
  }
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
