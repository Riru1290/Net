#pragma once
#include "BulletBase.h"

class BulletAR final : public BulletBase
{
public:

	BulletAR(int modelId, std::weak_ptr<ActorBase> parent);
	~BulletAR() = default;

	// 各自独自の設定
	void SetParam(void) override;

};

