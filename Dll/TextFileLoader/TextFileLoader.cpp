// TextFileLoader.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"
#include <iostream>

#define UNITY_INTERFACE_API __stdcall
#define UNITY_INTERFACE_EXPORT __declspec(dllexport)

extern "C" {
	UNITY_INTERFACE_EXPORT void* UNITY_INTERFACE_API LoadText(char *name) {
		FILE *fp;
		errno_t error;
		error = fopen_s(&fp, name, "r");
		if (error != 0)
			return false;

		fseek(fp, 0, SEEK_END);
		size_t size = ftell(fp);

		char* where = new char[size];

		rewind(fp);
		fread(where, sizeof(char), size, fp);

		return static_cast<void*>(where);
	}
}
