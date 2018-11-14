#include <iostream>
#include <string>
#include "exprtk.hpp"


int main()
{
	typedef exprtk::symbol_table<double> symbol_table_t;
	typedef exprtk::expression<double>     expression_t;
	typedef exprtk::parser<double>             parser_t;

	std::string expression_string = "2 * x - 0.3 * y + 0.5 - (x + y) / 3";

	double x=0, y=0;

	symbol_table_t symbol_table;
	symbol_table.add_variable("x", x);
	symbol_table.add_variable("y", y);
	symbol_table.add_constants();

	expression_t expression;
	expression.register_symbol_table(symbol_table);

	parser_t parser;
	parser.compile(expression_string, expression);

	std::cout << expression.value();

	return 0;
}
