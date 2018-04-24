#ifndef __COREMANAGER_H__
#define __COREMANAGER_H__ 
#include "Singleton.h"

namespace SonyCandal
{
	class CoreManager
		: public Singleton<CoreManager>
	{
	public:
		//static CoreManager* getSingletonPtr();
		//static CoreManager& getSingleton();
		//CoreManager(); // Inicialización de los recursos
		~CoreManager(); // Finalización de los recursos
		int run(); // Inicio del gestor de estados
		// Funciones para acceder a los recursos globales
		//InputReader* getInputReader() { return m_inputReader; }
	private:
	// Recursos globales
	//InputReader* m_inputReader;
	};
}
#endif

