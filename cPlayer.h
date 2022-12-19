#pragma once
#include "cGameChar.h"
class cPlayer :
    public cGameChar
{
	uint8 inputFlags;
	void Input();
public:
	cPlayer(Vec2 _pos):cGameChar(_pos),inputFlags(0)
	{
		position_ = Vec2(200, 200);
	}
	void Update() override;
	void Draw() override;
};

