//
//  MaxSubArray.h
//  Test_Algorithm
//
//  Created by xuyi on 23/05/2018.
//  Copyright © 2018 xuyi. All rights reserved.
//

#ifndef MaxSubArray_h
#define MaxSubArray_h

class MaxSubArray
{
public:
    static int GetMaxSubArray();
private:
    static int helper(int a[], int size);
};

#endif /* MaxSubArray_h */
