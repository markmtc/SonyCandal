#ifndef __MENUSTATE_H__
#define __MENUSTATE_H__

#include "iState.h"
#include "StateManager.h"


class MenuState
	: public iState
{
	private:
		StateManager* m_manager;
		int options;

	public:
		MenuState()
		{ }
		// IState members
		
		void enter() { /* Dibujar menú */ }
		void leave() { /* Limpiar menú */ }
		void update(double timeElapsed) { /* Mirar entrada de datos y actuar */	}
};
#endif