#pragma once

#ifndef _GAME_H
#define _GAME_H

#include "bird.h"
#include "directx.h"

class CGame
{
public:
	CBird* Bird;
	
	CGame();
	~CGame();

	void DrawBackground();

	ID3DXSprite* pSprite;

	struct
	{
		IDirect3DTexture9* Background;

	}Textures;
};

extern CGame* g_pGame;

#endif