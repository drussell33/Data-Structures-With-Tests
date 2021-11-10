#ifndef CRTCHECKMEMORY_H
#define CRTCHECKMEMORY_H

#include "CppUnitTest.h"
#include "crtdbg.h"

#define _CRTDBG_MAP_ALLOC

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace data_structures_test
{
	class CrtCheckMemory
	{
	public:
		CrtCheckMemory()
		{
			_CrtMemCheckpoint(&state1_);
		}
		
		CrtCheckMemory(const CrtCheckMemory& copy) = delete;
		CrtCheckMemory& operator=(const CrtCheckMemory& copy) = delete;
		CrtCheckMemory(CrtCheckMemory&& copy) = delete;
		CrtCheckMemory& operator=(CrtCheckMemory&& copy) = delete;

		~CrtCheckMemory()
		{
			_CrtMemCheckpoint(&state2_);

			if (_CrtMemDifference(&state3_, &state1_, &state2_) != 0)
			{
				Assert::Fail(L"Detected memory leaks!");
			}
		}

		_CrtMemState state1_{};
		_CrtMemState state2_{};
		_CrtMemState state3_{};
	};
}

#endif