#include "Player.hpp"
using namespace coup;
using namespace std;

Player::~Player()
{
}
void Player::income()
{
    this->fa = false;
    this->st = false;
    this->zero = false;
    this->one = false;
    this->co = false;
    int index = -1;
    for (unsigned int i = 0; i < this->g->names.size(); i++)
    {
        if (this->g->names[i] == this->name)
        {
            index = (int)i;
            break;
        }
    }
    if (this->g->next != index || index==-1)
    {
        throw std::invalid_argument("Not his turn");
    }
    if (this->g->next == this->g->names.size() - 1)
    {
        this->g->next = 0;
    }
    else
    {
        (*this->g).next++;
    }
    this->coin++;
}
void Player::foreign_aid()
{
    this->fa = false;
    this->st = false;
    this->zero = false;
    this->one = false;
    this->co = false;
    int index = 0;
    for (unsigned int i = 0; i < this->g->names.size(); i++)
    {
        if (this->g->names[i] == this->name)
        {
            index = (int)i;
            break;
        }
    }
    if (this->g->next != index)
    {
        throw std::invalid_argument("Not his turn");
    }
    if (this->g->next == this->g->names.size() - 1)
    {
        this->g->next = 0;
    }
    else
    {
        (*this->g).next++;
    }
    this->coin += 2;
    this->fa = true;
}
void Player::coup(Player &p)
{
    this->fa = false;
    this->st = false;
    this->zero = false;
    this->one = false;
    this->co = false;
    int const num = 7;
    if (this->coins() < num &&this->role() == "Assassin")
    {
        if (this->coins() < 3)
        {
            throw std::invalid_argument("Not enough money");
        }
        this->coin -= 3;
        this->co = true;
        this->victim_co = &p;
    }
    else
    {
        if (this->coins() < num)
        {
            throw std::invalid_argument("Not enough money");
        }
        this->coin -= num;
    }
    int index = 0;
    int index2=0;
    for (unsigned int i = 0; i < this->g->names.size(); i++)
    {
        if (this->g->names[i] == p.name)
        {
            index = (int)i;
        }
    }
    this->victim_ind=index;
    this->g->names.erase(this->g->names.begin() + index);
    for (unsigned int i = 0; i < this->g->names.size(); i++)
    {
        if (this->g->names[i] == this->name)
        {
            index2= (int)i;
        }
    }
    if (this->g->next == this->g->names.size())
    {
        this->g->next = 0;
    }
    else
    {
        (*this->g).next=index2+1;
    }
}
string Player::role()
{
    return this->r;
}
int Player::coins() const
{
    return this->coin;
}
