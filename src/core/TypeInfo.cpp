//
//  TypeID.cpp
//  Labirint
//
//  Created by marina porkhunova on 04.02.2023.
//

#include "TypeInfo.hpp"
#include <zlib.h>

std::map<const char*, TypeInfo> TypeInfoStorage::_types{};

bool TypeInfoStorage::Register(const char* className)
{
    if(_types.find(className) != _types.end())
        return false;
    
    uint32_t id = crc32(0L, reinterpret_cast<const Bytef*>(className), strlen(className));
    
    _types[className] = TypeInfo{id, className};
    return true;
}


const TypeInfo* TypeInfoStorage::GetTypeInfo(const char* className)
{
    if(auto it = _types.find(className); it != _types.end())
    {
        return &it->second;
    }
    return nullptr;
}

typeId TypeInfoStorage::GetTypeID(const char* className)
{
    if(auto it = _types.find(className); it != _types.end())
    {
        return it->second.id;
    }
    return ERROR_TYPE_ID;
}
