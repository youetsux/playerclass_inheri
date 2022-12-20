#include "stdafx.h"
#include "cEnemy.h"


void cEnemy::SetAffineMatrixRadians(double _angle_rad)
{
	afn_ = Mat2x2::Identity();
	afn_._11 = static_cast<float>(-Math::Cos(_angle_rad));
	afn_._22 = static_cast<float>(Math::Sin(_angle_rad));
}

void cEnemy::SetAffineMatrixDegrees(double _angle_deg)
{
	afn_ = Mat2x2::Identity();
	afn_._11 = static_cast<float>(-Math::Cos(Math::ToRadians(_angle_deg)));
	afn_._22 = static_cast<float>(Math::Sin(Math::ToRadians(_angle_deg)));
}

//void cEnemy::SetMirrorTransformMatrix()
//{
//	afn_ = Mat2x2::Identity();
//	afn_._11 = -1;
//}

void cEnemy::Update()
{
	Mat2x2 invMat(-1.0f, 0.0f, 0.0f, 1.0f); //y軸反転のアフィン変換行列
	 
	//往復運動させよう！
	if (position_.x < radius_ || position_.x > Scene::Size().x - radius_)
		Mat2x2::multiMatAndMat(afn_, afn_, invMat);

	direction_ = afn_.transformPoint(direction_); //キャラの方向を更新
	position_ = position_ + speed_ * direction_;  //キャラの方向にspeed_分進める
}

void cEnemy::Draw()
{   //輪郭付きの円を書いてキャラを表す
	Circle(position_.x, position_.y, radius_)  
		.drawFrame(1.0, Palette::Black)
		.draw(Palette::Yellow);
	//キャラの向いている方向に矢印を書くよ
	Vec2 endPoint = position_ + direction_ * radius_;
	Line{ position_, endPoint }
	.drawArrow(3, Vec2{ 15, 10 }, Palette::Red);
}
