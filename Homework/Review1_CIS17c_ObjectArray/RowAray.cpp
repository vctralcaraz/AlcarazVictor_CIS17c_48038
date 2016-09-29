/* 
 * File:   RowAray.cpp
 * Author: Victor Alcaraz
 * Created on September 6, 2016, 9:08 PM
 * Purpose: Implementation for RowAray
 */

#include "RowAray.h"

RowAray::RowAray(int cols)
{
    size = cols;
    rowData = new int[size];
    
    for(int i = 0; i < size; i++)
    {
        rowData[i] = (rand() % 90) + 10;
    }
}

RowAray::~RowAray()
{
    delete [] rowData;
}