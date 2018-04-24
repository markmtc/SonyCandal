#include <stdio.h>
#include "CoreManager.h"

CoreManager *CoreManager::m_CoreManager;

int CoreManager::run()
{
    return 0;
}

//CoreManager* CoreManager::getSingletonPtr()


// CoreManager& CoreManager::getSingleton()
// {
//     if (CoreManager::m_CoreManager==nullptr)
//         CoreManager::m_CoreManager=new CoreManager();
//     return *CoreManager::m_CoreManager;
// }
