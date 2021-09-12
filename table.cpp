/**
 * Implementation file for table
 * 
 * Author: Bradley Henderson
*/

#include "table.h"

template<typename T>
ostream& operator<<(ostream& out, const Table<T> table)
{
    if(table.rowCount == 0)
        out << "∅";
    else if(table.columnCount == 0)
        out << "∅";

    for(int row = 0; row < newTable.rowCount; row++)
    {
        for(int column = 0; column < newTable.columnCount; column++)
        {
            out << table[row][column];
        }
        out<<endl;
    }
    return out;
}

template <typename T>
Table<T>::Table(int row, int column)
{
    rowCount = row;
    columnCount = column;
    pTable = new T[row][column];
}

template <typename T>
Table<T>::Table(int dimensions)
{
    rowCount = dimensions;
    columnCount = dimensions;
    pTable = new T[dimensions][dimensions];
}

template <typename T>
Table<T>::Table(Table<T>& newTable)
{
    pTable = new T[newTable.rowCount][newTable.columnCount];
    for(int row = 0; row < newTable.rowCount; row++)
        for(int column = 0; column < newTable.columnCount; column++)
            pTable[row][column] = newTable.pTable[row][column];

    rowCount = newTable.rowCount;
    columnCount = newTable.columnCount;
}

template <typename T>
Table<T>& Table<T>::operator=(const Table<T>& newTable)
{
    //Erase the table
    for(int row = 0; row < rowCount; row++)
        delete[] pTable[row];
    delete[] pTable;

    //Make new table and copy
    pTable = new T[newTable.rowCount][newTable.columnCount];
    for(int row = 0; row < newTable.rowCount; row++)
        for(int column = 0; column < newTable.columnCount; column++)
            pTable[row][column] = newTable.pTable[row][column];
    rowCount = newTable.rowCount;
    columnCount = newTable.columnCount;
    return *this;
}

template <typename T>
Table<T>::~Table()
{
    for(int row = 0; row < rowCount; row++)
        delete[] pTable[row];
    delete[] pTable;
    rowCount = 0;
    columnCount = 0;
}

template <typename T>
int Table<T>::get_rows()
{
    return rowCount;
}

template <typename T>
int Table<T>::get_cols()
{
    return columnCount;
}