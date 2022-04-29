#include "Contessa.hpp"
using namespace coup;

void Contessa::block(Player &d)
{
    if(!d.co || d.role()!="Assassin")
    {
          throw std::invalid_argument("Invalid operation");
    }
    this->g->names.insert(this->g->names.begin()+d.victim_ind,d.victim_co->name);
    this->g->next++;
    d.co=false;
}

string Contessa::role()
{
    return "Contessa";
}