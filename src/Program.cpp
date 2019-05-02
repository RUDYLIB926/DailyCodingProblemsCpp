#include <cstdlib>
#include <iostream>
#include <windows.h>
#include "ProblemSelector.h"

int main()
{
    std::string problem = "";
    ProblemSelector selector;

    while (true){
        selector.DisplayAllProblems();
        std::cout << "Enter the problem you want to open: ";
        std::cin >> problem;
        if (problem == "EXIT") break;
        selector.SetNewProblem(problem);
        if (selector.InitializeProblem()){
            std::cout << "Problem was executed." << std::endl
                << "type EXIT to quit, or..." << std::endl;
        }
    }
    return 0;
}

