#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <numeric>

/*
Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
*/

std::vector<int> productOfOtherIndices(std::vector<int> input);
std::vector<std::string> split(const std::string& s, char delimiter);

int main(){
    std::cout << "Enter the integers for the array seprated by spaces: " << std::endl;
    std::string listAsString = "";
    std::getline(std::cin, listAsString);
    std::vector<std::string> listAsStringVector = split(listAsString, ' ');
    std::vector<int> input(listAsStringVector.size());
    for (int i = 0; i < listAsStringVector.size(); i++) input[i] = std::stoi(listAsStringVector[i]);
    std::vector<int> products = productOfOtherIndices(input);
    std::cout << "Products are: " << std::endl;
    for (auto x: products) std::cout << x << " ";
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

std::vector<std::string> split(const std::string& s, char delimiter){
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}