//
//  PayOff.cpp
//
// Donne le payoff selon l'option traitée.
// On implémente les méthodes de la classe.

#include "PayOff.h"

#define max(a,b) ((a) > (b) ? (a) : (b)) // la fonction max n'étant pas définie en C++ on la définit en amont.

PayOff::PayOff(){};

PayOffCall::PayOffCall(double Strike) : m_Strike(Strike)
{}


double PayOffCall::CalPayOff(double Spot) const // on met un const car on ne veut pas modifier l'objet, juste calculer une nouvelle valeur
{
    return max(Spot-m_Strike,0.0);
}


PayOffPut::PayOffPut(double Strike) : m_Strike(Strike)
{}

double PayOffPut::CalPayOff(double Spot) const
{
    return max(m_Strike-Spot, 0.0);
}















