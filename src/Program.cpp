#include <cstdlib>
#include <iostream>
#include <windows.h>
#include "ProblemSelector.h"

std::string normalizePath(std::string path);

int main()
{
    std::string problem = "";
    std::string path = "";
    std::cout << "Enter the directory path to the problems: " << std::endl;
    getline(std::cin, path);
    path = normalizePath(path);
    ProblemSelector selector;
    selector.SetPath(path);
    std::cout << std::endl;

    while (true){
        selector.DisplayAllProblems();
        std::cout << "Enter the problem you want to open: ";
        std::cin >> problem;
        std::cout << std::endl;
        if (problem == "EXIT") break;
        selector.SetNewProblem(problem);
        if (selector.InitializeProblem()){
            std::cout << "Problem was executed." << std::endl
                << "type EXIT to quit, or..." << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}

std::string normalizePath(std::string path){
    std::string normalizePath = "";
    // ToDo: algorithm to noramlize the path
    //std::string path("C:\\Users\\rlibe\\source\\repos\\DailyCodingProblems\\DailyCodingProblemsCpp\\Problems\\");
    //std::string path("C:\\Users\\rlibertini\\Source\\Repos\\DailyCodingProblemsCpp\\Problems\\");
    normalizePath = "C:\\Users\\rlibertini\\Source\\Repos\\DailyCodingProblemsCpp\\Problems\\";
    return normalizePath;
}