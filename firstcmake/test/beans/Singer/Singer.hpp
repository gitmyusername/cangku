//
//  Singer.hpp
//  test
//
//  Created by mac on 2021/4/22.
//

#ifndef Singer_hpp
#define Singer_hpp

#include <stdio.h>
#include <string>
#include "BaseSinger.hpp"
#include "Song.hpp"
#include <vector>
using std::vector;

using namespace std;

class Singer : public BaseSinger
{
    setter(int, Age);
    setter(string, Name);
    getter(int, Age);
    getter(string, Name);
private:
    vector<Song*>* Songs = nullptr;
    getter(vector<Song*>*, Songs);
    
public:
    void saveSongs();
    
    Singer();
    Singer(string name);
    ~Singer();
protected:
    virtual void sing();
    
};

#endif /* Singer_hpp */
