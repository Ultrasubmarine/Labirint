//
//  StringID.cpp
//  Labirint
//
//  Created by marina porkhunova on 18.01.2023.
//

#include "StringId.hpp"
#include <zlib.h>


std::map<SId, const char*> StringIdStorage::_sids = {};

const char* StringIdStorage::GetName(SId id)
{
    if(auto it = _sids.find(id); it!= _sids.end())
        return it->second;
    return nullptr;
}

SId StringIdStorage::GenerateSId(const char* name)
{
    SId id = crc32(0L, reinterpret_cast<const Bytef*>(name), strlen(name));
    
    auto id_it = _sids.find(id);
    if(id_it == _sids.end())
        _sids[id] = strdup(name);
    
    return id;
};

void StringIdStorage::DeleteSId(SId id)
{
    _sids.erase(id);
}


