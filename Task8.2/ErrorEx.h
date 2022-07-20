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
	FigureHierarhyException();
	ErrorCode get_error_code() const;
	const char* what() const override;
};

class NonPositiveSideException : public FigureHierarhyException
{
public:
	NonPositiveSideException();
	const char* what() const override;
};

class TriangleSidesException : public FigureHierarhyException
{
public:
	TriangleSidesException();
	const char* what() const override;
};

class AnglesSumNot180Exception : public FigureHierarhyException
{
public:
	AnglesSumNot180Exception();
	const char* what() const override;
};

class AnglesSumNot360Exception : public FigureHierarhyException
{
public:
	AnglesSumNot360Exception();
	const char* what() const override;
};

class UnknownException : public FigureHierarhyException
{
public:
	UnknownException();
	const char* what() const override;
};