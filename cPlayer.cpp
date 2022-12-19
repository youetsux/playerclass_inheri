#include "stdafx.h"
#include "cPlayer.h"

void cPlayer::Input()
{
	//0000上下左右
	//00000001 右
	//00000010 左
	//00001010 左上
	inputFlags = 0;
	inputFlags = ((KeyUp.pressed()) << 0 ) + ((KeyDown.pressed()) << 1)
			      + ((KeyLeft.pressed()) << 2) + ((KeyRight.pressed()) << 3);
}

void cPlayer::Update()
{
	Input();
	//ルックアップテーブルで移動ベクトルをセットしておく
	std::map<uint8, Vec2> dVec = { {1, { 0,-2 }}, { 2,{0, 2} }, { 4,{-2,0} },
								   { 5,{-1.2,-1.2} },{6,{-1.2, 1.2}}, { 8,{2,0} },
                                	{ 9,{1.2,-1.2} },{10,{1.2, 1.2}}};
									
	position_ = position_ + dVec[inputFlags];
}

void cPlayer::Draw()
{
	const double radius = 20.0;
	//これもパラメータとして設定できるようにしたいね。今のところ定数
	Circle(position_.x, position_.y, radius).draw(Palette::Aliceblue);
}
