#ifndef __ISTATE_H__
#define __ISTATE_H__ 

namespace SonyCandal
{

	class iState
	{
		public:
			virtual void enter() = 0;
			virtual void leave() = 0;
			virtual void pause() = 0;
			virtual void resume() = 0;

			virtual void update(double timeElapsed) = 0;	
	};
}
#endif