/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Victor Alcaraz
 * Created on September 21, 2016, 8:42 PM
 * Purpose: Linked List Version 1 - Procedures with ADT
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Link.h"

//Global Constants

//Function Prototypes
Link *fillLst(int);
void prntLst(Link *);
void destLst(Link *);
Link *endLst(Link *);
void addLst(Link *, int);
int findLst(Link *, int);
Link *fndLst(Link *, int);
int cntLst(Link *);

//execution begins here
int main(int argc, char** argv) {

    //Initialize Linked List
    Link *lnkList;
    
    //Fill Linked List
    lnkList = fillLst(10);
    
    //Print Linked List
    prntLst(lnkList);
    
    //Add a value to the end of the list
    addLst(lnkList, 42);
    
    //Print Linked List after adding
    prntLst(lnkList);
    
    //find some values in the list
    cout << "5 is found at link " << findLst(lnkList, 5) << endl;
    cout << "5 is found at link " << fndLst(lnkList, 5)->data << endl;
    cout << "11 is found at link " << findLst(lnkList, 11) << endl;
    cout << "The number of elements is the list = " << cntLst(lnkList) << endl;

    //Deallocate Memory
    destLst(lnkList);
    
    return 0;
}

Link *fillLst(int n)
{
    //Think of this part as the constructor
    Link *front = new Link;
    Link *next = front;
    next->data = n;
    next->linkPtr = NULL;
    
    //Fill the rest of the list
    n--;
    do
    {
        Link *temp = new Link;
        temp->data = n;
        next->linkPtr = temp;
        next = temp;
    }while(--n > 0);
    
    //Exit by returning the original link pointer
    return front;
}

void prntLst(Link *front)
{
    Link *next = front;
    
    cout << endl;
    
    do
    {
        cout << next->data << endl;
        next = next->linkPtr;
    }while(next != NULL);
    
    cout << endl;
}

void destLst(Link *front)
{
    if(front == NULL) return;
    do
    {
        Link *temp = front->linkPtr;
        delete front;
        front = temp;
    }while(front != NULL);
}

Link *endLst(Link *front)
{
    Link *temp = front;
    Link *next;
    
    do
    {
        next = temp;
        temp = temp->linkPtr;
    }while(temp != NULL);
    return next;
}

void addLst(Link *front, int data)
{
    Link *last = endLst(front);
    Link *add = new Link;
    add->data = data;
    add->linkPtr = NULL;
    last->linkPtr = add;
}

int findLst(Link *front, int value)
{
    int n = 0;
    
    Link *temp = front;
    Link *next;
    do
    {
        n++;
        if(temp->data == value) return n;
        next = temp;
        temp = temp->linkPtr;
    }while(temp != NULL);
    return 0;
}

Link *fndLst(Link *front, int value)
{    
    Link *temp = front;
    Link *next;
    do
    {
        if(temp->data == value) return temp;
        next = temp;
        temp = temp->linkPtr;
    }while(temp != NULL);
    return NULL;
}
int cntLst(Link *front)
{
    int n = 0;
    
    Link *temp = front;
    Link *next;
    do
    {
        n++;
        next = temp;
        temp = temp->linkPtr;
    }while(temp != NULL);
    return n;
}