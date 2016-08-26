//
//  Solution.cpp
//  Test_Algorithm
//
//  Created by xuyi on 8/26/16.
//  Copyright © 2016 xuyi. All rights reserved.
//

#include <stdio.h>
#include <string>

int solution_brackets_A(std::string &S)
{
    int ret = 0;
    
    int count_open_brackets = 0;
    int count_close_brackets = 0;
    
    printf("length: %d \n", S.length());
    
    for(int i = 0; i < S.length(); i++)
    {
        if(S[i] == '(')
        {
            count_open_brackets++;
        }
        
        if(S[i] == ')')
        {
            count_close_brackets++;
        }
    }
    
    int tmp_count_open_brackets = 0;
    int tmp_count_close_brackets = 0;
    for(int i = 0; i < S.length(); i++)
    {
        if(S[i] == '(')
        {
            tmp_count_open_brackets++;
        }
        
        if(S[i] == ')')
        {
            tmp_count_close_brackets++;
        }
        
        if(tmp_count_open_brackets == count_close_brackets - tmp_count_close_brackets)
        {
            ret = i + 1;
            
            return ret;
        }
    }
    
    return ret;
}

int solution_brackets_B(std::string &S)
{
    int ret = 0;
    
    // (())))(
    printf("%d\n", S.length());
    
    std::string::iterator iter_begin = S.begin();
    std::string::iterator iter_end = S.end() - 1;
    
    
    while (iter_begin < iter_end)
    {
        while((iter_begin < iter_end) && ('(' != *iter_begin))
        {
            printf("%c ", *iter_begin);
            iter_begin++;
            //            ret++;
        }
        
        while((iter_begin < iter_end) && (')' != *iter_end))
        {
            printf("%c ", *iter_end);
            iter_end--;
        }
        
        if(iter_begin < iter_end)
        {
            iter_begin++;
            //            ret++;
            
            if(iter_begin < iter_end)
            {
                iter_end--;
            }
        }
    }
    
    return iter_begin - S.begin();
    //    return ret == 0 ? 0 : ret + 1;
}
