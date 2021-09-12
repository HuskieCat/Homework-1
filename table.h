/**
 * Header file for table
 * 
 * Author: Bradley Henderson
*/

#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#include <iostream>

template <typename T>
class Table
{
    friend ostream& operator<<(ostream&, const Table<T>&);


    public:
        Table(int = 2, int = 5);
        Table(int = 2);
        Table(Table&);
        Table& operator=(const Table&);
        ~Table();
    private:
        int rowCount;
        int columnCount;
        T* pTable;
};

#endif