#include <stdio.h>
#include "CoreManager.h"
#include <gccore.h>
#include <wiiuse/wpad.h>
#include "GameState.h"
#include "MenuState.h"

#include <SDL/sdl.h>

SDL_Surface* screen=NULL;


CoreManager *CoreManager::m_CoreManager;
void *CoreManager::xfb = NULL;
GXRModeObj *CoreManager::rmode = NULL;

CoreManager::CoreManager()
{
    CoreManager::IniciaHardware();
    CoreManager::IniciaEstados();
}

CoreManager *CoreManager::getSingletonPtr()
{
    if (CoreManager::m_CoreManager == nullptr)
    {
        CoreManager::m_CoreManager = new CoreManager();
    }

    return CoreManager::m_CoreManager;
}

CoreManager &CoreManager::getSingleton()
{
    if (CoreManager::m_CoreManager == nullptr)
    {
        CoreManager::m_CoreManager = new CoreManager();
    }

    return *CoreManager::m_CoreManager;
}

void CoreManager::lecturaDatosEntrada(double timeElapsed)
{
}

void CoreManager::modificarDispositivosSalida(double timeElapsed)
{
}

int CoreManager::run()
{
    printf("\x1b[2;0H");
    printf("Hello World!");

    while (1)
    {
        // Call WPAD_ScanPads each loop, this reads the latest controller states
        WPAD_ScanPads();
        // WPAD_ButtonsDown tells us which buttons were pressed in this loop
        // this is a "one shot" state which will not fire again until the button has been released
        u32 pressed = WPAD_ButtonsDown(WPAD_CHAN_0);
        // We return to the launcher application via exit
        if (pressed & WPAD_BUTTON_LEFT)
            printf("IZQUIERDA\r\n");
        if (pressed & WPAD_BUTTON_RIGHT)
            printf("DERECHA\r\n");
        if (pressed & WPAD_BUTTON_DOWN)
            printf("ABAJO\r\n");
        if (pressed & WPAD_BUTTON_UP)
            printf("ARRIBA\r\n");
        if (pressed & WPAD_BUTTON_HOME)
            return 0;
        // Wait for the next frame
        VIDEO_WaitVSync();
    }
    return 0;
}

void CoreManager::IniciaHardware()
{
    VIDEO_Init();
    WPAD_Init();
    rmode = VIDEO_GetPreferredMode(NULL);
    xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
    // // Initialise the console, required for printf
    console_init(xfb, 20, 20, rmode->fbWidth, rmode->xfbHeight, rmode->fbWidth * VI_DISPLAY_PIX_SZ);
    VIDEO_Configure(rmode);
    VIDEO_SetNextFramebuffer(xfb);
    VIDEO_SetBlack(FALSE);
    VIDEO_Flush();
    VIDEO_WaitVSync();
    if (rmode->viTVMode & VI_NON_INTERLACE)
        VIDEO_WaitVSync();
}

void CoreManager::IniciaEstados()
{
    CoreManager::stateManager = new StateManager();
    CoreManager::stateManager->registerState("GAME", new GameState());
    CoreManager::stateManager->registerState("MENU", new MenuState());

    CoreManager::stateManager->changeTo("MENU");
}