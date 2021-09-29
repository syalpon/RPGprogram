#ifndef CHARACTER_H
#define CHARACTER_H

#include "Side.h"
#include "Parameter.h"
#include "Hp.h"
#include "Mp.h"
#include "Exp.h"
#include "Lv.h"
#include "Atk.h"

#define NAME_SIZE 8 //名前の最大文字数

//キャラクタークラス
class Character
{
private:
	//フィールド
	char name[NAME_SIZE];	//名前
	Side side;				//陣営
	Hp   hp;				//体力
	Mp   mp;				//魔力
	Exp  exp;				//経験値
	Lv   lv;				//レベル
	Atk  atk;				//攻撃力

public :
	//コンストラクタ
	Character();
	Character(const char *);
	Character(
		const char *,
		Side ,
		int,int,int,	//HP
		int,int,int,	//MP
		int,int,int,	//EXP
		int,int,int,	//LV
		int,int,int		//ATK
	);
	//ゲッター
	char* GetName();



	//攻撃処理
	void Atack(Character &);

	//レベルアップ処理
	void LevelUp();

	//死亡処理
	void Dead();

	//ステータス表示
	void Show();


	//デバッグ
	void Test();
};

#endif