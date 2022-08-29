/*
*****************************************************************************
							  Milestone 5
Full Name  : Seonghoon Kim
Student ID#: 143080216
Email      : shkim61@myseneca.ca
Section    : NGG
Date	   : 08.06.2022

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my project milestones.
*****************************************************************************
*/

#include "Streamable.h"
namespace sdds
{
	std::ostream& operator<<(std::ostream& os, const Streamable& streamable)
	{
		if (streamable) streamable.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, Streamable& streamable)
	{
		return streamable.read(is);
	}
}

