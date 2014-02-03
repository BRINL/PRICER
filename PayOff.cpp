//
//  PayOff.cpp
//
// Donne le payoff selon l'option traitée.
// On implémente les méthodes de la classe.

#include "PayOff.h"

#define max(a,b) ((a) > (b) ? (a) : (b)) // la fonction max n'étant pas définie en C++ on la définit en amont.


PayOffCall::PayOffCall(double Strike_) : Strike(Strike_)
{
}

double PayOffCall::operator()(double Spot) const
{
    return max(Spot-Strike,0.0);
}



PayOffPut::PayOffPut(double Strike_) : Strike(Strike_)
{
}

double PayOffPut::operator()(double Spot) const
{
    return max(Strike-Spot, 0.0);
}















