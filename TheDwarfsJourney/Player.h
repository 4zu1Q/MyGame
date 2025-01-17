#pragma once
#include "DxLib.h"

class Player
{
public:
	Player();
	virtual ~Player();

	void Load();
	void Delete();

	void Init();
	void Update();
	void Draw();

	//カメラの方向を取得
	void SetCameraAngle(float angle) { m_cameraAngle = angle; }
	//半径の取得
	float GetRadius() { return m_radius; }

	//プレイヤーの座標を取得
	const VECTOR& GetPos() const { return m_pos; }
	void SetPos(const VECTOR pos) { m_pos = pos; }

	//プレイヤーのHPを取得
	const int& GetHp() const { return m_hp; }
	void SetHp(const int hp) { m_hp = hp; }

	//プレイヤーの攻撃の座標を取得
	void OnGimmickHitUpdate();

	////プレイヤーの状態
	//enum class State : int
	//{
	//	kStand,		//立ち止まり
	//	kWalk,		//歩き
	//	kRun,		//走り
	//	kAttack,	//攻撃
	//	kJump,		//ジャンプ
	//	kBigJump,	//大ジャンプ
	//};

	//プレイヤーのアニメーション種別
	enum class AnimKind : int
	{
		kNone = -1,	//なし
		kUnknown,	//不明
		kIdle = 1,		//待機
		kWalk = 2,		//歩き
		kRun,		//走り
		kAttack = 30,	//攻撃
		kJump,		//ジャンプ
		kBigJump,	//大ジャンプ
		kFall,		//落下中
		kDamage,	//ダメージ
		kStop,		//立ち止まり
	};

private:
	//アニメーションの進行
	//ループしたかどうかを返す
	bool UpdateAnim(int attachNo);

	//アニメーションの変更
	void ChangeAnim(int animIndex);

	void ShaderLoad();
	void ShaderUpdate();

	void PlayAnim(AnimKind playAnim);	//新たなアニメーションを再生

	void AttackCol(VECTOR pos);

private:
	//モデルハンドル
	int m_modelH;

	//画像ハンドル
	int m_hpH;
	int m_losthpH;

	//シェーダハンドル
	int m_outlineVsH;
	int m_outlinePsH;

	//HP
	int m_hp;
	int m_losthp;

	//表示情報
	VECTOR m_pos;
	VECTOR m_attackPos;


	float m_angle;

	//攻撃中フラグ
	bool m_isAttack;
	bool m_isJump;

	//アニメーション情報
	int m_currentAnimNo;	//現在のアニメーション
	int m_prevAnimNo;		//変更前のアニメーション
	float m_animBlendRate;	//アニメーション合成割合


	//当たり判定の半径
	float m_radius;

	//カメラ情報
	float m_cameraAngle;

	int m_currentPlayAnim;
	float m_currentAnimCount;

	int m_prevPlayAnim;
	float m_prevAnimCount;
	//float m_animBlendRate;
	bool m_isMove;

	float m_hpAnimationHeight;

	//State m_currentState;
	AnimKind m_animIndex;
	int m_animationIndex;
};

