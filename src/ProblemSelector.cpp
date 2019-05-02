#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <locale>
#include <codecvt>
#include <string>
#include <windows.h>
#include "ProblemSelector.h"

// private function declarations
bool checkIfProblemWasSpecified(std::string _problemFilePath);
bool tryRunExistingProblem(std::string _problemFilePath);
int runExistingProblem(LPCSTR problemName);
std::vector<std::string> split(const std::string& s, char delimiter);
void printList(std::vector<std::string> list);

// ------------------------------------------------------------------------------------------------------------
bool ProblemSelector::InitializeProblem(){
    if (!checkIfProblemWasSpecified(_problemFilePath)){
        return false;
    }
    else return tryRunExistingProblem(_problemFilePath);
}

bool checkIfProblemWasSpecified(std::string _problemFilePath){
    if (_problemFilePath.empty()){
        std::cout << "No problem was specified: did not initialize." << std::endl;
        return false;
    }
    return true;
}

bool tryRunExistingProblem(std::string _problemFilePath){
    int success = runExistingProblem(_problemFilePath.c_str());
    if (success != 0) return false;
    else return true;
}

int runExistingProblem(LPCSTR problemName){
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    if (!CreateProcess(problemName, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        printf( "CreateProcess failed (%d).\n", GetLastError() );
        return -1;
    }

    // Wait until child process exits.
    WaitForSingleObject( pi.hProcess, INFINITE );

    // Close process and thread handles. 
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
    return 0;
}

// ------------------------------------------------------------------------------------------------------------
void ProblemSelector::DisplayAllProblems(){
     try{
        std::string path("C:\\Users\\rlibe\\source\\repos\\DailyCodingProblems\\DailyCodingProblemsCpp\\Problems\\");
        std::string ext(".exe");
        std::vector<std::string> problemList;
        for (const auto & entry : std::filesystem::directory_iterator(path)){
            if (entry.path().extension() == ext){
                std::vector<std::string> tokens = split(entry.path(), '/');
                problemList.push_back(tokens[1]);
            }
        }

        printList(problemList);

    }catch(...){
        std::cout << "Error: Could not list all problems. Look in ProblemSelctor.cpp listProblems() function.";
    }
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

void printList(std::vector<std::string> list){
    std::cout << "Problems:" << std::endl;
    for (auto p: list) std::cout << p << std::endl;
}

// ------------------------------------------------------------------------------------------------------------
void ProblemSelector::SetNewProblem(std::string problemName){
     _problemFilePath = 
        "C:\\Users\\rlibe\\source\\repos\\DailyCodingProblems\\DailyCodingProblemsCpp\\Problems\\"
        + problemName;
}