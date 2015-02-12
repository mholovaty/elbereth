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

using namespace std;


template <typename T>
T string_to_number(const string &value) {
	stringstream ss(value);
	T result;
	return ss >> result ? result : 0;
}


void tokenize(const string& str, vector<string>& tokens) {
	stringstream ss(str);
	string buf;

	while (ss >> buf)
		tokens.push_back(buf);
}


void print_error() {
	cout << "error" << endl;
}


void calc(const string& line) {
	vector<string> tokens;
	tokenize(line, tokens);

	// TODO: Expression parser

	if (tokens.size() != 3 ) {
		print_error();
		return;
	}

	int a = string_to_number<int>(tokens[0]);
	int b = string_to_number<int>(tokens[2]);
	string sign = tokens[1];

	if (sign == "+") {
		cout << a + b << endl;
	} else if (sign == "-") {
		cout << a - b << endl;
	} else {
		print_error();
	}
}


bool readline(const string& prompt, string& line) {
	cout << prompt;
	return getline(cin, line);
}


int main(void) {
	string line;
	string prompt = "\n> ";

	while (readline(prompt, line)) {
		calc(line);
	}

	return 0;
}
