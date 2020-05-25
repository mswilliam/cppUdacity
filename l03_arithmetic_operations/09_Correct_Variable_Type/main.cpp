/*Goal: fix the variable types problem. 
**This program outputs the wrong answer
**even though it compiles and executes without errors. 
**Fix it so that it outputs the correct value.
*/

#include <iostream>
int main(void)
{
    int numerator = 4;
    int denominator = 5;

    float answer = (float)numerator / denominator;
    std::cout<<"answer = "<<answer;
    return 0;
}

