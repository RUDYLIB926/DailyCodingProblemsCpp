#ifndef _PROBLEMSELECTOR_H_INCLUDED_
#define _PROBLEMSELECTOR_H_INCLUDED_

#include <string>

class ProblemSelector
{
    private:
        std::string _problemFilePath;

    public:
        bool InitializeProblem();

        void DisplayAllProblems();

        void SetNewProblem(std::string problemName);
};

#endif