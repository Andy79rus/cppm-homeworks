#include "ErrorEx.h"

FigureHierarhyException::FigureHierarhyException(): std::domain_error("")
{
	set_error_code(ErrorCode::Success);
}

void FigureHierarhyException::set_error_code(ErrorCode e)
{
	this->er = e;
}

ErrorCode FigureHierarhyException::get_error_code() const
{
	return this->er;
}

const char* FigureHierarhyException::what() const
{
	return "";
}

NonPositiveSideException::NonPositiveSideException() : FigureHierarhyException()
{
	set_error_code(ErrorCode::NonPositiveSideErrorCode);
}

const char* NonPositiveSideException::what() const
{
	return "все длины сторон должны быть положительным числом";
}

TriangleSidesException::TriangleSidesException() : FigureHierarhyException()
{
	set_error_code(ErrorCode::TriangleSidesErrorCode);
}

const char* TriangleSidesException::what() const
{
	return "сумма длин любых двух сторон треугольника должна быть строго больше длинны третьей стороны";
}

AnglesSumNot180Exception::AnglesSumNot180Exception() : FigureHierarhyException()
{
	set_error_code(ErrorCode::AnglesSumNot180ErrorCode);
}

const char* AnglesSumNot180Exception::what() const
{
	return "сумма углов треугольника не равна 180";
}

AnglesSumNot360Exception::AnglesSumNot360Exception() : FigureHierarhyException()
{
	set_error_code(ErrorCode::AnglesSumNot360ErrorCode);
}

const char* AnglesSumNot360Exception::what() const
{
	return "сумма углов четырехугольника не равна 360";
}

UnknownException::UnknownException() : FigureHierarhyException()
{
	set_error_code(ErrorCode::UnknownErrorCode);
}

const char* UnknownException::what() const
{
	return "неизвестная ошибка";
}