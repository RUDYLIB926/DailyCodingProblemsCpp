#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <numeric>

bool doNumbersInListAddToK(std::vector<int> list, int k);
std::vector<std::string> split(const std::string& s, char delimiter);

int main(){
    std::cout << "Enter a list of integers separated by spaces: " << std::endl;
    std::string listAsString = "";
    std::getline(std::cin, listAsString);
    std::vector<std::string> listAsStringVector = split(listAsString, ' ');
    std::vector<int> list(listAsStringVector.size());
    for(auto y: listAsStringVector) list.push_back(std::stoi(y));

    std::cout << "Enter the value of k to compare the list to: " << std::endl;
    std::string valueOfK = "";
    std::getline(std::cin, valueOfK);
    int k = std::stoi(valueOfK);

    bool doesItAdd = doNumbersInListAddToK(list, k);
    std::string printableDoesItAdd = "no";
    if (doesItAdd) printableDoesItAdd = "yes";

    std::cout << "Do any of the numbers in the list add to equal k? " << printableDoesItAdd << std::endl;

    return 0;
    
}

bool doNumbersInListAddToK(std::vector<int> list, int k){
    for (int i = 0; i <= list.size(); i++){
        for (int j = i + 1; j <= list.size(); j++){
            if (list[i] + list[j] == k) return true;
        }
    }
    return false;
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