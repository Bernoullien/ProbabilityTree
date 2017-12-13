#ifndef TREE_H
#define TREE_H

#include <vector>
#include <cmath>


class Tree
{
public:
    Tree(const unsigned int eventsNumber);
    double getProbabilityWay(const unsigned int way);
    long fact(long n);

private:
    unsigned int m_ways; //chemins
    std::vector<double> m_eventsArray; //tableau des évènements proba
    std::vector<double> m_waysArray; //tableau des chemins proba
};

#endif // TREE_H
