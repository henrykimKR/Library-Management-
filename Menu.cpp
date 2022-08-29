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
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
	MenuItem::MenuItem(const char* cstr)
	{
		if (cstr && cstr[0] != '\0')
		{
			m_content = new char[strlen(cstr) + 1];
			strcpy(m_content, cstr);
		}
		else m_content = nullptr;

	}
	MenuItem::~MenuItem()
	{
		delete[] m_content;
	}
	MenuItem::operator const char* () const
	{
		return m_content;
	}
	std::ostream& MenuItem::display(std::ostream& os) const
	{
		if (m_content)
		{
			os << m_content;
		}
		return os;
	}

	Menu::Menu() :m_noOfptrs{ 0 }
	{

	}
	Menu::Menu(const char* title) : m_title{ title }, m_noOfptrs{ 0 }
	{
	}

	Menu::~Menu()
	{
		for (unsigned int i = 0; i < m_noOfptrs; i++)
		{
			delete m_menuItemPtrs[i];
		}

	}

	std::ostream& Menu::displayTitle(std::ostream& os) const
	{
		if (m_title)
		{
			m_title.display(os);
		}
		return os;
	}

	std::ostream& Menu::display(std::ostream& os) const
	{
		if (*this)
		{
			if (m_title)
			{
				displayTitle(os);
				os << endl;
			}
			for (unsigned int i = 0; i < m_noOfptrs; i++)
			{
				os << setw(2) << right << i + 1 << "- ";
				m_menuItemPtrs[i]->display(os);
				os << endl;
			}
			os << " 0- Exit" << endl << "> ";
		}

		return os;
	}

	unsigned int Menu::run() const
	{
		display(cout);
		unsigned int menuNum = (unsigned int)getInt(0, m_noOfptrs);
		return menuNum;
	}

	unsigned int Menu::operator~() const
	{
		return run();
	}

	Menu::operator unsigned int() const
	{
		return m_noOfptrs;
	}
	const char* Menu::operator[](int index) const
	{
		return m_menuItemPtrs[index % m_noOfptrs]->m_content;
	}
	Menu::operator int() const
	{
		return (int)m_noOfptrs;
	}
	Menu::operator bool() const
	{
		return m_noOfptrs > 0;
	}
	Menu& Menu::operator<<(const char* menuitemConent)
	{
		if (m_noOfptrs < MAX_MENU_ITEMS)
		{
			m_menuItemPtrs[m_noOfptrs++] = new MenuItem(menuitemConent);
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Menu& menu)
	{
		return menu.displayTitle(os);
	}

}

