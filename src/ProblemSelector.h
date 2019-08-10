#ifndef _PROBLEMSELECTOR_H_INCLUDED_
#define _PROBLEMSELECTOR_H_INCLUDED_

#include <string>

class ProblemSelector
{
    private:
        std::string _problemFilePath;
        std::string _problemName;

    public:
        bool InitializeProblem();

        void DisplayAllProblems();

        void SetNewProblem(std::string problemName);

        void SetPath(std::string path);
};

#endif