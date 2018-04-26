#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include "iState.h"
#include "StateManager.h"
#include "CoreManager.h"

class GameState
    : public iState
{
  private:
    StateManager *m_manager;
    int options;

  public:
    GameState() {};
    // IState members
  public:
    void enter() { /* Inicializar nivel del juego */}
    void leave() { /* Liberar recursos del nivel del juego */}
    void pause() { }
    void resume() { }
    void update(double timeElapsed)
    {
        CoreManager &core = CoreManager::getSingleton();
        core.lecturaDatosEntrada(timeElapsed);
        // core.lecturaDatosDeRed(timeElapsed);
        // core.lecturaDatosIA(timeElapsed);
        // core.getFisica().update(timeElapsed);
        // core.getLogica().updateReglasDeJuego(timeElapsed);
        // core.enviarCambiosDeEstadoPorRed(timeElapsed);
         core.modificarDispositivosSalida(timeElapsed);
    }
};

#endif