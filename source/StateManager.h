#ifndef __STATEMANAGER_H__
#define __STATEMANAGER_H__

#include <string>
#include <map>
#include "iState.h"

namespace SonyCandal
{
	class StateManager
	{
	private:
		std::map<std::string, iState*> m_states;
		iState* m_current;
	
	public:
		StateManager() : m_current(NULL) { }
	
		void registerState(const std::string& name, iState* state)
		{
			m_states[name] = state;
		}
	
		void changeTo(const std::string& name)
		{
			if (m_current != NULL)
				m_current->leave();
	
		m_current = m_states[name];
		m_current->enter();
		}
	
		void update(double timeElapsed)
		{
		if (m_current != NULL)
			m_current->update(timeElapsed);
		}
	};
}
#endif	