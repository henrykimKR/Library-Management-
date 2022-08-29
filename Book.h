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
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Publication.h"
namespace sdds
{
	class Book : public Publication
	{
		char* m_author;
	public:
		Book();
		//The rule of three
		Book(Book& obj);
		Book& operator=(const Book& obj);
		~Book();

		char type()const;
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
		void set(int member_id);
		operator bool() const;
	};
}
#endif // !SDDS_BOOK_H
