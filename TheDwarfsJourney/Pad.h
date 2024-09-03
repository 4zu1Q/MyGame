#pragma once
namespace Pad
{
	// パッドの更新処理 1フレームに1回行う
	void Update();

	// 押されているかを取得
	bool IsPress(int key);
	// 押された瞬間を取得
	bool IsTrigger(int key);
	// 話した瞬間を取得
	bool IsRelase(int key);
};

