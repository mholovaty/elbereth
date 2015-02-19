/*
 ============================================================================
 Name        : calc.cpp
 Author      : Mikhail Golovatyi
 Version     :
 Copyright   : 
 Description : An arithmetic calculator
 ============================================================================
 */
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <exception>


template <typename T>
T string_to_number(const std::string &value) {
	std::stringstream ss(value);
	T result;
	ss >> result;
	return result;
}


void tokenize(const std::string& str, std::vector<std::string>& tokens) {
	std::stringstream ss(str);
	std::string buf;

	while (ss >> buf)
		tokens.push_back(buf);
}


class CalcException: public std::exception {
public:
	virtual const char* what() const throw() {
    return "error";
  }
} calc_exc;


class Calc {
public:
	int eval(const std::string& line) {
		std::vector<std::string> tokens;
		tokenize(line, tokens);

		// TODO: Expression parser

		if (tokens.size() != 3 ) {
			throw calc_exc;
		}

		int a = string_to_number<int>(tokens[0]);
		int b = string_to_number<int>(tokens[2]);
		std::string sign = tokens[1];

		if (sign == "+") {
			return a + b;
		}

		if (sign == "-") {
			return a - b;
		}

		if (sign == "*") {
			return a * b;
		}

		if (sign == "/") {
			if (b == 0) throw calc_exc;
			return a / b;
		}

		throw calc_exc;
	}
};


bool readline(const std::string& prompt, std::string& line) {
	std::cout << std::endl << prompt;
	return std::getline(std::cin, line);
}


int main() {
	std::string line;
	std::string prompt = "> ";

	Calc calc;

	while (readline(prompt, line)) {
		try {
			std::cout << calc.eval(line) << std::endl;
		} catch (CalcException& e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
