#pragma once

#ifdef _MSC_VER
	#ifdef FACTORY_SHARED_LIB
	#define FACTORY_SPEC __declspec(dllexport)
	#else
	#define FACTORY_SPEC __declspec(dllimport)
	#endif
#else
#endif