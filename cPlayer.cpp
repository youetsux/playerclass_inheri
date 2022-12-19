#include "stdafx.h"
#include "cPlayer.h"

void cPlayer::Update()
{
	if (KeyUp.pressed())
	{
		position_ = position_ + Vec2(0, -2);
	}
	if (KeyDown.pressed())
	{
		position_ = position_ + Vec2(0, 2);
	}
	if (KeyLeft.pressed())
	{
		position_ = position_ + Vec2(-2, 0);
	}
	if (KeyRight.pressed())
	{
		position_ = position_ + Vec2(2, 0);
	}
}

void cPlayer::Draw()
{
	const double radius = 20.0;
	//これもパラメータとして設定できるようにしたいね。今のところ定数
	Circle(position_.x, position_.y, radius).draw(Palette::Aliceblue);
}
