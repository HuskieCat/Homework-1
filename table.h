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
    //Output
    friend ostream& operator<<(ostream&, const Table<T>&);

    //Arithmetic operations
    friend Table<T>& operator+(const Table<T>&, const int&);

    public:
        Table(int = 2, int = 5);
        Table(int = 2);
        Table(Table&);
        Table& operator=(const Table&);
        ~Table();

        get_rows();
        get_cols();

        T& operator()(int, int);
        Table<T>& operator()(int, int, int, int);
    private:
        int rowCount;
        int columnCount;
        T* pTable;
};

#endif