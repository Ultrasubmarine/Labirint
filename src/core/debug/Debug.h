//
//  Debug.h
//  Labirint
//
//  Created by marina porkhunova on 23.03.2023.
//

#ifndef Debug_h
#define Debug_h

#include "DebugSystem.hpp"
#include "Game.hpp"

//#ifdef DEBUG
#define LOG(message) Game::Instance().debug->Log(std::string{message})

#define LOG_ERROR(message) Game::Instance().debug->Log(std::string{message}, LogType::error)

#define LOG_EXEPTION(message) Game::Instance().debug->Log(std::string{message}, LogType::exeption)
//#else
//#define LOG(message)

#endif /* Debug_h */
