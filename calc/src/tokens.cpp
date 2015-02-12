#include <iostream>
#include <cassert>


struct Tokens {

	std::string& str;
	std::string::iterator it;

	Tokens(std::string& str): str(str) {
		it = str.begin();
	}

	bool operator>>(std::string& token) {

		char c;

		while (it != str.end()) {
			c = *it;

			if (c == ' ' || c == '\0') {
				token.push_back('\0');
				break;
			}

			token.push_back(c);
			++it;
		}

		return it != str.end();
	}

};


void print_tokens(const char* str, char sep) {

	char c;
	int i = 0;
	while (true) {
		char c = *(str + i);

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


int main(void) {
	// Case 1
	print_tokens("foo bar", ' ');

	// Case 2
	std::string s = "foo bar";
	std::string buf;

	Tokens tokenize1(s);

	assert(tokenize1.operator>>(buf));
	assert(!tokenize1.operator>>(buf));  // Fails

	Tokens tokenize2(s);
	while (tokenize2 >> buf) {
		std::cout << buf << std::endl;
	}


}
