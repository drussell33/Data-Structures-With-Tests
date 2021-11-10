#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

int main()
{
	{
		// Your code here inside an inner scope
		// so that it destructs before the memory
		// checking happens

		
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	return 0;
}