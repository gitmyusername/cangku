//
//  main.cpp
//  test
//
//  Created by mac on 2021/4/20.
//

#include <iostream>

#include "JsonParse.hpp"

using std::vector;
using namespace std;

enum MusicType
{
    Pop=1, Classic, Jazz
};
typedef enum MusicType MusicType;

void freeMem(map<string, vector<Singer*>> &singerMap);
void startMachine(map<string, vector<Singer*>> &singerMap);
void startChooseSinger(vector<Singer*> &singerVector);
void startChooseSongw(vector<Song*> *vectorSongs);

int main(int argc, const char * argv[])
{
    
    /** 获取歌单 */
    map<string, vector<Singer*>> singerMap;
    parseJson<Singer>(singerMap);
    

    for (bool flag=false;;)
    {
        if(flag)
        {
            cout<<"是否继续 1:yes 2:no"<<endl;
            int iFlag = 0;
            cin>>iFlag;
            
            if(iFlag != 1)
            {
                freeMem(singerMap);
                cout<<"点歌结束"<<endl;
                return 0;
            }
        }
        startMachine(singerMap);
        flag = true;
    }
    

    
    
    
    return 0;
}
void startMachine(map<string, vector<Singer*>> &singerMap)
{
    int musicType = 0;
    
    cout<<"请输入您想选择的音乐类型"<<endl;
//    cout<<"1:流行乐\n2.古典乐\n3.爵士乐" <<endl;
    
    map<string, vector<Singer*>>::iterator it;
    int index = 1;
    
    map<int, string> types;
    for(it = singerMap.begin(); it!=singerMap.end(); it++)
    {
        types[index] = it->first;
        cout<<index++<<"."<<it->first<<endl;
    }
    
    cin >> musicType;
    
    map<int, string>::iterator musicIt;
    
    
    switch (musicType) {
        case Pop:
        {
            musicIt = types.find(Pop);
            cout<<"您选择了 1:"<<musicIt->second<<endl;
        }
            break;
        case Classic:
        {
            musicIt = types.find(Classic);
            cout<<"您选择了 2:"<<musicIt->second<<endl;
        }
            break;
        case Jazz:
        {
            musicIt = types.find(Jazz);
            cout<<"您选择了 3:"<<musicIt->second<<endl;
            cout<<"正在开发中"<<endl;
        }
            break;
            
        default:
        {
           
        }
            break;
    }
    
    vector<Singer*> singerVector = singerMap.find(musicIt->second)->second;
    startChooseSinger(singerVector);
    
}

void startChooseSinger(vector<Singer*> &singerVector)
{
    cout<<"请选择歌手"<<endl;
//    vector<Singer*>::const_iterator it;
//    int index = 1;
//    for (it = singerVector.begin(); it!=singerVector.end(); it++)
//    {
//        cout<<index++<<"."<<(*it)->getName()<<endl;
//        vector<Song*> *songVector = (*it)->getSongs();
//    }
    for(int i=0, index = 1; i<singerVector.size(); i++)
    {
        cout<<index++<<"."<<singerVector.at(i)->getName()<<endl;
    }
    
    int singer = 0;
    cin>>singer;
    
    vector<Song*> *songVector = singerVector.at(singer-1)->getSongs();
    startChooseSongw(songVector);
    
}

void startChooseSongw(vector<Song*> *vectorSongs)
{
    cout<<"请选择歌曲"<<endl;
    for(int i=0, index=1; i<vectorSongs->size(); i++)
    {
        Song* song = vectorSongs->at(i);
        cout<<index++<<"."<<song->getName()<<endl;
    }
    
    int music = 0;
    cin>>music;
    
    Song* song = vectorSongs->at(music-1);
    cout<<"您选择了: "<<song->getName()<<endl;
    cout<<"马上为您播放: "<<song->getUrl()<<endl;
    
    
}

void freeMem(map<string, vector<Singer*>> &singerMap)
{
    //正确遍历:
    map<string, vector<Singer*>>::iterator mapIter;
    for (mapIter=singerMap.begin(); mapIter!=singerMap.end(); mapIter++)
    {
        vector<Singer*> singerVector = mapIter->second;
        vector<Singer*>::const_iterator vecIter;
        for(vecIter=singerVector.begin(); vecIter!=singerVector.end();vecIter++)
        {
            Singer* singer =*vecIter;
            delete singer;
        }
        
    }

}
