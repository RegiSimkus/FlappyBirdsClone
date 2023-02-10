#include "game.h"
#include "drawing.h"

CGame::CGame()
{
	Bird = new CBird();

	D3DXCreateSprite(g_pDevice, &pSprite);

	// D3DXCreateTextureFromFileEx(g_pDevice, L".\\background-day.png", 288, 512, 1, D3DUSAGE_DYNAMIC, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, 0, NULL, NULL, &Textures.Background)
	//D3DXIMAGE_INFO img;
	//img.Height = 512;
	//img.Width = 288;

	//if (FAILED(D3DXCreateTextureFromFileEx(
	//	g_pDevice,
	//	L".\\background-day.png",
	//	288, // w
	//	512, // h
	//	1, // MipLevels 
	//	D3DUSAGE_DYNAMIC, // Usage 
	//	D3DFMT_FROM_FILE, // Format 
	//	D3DPOOL_DEFAULT, // Pool 
	//	D3DX_DEFAULT, // Filter 
	//	D3DX_DEFAULT, // MipFilter 
	//	0, // ColorKey 
	//	&img, // pSrcInfo 
	//	NULL, // pPalette 
	//	&Textures.Background // ppTexture 
	//)))
	{
		if (FAILED(D3DXCreateTextureFromFile(g_pDevice, L".\\background-day.png", &Textures.Background)))
		{
			MessageBoxA(NULL, "Erro", "Failed to create texture", MB_OK);
		}
	}

}

CGame::~CGame()
{
	pSprite->Release();
	delete pSprite;
	delete Bird;
}

void CGame::DrawBackground()
{

	D3DXCreateSprite(g_pDevice, &pSprite);

	if (SUCCEEDED(pSprite->Begin(D3DXSPRITE_ALPHABLEND)))
	{


		D3DXMATRIX matrix;
		float scale = g_d3dparams.BackBufferHeight / 512.f;
		D3DXMatrixScaling(&matrix, (288.f / 512.f) * scale, scale, 1);
		D3DXVECTOR2 scaling = { (288.f / 512.f) * scale, scale };
		D3DXVECTOR2 translation;

		for (size_t i = 0; i < ceil(g_d3dparams.BackBufferWidth / 288.f); i++)
		{
			translation = { i * 288.f, 0 };
			D3DXMatrixTransformation2D(&matrix, NULL, 0, &scaling, NULL, 0, &translation);
			pSprite->SetTransform(&matrix);
			pSprite->Draw(Textures.Background, NULL, NULL, NULL, D3DCOLOR_RGBA(255, 255, 255, 255));
		}
		pSprite->End();
	}
};

CGame* g_pGame = nullptr;