//
//  GetPath.h
//  Labirint
//
//  Created by marina porkhunova on 05.01.2023.
//

#ifndef GetPath_h
#define GetPath_h


#endif /* GetPath_h */
#include <CoreFoundation/CoreFoundation.h>

//use free() to returned string
char * GetPath(CFStringRef name, CFStringRef type)
{
#ifdef __APPLE__
    CFURLRef manifest_url = CFBundleCopyResourceURL(CFBundleGetMainBundle(),
                                                    name, type,
                                                    NULL);
    char * manifest_path = (char *)malloc(PATH_MAX);
    CFURLGetFileSystemRepresentation(manifest_url, true, (Uint8 *)manifest_path, PATH_MAX);
    
    if (manifest_url != NULL)
        {
          CFRelease(manifest_url);
        }
    return manifest_path;
#endif
    return NULL;
}
