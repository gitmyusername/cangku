//
//  Singer.cpp
//  test
//
//  Created by mac on 2021/4/22.
//

#include "Singer.hpp"

void Singer::sing()
{
//    BaseSinger::sing();
    cout<<"son sing"<<endl;
}
Singer::Singer()
{
    cout<<"gouzao zi "<<this<<endl;
    Songs = new vector<Song*>;
}
Singer::Singer(string name)
{
    cout<<"gouzao zi "<<this<<endl;
    Songs = new vector<Song*>;
}
Singer::~Singer()
{
    cout<<"xigou zi "<<this<<endl;
    
    vector<Song*>::const_iterator iter;
    for (iter=Songs->begin(); iter!=Songs->end(); iter++) {
        Song* song = *iter;
        delete song;
    }
    
    delete Songs;
}
