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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "Book.h"
using namespace std;
namespace sdds
{
	Book::Book() : m_author{ nullptr }
	{
	}
	Book::Book(Book& obj) : m_author{ nullptr }
	{
		*this = obj;
	}
	Book& Book::operator=(const Book& obj)
	{
		if (this != &obj)
		{
			Publication::operator=(obj);
			if (obj.m_author)
			{
				delete[] m_author;
				m_author = new char[strlen(obj.m_author) + 1];
				strcpy(m_author, obj.m_author);
			}
		}
		return *this;
	}
	Book::~Book()
	{
		delete[] m_author;
	}
	char Book::type() const
	{
		return 'B';
	}
	std::ostream& Book::write(std::ostream& ostr) const
	{
		char temp[SDDS_AUTHOR_WIDTH + 1] = {};
		strncpy(temp, m_author, SDDS_AUTHOR_WIDTH);
		Publication::write(ostr);
		if (conIO(ostr)) // if it is console IO
		{
			ostr << ' ';
			if (strlen(m_author) > SDDS_AUTHOR_WIDTH) ostr << temp;
			else ostr << setw(SDDS_AUTHOR_WIDTH) << left << m_author;
			ostr << " |";
		}
		else
		{
			ostr << '\t' << m_author;
		}
		return ostr;
	}
	std::istream& Book::read(std::istream& istr)
	{
		char temp[256 + 1];
		Publication::read(istr);
		delete[] m_author;
		if (conIO(istr))
		{
			istr.ignore();
			cout << "Author: ";
			istr.get(temp, 256);
		}
		else
		{
			istr.ignore();
			istr.get(temp, 256);
		}
		if (istr)
		{
			m_author = new char[strlen(temp) + 1];
			strcpy(m_author, temp);	
		}
		return istr;
	}
	void Book::set(int member_id)
	{
		Publication::set(member_id);
		Publication::resetDate();
	}
	Book::operator bool() const
	{
		return Publication::operator bool() && m_author && m_author[0] != '\0';
	}
}