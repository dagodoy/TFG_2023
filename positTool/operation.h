#ifndef OPERATION_H
#define OPERATION_H


#include <string>
#include <vector>

struct substep{
    substep();
    substep(std::string s): title(s){}
    std::string title;
    std::vector<std::string> text;
};

struct step{
    step();
    step(std::string s): title(s){}
    std::string title;
    std::vector<substep> substeps;
    std::vector<int> highlights;
};
template<typename T>
struct operation{
    operation();
    operation(std::string s): title(s){}
    void add(std::string s)
    {
        steps.back().substeps.back().text.push_back(s);
    }
    void addHighlight(int h)
    {
        steps.back().highlights.push_back(h);
    }
    void nextStep(std::string title)
    {
        steps.push_back(step(title));
    }
    void nextSubstep(std::string title)
    {
        steps.back().substeps.push_back(substep(title));
    }
    T result;
    std::string title;
    std::vector<step> steps;
};
#endif // OPERATION_H
