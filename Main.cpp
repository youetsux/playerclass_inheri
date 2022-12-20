# include <Siv3D.hpp> // OpenSiv3D v0.6.3
#include "cGameChar.h"
#include "cEnemy.h"
#include "cPlayer.h"
void Main()
{
	// 背景の色を設定 | Set background color
	Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 });
	// 通常のフォントを作成 | Create a new font
	const Font font{ 60 };

	//cEnemy* pEnemy = new cEnemy(Vec2(0,0));
	//cPlayer* pPlayer = new cPlayer(Vec2(0, 0));

	//cGameChar* OBJS[2];
	//OBJS[0] = pEnemy;
	//OBJS[1] = pPlayer;
	// こいつらは可変長配列を使って以下のように書き換えられます。
	std::vector<cGameChar*> g_objs;
	g_objs.emplace_back(new cEnemy(Vec2(0, 0)));
	g_objs.emplace_back(new cPlayer(Vec2(0, 0)));


	//Size s = Scene::Size(); s.x s.y でウィンドウの幅と高さがとれるよ
	while (System::Update())
	{
		//for (int i = 0; i < 2; i++)
		//{
		//	OBJS[i]->Update();
		//}
		//for (int i = 0; i < 2; i++)
		//{
		//	OBJS[i]->Draw();
		//}
		for (auto& i : g_objs)
		{
			i->Update();
		}
		for (auto& i : g_objs)
		{
			i->Draw();
		}
		//pEnemy->Update();
		//pPlayer->Update();
		//pEnemy->Draw();
		//pPlayer->Draw();
	}
}
