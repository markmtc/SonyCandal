 #ifndef __COREMANAGER_H__
 #define __COREMANAGER_H__ 

using namespace std;

class CoreManager
{
private:
	static CoreManager*  m_CoreManager;

public:
	~CoreManager(){}; // Finalización de los recursos

	static CoreManager* getSingletonPtr()
	{
    	if (CoreManager::m_CoreManager==nullptr)
        	{m_CoreManager=new CoreManager();}
   
		return m_CoreManager;
	};

	//static CoreManager& getSingleton();

	int run();
private:
	CoreManager(){};
	


 // Inicio del gestor de estados

	// Funciones para acceder a los recursos globales
	//InputReader* getInputReader() { return m_inputReader; }
		// Inicialización de los recursos

// Recursos globales
//InputReader* m_inputReader;
};

#endif

