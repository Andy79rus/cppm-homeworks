#pragma once
#include <stdexcept>

class FigureException : public std::domain_error
{
public:
	FigureException(std::string const& err);
};