#include"Game.hpp"
using namespace std;
namespace coup{
    Game::~Game()
    {
    }
    vector<string> Game::players() const
    {
        return this->names;
    }
    string Game::turn()
    {
        return this->names[(unsigned int)this->next];
    }
    string Game::winner()
    {
        if(this->names.size()!=1)
        {
             throw std::invalid_argument("There is still no winner");
        }
        return this->names[0];
    }
}