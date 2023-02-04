//
//  StringID.cpp
//  Labirint
//
//  Created by marina porkhunova on 18.01.2023.
//

#include "StringID.hpp"
#include <zlib.h>


std::map<sid, const char*> StringID::_sids = {};

sid StringID::GetSID(const char* name)
{
    sid id = crc32(0L, reinterpret_cast<const Bytef*>(name), strlen(name));
    
    auto id_it = _sids.find(id);
    if(id_it == _sids.end())
        _sids[id] = strdup(name);
    
    return id;
};
