#include <iostream>
#include <cassert>


struct Tokens {

	std::string::iterator begin;
	std::string::iterator end;

	Tokens(std::string::iterator begin, std::string::iterator end): begin(begin), end(end) {}

	bool operator>>(std::string& token) {

		if (begin == end) return false;

		char c;

		while (begin != end) {
			c = *begin;

			if (c == ' ') {
				begin++;
				break;
			} else {
				begin++;
				token.push_back(c);
			}
		}

		return true;
	}

};


void print_tokens(const char* str, char sep) {

	char c;
	int i = 0;
	while (true) {
		c = *(str + i);

		if (c == sep)
			std::cout << std::endl;
		else
			std::cout << c;

		if (c == '\0') {
			std::cout << std::endl;
			break;
		}

		i++;
	}
}


int main() {
	// Case 1
	print_tokens("foo bar", ' ');

	// Case 2
	std::string s = "foo bar";

	Tokens tokenize(s.begin(), s.end());

	// TODO: This construction is clumsy. Think how to make it better
	while(true) {
		std::string token;
		if (tokenize >> token)
			std::cout << token << std::endl;
		else break;
	}

}
