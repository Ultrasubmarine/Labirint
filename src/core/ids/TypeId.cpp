//
//  TypeID.cpp
//  Labirint
//
//  Created by marina porkhunova on 04.02.2023.
//

#include "TypeId.hpp"
#include <zlib.h>

std::map<TypeId, TypeInfo> TypeInfoStorage::_types{};

bool TypeInfoStorage::Register(const char* className)
{
    uint32_t id = GenerateId(className);
    if(_types.find(id) != _types.end())
        return false;
    
    _types[id] = TypeInfo{id, className};
    return true;
}

const TypeInfo* TypeInfoStorage::GetTypeInfoByName(const char* className)
{
    uint32_t id = GenerateId(className);
    if(auto it = _types.find(id); it != _types.end())
    {
        return &it->second;
    }
    return nullptr;
}

const TypeInfo* TypeInfoStorage::GetTypeInfo(TypeId id)
{
    if(auto it = _types.find(id); it != _types.end())
    {
        return &it->second;
    }
    return nullptr;
}

TypeId TypeInfoStorage::GetTypeID(const char* className)
{
    uint32_t id = GenerateId(className);
    if(auto it = _types.find(id); it != _types.end())
    {
        return it->second.id;
    }
    return ERROR_TYPE_ID;
}

TypeId TypeInfoStorage::GenerateId(const char* className)
{
    return crc32(0L, reinterpret_cast<const Bytef*>(className), strlen(className));
}
