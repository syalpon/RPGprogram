#include "Character.h"
#include <cstdio>
#include <cstring>

//---------------------------------------------------------------------
//コンストラクタ
//---------------------------------------------------------------------
Character::Character():Character("No Name")
{
	/* 引数付きコンストラクタに委譲 */
}

Character::Character(const char* _name)
	: hp(this , 0, 100, 100),
	  mp(this , 0, 100, 100),
	  exp(this, 0,   0, 100),
	  lv(this , 1,   1,  99),
	  atk(this, 0,  10, 100)
{
	strcpy(name, _name);
	side = OTHER;
	alive = true;
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
	alive = true;
}

//---------------------------------------------------------------------
//ゲッター
//---------------------------------------------------------------------
char* Character::GetName()
{
	return name;
}

bool  Character::GetAlive()
{
	return alive;
}


//---------------------------------------------------------------------
//キャラクター攻撃処理
//---------------------------------------------------------------------
void Character::Atack(Character &character)
{
	int now = character.hp.GetNow();

	printf("%sは%sに攻撃した\n", this->name,character.name);
	character.hp.SetNow( now - this->atk.GetNow() );
}

//---------------------------------------------------------------------
//キャラクターレベルアップ処理
//---------------------------------------------------------------------
void Character::LevelUp()
{
	printf("%sはレベルアップした\n", name);
	lv.SetNow(lv.GetNow()+1);
	exp.SetMax(exp.GetMax()+5);
	hp.SetMax(hp.GetMax()+10);
	mp.SetMax(mp.GetMax()+20);
	atk.SetNow(atk.GetNow()+5);

	//デバッグ
	Show();
}

//---------------------------------------------------------------------
//キャラクター死亡処理
//---------------------------------------------------------------------
void Character::Dead()
{
	printf("%sは死亡した\n",name);
	alive = false;
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
		printf("[陣営]:%s\n", "味方");
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
	exp.SetNow(exp.GetNow()+350);
}