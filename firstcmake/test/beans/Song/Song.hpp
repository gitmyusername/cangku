//
//  Song.hpp
//  test
//
//  Created by mac on 2021/4/22.
//

#ifndef Song_hpp
#define Song_hpp

#include <stdio.h>
#include "BaseBean.hpp"

class Song :public BaseBean{
    
    setter(string, Name);
    setter(string, Url);
    getter(string, Name);
    getter(string, Url);
    
public:
    
};


#endif /* Song_hpp */
