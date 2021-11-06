#include<iostream>
#include "src/equationLib.hpp"

int main(){
    EQ::Write::createNewCategory("equations.physic","electricity");
    EQ::Write::createNewEntry("equations.physic.electricity","{\"name\":\"Ohm's Law\",\"equation-latex\":\"\\\\R=\\\\frac{U}{I}=\\\\frac{U^2}{P}=\\\\frac{P}{I^2}\",\"author\":\"Georg Simon Ohm\",\"result\":\"\\\\R\",\"description\":\"The resistance R [Ohm] equals the voltage U [Volt] divided by the current I [Ampere]\",\"sort-word\":[\"resistance\"]}");
    return 0;
}