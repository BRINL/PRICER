//
//  Genealeatoire.cpp
//  Le but est de générer des observations de variables aléatoires suivant des lois définies dans des sous classes ///
// Loïc : Ce n'est pas une classe, juste une externalisation d'une fonction. Il faudrait peut-être créer une classe genealeatoire et deux filles : normale / poisson. On peut jeter ces techniques et en créer des nouvelles//




#include "Genealeatoire.h"
#include <cstdlib>
#include <cmath>

using namespace std;

Normale :: Normale(double mu, double sigma2) : m_mu(mu), m_sigma2(sigma2) // constructeur Normale
{
}

double Normale:: gNormale() const
{
    // ICI simulation d'une loi normale (m_mu, m_sigma2)
    return m_mu+m_sigma2 ;
}

Poisson :: Poisson(double lambda) : m_lambda(lambda) // Constructeur Poisson
{
}

double Poisson::gPoisson() const
{
    // ICI simulation d'une loi de poisson(m_lambda)
    return 0;
}

