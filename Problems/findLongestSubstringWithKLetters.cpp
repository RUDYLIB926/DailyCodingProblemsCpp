/*
Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
*/

#include <cstdlib>
#include <iostream>
#include <map>

int findSubstringLengthWithKLetters(std::string input, int k){
    int length = 0;
    std::string substring = "";
    std::map<char,int> occurances;
    for(int i = 0; i < input.length(); i++){
        std::cout << "i = " << i << ", length = " << length << ", currentLength = " << substring.length();
        std::cout << ", substring contains: " << substring;
        std::cout << ", occurances.size: " << occurances.size() << std::endl;
        
        if (occurances.find(input[i]) != occurances.end()){
            occurances[input[i]] += 1;
        }
        else{
            occurances[input[i]] = 1;
        }
        substring += input[i];
        
        if (occurances.size() <= k && substring.length() > length){
            length = substring.length();
            std::cout << "setting new length: " << length << std::endl;
        }

        if (occurances.size() > k && i != input.length()-1){
            int firstIndexOfSubstring = input.find(substring);
            std::string firstIndexReplacement = "a";
            if(input[i] == 'a'){
                firstIndexReplacement = "b";
            }
            input.replace(firstIndexOfSubstring, 1, firstIndexReplacement);
            i = firstIndexOfSubstring;
            substring.clear();
            occurances.clear();
        }
    }

    return length;
}

int main(){
    std::cout << "Enter a string to use:" << std::endl;
    std::string input = "";
    std::cin >> input;
    std::cout << "Enter a number of distinct characters to find:" << std::endl;
    int k = 0;
    std::string num;
    std::cin >> num;
    k = stoi(num);
    //std::cout << std::endl << k;

    int output = findSubstringLengthWithKLetters(input, k);
    std::cout << std::endl << output;
}