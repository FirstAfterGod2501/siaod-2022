#include <iostream>
#include <string>
#include "converters/infix_to_postfix.h"
#include "converters/postfix_to_infix.h"
#include "converters/infix_to_prefix.h"
#include "calculate_prefix_expression.h"
//18 prefix list calculate
int main()
{
    std::string infix = "=a+(b+c*d)/e-f^k";
    std::string postfix = "xyz*abd/-+c-+";
    std::string prefix = "-+7*45+20";
    infix_to_prefix infixToPrefix;
    calculator calc;
    std::cout<<calc.evaluatePrefix(prefix);
    return 0;
}