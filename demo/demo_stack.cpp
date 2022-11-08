#include <stack>

void addStep(int step,std::stack<int> steps){
    steps.push(step);
}
void removeStep(std::stack<int> steps){
    steps.pop();
}