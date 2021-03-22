#include <string>
#include <iostream>
#include <vector>
#include "Direction.hpp"
using namespace std;
namespace ariel{
    class Board {
      
    public:


        Board(){
       
        }
        ~Board(){

        }

        void post(unsigned i, unsigned j, Direction d, string const &ads);

        static std:: string read(unsigned i, unsigned j, Direction d, unsigned size);

        void show();

    };

}