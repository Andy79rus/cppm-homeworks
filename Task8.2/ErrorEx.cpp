#include "ErrorEx.h"

FigureException::FigureException(std::string const& what) : std::domain_error(what)
{}