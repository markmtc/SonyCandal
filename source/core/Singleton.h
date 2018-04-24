 #ifndef _SINGLETON_H__
 #define _SINGLETON_H__

namespace SonyCandal 
{
	template <typename T> class Singleton
	{
	private:
		Singleton(const Singleton<T> &);
	 
		Singleton& operator=(const Singleton<T> &);
	     
	protected:
		static T* msSingleton;

	public:
	    Singleton( void )
		{ 
			assert( !msSingleton );
			msSingleton = static_cast< T* >( this );
	 	}
 	
 		~Singleton( void )
	 		{  
	 			assert( msSingleton );  
	 			msSingleton = 0;  
	 		}
	
		static T& getSingleton( void )
	 		{   
	 			assert( msSingleton );  
	 			return ( *msSingleton ); 
	 		}
	
	 	static T* getSingletonPtr( void )
			{
				if (msSingleton==nullptr)
					msSingleton = new T();
				return msSingleton; 
			}
	};
}

#endif