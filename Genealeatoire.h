// Genealeatoire //

#ifndef __PRICER__Genealeatoire__
#define __PRICER__Genealeatoire__

#include <iostream>

// PROJET LOIC //

class Genealeatoire // classe mère des générateurs de simulations
{
    public :
    Genealeatoire(){} // constructeur
    private :
};

class Normale : public Genealeatoire
{
    public :
    Normale(double mu, double sigma2);
    double gNormale() const;
    private :
    double m_mu;
    double m_sigma2;
};

class Poisson : public Genealeatoire
{
    public :
    Poisson(double lambda); // constructeur
    double gPoisson() const;
    private :
    double m_lambda;
    
};

#endif /* defined(__PRICER__Genealeatoire__) */

