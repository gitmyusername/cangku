//
//  BaseBean.hpp
//  test
//
//  Created by mac on 2021/4/22.
//

#ifndef BaseBean_hpp
#define BaseBean_hpp

#include <stdio.h>
#include <string>
using std::string;

class BaseBean {
    
    
public:
    
};

#define setter(pType, param)    \
protected:                      \
    pType param;                \
public:                         \
void set##param(pType param)    \
{                               \
    this->param = param;        \
}

#define getter(pType, param)    \
public:                         \
pType get##param()              \
{                               \
    return this->param;         \
}

#endif /* BaseBean_hpp */
