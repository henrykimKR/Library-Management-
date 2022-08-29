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
#include <iostream>
#include <iomanip>
#include <fstream>
#include "LibApp.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
    bool LibApp::confirm(const char* message)
    {
        Menu menu(message);
        menu << "Yes";
        return menu.run() == 1;
    }
    void LibApp::load()
    {
        cout << "Loading Data" << endl;
        ifstream ifstr(m_fileName);
        char type;
        int llrn = 0;
        do
        {
            type = '\0';
            ifstr >> type;
            if (type == 'P') m_ppa[m_nolp] = new Publication();
            else if (type == 'B') m_ppa[m_nolp] = new Book();
            if (type == 'P' || type == 'B')
            {
                ifstr >> *m_ppa[m_nolp];
                llrn = m_ppa[m_nolp++]->getRef();
            }
        } while (ifstr);
        m_llrn = llrn;
    }
    void LibApp::save()
    {
        cout << "Saving Data" << endl;
        ofstream ofstr(m_fileName);
        for (int i = 0; i < m_nolp; i++)
        {
            if (m_ppa[i]->getRef() != 0) ofstr << *m_ppa[i] << endl;
        }
    }
    int LibApp::search(int menuSelect)
    {
        PublicationSelector pSelector("Select one of the following found matches:");
        int select = m_pubType.run();
        char type{};
        char temp[256 + 1];
        int lrn = 0;

        cout << "Publication Title: ";
        cin.getline(temp, 255);
        switch (select)
        {
        case 1:
            type = 'B';
            break;
        case 2:
            type = 'P';
            break;
        }
        if (select == 1 || select == 2)
        {
            for (int i = 0; i < m_nolp; i++)
            {
                if (m_ppa[i] && m_ppa[i]->type() == type && *m_ppa[i] == temp)
                {
                    if (menuSelect == 0)
                    {
                        pSelector << m_ppa[i];
                    }
                    else if (menuSelect == 1)
                    {
                        if (m_ppa[i]->onLoan())
                            pSelector << m_ppa[i];
                    }
                    else if (menuSelect == 2)
                    {
                        if (!m_ppa[i]->onLoan())
                            pSelector << m_ppa[i];
                    }
                }
            }
            if (pSelector)
            {
                pSelector.sort();
                if ((lrn = pSelector.run()) == 0) cout << "Aborted!" << endl;
            }
            else cout << "No matches found!" << endl;
        }
        else cout << "Aborted!" << endl;
        return lrn;
    }
    void LibApp::returnPub()
    {
        cout << "Return publication to the library" << endl;
        int lrn = search(1);
        if (lrn != 0)
        { 
            Publication* returnPub = getPub(lrn);
            returnPub->write(cout);
            cout << endl;
            if (confirm("Return Publication?"))
            {
                int duration = Date() - returnPub->checkoutDate();
                cout << setprecision(2) << fixed;
                if (duration > 15)
                {
                    cout << "Please pay $" << (duration - 15) * 0.5 << " penalty for being " << duration - 15 << " days late!" << endl;
                }
                returnPub->set(0);
                m_changed = true;
                cout << "Publication returned" << endl;
            }
        }
    }
    void LibApp::newPublication()
    {
        if(m_nolp == SDDS_LIBRARY_CAPACITY) cout << "Library is at its maximum capacity!" << endl;
        else
        {
            cout << "Adding new publication to the library" << endl;
            int select = m_pubType.run();
            Publication* pptr = nullptr;
            switch (select)
            {
            case 1: 
                pptr = new Book();
                break;
            case 2: 
                pptr = new Publication();
                break;
            }
            if (select == 1 || select == 2)
            {
                if (!(pptr->read(cin)))
                {
                    cin.ignore(1000, '\n');
                    cout << "Aborted!" << endl;
                }
                else
                {
                    if (confirm("Add this publication to the library?"))
                    {
                        if (*pptr)
                        {
                            pptr->setRef(++m_llrn);
                            m_ppa[m_nolp++] = pptr;
                            m_changed = true;
                            cout << "Publication added" << endl;
                        }
                        else
                        {
                            cout << "Failed to add publication!" << endl;
                            delete pptr;
                        }
                    }
                    else cout << "Aborted!" << endl;
                }
            }
            else cout << "Aborted!" << endl;
        }


    }
    void LibApp::removePublication()
    {
        cout << "Removing publication from the library" << endl;
        int lrn = search(0);
        if (lrn != 0)
        {
            Publication* remove = getPub(lrn);
            remove->write(cout);
            cout << endl;
            if (confirm("Remove this publication from the library?"))
            {
                remove->setRef(0);
                m_changed = true;
                cout << "Publication removed" << endl;
            }
        }
    }
    void LibApp::checkOutPub()
    {
        cout << "Checkout publication from the library" << endl;
        int lrn = search(2);
        if (lrn != 0)
        {
            Publication* checkOut = getPub(lrn);
            checkOut->write(cout);
            cout << endl;
            if (confirm("Check out publication?"))
            {
                cout << "Enter Membership number: ";
                checkOut->set(getIntForMemberShip(10000, 99999));
                m_changed = true;
                cout << "Publication checked out" << endl;
            }
        }
    }
    LibApp::LibApp(const char* fileName) :m_fileName{ "" }, m_ppa{ nullptr }, m_nolp{ 0 }, m_llrn{ 0 }, m_pubType{ "Choose the type of publication:" }, m_changed(false), m_mainMenu("Seneca Library Application"), m_exitMenu("Changes have been made to the data, what would you like to do?")
    {
        strcpy(m_fileName, fileName);
        m_pubType << "Book" << "Publication";
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
        load();
    }
    LibApp::~LibApp()
    {
        for (int i = 0; i < m_nolp; i++)
        {
            delete m_ppa[i];
        }
    }
    void LibApp::run()
    {
        bool flag = true;
        int selection = -1;
        while (flag)
        {
            selection = m_mainMenu.run();
            switch (selection)
            {
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            default:
                if (m_changed)
                {
                    selection = m_exitMenu.run();
                    if (selection == 1)
                    {
                        save();
                        flag = false;
                    }
                    else if (selection == 0)
                    {
                        if (confirm("This will discard all the changes are you sure?"))
                        {
                            flag = false;
                        }
                    }
                }
                else flag = false;
            }
            cout << endl;
        }
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }
    Publication* LibApp::getPub(int libRef) const
    {
        Publication* pptr = nullptr;
        for (int i = 0; i < m_nolp && !pptr; i++)
        {
            if (m_ppa[i]->getRef() == libRef) pptr = m_ppa[i];
        }
        return pptr;
    }
}

