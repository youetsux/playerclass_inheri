#pragma once
#include "cGameChar.h"
#include "Mat2x2.h"


class cEnemy :
    public cGameChar
{
	Mat2x2 afn_; //変換用行列
	double speed_;  //移動速度
	double radius_; //キャラの大きさ
	//各ベクトルと回転角からそのフレームの変換行列を求める
	void SetAffineMatrixRadians(double _angle_rad);
	void SetAffineMatrixDegrees(double _angle_deg);
	//void SetMirrorTransformMatrix();
public:
	cEnemy(Vec2 _pos)
		:cGameChar(_pos)
	{
		radius_ = 20.0;
		direction_ = Vec2(1, 0);
		position_ = Vec2(100, 100);
		speed_ = 2.0; //とりあえずスピード2.0 pix/frameで動くことにする
		rot_ = 0;
		afn_ = Mat2x2::Identity();
	}
	void Update() override;
	void Draw() override;
};

