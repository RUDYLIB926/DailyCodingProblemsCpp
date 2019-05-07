#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

std::vector<std::string> autocompleteOnPrefix(std::string s, std::vector<std::string> list);
int findSubstringFirstIndex(const std::string *parentstring, const std::string *sunstring);

int main(){
    std::vector<std::string> list {"dog", "deer", "deal", "apples", "bananas", "balls", "golf", "goffer"};
    std::cout << "The list contains: ";
    for (auto y: list) std::cout << y << " ";
    std::cout << std::endl;
    std::cout << "Enter the prefix you would like to query for: " << std::endl;
    std::string prefix = "";
    std::cin >> prefix;

    std::vector<std::string> results = autocompleteOnPrefix(prefix, list);

    if (results.empty()){
        std::cout << "There were no matches for your specified prefix." << std::endl;
    }
    else {
        std::cout << "Results: ";
        for (auto y: results) std::cout << y << " ";
        std::cout << std::endl;
    }
    

    return 0;
}

std::vector<std::string> autocompleteOnPrefix(std::string s, std::vector<std::string> list){
    std::vector<std::string> results;
    for (auto y: list){
        int i = findSubstringFirstIndex(&y, &s);
        //std::cout << i << " for " << y << std::endl;
        if (i == 0){
            results.push_back(y);
        }
    }
    return results;
}

// commented line is for debugging
int findSubstringFirstIndex(const std::string *parentstring, const std::string *substring){
    int e = 0, indx = -1;
    const char *parentcstring = parentstring->c_str();
    const char *csubstring = substring->c_str();

    for (int i = 0; i < strlen(parentcstring); i++){
        //std::cout << "i : " << i << " && parentcstring[i]: " << parentcstring[i] << " && csubstring[e]: " << csubstring[e] << " && e : " << e << std::endl;
        if (parentcstring[i] == csubstring[e]){
            if (e == 0){ 
                indx = i; 
            }
            if (e == strlen(csubstring)-1){ 
                return indx;
            }
            else
                e++;
        }
    }
    return -1;
}