#include "doctest.h"
#include "Board.hpp"
#include <iostream>
#include <ctime>
#include <stdexcept>
#include <string>

using namespace ariel;
using namespace std;
TEST_CASE("TEST abcdefg"){
    Board b;
    b.post(0,0,Direction::Horizontal,"abcdefg");
    CHECK(b.read(0,0,Direction::Horizontal,7)==string("abcdefg"));
    CHECK(b.read(0,0,Direction::Horizontal,1)==string("a"));
    CHECK(b.read(0,1,Direction::Horizontal,1)==string("b"));
    CHECK(b.read(0,2,Direction::Horizontal,1)==string("c"));
    CHECK(b.read(0,3,Direction::Horizontal,1)==string("d"));
    CHECK(b.read(0,4,Direction::Horizontal,1)==string("e"));
    CHECK(b.read(0,5,Direction::Horizontal,1)==string("f"));
    CHECK(b.read(0,6,Direction::Horizontal,1)==string("g"));
    CHECK(b.read(0,0,Direction::Vertical,2)==string("a_"));
    CHECK(b.read(0,1,Direction::Vertical,2)==string("b_"));
    CHECK(b.read(0,2,Direction::Vertical,2)==string("c_"));
    CHECK(b.read(0,3,Direction::Vertical,2)==string("d_"));
    CHECK(b.read(0,4,Direction::Vertical,2)==string("e_"));
    CHECK(b.read(0,5,Direction::Vertical,2)==string("f_"));
    CHECK(b.read(0,6,Direction::Vertical,2)==string("g_"));
}
TEST_CASE("TEST Vertical and then Horizontal"){
    Board b;
    b.post(0,0,Direction::Vertical,"1111111");
    CHECK(b.read(0,0,Direction::Vertical,7)==string("1111111"));
    b.post(0,0,Direction::Horizontal,"1111111");
    CHECK(b.read(0,0,Direction::Vertical,7)==string("1111111"));
    b.post(1,0,Direction::Horizontal,"2222222");
    CHECK(b.read(0,0,Direction::Vertical,7)==string("1211111"));
    b.post(2,0,Direction::Horizontal,"3333333");
    CHECK(b.read(0,0,Direction::Vertical,7)==string("1231111"));
    b.post(3,0,Direction::Horizontal,"4444444");
    CHECK(b.read(0,0,Direction::Vertical,7)==string("1234111"));
    b.post(4,0,Direction::Horizontal,"5555555");
    CHECK(b.read(0,0,Direction::Vertical,7)==string("1234511"));
    b.post(5,0,Direction::Horizontal,"6666666");
    CHECK(b.read(0,0,Direction::Vertical,7)==string("1234561"));
    b.post(6,0,Direction::Horizontal,"7777777");
    CHECK(b.read(0,0,Direction::Vertical,7)==string("1234567"));

}

TEST_CASE("TEST Horizontal and then Vertical"){
    Board b;
    b.post(0,0,Direction::Horizontal,"1111111");
    CHECK(b.read(0,0,Direction::Horizontal,7)==string("1111111"));
    b.post(0,0,Direction::Vertical,"1111111");
    CHECK(b.read(0,0,Direction::Horizontal,7)==string("1111111"));
    b.post(0,1,Direction::Vertical,"2222222");
    CHECK(b.read(0,0,Direction::Horizontal,7)==string("1211111"));
    b.post(0,2,Direction::Vertical,"3333333");
    CHECK(b.read(0,0,Direction::Horizontal,7)==string("1231111"));
    b.post(0,3,Direction::Vertical,"4444444");
    CHECK(b.read(0,0,Direction::Horizontal,7)==string("1234111"));
    b.post(0,4,Direction::Vertical,"5555555");
    CHECK(b.read(0,0,Direction::Horizontal,7)==string("1234511"));
    b.post(0,5,Direction::Vertical,"6666666");
    CHECK(b.read(0,0,Direction::Horizontal,7)==string("1234561"));
    b.post(0,6,Direction::Vertical,"7777777");
    CHECK(b.read(0,0,Direction::Horizontal,7)==string("1234567"));

}