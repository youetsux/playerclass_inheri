#pragma once
#include "cGameChar.h"
class cPlayer :
    public cGameChar
{
public:
	cPlayer(Vec2 _pos):cGameChar(_pos)
	{
		position_ = Vec2(200, 200);
	}
	void Update() override;
	void Draw() override;
};

