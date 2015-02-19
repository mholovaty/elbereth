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
T string_to_number(const std::string &value)
{
	std::stringstream ss(value);
	T result;
	ss >> result;
	return result;
}


void tokenize(const std::string& str, std::vector<std::string>& tokens)
{
	std::stringstream ss(str);
	std::string buf;

	while (ss >> buf)
		tokens.push_back(buf);
}


class EvalError: public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "error";
	}
} eval_error;


float eval(const std::string& line)
{
	std::vector<std::string> tokens;
	tokenize(line, tokens);

	std::string out;

	// TODO: Expression parser

	if (tokens.size() != 3 ) {
		throw eval_error;
	}

	float a = string_to_number<float>(tokens[0]);
	float b = string_to_number<float>(tokens[2]);
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
		if (b == 0) throw eval_error;
		return a / b;
	}

	throw eval_error;
}

class ICalculator {
public:

	/* Consumes and parses a line of input.
	 *  On success, produces one line of output, on error, throws and exception.
	 */
	virtual void OnInput(const std::string& line) = 0;
};


class IOutput {
public:

	virtual void PrintOutput(const std::string& out) = 0;
};


class Calculator: public ICalculator
{
public:
	IOutput& output;

	Calculator(IOutput& output): output(output) {};

	void OnInput(const std::string& line) {
		try
		{
			std::ostringstream convert;

			convert << eval(line);

			output.PrintOutput(convert.str());

		} catch (EvalError& e) {
			output.PrintOutput(e.what());
		}
	}
};


class Console: public IOutput
{
public:
	std::string prompt = "> ";
	
	std::basic_istream<char>& ReadInput(std::string& line)
	{
		std::cout << std::endl << prompt;
		return std::getline(std::cin, line);
	}
	

	void PrintOutput(const std::string& out)
	{
		std::cout << out << std::endl;
	}

};


int main()
{
	std::string line;

	Console console;
	Calculator calculator(console);

	while (console.ReadInput(line))
		calculator.OnInput(line);

	return 0;
}
