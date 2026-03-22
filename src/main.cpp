#include <Windows.h>
#include <iostream>
#include "proxy_gl32.h"

DWORD WINAPI MainThread(LPVOID lpParam)
{
    Beep(750, 300); 
    Beep(1000, 300);

    MessageBoxA(NULL, "ProxyGL32: Gacor Terinject!", "Status Mod", MB_OK | MB_ICONINFORMATION);

    return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        proxy_gl32::setup_proxy();

        DisableThreadLibraryCalls(hinstDLL);
        
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hinstDLL, 0, nullptr);
    }
    return TRUE;
}