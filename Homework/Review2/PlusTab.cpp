/* 
 * File:   PlusTab.cpp
 * Author: Victor Alcaraz
 * Created on September 29, 2016, 12:27 AM
 * Purpose: 
 */

#include "PlusTab.h"

PlusTab PlusTab::operator+(const PlusTab &nPlusTab)
{
    PlusTab temp(this->szRow, this->szCol);
    for(int i = 0; i < this->szRow; i++)
    {
        for(int j = 0; j < this->szCol; j++)
        {
            temp.setData(i, j, (this->getData(i,j) + nPlusTab.getData(i,j)));
        }
    }
    return temp;
}