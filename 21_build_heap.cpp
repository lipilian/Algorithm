#include <iostream>
#include <vector>
#include <algorithm>

class HeapBuilder {
private:
	std::vector<int> data_;
	std::vector< std::pair<int, int> > swaps_;

	void WriteResponse() const {
		std::cout << swaps_.size() << "\n";
		for (int i = 0; i < swaps_.size(); ++i) {
			std::cout << swaps_[i].first << " " << swaps_[i].second << "\n";
		}
	}

	void ReadData() {
		int n;
		std::cin >> n;
		data_.resize(n);
		for (int i = 0; i < n; ++i)
			std::cin >> data_[i];
	}

	void SiftDown(int i) {
		int maxIndex = i;
		int LeftIndex = 2 * i + 1;
		if (LeftIndex < data_.size() && data_[LeftIndex] < data_[maxIndex]) {
			maxIndex = LeftIndex;
		}
		int RightIndex = 2 * i + 2;
		if (RightIndex < data_.size() && data_[RightIndex] < data_[maxIndex]) {
			maxIndex = RightIndex;
		}
		if (i != maxIndex) {
			std::swap(data_[i], data_[maxIndex]);
			swaps_.push_back(std::make_pair(i, maxIndex));
			SiftDown(maxIndex);
		}

	}

	void GenerateSwaps() {
		swaps_.clear();
		// The following naive implementation just sorts 
		// the given sequence using selection sort algorithm
		// and saves the resulting sequence of swaps.
		// This turns the given array into a heap, 
		// but in the worst case gives a quadratic number of swaps.
		//
		// TODO: replace by a more efficient implementation
		for (int i = data_.size() / 2; i >= 0; i--) {
			SiftDown(i);
		}
	}

public:
	void Solve() {
		ReadData();
		GenerateSwaps();
		WriteResponse();
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	HeapBuilder heap_builder;
	heap_builder.Solve();
	return 0;
}
