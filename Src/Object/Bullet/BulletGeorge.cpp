#include "../../Utility/Utility.h"
#include "../../Manager/CollisionManager.h"
#include "../Common/ColliderLine.h"
#include "BulletGeorge.h"

BulletGeorge::BulletGeorge(int modelId, std::weak_ptr<ActorBase> parent) : BulletBase(modelId, parent)
{
}

void BulletGeorge::Init_Object(void)
{
	// 各自独自の設定
	SetParam();

	// 移動回転大きさ等をモデルに反映
	transform_.Update();

	// コライダー
	collider_ = std::make_shared<ColliderLine>(GetPtr(), Collider::OBJECT_TYPE::ENEMY_BULLET);
	CollisionManager::GetInstance().SetCollider(collider_);
}

void BulletGeorge::SetParam(void)
{
	// スピード
	speed_ = 200.0f;

	// 生存時間
	aliveTime_ = 1.0f;

	// ダメージ
	damage_ = 15.0f;

	// ローカル回転
	// Z軸方向を前に
	VECTOR localRot = { Utility::Deg2RadF(90.0f),Utility::Deg2RadF(0.0f),Utility::Deg2RadF(0.0f) };
	transform_.quaRotLocal = Quaternion::Euler(localRot);

	// 大きさ
	float scale = 0.1f;
	transform_.scl = { scale,scale,scale };
}
