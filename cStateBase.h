#pragma once
#include "cGameChar.h"

class cStateBase
{
public:
	virtual ~State(){ }
	// 初期化
	virtual void Init(cGameChar* pParent) = 0;
	// 更新
	virtual void Update() = 0;
	// 状態表示(デバッグ用)
	virtual void PrintState() = 0;
};
