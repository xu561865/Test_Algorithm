//
//  main.cpp
//  Test_Algorithm
//
//  Created by xuyi on 4/14/16.
//  Copyright © 2016 xuyi. All rights reserved.
//

#include "StraightInsertionSort.h"

#include <iostream>
#include "ShellSort.h"
#include "Sample1.h"

int main(int argc, const char * argv[]) {
    
#if 0
    int v[] = {2, 4, 3, 1};
    StraightInsertionSort sot;
//    sot.insertSort(v, 4);
    
//    sot.iSort(v, 4);
    
    ShellSort sSort;
    sSort.sort(v, 4);
    
#endif
    
    
    bool ret = find_string("abcdef", "acd");
    if(ret)
    {
        printf("find it\n");
    }
    else
    {
        printf("not find\n");
    }
    
    
    return 0;
}
