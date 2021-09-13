/**
 * Header file for table
 * 
 * Author: Bradley Henderson
*/

#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T>
class Table
{
    //Output
    friend ostream& operator<<(ostream&, const Table<T>&);

    friend Table<T> operator+(const Table<T>&, const T&);

    public:
        Table(int = 2, int = 5);
        Table(const int = 2);
        Table(Table&);
        Table& operator=(const Table&);
        ~Table();

        int get_rows();
        int get_cols();

        Table<T>* append_rows(const Table<T>&);
        Table<T>* append_cols(const Table<T>&);

        T& operator()(int, int);
        Table<T>& operator()(int, int, int, int);
    private:
        int rowCount;
        int columnCount;
        T** pTable;
};

#endif