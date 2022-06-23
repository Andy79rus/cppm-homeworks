#pragma once
#include <iostream>

#ifdef LEAVERLYBRARYDYNAMIC_EXPORTS
#define LEAVERLYBRARY_API __declspec(dllexport)
#else
#define LEAVERLYBRARY_API __declspec(dllimport)
#endif

namespace LeaverDynamicLib
{
	class Leaver
	{
	public:
		LEAVERLYBRARY_API std::string leave(std::string s);
	};
}