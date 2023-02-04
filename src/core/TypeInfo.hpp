//
//  TypeID.hpp
//  Labirint
//
//  Created by marina porkhunova on 04.02.2023.
//

#ifndef TypeID_hpp
#define TypeID_hpp

#include <stdio.h>
#include <iostream>
#include <map>
#endif /* TypeID_hpp */

#define REGISTER_TYPE(CLASS) TypeInfoStorage::Register(#CLASS);

#define TYPE_ID(CLASS) TypeInfoStorage::GetTypeID(const char* className);
#define TYPE_INFO(CLASS) TypeInfoStorage::GetTypeInfo(const char* className);

#define ERROR_TYPE_ID 0

typedef uint32_t typeId;

struct TypeInfo
{
    typeId id;
    const char* name;
};


class TypeInfoStorage
{
    static std::map<const char*, TypeInfo> _types;
public:

    static typeId GetTypeID(const char* className);
    static const TypeInfo* GetTypeInfo(const char* className);    
    static bool Register(const char* className);
};



