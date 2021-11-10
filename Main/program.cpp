#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

int main()
{
	{
		// Move constructor.
		//MemoryBlock(MemoryBlock && other)
		//	: _data(nullptr)
		//	, _length(0)
		//{
		//	std::cout << "In MemoryBlock(MemoryBlock&&). length = "
		//		<< other._length << ". Moving resource." << std::endl;

		//	// Copy the data pointer and its length from the
		//	// source object.
		//	_data = other._data;
		//	_length = other._length;

		//	// Release the data pointer from the source object so that
		//	// the destructor does not free the memory multiple times.
		//	other._data = nullptr;
		//	other._length = 0;
		//}

		//// Move assignment operator.
		//MemoryBlock& operator=(MemoryBlock && other)
		//{
		//	std::cout << "In operator=(MemoryBlock&&). length = "
		//		<< other._length << "." << std::endl;

		//	if (this != &other)
		//	{
		//		// Free the existing resource.
		//		delete[] _data;

		//		// Copy the data pointer and its length from the
		//		// source object.
		//		_data = other._data;
		//		_length = other._length;

		//		// Release the data pointer from the source object so that
		//		// the destructor does not free the memory multiple times.
		//		other._data = nullptr;
		//		other._length = 0;
		//	}
		//	return *this;
		//}
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	return 0;
}