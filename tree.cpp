#include "tree.h"

Tree::Tree()
{

}

Tree::Tree(const unsigned int eventsNumber)
{
    m_ways = pow(2, eventsNumber); //nombre de chemins d'un arbre = 2^évènements

    //on remplit le tableau des évènements de l'arbre
    for(unsigned int i = 0 ; i < eventsNumber ; ++i)
    {
         m_eventsArray.push_back(0);
         std::cout << "Probabilité de réussite de l'évènement n° " << i << " ?" << std::endl;
         std::cin >> m_eventsArray[i];
    }

     //on remplit le tableau dun nombre de chemins en amont, sans leur probabilit
    for(unsigned int i = 0 ; i < m_ways ; ++i)
    {
        m_waysArray.push_back( 0 );
    }

   //on associe au chemin 0 sa probabilité (trivial, c'est le produit des probas des events tous réussis rencontrés sur le chemin)
    for(unsigned int i = 0 ; i < eventsNumber ; ++i)
    {
        m_waysArray[0].second *= m_eventsArray[i];
    }

    //de même pour le dernier chemin du tableau qui est d'indice "taille du tableau - 1". cette fois c'est le produit de probas d'évents tous ratés
    for(unsigned int i = 0 ; i < eventsNumber ; ++i)
    {
        m_waysArray[m_waysArray.size - 1] *= 1-m_eventsArray[i];
    }

    //chemins à une réussite

    for(unsigned int i = 1 ;  i < fact(eventsNumber) / ( fact(eventsNumber-1) * fact(1) ) ; ++i)
    {
        for(unsigned int j = 0 ; i < eventsNumber ; ++j)
        {
            m_waysArray[i] = m_eventsArray[j];
            m_waysArray[i] *= 1-m_eventsArray[j];
        }
    }

}

long Tree::fact(long n)
{
    long ret = n--;
    while (n>1) ret *= n--;
    return ret;
}

