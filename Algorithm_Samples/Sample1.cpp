//
//  Sample1.cpp
//  Test_Algorithm
//
//  Created by 徐以 on 5/24/16.
//  Copyright © 2016 xuyi. All rights reserved.
//

#include <stdio.h>

#include "Sample1.h"

bool find_string(const char * pStr, const char *pDest)
{
    bool ret = true;
    
    if(pStr == nullptr || pDest == nullptr)
    {
        return false;
    }
    
    
    const char * pTempDest = pDest;
    
    while(*pTempDest != '\0')
    {
        const char * pTempStr = pStr;
        while(*pTempStr != *pTempDest && *pTempStr != '\0')
        {
            ++pTempStr;
        }
        
        if(*pTempStr == '\0')
        {
            ret = false;
            return ret;
        }
        
        ++pTempDest;
    }
    
    return ret;
}