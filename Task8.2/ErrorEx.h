#pragma once
#include <stdexcept>

enum class ErrorCode { Success = 0, NonPositiveSideErrorCode = 10,TriangleSidesErrorCode = 11,
						AnglesSumNot180ErrorCode = 21, AnglesSumNot360ErrorCode = 22, UnknownErrorCode = 99 };

class FigureHierarhyException : public std::domain_error
{
private:
	ErrorCode er;

protected:
	void set_error_code(ErrorCode);

public:
	FigureHierarhyException(ErrorCode ErrorType);
	ErrorCode get_error_code() const;
	const char* what() const override;
};