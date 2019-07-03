#include <algorithm>
#include <iostream>
#include <vector>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class Node;

class Node {
public:
	int key;
	Node* parent;
	std::vector<Node*> children;

	Node() {
		this->parent = NULL;
	}

	void setParent(Node* theParent) {
		parent = theParent;
		parent->children.push_back(this);
	}
};

int Height(Node* element) {
	if (element->children.empty()) {
		return 0;
	}
	else {
		int h = Height(element->children[0]);
		for (int i = 1; i < element->children.size(); i++) {
			h = std::max(Height(element->children[i]), h);
		}
		return h + 1;
	}
}

int main_with_large_stack_space() {
	std::ios_base::sync_with_stdio(0);
	int n;
	std::cin >> n;
	int maxHeight = 0;
	Node* nodes = new Node[n];
	int root_index = -1;
	for (int child_index = 0; child_index < n; child_index++) {
		int parent_index;
		std::cin >> parent_index;
		if (parent_index == -1) {
			root_index = child_index;
		}
		if (parent_index >= 0)
			nodes[parent_index].children.push_back(&nodes[child_index]); //.setParent(&nodes[parent_index]);
	}

	maxHeight = Height(&nodes[root_index]);

	delete[] nodes;
	std::cout << maxHeight + 1 << std::endl;
	return 0;
}

int main(int argc, char** argv)
{
#if defined(__unix__) || defined(__APPLE__)
	// Allow larger stack space
	const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
	struct rlimit rl;
	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0)
	{
		if (rl.rlim_cur < kStackSize)
		{
			rl.rlim_cur = kStackSize;
			result = setrlimit(RLIMIT_STACK, &rl);
			if (result != 0)
			{
				std::cerr << "setrlimit returned result = " << result << std::endl;
			}
		}
	}

#endif
	return main_with_large_stack_space();
}

