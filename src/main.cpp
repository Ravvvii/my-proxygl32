#include <Windows.h>
#include <iostream>

#include "proxy_gl32.h"

// The thread function that will run once the DLL is injected
DWORD WINAPI MainThread(LPVOID lpParam)
{
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    freopen_s(&f, "CONOUT$", "w", stderr);

    std::cout << "[+] DLL Injected successfully!" << std::endl;

    // Cleanup
    if (f) fclose(f);
    FreeConsole();

    // Unload the DLL and exit the thread safely
    FreeLibraryAndExitThread((HMODULE)lpParam, 0);
    return 0;
}



BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        proxy_gl32::setup_proxy();

        DisableThreadLibraryCalls(hinstDLL);
        CreateThread(nullptr, 0, MainThread, hinstDLL, 0, nullptr);

    } else if (fdwReason == DLL_PROCESS_DETACH)
    {
        std::cout << "unloading" << std::endl;
    }
    return TRUE;
}