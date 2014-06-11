#ifndef BOIL_MAIN_LOOP_H
#define BOIL_MAIN_LOOP_H

#include <deque>
#include <functional>
#include <iostream>

namespace boil
{
	class main_loop : public std::deque<std::function<bool()>>
	{
	public:
		main_loop(): _stopping(false) {}
		virtual ~main_loop() {}
		
		void run()
		{
			while(!_stopping && this->size() > 0)
				for(auto it = this->begin(); it != this->end(); it++)
					if(!(*it)() || _stopping) break;
		}
		
		void stop()
		{
			_stopping = true;
		}
		
	protected:
		bool _stopping;
	};
}

#endif
