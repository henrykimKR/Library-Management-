# LibraryApps :books: 
As the final project of the C++ course in Seneca College, it is a program that manages books and publications in the Seneca Library. 
This project includes all the lessons learned from OOP course. As follows:
- **Encapsulation**: Data should not be accessed directly from the outside, but only through functions.
- **Inheritance**: Derived class inherits the characteristics and functions of the base class.
- **Abstraction**: Expressing common characteristics (variables, methods) of classes by grouping them together with interfaces.
- **Polymorphism**: It means that one variable name can be interpreted in different meanings depending on the situation.
  - Generally, it means over-riding or overloading.

## Description :pushpin:
When Books and other publications arrive in the Seneca library, they should be tagged and put on shelves, so they are easily retrievable to be lent out to those who need them. 
This application is designed that receives the publications and stores them into the system with the information needed for their retrieval. 
Later, each publication can be lent out to members of the library with a due date for return.

## Modular Programming :pushpin:
### 1. Date Module :key:
A class the encapsulates year, and month and day values for Date stamp, comparison and Date IO purposes.

### 2. Menu Module :key:
This module will hold both MenuItem and Menu Classes’ implementation code.
- #### The MenuItem Class
This class holds only one Cstring of characters for the content of the menu item dynamically.
- #### The Menu Class
The Menu class owns its MenuItem objects.

### 3. LibApp Module :key:
The LibApp class demos the execution of the Seneca Library Application with actually doing the tasks. This module configures the Main Menu and the Publication Type Menu and shows it to the user.

### 4. Streamable Interface module and Publication class module :key:
#### Types of publications in Seneca Library
Seneca Library holds two types of Publication; Periodical (like newspapers and Magazines) and Books.  

**Publications** are not loaned out to members. Members can check them out and read them in the library. These publications are put back on their shelves at the end of the day.  

**Books** can be borrowed and returned within 15 days. After 15 days, the member will be charged daily for a late penalty.

- #### Streamable Interface Module 
Any class inherited from Streamable will have the capability to be inserted into or extracted from a stream.

- #### Publication Class Module
The publication class is a general encapsulation of any periodic publication. This class contains data for publications.

### 5. Book Class Module :key:
The Book class is derived from the Publication class. A book is a publication with an "Author name".

The book class only has one attribute that is a pointer to a character to hold an author's name Dynamically.

### 6. PublicationSelector Module :key:
The PublicationSelector module holds the addresses of a selection of the Publications in an array and lets the user select one of them. Upon user's selection, the Library Reference number of the selected publication is returned to the caller module for further actions.

For example, the array of Publications can be searched for a match to a specific title, and the matches found in the array can be inserted into the PublicationSelector. Then the PublicationSelector can be run to display the search results and ask the user to select one of them.

## Sample Output
```
Seneca Library Application
 1- Add New Publication
 2- Remove Publication
 3- Checkout publication from library
 4- Return publication to library
 0- Exit
> 3
Checkout publication from the library
Choose the type of publication:
 1- Book
 2- Publication
 0- Exit
> 2
Publication Title: Sen
Select one of the following found matches:
 Row  |LocID | Title                          |Mem ID | Date       | Author          |
------+------+--------------------------------+-------+------------+-----------------|
   1- | P008 | MoneySense Magazine........... |  N/A  | 2021/11/11 |
   2- | P008 | MoneySense Magazine........... |  N/A  | 2021/11/18 |
   3- | S001 | Seneca Student Handbook....... |  N/A  | 2022/01/05 |
> X (to Exit)
> Row Number(select publication)
> 3
| S001 | Seneca Student Handbook....... |  N/A  | 2022/01/05 |
Check out publication?
 1- Yes
 0- Exit
> 1
Enter Membership number: 12345
Publication checked out
```
