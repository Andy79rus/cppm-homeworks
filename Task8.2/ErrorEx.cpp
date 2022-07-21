#include "ErrorEx.h"

FigureHierarhyException::FigureHierarhyException(ErrorCode ErrorType) : std::domain_error("")
{
	set_error_code(ErrorType);
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
	switch (static_cast<int>(er))
	{
		case static_cast<int>(ErrorCode::NonPositiveSideErrorCode):
				return "все длины сторон должны быть положительным числом";
			break;
		case static_cast<int>(ErrorCode::TriangleSidesErrorCode):
				return "сумма длин любых двух сторон треугольника должна быть строго больше длинны третьей стороны";
			break;
		case static_cast<int>(ErrorCode::AnglesSumNot180ErrorCode):
				return "сумма углов треугольника не равна 180";
			break;
		case static_cast<int>(ErrorCode::AnglesSumNot360ErrorCode):
				return "сумма углов четырехугольника не равна 360";
			break;
		case static_cast<int>(ErrorCode::UnknownErrorCode):
				return "неизвестная ошибка";
			break;
		case static_cast<int>(ErrorCode::Success):
		default:
				return "";
			break;
	}
}