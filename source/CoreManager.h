 #ifndef __COREMANAGER_H__
 #define __COREMANAGER_H__ 

using namespace std;

class CoreManager
{
private:
	static CoreManager*  m_CoreManager;
	CoreManager(){};

public:
	~CoreManager(){}; 
	static CoreManager* getSingletonPtr();
	static CoreManager& getSingleton();

	int run();
	


 // Inicio del gestor de estados

	// Funciones para acceder a los recursos globales
	//InputReader* getInputReader() { return m_inputReader; }
		// Inicialización de los recursos

// Recursos globales
//InputReader* m_inputReader;
};

#endif

