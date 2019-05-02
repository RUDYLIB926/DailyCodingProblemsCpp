#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

/*
How tall is the tree: 5
    #
   ###
  #####
 #######
#########
    #
*/

/* algorithm
1. decrement spaces by 1 each time through loop
2. incrememnt pounds by 2 each time through the loop
3. stumpSpaces = (height - 1)
4. decrement from height unitl it equals 0
5. print spaces then pounds for each row
6. print stump spaces then 1 pound
*/

//int calculateWidth(int height);
//void printTreeRows(int height, int width);
void printTreeRows(int height);

int main(){
    std::cout << "How tall is the tree: ";
    int height;
    std::cin >> height;
    
    printTreeRows(height);
    
    return 0;
}

/*
int calculateWidth(int height){
    int width = 1;
    while (height > 0){
        width += 2;
        height--;
    }
    return width;
}
*/

/* my answer
void printTreeRows(int height, int width){
    int spaces = (width / 2) - 1;
    int numberOfPounds = 1;
    while (spaces >= 0 && numberOfPounds <= width){
        for (int i = spaces; i > 0; i--) std::cout << " ";
        for (int i = 1; i <= numberOfPounds; i++) std::cout << "#";  
        std::cout << std::endl;      
        spaces--;
        numberOfPounds += 2;
    }

    for(int i = (width / 2) -1; i > 0; i--) std::cout << " ";
    std::cout << "#" << std::endl;
}
*/

// his answer
void printTreeRows(int height){
    int stumpSpaces = height - 1;
    int numberOfPounds = 1;
    while (height > 0){
        for (int spaces = height - 1; spaces > 0; spaces--) std::cout << " ";
        for (int i = numberOfPounds; i > 0; i--) std::cout << "#";
        std::cout << std::endl;
        height--;
        numberOfPounds += 2;
    }
    while(stumpSpaces > 0){
        std::cout << " ";
        stumpSpaces--;
    }
    std::cout << "#" << std::endl;
}