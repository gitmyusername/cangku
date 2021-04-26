//
//  BaseSinger.hpp
//  test
//
//  Created by mac on 2021/4/22.
//

#ifndef BaseSinger_hpp
#define BaseSinger_hpp

#include <iostream>
#include <string>
#include "BaseBean.hpp"

using namespace std;
class BaseSinger : public BaseBean
{
private:

public:
    virtual void sing() {cout<<"base sing"<<endl;};
    void readSingList(std::string fileName);
    ~BaseSinger();
};



#endif /* BaseSinger_hpp */
