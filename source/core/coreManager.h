#ifndef __COREMANAGER_H__
#define __COREMANAGER_H__ 
#include "Singleton.h"

namespace SonyCandal
{
	class CoreManager
		: public Singleton<CoreManager>
	{
		friend class Singleton;
	public:
		~CoreManager(); // Finalización de los recursos
		//static CoreManager* getSingletonPtr();
		//static CoreManager& getSingleton();
		int run(); // Inicio del gestor de estados
		// Funciones para acceder a los recursos globales
		//InputReader* getInputReader() { return m_inputReader; }
	private:
		CoreManager(); // Inicialización de los recursos


	// Recursos globales
	//InputReader* m_inputReader;
	};
}
#endif

