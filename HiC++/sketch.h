//
//  sketch.h
//  HiC++
//
//  Created by My AD on 3/11/16.
//  Copyright © 2016 My AD. All rights reserved.
//


#ifndef sketch_h
#define sketch_h

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;


class sketch {
private:
    string name;
public:
    sketch();
    ~sketch();
    void lastKline(int k);
    virtual void say(int i);
    virtual void say2(int i,int j);
    
};

sketch::sketch(void){
    cout << "Sketch object is being created" << endl;
}

void sketch::lastKline(int k) {
    string *L = new string[k];
    string line;
    int i = 1;
    ifstream fs("/Users/Steven/Documents/HiC++/example.txt");
    if(fs.is_open()) {
        while(getline(fs,line)) {
            L[i%k] = line;
            ++i;
        }
    }
    
    if(i <= k)
        for(int j = 0; j < i; j++) cout << L[j] << endl;
    else {
        for(int j = i%k; j < (i%k + k);j++) cout << L[j%k] << endl;
    }
}

void sketch::say(int i) {
    cout << "Base Class is Saying 1." << endl;
}

void sketch::say2(int i, int j) {
    cout << "Base Class is Saying 2." << endl;
}

sketch::~sketch(){
    
}



class test: public sketch {
private:
 
public:
    test(){
        cout << " A test object is constructing" << endl;
    }
    ~test() {
        
    }
    void say(int i) {
        cout << "Derived Class is Saying!" << endl;
    }
    
};

class getSum:public sketch {
public:
    int getMaxSum(vector<int> nums) {
        int Sum = 0, maxSum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            Sum += nums[i];
            if(maxSum < Sum) maxSum = Sum;
            else if(Sum < 0) Sum = 0;
        }
        return maxSum;
    }
};

template <class T>
T getMax(T a, T b) {
    return (a>=b)?a:b;
}

class CountInversion:public sketch {
private:
    fstream f;
    vector<int> IntArray;
    string str;
    unsigned long len;
    unsigned long mid;
public:
    CountInversion() {
        
    }
    ~CountInversion() {
        
    }
    
    void ReadTXT() {
        f.open("/Users/Steven/Documents/HiC++/IntegerArray.txt");
        if(f.is_open()) {
            while(getline(f,str)) IntArray.push_back(stoi(str));
            str = "";
        }
        f.close();
    }
    
    unsigned long Count() {
        len = IntArray.size();
        mid = len / 2;
        if(len == 1) return 0;
        return (CountLeft(IntArray, mid) + CountRight(IntArray, mid, len) + CountSplit(IntArray, mid, len));
    }
    
    static unsigned long CountLeft(vector<int> IntArray, unsigned long mid) {
        int countLeft = 0;
        for(int i = 0; i < mid; ++i)
            for(int j = i + 1; j < mid; ++j) {
                if(IntArray[i] > IntArray[j]) countLeft++;
            }
        return countLeft;
    }
    
    static unsigned long CountRight(vector<int> IntArray, unsigned long mid, unsigned long len) {
        int countRight = 0;
        for(unsigned long i = mid; i < len; ++i)
            for(unsigned long j = i + 1; j < len; ++j) {
                if(IntArray[i] > IntArray[j]) countRight++;
            }
        return countRight;
    }
    
    static unsigned long CountSplit(vector<int> IntArray, unsigned long mid, unsigned long len) {
        int countSplit = 0;
        for(int i = 0; i < mid; ++i)
            for(unsigned long j = mid; j < len; ++j) {
                if(IntArray[i] > IntArray[j]) countSplit++;
            }
        return countSplit;
    }
    
};

#endif /* sketch_h */
