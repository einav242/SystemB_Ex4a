#include "Ambassador.hpp"
namespace coup
{
    void Ambassador::transfer(Player &p1, Player &p2)
    {
        this->fa = false;
        this->st = false;
        this->zero = false;
        this->one = false;
        this->co = false;
        if (p1.coin > 0)
        {
            p1.coin--;
            p2.coin++;
        }
        if (this->g->next == this->g->names.size() - 1)
        {
            this->g->next = 0;
        }
        else
        {
            (*this->g).next++;
        }
    }
    void Ambassador::block(Player &d)
    {
        if (!d.st || d.role() != "Captain")
        {
            throw std::invalid_argument("Not stolen from this player");
        }
        if (d.one)
        {
            d.coin++;
            this->coin--;
        }
        else if (!d.zero)
        {
            d.coin += 2;
            this->coin -= 2;
        }
    }
    string Ambassador::role()
    {
        return "Ambassador";
    }
}