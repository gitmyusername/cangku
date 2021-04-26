//
//  JsonParse.hpp
//  test
//
//  Created by mac on 2021/4/22.
//

#ifndef JsonParse_hpp
#define JsonParse_hpp

#include <iostream>
#include <vector>
#include <json.h>
#include <fstream>
#include "Singer.hpp"

#include <map>
using std::cout;
using namespace Json;
using std::string;
using std::map;

template <typename T>
void parseJson(map<string, vector<Singer*>> &map)
{
    Value root;
    std::ifstream ifs;
    ifs.open("/Users/mac/Desktop/test.txt");

    CharReaderBuilder builder;
    builder["collectComments"] = true;
    
    JSONCPP_STRING errs;
    if (!parseFromStream(builder, ifs, &root, &errs)) {
      std::cout << errs << std::endl;
      return;
    }

    Value total = root["total"];
    
    
    int totalSize = total.size();
    for (int i=0; i<totalSize; i++)
    {
        string musicType = total[i]["type"].asString();
        
        
        
        vector<Singer*> vectorSing;
        Value singers = total[i]["singer"];
        int singerSize = singers.size();
        
        for (int i=0; i<singerSize; i++)
        {
            Singer *singer = new Singer(musicType);
            singer->setName(singers[i]["name"].asString());
            Value songs = singers[i]["songs"];
            int songsSize = songs.size();
            for(int i=0;i<songs.size();i++)
            {
                Song *song = new Song;
                song->setName(songs[i]["name"].asString());
                song->setUrl(songs[i]["url"].asString());
                singer->getSongs()->push_back(song);
            }
            
            vectorSing.push_back(singer);
            
        }
        
        map[musicType] = vectorSing;
        
        
    }

}



#endif /* JsonParse_hpp */
