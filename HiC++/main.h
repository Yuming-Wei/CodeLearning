//
//  main.h
//  HiC++
//
//  Created by My AD on 7/17/15.
//  Copyright (c) 2015 My AD. All rights reserved.
//

#ifndef HiC___main_h
#define HiC___main_h

#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
using namespace std;

void pointer(char *p){
    int len = strlen(p);
    int tempCnt = 0;
    for (int i = 0; i <= len - 2; i++) {
        for (int j = 0; j <= len - 2; j++) {
            if (p[i] == p[i + j]) {
                if (p[i + 1] ==p[i + 1 + j]) {
                    tempCnt ++;
                }
            }
        }
        if (tempCnt > 1) {
            cout << p[i] <<p[i+1] << " Shows more than 1 time, shows " << tempCnt << " times." << endl;
        }
        tempCnt = 0;
    }
}


void StrMan() {
    char p1[] = "ab\n";
    char *p2 = p1;
    cout << p1 << endl;
    cout << p2 << endl;
    
    int LL = strlen(p2);
    
    cout << "Size of string is " << LL<< endl;
    
    if (p2[LL - 1] == '\n') {
        cout << "Found enter" << endl;
    }
    
    if (p2[LL] == 0) {
        cout << "Found end" << endl;
    }
    
}

double Add_Min(char* in){
    double Left_Rst = 0;
    int NumLen = 0;
    char* CurrNum;
    char* expr;
    bool flag = true;
    for (expr = in; flag; expr++) {
        NumLen++;
        switch (*expr) {
            case '+':{
                flag = false;
                break;
            }
            case '-':{
                flag = false;
                break;
            }
            default:
                break;
        }
    }
    
    NumLen = 0;
    for (; *expr!=0; expr++) {
        NumLen++;
        switch (*expr) {
            case '+':{
                Left_Rst += double(strlcpy(in, CurrNum, NumLen));
                NumLen = 0;
                break;
            }
            case '-':{
                Left_Rst -= double(strlcpy(in, CurrNum, NumLen));
                NumLen = 0;
                break;
            }
            default:
                break;
        }
    }
    return Left_Rst;
}



#endif