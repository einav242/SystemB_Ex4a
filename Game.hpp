#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
namespace coup{
    class Game
    {
    public:
        vector<string>names;
        string t;
        int next;
        Game()
        {
            this->next=0;
        };
        ~Game();
        vector<string>players() const;
        string turn();
        string winner();
    };
    

    
}