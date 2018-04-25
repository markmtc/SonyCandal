#include <stdio.h>
#include "CoreManager.h"

CoreManager* CoreManager::m_CoreManager;

CoreManager* CoreManager::getSingletonPtr()
{
    if (CoreManager::m_CoreManager==nullptr)
        {CoreManager::m_CoreManager=new CoreManager();}

    return CoreManager::m_CoreManager;
}

CoreManager& CoreManager::getSingleton()
{
    if (CoreManager::m_CoreManager==nullptr)
        {CoreManager::m_CoreManager=new CoreManager();}

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
    return 0;
}

