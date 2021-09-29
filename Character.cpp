#include "Character.h"
#include <cstdio>
#include <cstring>

//---------------------------------------------------------------------
//コンストラクタ
//---------------------------------------------------------------------
Character::Character()
	:Character("No Name")
{
	/* 引数付きコンストラクタに委譲 */
}

Character::Character(const char* _name)
	: hp(this, 0, 100, 100),
	mp(this, 0, 100, 100),
	exp(this, 0, 0, 100),
	lv(this,1,1,99),
	atk(this,0,10,100)

{
	strcpy(name, _name);
	side = OTHER;
}

Character::Character(
	const char* _name,
	Side _side,
	int _hp_min , int _hp_now , int _hp_max,
	int _mp_min , int _mp_now , int _mp_max,
	int _exp_min, int _exp_now, int _exp_max,
	int _lv_min , int _lv_now , int _lv_max,
	int _atk_min, int _atk_now, int _atk_max
)
	: hp( this, _hp_min , _hp_now , _hp_max ),
	  mp( this, _mp_min , _mp_now , _mp_max ),
	  exp(this, _exp_min, _exp_now, _exp_max),
	  lv( this, _lv_min , _lv_now , _lv_max ),
	  atk(this, _atk_min, _atk_now, _atk_max)
{
	strcpy(name, _name);
	side = _side;
}

//---------------------------------------------------------------------
//ゲッター
//---------------------------------------------------------------------
char* Character::GetName()
{
	return name;
}

//---------------------------------------------------------------------
//キャラクター攻撃処理
//---------------------------------------------------------------------
void Character::Atack(Character &character)
{
	int now = character.hp.Now();

	printf("%sは%sに攻撃した\n", this->name,character.name);
	character.hp.Now( now - this->atk.Now() );
}

//---------------------------------------------------------------------
//キャラクターレベルアップ処理
//---------------------------------------------------------------------
void Character::LevelUp()
{
	printf("%sはレベルアップした\n", name);
	lv.Now(lv.Now()+1);
	exp.Max(exp.Max()+5);
	hp.Max(hp.Max()+10);
	mp.Max(mp.Max()+20);
	atk.Now(atk.Now()+5);

	//デバッグ
	Show();
}

//---------------------------------------------------------------------
//キャラクター死亡処理
//---------------------------------------------------------------------
void Character::Dead()
{
	printf("%sは死亡した\n",name);
}

//---------------------------------------------------------------------
//キャラクターステータス表示
//---------------------------------------------------------------------
void Character::Show()
{
	printf("-----------------------------------\n");
	printf("[名前]:%s\n", name);
	switch (side)
	{
	case ALLY:
		printf("[陣営]:%s\n", "見方");
		break;

	case ENEMY:
		printf("[陣営]:%s\n", "敵");
		break;

	case OTHER :
		printf("[陣営]:%s\n", "その他");
		break;
		
	default :
		printf("ERROR : Character::Show \n");
		break;
	}
	
	hp.Show("HP");
	mp.Show("MP");
	exp.Show("EXP");
	lv.Show("LV");
	atk.Show("ATK");

	printf("-----------------------------------\n");
}


//デバッグ
void Character::Test()
{
	exp.Now(exp.Now()+350);
}