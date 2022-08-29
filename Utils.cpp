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

/***********************************************************************
// OOP244 Utils Module:
// File  utils.cpp
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
using namespace std;
#include "Utils.h"
namespace sdds {
	int getInt(int min, int max)
	{
		int val;
		int flag = 0;
		do
		{
			cin >> val;
			if (cin.fail())
			{
				cout << "Invalid Selection, try again: ";
				cin.clear();
				while (cin.get() != '\n');
			}
			else if (cin.get() != '\n')
			{
				cout << "Invalid Selection, try again: ";
				while (cin.get() != '\n');
			}
			else if (val<min || val>max)
			{
				cout << "Invalid Selection, try again: ";
			}
			else flag = 1;

		} while (flag == 0);
		return val;
	}
	int getIntForMemberShip(int min, int max)
	{
		int val;
		int flag = 0;
		do
		{
			cin >> val;
			if (cin.fail())
			{
				cout << "Invalid membership number, try again: ";
				cin.clear();
				while (cin.get() != '\n');
			}
			else if (cin.get() != '\n')
			{
				cout << "Invalid membership number, try again: ";
				while (cin.get() != '\n');
			}
			else if (val<min || val>max)
			{
				cout << "Invalid membership number, try again: ";
			}
			else flag = 1;

		} while (flag == 0);
		return val;
	}
}