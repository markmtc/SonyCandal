 #ifndef __COREMANAGER_H__
 #define __COREMANAGER_H__ 
#include <gccore.h>

using namespace std;

class CoreManager
{
private:
	static CoreManager*  m_CoreManager;
	static void *xfb;
	static GXRModeObj *rmode;

	CoreManager(); //Tenelos que iniciar todos los recursos

public:
	~CoreManager(){};  

	static CoreManager* getSingletonPtr();
	static CoreManager& getSingleton();

	void lecturaDatosEntrada(double timeElapsed);
	void modificarDispositivosSalida(double timeElapsed);

	int run(); //Creamos el primer estado y le pasamos el control
	


 // Inicio del gestor de estados

	// Funciones para acceder a los recursos globales
	//InputReader* getInputReader() { return m_inputReader; }
		// Inicialización de los recursos

// Recursos globales
//InputReader* m_inputReader;
};

#endif

