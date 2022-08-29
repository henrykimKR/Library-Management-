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

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds
{
	const unsigned int MAX_MENU_ITEMS = 20;

	class MenuItem
	{
		friend class Menu;
		char* m_content;
		MenuItem(const char* cstr = nullptr);
		MenuItem(const MenuItem& I) = delete;
		MenuItem& operator=(const MenuItem& other) = delete;
		~MenuItem();
		operator const char* ()const;
		std::ostream& display(std::ostream& os) const;
	};
	class Menu
	{
		MenuItem m_title;
		MenuItem* m_menuItemPtrs[MAX_MENU_ITEMS];
		unsigned int m_noOfptrs;
	public:
		Menu();
		Menu(const char* title);
		Menu(const MenuItem& I) = delete;
		~Menu();
		Menu& operator=(const Menu& other) = delete;
		std::ostream& displayTitle(std::ostream& os) const;
		std::ostream& display(std::ostream& os) const;
		unsigned int run() const;
		unsigned int operator~()const;
		Menu& operator<<(const char* menuitemConent);
		operator unsigned int() const;
		operator int() const;
		operator bool() const;
		const char* operator[](int index)const;
	};
	std::ostream& operator<<(std::ostream& os, const Menu& menu);
}
#endif // !SDDS_MENU_H
