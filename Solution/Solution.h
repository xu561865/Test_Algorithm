//
//  Solution.h
//  Test_Algorithm
//
//  Created by xuyi on 8/26/16.
//  Copyright © 2016 xuyi. All rights reserved.
//

#ifndef Solution_h
#define Solution_h

/*
You are given a string S consisting of N brackets, opening "(" and/or closing ")". The goal is to split S into two parts, such that the number of opening brackets in the first part is equal to the number of closing brackets in the second part. More formally, we are looking for an integer K such that:
•	0 ≤ K ≤ N, and
•	the number of opening brackets in the K leading characters of S is the same as the number of closing brackets in the N − K trailing characters of S.
For example, given S = "(())))(", K equals 4, because:
•	the first four characters of S, "(())", contain two opening brackets, and
•	the remaining three characters of S, "))(", contain two closing brackets.
Write a function:
int solution(string &S);
that, given string S, returns a value for K that satisfies the above conditions. It can be shown that such an index K always exists and is unique.
For example, given S = "(())))(", the function should return 4, as explained above.
Assume that:
•	N is an integer within the range [0..100,000];
•	string S consists only of the characters "(" and/or ")".
Complexity:
•	expected worst-case time complexity is O(N);
•	expected worst-case space complexity is O(1) (not counting the storage required for input arguments).

 
 
 std::vector<std::string> s=
 {
 "((((())))))))))))))(()",       //0     15
 "()((()()()()()(((())))(()))()()",  //1
 "((()))))((((()))",     //2
 "(())))(",      //3
 ")(",       //4
 "(",        //5
 "" ,     //6
 "()" ,   //7
 "((((((((", // 8
 "))))))",   // 9
 };
 printf("solution: %d \n", solution_brackets(s[1]));;
 
*/

int solution_brackets_A(std::string &S);

int solution_brackets_B(std::string &S);



#endif /* Solution_h */
