#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

/*
There exists a staircase with N steps,
and you can climb up either 1 or 2 steps at a time.
Given N, write a function that returns the number of unique ways you can climb the staircase.
The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2

What if, instead of being able to climb 1 or 2 steps at a time,
you could climb any number from a set of positive integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*/

int uniqueWaysToClimbNStepsInIntervalsOf1or2(const int N);
int uniqueWaysToClimbNStepsInIntervalsOfX(const int N, const int[] X);

int main(){
    return 0;
}

int uniqueWaysToClimbNStepsInIntervalsOf1or2(const int N){
    if (N == 0 || N == 1) return 1;
    int[N+1] uniqueWays;
    uniqueWays[0] = 1;
    uniqueWays[1] = 1;
    for(int i = 2; i =< N; i++){
        uniqueWays[i] = uniqueWays[i-1] + uniqueWays[i-2];
    }
    return uniqueWays[N];
}

int uniqueWaysToClimbNStepsInIntervalsOfX(const int N, const int[] X){
    
}