//
//  StringID.hpp
//  Labirint
//
//  Created by marina porkhunova on 18.01.2023.
//

#ifndef StringID_hpp
#define StringID_hpp

#include <stdio.h>
#include <map>

#define SID(X) StringID::GetSID(X)

typedef uint32_t sid;

class StringID
{
public:
    static std::map<sid, const char*> _sids;
    
    static sid GetSID(const char* name);
    
};
#endif /* StringID_hpp */
