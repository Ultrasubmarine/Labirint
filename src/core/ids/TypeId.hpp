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

#define REGISTER_TYPE(CLASS_NAME) TypeInfoStorage::Register(#CLASS_NAME)
#define REGISTER_TYPE_BODY(CLASS_NAME) public: \
    static const TypeInfo& GetTypeInfo() \
{ static TypeInfo info = *TYPE_INFO_BY_NAME(CLASS_NAME);return info;}; private:

#define TYPE_ID(CLASS_NAME) CLASS_NAME::GetTypeInfo().id
#define TYPE_ID_BY_PTR_STR(str_ClassName) TypeInfoStorage::GetTypeInfoByName(str_ClassName)->id;

#define TYPE_INFO_BY_NAME(CLASS_NAME) TypeInfoStorage::GetTypeInfoByName(#CLASS_NAME)
#define TYPE_INFO(CLASS_ID) TypeInfoStorage::GetTypeInfo(CLASS_ID)

#define ERROR_TYPE_ID 0

typedef uint32_t TypeId;

struct TypeInfo
{
    TypeId id;
    const char* name;
};

class TypeInfoStorage
{
    static std::map<TypeId, TypeInfo> _types;
    
    static TypeId GenerateId(const char* className);
public:

    /// try to use GetTypeInfo(TypeId id) instead of this function;
    static const TypeInfo* GetTypeInfoByName(const char* className);
    static const TypeInfo* GetTypeInfo(TypeId id);
    
    static bool Register(const char* className);
};


