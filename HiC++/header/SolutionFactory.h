//
//  SolutionFactory.h
//  HiC++
//
//  Created by My AD on 8/3/16.
//  Copyright © 2016 My AD. All rights reserved.
//

#ifndef SolutionFactory_h
#define SolutionFactory_h

using namespace std;
#include "AbstractFactory.h"
#include "SolutionClass.h"
#include "LeetCode_1.h"

class SolutionFactory: public AbstractFactory {
private:
    string factoryName;
public:
//    SolutionFactory(){}
    string getFactoryName() {
        return factoryName;
    }
    
    SolutionClass *createSolution(string SolutionName) {
        if(SolutionName == "LeetCode_1") return new LeetCode_1;
        return nullptr;
    }
    
};

#endif /* SolutionFactory_h */
