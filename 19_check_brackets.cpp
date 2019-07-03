#include <iostream>
#include <stack>
#include <string>

struct Bracket {
	Bracket(char type, int position) :
		type(type),
		position(position)
	{}

	bool Matchc(char c) {
		if (type == '[' && c == ']')
			return true;
		if (type == '{' && c == '}')
			return true;
		if (type == '(' && c == ')')
			return true;
		return false;
	}

	char type;
	int position;
};

int main() {
	std::string text;
	getline(std::cin, text);

	int error_position = 0;

	std::stack <Bracket> opening_brackets_stack;
	for (int position = 0; position < text.length(); ++position) {
		char next = text[position];

		if (next == '(' || next == '[' || next == '{') {
			Bracket b(next, position + 1);
			opening_brackets_stack.push(b);
		}

		if (next == ')' || next == ']' || next == '}') {
			if (opening_brackets_stack.empty()) {
				error_position = position + 1;
				break;
			}
			Bracket top = opening_brackets_stack.top();
			opening_brackets_stack.pop();
			if (!top.Matchc(next)) {
				error_position = position + 1;
				break;
			}
		}
	}

	// Printing answer, write your code here
	if (error_position == 0 && opening_brackets_stack.empty()) {
		std::cout << "Success" << std::endl;
	}
	else {
		if (error_position == 0) {
			while (opening_brackets_stack.size() > 1) {
				opening_brackets_stack.pop();
			}
			error_position = opening_brackets_stack.top().position;
		}
		std::cout << error_position << std::endl;
	}


	return 0;
}
