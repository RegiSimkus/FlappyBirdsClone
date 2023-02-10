#pragma once

#ifndef _DIRECT_X_H
#define _DIRECT_X_H

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

extern IDirect3D9* g_pD3D;
extern IDirect3DDevice9* g_pDevice;
extern D3DPRESENT_PARAMETERS g_d3dparams;
extern ID3DXLine* g_pLine;
extern ID3DXFont* g_pFont;

void InitializeDirectX(HWND hWnd);

#endif