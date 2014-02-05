//  PRICER
//
//  Aymeric BELLON / Loïc BRIN


#include "MonteCarlo.h"
#include <iostream>
#include <cmath>

using namespace std;

// Dans le main.cpp, on récolte les données de l'utilisateur //
// La maturité (Expiry), le strike (Strike), le prix spot    //
// (Spot), la volatilité (Vol), le taux sans risque (r) et   //
// le nombre d'itérations désirés pour le Monte-Carlo (Number//
// OfPaths).                                                 //

int main()
{
    double Expiry;
    double Strike ;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    int TypeOption;
    cout << "\nEntrer la maturité\n";
    cin >> Expiry;
    cout<< "\nEntrer strike\n";
    cin >> Strike;
    cout<< "\nEntrer spot\n";
    cin >> Spot;
    cout<< "\nEntrer vol\n";
    cin >> Vol;
    cout<< "\nEntrer r\n";
    cin >> r;
    cout<< "\nEntrer nombre d'itérations\n";
    cin >> NumberOfPaths;
    cout<< "\nEntrer 1 pour un Call, 0 pour Put\n";
    cin >> TypeOption;

    
    MonteCarloB MonTest(TypeOption, Strike, Expiry, Spot, Vol, r, NumberOfPaths);
    //
    
    double resultcall= MonTest.PrixCallB();
    
    cout <<"Les prix sont de " << resultcall << " pour le call ";
    
    double tmp;
    cin >> tmp;
    
    return 0;

}

