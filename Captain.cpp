#include "Captain.hpp"
using namespace coup;

void Captain::block(Player &d)
{
    if(!d.st || d.role()!="Captain")
    {
          throw std::invalid_argument("Not stolen from this player");
    }
    d.st=false;
    if(d.one)
    {
        d.coin++;
        this->coin--;
    }
    else if(!d.zero)
    {
        d.coin+=2;
        this->coin-=2;
    }

}
void Captain::steal(Player &p)
{
    this->one=false;
    this->zero=false;
    this->fa=false;
    this->co=false;
    this->st=true;
    this->victim=&p;
    if(p.coins()==1)
    {
        p.coin=0;
        this->coin+=1;
        this->one=true;
    }
    else if(p.coins()>=2)
    {
        p.coin-=2;
        this->coin+=2;
    }
    else
    {
        this->zero=true;
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
    string Captain::role()
    {
        return "Captain";
    }