//
//  main.cpp
//  FortuneCookie
//
//  Created by marina porkhunova on 26.10.2022.
//

#include <stdio.h>
#include <SDL2/SDL.h>

#define TITLE "sdl cookie"

#include <string.h>
#include <fstream>
#include <iostream>

#include <unistd.h>
#include <cmath>

#include <CoreFoundation/CoreFoundation.h>
#include <SDL2/SDL_render.h>
#include <cstdio>


char * GetPath(CFStringRef name, CFStringRef type);
Uint32 getpixel(SDL_Surface *surface, int x, int y);

using namespace std;

#include "src/core/Game.hpp"
#include "CallBack.hpp"


int main(int argc, char *argv[])
{

    Game *g = new Game();
    
  
    if(g->Init())
        return -1;

    
 //   Game::CreateSceneObject(SCENE_OBJ_RENDER_TICK);
    
    while(g->play)
    {
        g->Input();
      //  g->Tick(0.44);//TODO GET TIME
        g->Render();
        sleep(0.05f);
    }
//
//    delete g;
    
////    std::cout<<"current path: "<<std::filesystem::current_path().string();
////    std::cout<<"\npath::\n"<<getenv("PWD")<<'\n';
////
//
//    //bool isLose = false;
//
//    //// LOOOAD for XCODe version
//    char *image_path = GetPath(CFSTR("resources/images/labirint"), CFSTR("bmp"));
//
//
//    auto Loading_Surf = SDL_LoadBMP(image_path);
//
//    if(!Loading_Surf)
//        std::cout<<"\nFAIL\n";
//    else
//        std::cout<<"\nOK BRO\n";
//
//
//  // SDL_Texture* Background_Tx = SDL_CreateTextureFromSurface(render, Loading_Surf);
//
//   // Uint8 r,g,b;
//
//    free(image_path);
//
//    //  SDL_SetRenderDrawColor(render, 0xFf, 0xFf, 0xFf, 0xFF);
//    //  SDL_RenderClear(render);
//
//    SDL_Event event;
//
//    int mouse_x, mouse_y;
//
//
//
//
////
//
//
//    while(true)
//    {
//        if(SDL_PollEvent(&event) )
//        {
//            if(event.type == SDL_QUIT)
//                break;
//
//        }
//
//
//
////        SDL_GetWindowMouseRect(window);
//        auto where = SDL_GetMouseFocus();
//
//        if(where == window)
//        {
//            std::cout<<"\nMOUSE IN WINDOW\n";
//            SDL_GetMouseState(&mouse_x, &mouse_y);
//
//         //   Uint32* pixels =Background_Tx->getPixels32();
//          //  Background_Tx
//
//
//
//            SDL_Color rgb;
//            Uint32 data =  getpixel(Loading_Surf,mouse_x , mouse_y);
//            SDL_GetRGB(data, Loading_Surf->format, &rgb.r, &rgb.g, &rgb.b);
//
//
//            printf("color : %d %d %d\n", rgb.r, rgb.g, rgb.b);
////
//        }
//
//
//        SDL_SetRenderDrawColor(render, 0xff, 0xFf, 0xFf, 0xFF);
//      //  SDL_RenderClear(render);
//
//        SDL_RenderClear(render);
//        SDL_RenderCopy(render, Background_Tx, NULL, NULL);
//
//      //  Loading_Surf = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
//
//        /* Filling the surface with red color. */
//
//        SDL_RenderPresent(render);
//    }
//
//
//    SDL_FreeSurface(Loading_Surf);
//
//    SDL_DestroyRenderer(render);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//
    return 0;
    
}



Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

switch (bpp)
{
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
            break;

        case 4:
            return *(Uint32 *)p;
            break;

        default:
            return 0;       /* shouldn't happen, but avoids warnings */
      }
}



void Logic()
{
    
}

void Render()
{
    
}

void LoadResources()
{
    
}
