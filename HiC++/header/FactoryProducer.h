//
//  FactoryProducer.h
//  HiC++
//
//  Created by My AD on 8/3/16.
//  Copyright © 2016 My AD. All rights reserved.
//

#ifndef FactoryProducer_h
#define FactoryProducer_h

#include "AbstractFactory.h"
#include "SolutionFactory.h"

class FactoryProducer {
public:    
    AbstractFactory *createFactoryByName(std::string factoryName) {
        if(factoryName == "Solution") {
            return new SolutionFactory;
        }
        return nullptr;
    }
};

#endif /* FactoryProducer_h */
