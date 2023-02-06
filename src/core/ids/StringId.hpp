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


#define SID(X) StringIdStorage::GenerateSId(X)

#define DESTROY_SID(X) StringIdStorage::DeleteSId(X)

typedef uint32_t SId;

class StringIdStorage
{
    static std::map<SId, const char*> _sids;
public:

    static const char* GetName(SId id);
    
    static SId GenerateSId(const char* name);
    static void DeleteSId(SId id);
    
};
#endif /* StringID_hpp */
