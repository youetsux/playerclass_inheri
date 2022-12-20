#pragma once
#include "cGameChar.h"
#include "Mat2x2.h"

class cPlayer :
    public cGameChar
{
	uint8 inputFlags;
	Mat2x2 afn_; //変換用行列
	double speed_;  //移動速度
	double radius_; //キャラの大きさ
	Vec2 dirVec_;
	void SetAffineMatrixRadians(double _angle_rad);
	void SetAffineMatrixDegrees(double _angle_deg);
	void Input();
public:
	cPlayer(Vec2 _pos):cGameChar(_pos),inputFlags(0)
	{
		dirVec_ = { 1.0, 0 };
		speed_ = 2.0;
		radius_ = 25.0;
		position_ = Vec2(200, 200);
		afn_ = Mat2x2::Identity();
	}
	void Update() override;
	void Draw() override;
};

