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
#include "Publication.h"
#include "Lib.h"
using namespace std;
namespace sdds
{
	Publication::Publication() : m_title{ nullptr }, m_shelfId{ "" }, m_membership{ 0 }, m_libRef{ -1 }, m_date{ Date() }
	{
	}
	Publication::Publication(const Publication& origin) : m_title{ nullptr }, m_shelfId{ "" }, m_membership{ 0 }, m_libRef{ -1 }, m_date{ Date() }
	{
		*this = origin;
	}
	Publication::~Publication()
	{
		delete[] m_title;
	}
	Publication& Publication::operator=(const Publication& origin)
	{
		if (this != &origin)
		{
			if (origin.m_title)
			{
				delete[] m_title;
				m_title = new char[strlen(origin.m_title) + 1];
				strcpy(m_title, origin.m_title);
			}
			strcpy(m_shelfId, origin.m_shelfId);
			m_membership = origin.m_membership;
			m_libRef = origin.m_libRef;
			m_date = origin.m_date;
		}
		return *this;
	}
	void Publication::set(int member_id)
	{
		if (member_id < 100000 && member_id >= 0) m_membership = member_id;
	}
	void Publication::setRef(int value)
	{
		m_libRef = value;
	}
	void Publication::resetDate()
	{
		m_date = Date();
	}
	char Publication::type() const
	{
		return 'P';
	}
	bool Publication::onLoan() const
	{
		return m_membership != 0;
	}
	Date Publication::checkoutDate() const
	{
		return m_date;
	}
	bool Publication::operator==(const char* title) const
	{
		return strstr(m_title, title);
	}
	Publication::operator const char* () const
	{
		return m_title;
	}
	int Publication::getRef() const
	{
		return m_libRef;
	}
	bool Publication::conIO(std::ios& io) const
	{
		return &io == &cin || &io == &cout;
	}
	std::ostream& Publication::write(std::ostream& ostr) const
	{
		if (conIO(ostr))
		{
			ostr << "| " << m_shelfId << " | ";
			if (strlen(m_title) > SDDS_TITLE_WIDTH)
			{
				for (int i = 0; i < SDDS_TITLE_WIDTH; i++)
				{
					ostr << m_title[i];
				}
			}
			else ostr << setw(30) << left << setfill('.') << m_title;
			ostr << " | ";
			if (m_membership > 0)
			{
				ostr << m_membership;
			}
			else
			{
				ostr << " N/A ";
			}
			ostr << " | " << m_date << " |";
		}
		else
		{
			ostr << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t' << m_title << '\t' << m_membership << '\t' << m_date;
		}
		return ostr;
	}
	std::istream& Publication::read(std::istream& istr)
	{
		delete[] m_title;
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		m_date = Date();
		char tempTitle[256];
		char tempShelf[256];
		if (conIO(istr))
		{
			cout << "Shelf No: ";
			istr >> tempShelf;
			if (strlen(tempShelf) != SDDS_SHELF_ID_LEN)
			{
				istr.setstate(std::ios::failbit);
			}
			else
			{
				strcpy(m_shelfId, tempShelf);
			}
			istr.ignore(1000, '\n');
			cout << "Title: ";
			istr.getline(tempTitle, 255);
			cout << "Date: ";
			istr >> m_date;
			if (!m_date)
			{
				istr.setstate(std::ios::failbit);
			}

		}
		else
		{
			istr >> m_libRef;
			istr.ignore();
			istr >> m_shelfId;
			istr.ignore();
			istr.getline(tempTitle, 255, '\t');
			istr >> m_membership;
			istr.ignore();
			istr >> m_date;
			if (!m_date)
			{
				istr.setstate(std::ios::failbit);
			}
		}
		if (istr)
		{
			m_title = new char[strlen(tempTitle) + 1];
			strcpy(m_title, tempTitle);
		}
		return istr;
	}
	Publication::operator bool() const
	{
		return m_title && m_title[0] != '\0' && m_shelfId[0] != '\0';
	}
}