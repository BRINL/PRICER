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
    
    // A clarifier.
    // Permet de créer un PayOff à partir d'un strike et d'un type d'option. //
    
    PayOffCall callPayOff(Strike);
    PayOffPut putPayOff(Strike);
    
    //
    
    double resultcall= SimpleMonteCarlo(callPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
    double resultput= SimpleMonteCarlo(putPayOff, Expiry, Spot, Vol, r, NumberOfPaths);
    
    cout <<"Les prix sont de " << resultcall << " pour le call " << resultput << " pour le put.\n";
    
    double tmp;
    cin >> tmp;
    
    return 0;

}

