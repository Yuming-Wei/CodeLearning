//
//  AbstractFactory.h
//  HiC++
//
//  Created by My AD on 8/3/16.
//  Copyright © 2016 My AD. All rights reserved.
//

#ifndef AbstractFactory_h
#define AbstractFactory_h

#include "SolutionClass.h"

class AbstractFactory {
public:
    virtual SolutionClass *createSolution(std::string SolutionName) = 0;
};


#endif /* AbstractFactory_h */
