//
//  VirtualTable.h
//  HiC++
//
//  Created by My AD on 7/27/16.
//  Copyright © 2016 My AD. All rights reserved.
//

#ifndef VirtualTable_h

#include <stdio.h>
#include <iostream>

using namespace std;

class Base {
public:
    Base() {
        cout << " Base is constructing" << endl;
    }
    virtual ~Base() {
        cout << " Base is destructing" << endl;
    }
    virtual void call() {
        cout << " base call 1" << endl;
    }
};

class derived : public Base {
public:
    derived() {
        cout << " derived is constructing" << endl;
    }
    virtual ~derived() {
        cout << " derived is destructing" << endl;
    }
    virtual void call() {
        cout << " derived call 2" << endl;
    }
};

class VirtualTable {
public:
    void printOrder() {
        cout << "-----------object---------" << endl;
        Base B;
        B.call();
        cout << "----------------" << endl;
        derived D;
        D.call();
        cout << "----------------" << endl;
        B = D;
        B.call();
        cout << "-----------pointer---------" << endl;
        Base *BP = &B;
        BP->call();
        cout << "----------------" << endl;
        BP = &D;
        BP->call();
        cout << "----------------" << endl;
        Base *BP2 = &D;
        BP2->call();
        cout << "----------------" << endl;
    }
};

#define VirtualTable_h


#endif /* VirtualTable_h */
