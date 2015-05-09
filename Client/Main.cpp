// Client.cpp : main project file.

#include "stdafx.h"
#include "Observer.h"
using namespace System;

int main(array<String ^> ^args)
{
	if (args->Length != 2)
		return 1;

	Observer ^ observer = gcnew Observer(args);
	observer->run();
}