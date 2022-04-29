#include <iostream>
#include <stdexcept>
#include <string>
#include"Player.hpp"
using namespace std;
namespace coup
{
    class Captain:public Player
    {
    public:
        Player* victim;
        Captain(Game  &g,string const &s):Player(g,s)
        {
            this->victim=NULL;
        }
        void steal(Player &p);
        void block(Player &d);
        string role();
    };
} 
