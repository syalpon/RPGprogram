#include "Hp.h"
#include "Character.h"
#include <cstdio>
//---------------------------------------------------------------------
//コンストラクタ
//---------------------------------------------------------------------
Hp::Hp():Parameter(this,0,100,100){}
Hp::Hp(void *p,int _min,int _now,int _max):Parameter(p, _min, _now, _max){}

//---------------------------------------------------------------------
//オーバーライド：HP最大値増加
//---------------------------------------------------------------------
void Hp::Event_MaxIncrease_Process(int now_value, int update_value)
{
	SetNow(update_value);
}

//---------------------------------------------------------------------
//オーバーライド：HP現在値増加
//---------------------------------------------------------------------
void Hp::Event_NowIncrease_Process(int now_value, int update_value)
{
	Character* cp = (Character*)owner;

	printf("%sはHPが%d回復した(HP:%d→%d)\n", cp->GetName(), update_value - now_value, now_value, update_value < GetMax() ? GetMax() : update_value);
}


//---------------------------------------------------------------------
//オーバーライド：HP現在値減少
//---------------------------------------------------------------------
void Hp::Event_NowDecrease_Process(int now_value,int update_value)
{
	Character* cp = (Character*)owner;

	printf("%sは%dのダメージを受けた(HP:%d→%d)\n", cp->GetName(), now_value - update_value, now_value, update_value <GetMin()?GetMin(): update_value);
}


//---------------------------------------------------------------------
//オーバーライド：死亡処理
//---------------------------------------------------------------------
void Hp::Event_NowBelowMin_Process(int now_value,int update_value)
{
	Character* cp = (Character*)owner;

	cp->Dead();
}
