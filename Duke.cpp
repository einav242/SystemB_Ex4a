#include "Duke.hpp"
using namespace coup;

void Duke::block(Player &d)
{
    if (!d.fa)
    {
        throw std::invalid_argument("the last operation was not foreign_aid");
    }
    if (d.coins() == 1)
    {
        d.coin = 0;
    }
    else if (d.coins() >= 2)
    {
        d.coin -= 2;
    }
}
void Duke::tax()
{
    this->fa = false;
    this->st = false;
    this->zero = false;
    this->one = false;
    this->co = false;
    this->coin += 3;
    if (this->g->next == this->g->names.size() - 1)
    {
        this->g->next = 0;
    }
    else
    {
        (*this->g).next++;
    }
}
string Duke::role()
{
    return "Duke";
}
