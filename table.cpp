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

    for(int row = 0; row < table.rowCount; row++)
    {
        for(int column = 0; column < table.columnCount; column++)
        {
            out << table[row][column];
        }
        out<<endl;
    }
    return out;
}

template<typename T>
Table<T> operator+(const Table<T>& newTable, const T& value)
{
    Table<T> newTable2 = new T[newTable.rowCount][newTable.columnCount];
    for(int row = 0; row < newTable2.rowCount; row++)
    {
        for(int column = 0; column < newTable2.columnCount; column++)
        {
            newTable2[row][column] = value;
        }
    }

    return newTable2;
}

template<typename T>
Table<T>::Table(const int row, const int column)
{
    rowCount = row;
    columnCount = column;
    //pTable = new T[row][column];
    pTable = new T*[row];
    for(int i = 0; i < row; i++)
        pTable[i] = new T[column];
}

template<typename T>
Table<T>::Table(const int dimensions)
{
    rowCount = dimensions;
    columnCount = dimensions;
    pTable = new T*[dimensions];
    for(int i = 0; i < dimensions; i++)
        pTable[i] = new T[dimensions];
}

template<typename T>
Table<T>::Table(Table<T>& newTable)
{
    pTable = new T[newTable.rowCount];
    for(int row = 0; row < newTable.rowCount; row++)
    {
        pTable[row] = new T[newTable.columnCount];
        for(int column = 0; column < newTable.columnCount; column++)
        {
            pTable[row][column] = newTable.pTable[row][column];
        }
    }



    /*pTable = new T[newTable.rowCount][newTable.columnCount];
    for(int row = 0; row < newTable.rowCount; row++)
        for(int column = 0; column < newTable.columnCount; column++)
            pTable[row][column] = newTable.pTable[row][column];*/

    rowCount = newTable.rowCount;
    columnCount = newTable.columnCount;
}

template<typename T>
Table<T>& Table<T>::operator=(const Table<T>& newTable)
{
    //Erase the table
    for(int row = 0; row < rowCount; row++)
        delete[] pTable[row];
    delete[] pTable;

    //Make new table and copy
    /*pTable = new T[newTable.rowCount][newTable.columnCount];
    for(int row = 0; row < newTable.rowCount; row++)
        for(int column = 0; column < newTable.columnCount; column++)
            pTable[row][column] = newTable.pTable[row][column];*/

    pTable = new T[newTable.rowCount];
    for(int row = 0; row < newTable.rowCount; row++)
    {
        pTable[row] = new T[newTable.columnCount];
        for(int column = 0; column < newTable.columnCount; column++)
        {
            pTable[row][column] = newTable.pTable[row][column];
        }
    }
    rowCount = newTable.rowCount;
    columnCount = newTable.columnCount;
    return *this;
}

template<typename T>
Table<T>::~Table()
{
    for(int row = 0; row < rowCount; row++)
        delete[] pTable[row];
    delete[] pTable;
    rowCount = 0;
    columnCount = 0;
}

template<typename T>
int Table<T>::get_rows()
{
    return rowCount;
}

template<typename T>
int Table<T>::get_cols()
{
    return columnCount;
}

template<typename T>
Table<T>& Table<T>::append_rows(const Table<T>& oldTable)
{
    Table<T> newTable = new T [oldTable.rowCount + rowCount];
    newTable.rowCount = oldTable.rowCount + rowCount;
    newTable.columnCount = oldTable.columnCount;

    /*for(int row = 0; row < newTable.rowCount; row++)
    {
        newTable[row] = new T [oldTable.columnCount];
        for(int column = 0; column < newTable.columnCount; column++)
        {
            if(row < rowCount)
                newTable[row][column] = pTable[row][column];
            else
                newTable[row][column] = oldTable[newTable.rowCount-row][column];
        }
    }*/

    return newTable;
}

template<typename T>
Table<T>& Table<T>::append_cols(const Table<T>& oldTable)
{
    Table<T> newTable = new T [oldTable.rowCount];
    newTable.rowCount = oldTable.rowCount;
    newTable.columnCount = oldTable.columnCount + columnCount;

    /*for(int row = 0; row < newTable.rowCount; row++)
    {
        newTable[row] = new T [oldTable.columnCount + columnCount];
        for(int column = 0; column < newTable.columnCount; column++)
        {
            if(column < columnCount)
                newTable[row][column] = pTable[row][column];
            else
                newTable[row][column] = oldTable[row][newTable.columnCount - column];
        }
    }*/

    return newTable;
}

template<typename T>
T& Table<T>::operator()(int row, int column)
{
    return pTable[row][column];
}

template<typename T>
Table<T>& Table<T>::operator()(int row1, int column1, int row2, int column2)
{
    int newRowCount = abs(row1-row2);
    int newColumnCount = abs(column1-column2);
    Table<T> newTable(newRowCount, newColumnCount);

    int biggerRow = row2;
    int smallerRow = row1;
    int biggerColumn = column2;
    int smallerColumn = column1;

    if(row1 > row2)
    {
        biggerRow = row1;
        smallerRow = row2;
    }
    if(column1 > column2)
    {
        biggerColumn = column1;
        smallerColumn = column2;
    }

    for(int row = smallerRow; row < biggerRow; row++)
    {
        for(int column = smallerColumn; column < biggerColumn; column++)
        {
            newTable[row-smallerRow][column-smallerColumn] = pTable[row][column];
        }
    }

    return newTable;
}