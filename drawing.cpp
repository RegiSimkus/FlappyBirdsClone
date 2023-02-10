#include "drawing.h"

void DrawLine(Vector2 start, Vector2 end, D3DCOLOR color, UINT thickness)
{
	D3DXVECTOR2 vertices[2];
	vertices[0] = { start.x, start.y };
	vertices[1] = { end.x, end.y };

	g_pLine->SetWidth(thickness);
	g_pLine->Draw(vertices, 2, color);
}