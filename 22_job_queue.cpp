#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using std::vector;
using std::cin;
using std::cout;

class JobQueue {
private:
	int num_workers_;
	std::vector<int> jobs_;

	std::vector<int> assigned_workers_;
	std::vector<long long> start_times_;

	struct compare {
		bool operator()(const std::pair<int, long long>& a, const std::pair<int, long long>& b) {
			if (a.second == b.second) {
				return a.first > b.first;
			}
			else {
				return a.second > b.second;
			}
		}
	};

	void WriteResponse() const {
		for (int i = 0; i < jobs_.size(); ++i) {
			cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
		}
	}

	void ReadData() {
		int m;
		cin >> num_workers_ >> m;
		jobs_.resize(m);
		for (int i = 0; i < m; ++i)
			cin >> jobs_[i];
	}



	void AssignJobs() {

		assigned_workers_.resize(jobs_.size());
		start_times_.resize(jobs_.size());
		std::priority_queue<std::pair<int, long long>, std::vector<std::pair<int, long long>>, compare>pq;
		for (int i = 0; i < num_workers_; i++) {
			pq.push(std::make_pair(i,0));
		}
		for (int i = 0; i < jobs_.size(); i++) {
			std::pair<int, long long> thread = pq.top();
			pq.pop();
			assigned_workers_[i] = thread.first;
			start_times_[i] = thread.second;
			thread.second += jobs_[i];
			pq.push(thread);
		}
	}

public:
	void Solve() {
		ReadData();
		AssignJobs();
		WriteResponse();
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	JobQueue job_queue;
	job_queue.Solve();
	return 0;
}
