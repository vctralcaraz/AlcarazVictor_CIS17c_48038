/* 
 * File:   Triangle.cpp
 * Author: Victor Alcaraz
 * Created on September 15, 2016, 8:27 PM
 * Purpose: 
 */

#include "Triangle.h"

Triangle::Triangle(int rows)
{
    szRow = rows;
    
    records = new RowAray *[szRow];
    
    for(int i = 0; i < szRow; i++)
    {
        records[i] = new RowAray(i + 1);
    }
}

Triangle::~Triangle()
{
    for(int i = 0; i < szRow; i++)
    {
        delete records[i];
    }
    delete [] records;
}

int Triangle::getData(int row, int col)
{
    return records[row]->getData(col);
}