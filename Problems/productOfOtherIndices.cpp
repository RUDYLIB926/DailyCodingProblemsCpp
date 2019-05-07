#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

/*
Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
*/

std::vector<int> productOfOtherIndices(std::vector<int> input);

int main(){
    std::vector<int> input1 {1,2,3,4,5};
    std::vector<int> products1 = productOfOtherIndices(input1);
    for (auto x: products1) std::cout << x << " ";
    std::cout << std::endl;

    std::vector<int> input2 {3,2,1};
    std::vector<int> products2 = productOfOtherIndices(input2);
    for (auto x: products2) std::cout << x << " ";
    std::cout << std::endl;
}

std::vector<int> productOfOtherIndices(std::vector<int> input){
    std::vector<int> products(input.size());
    for (int i = 0; i < input.size(); i++){
        int temp = input[i];
        input[i] = 1;
        int newi = 1;
        for (int j = 0; j < input.size(); j++){
            newi = newi * input[j];
        }
        input[i] = temp;
        products[i] = newi;
    }
    return products;
}