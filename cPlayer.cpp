#include "stdafx.h"
#include "cPlayer.h"


void cPlayer::SetAffineMatrixRadians(double _angle_rad)
{
	afn_ = Mat2x2::Identity();

	afn_._11 = static_cast<float>(Math::Cos(_angle_rad));
	afn_._12 = static_cast<float>(-Math::Sin(_angle_rad));
	afn_._21 = static_cast<float>(Math::Sin(_angle_rad));
	afn_._22 = static_cast<float>(Math::Cos(_angle_rad));
}

void cPlayer::SetAffineMatrixDegrees(double _angle_deg)
{
	afn_ = Mat2x2::Identity();
	afn_._11 = static_cast<float>(Math::Cos(Math::ToRadians(_angle_deg)));
	afn_._12 = static_cast<float>(-Math::Sin(Math::ToRadians(_angle_deg)));
	afn_._21 = static_cast<float>(Math::Sin(Math::ToRadians(_angle_deg)));
	afn_._22 = static_cast<float>(-Math::Cos(Math::ToRadians(_angle_deg)));
}

void cPlayer::Input()
{
	//0000上下左右
	//00000001 右
	//00000010 左
	//00001010 左上
	inputFlags = 0; //前フレームの入力をリセット
	inputFlags = ((KeyUp.pressed()) << 0) + ((KeyDown.pressed()) << 1)
		+ ((KeyLeft.pressed()) << 2) + ((KeyRight.pressed()) << 3);
}

void cPlayer::Update()
{
	Input();
	//ルックアップテーブルで移動ベクトルをセットしておく

	//std::map<uint8, Vec2> dVec = { {1, { 0,-2 }}, { 2,{0, 2} }, { 4,{-2,0} },
	//							   { 5,{-1.2,-1.2} },{6,{-1.2, 1.2}}, { 8,{2,0} },
	//                            	{ 9,{1.2,-1.2} },{10,{1.2, 1.2}}};
	std::map<uint8, double> dVec = { {0, 0}, {1, 90}, { 2,-90 }, { 4,180 },
								   { 5,135 },{6,-135}, { 8, 0 },{ 9,45 },{10,-45} };
	dirVec_ = { 1, 0 };
	rot_ = dVec[inputFlags];
	SetAffineMatrixDegrees(rot_);
	dirVec_ = afn_.transformPoint(dirVec_);
	position_ = position_ + (inputFlags > 0) * speed_ * dirVec_;
}

void cPlayer::Draw()
{
	Circle(position_.x, position_.y, radius_)
		.drawFrame(1.0, Palette::Black)
		.draw(Palette::Blueviolet);

	Vec2 endPoint = position_ + dirVec_ * radius_;
	Line{ position_, endPoint }
	.drawArrow(3, Vec2{ 15, 10 }, Palette::Red);
}
