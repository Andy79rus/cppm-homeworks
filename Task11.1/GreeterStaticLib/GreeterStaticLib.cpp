#include "GreeterStaticLib.h"

namespace GreeterStaticLib
{
	std::string Greeter::greet(std::string s)
	{
		return "Здравствуйте, " + s + "!\n";
	}
}