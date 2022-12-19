#pragma once

//キャラクターのベースになるクラス
class cGameChar
{
public:
	Vec2 position_; //位置（位置ベクトル）
	Vec2 direction_; //向き（単位ベクトル）
	double rot_;//回転角 （radian）
	cGameChar(Vec2 _pos);
	virtual void Update(); //位置情報や、キャラの状態の更新
	virtual void Draw();  //画面への描画処理
};

