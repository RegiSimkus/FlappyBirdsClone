#pragma once

#ifndef _DRAWING_H
#define _DRAWING_H

#include "directx.h"
#include "vector.h"

void DrawLine(Vector2 start, Vector2 end, D3DCOLOR color, UINT thickness);

#endif // _DRAWING_H