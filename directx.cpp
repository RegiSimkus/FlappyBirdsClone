#include "directx.h"

IDirect3D9* g_pD3D = nullptr;
IDirect3DDevice9* g_pDevice = nullptr;
ID3DXLine* g_pLine = nullptr;
ID3DXFont* g_pFont = nullptr;

D3DPRESENT_PARAMETERS g_d3dparams;
void InitializeDirectX(HWND hWnd)
{
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (g_pD3D == NULL)
	{
		throw "Failed to create IDirect3D9 object";
	}

	RECT rect;
	GetWindowRect(hWnd, &rect);

	ZeroMemory(&g_d3dparams, sizeof(D3DPRESENT_PARAMETERS));
	g_d3dparams.hDeviceWindow = hWnd;
	g_d3dparams.BackBufferWidth = rect.right - rect.left;
	g_d3dparams.BackBufferHeight = rect.bottom - rect.top;
	g_d3dparams.Windowed = TRUE;
	g_d3dparams.BackBufferFormat = D3DFMT_UNKNOWN;
	g_d3dparams.EnableAutoDepthStencil = TRUE;
	g_d3dparams.AutoDepthStencilFormat = D3DFMT_D16;
	g_d3dparams.SwapEffect = D3DSWAPEFFECT_DISCARD;

	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dparams, &g_pDevice)))
	{
		// try again but not windowed
		g_d3dparams.Windowed = FALSE;

		if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dparams, &g_pDevice)))
		{
			MessageBoxA(NULL, "Error", "Failed to create pdevice", MB_OK);
			throw "Failed to create pdevice";
		}
	}

	D3DXCreateLine(g_pDevice, &g_pLine);
	D3DXCreateFont(g_pDevice, 24, 12, FW_REGULAR, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH, L"Roboto", &g_pFont);
}