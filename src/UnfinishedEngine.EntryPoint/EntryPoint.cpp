#include "stdafx.h"
#include "DirectX12Application.h"
#include "Win32Application.h"

// TODO: follow DirectX-Graphics-Samples\Samples\Desktop\D3D12HelloWorld\src\HelloTriangle\D3D12HelloTriangle.cpp
// and create our first triangle

_Use_decl_annotations_
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	DirectX12Application application(1920, 1200);
	return Win32Application::Run(&application, hInstance, nCmdShow);
}

