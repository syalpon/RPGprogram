#include "Hp.h"
#include "Character.h"
#include <cstdio>
//---------------------------------------------------------------------
//コンストラクタ
//---------------------------------------------------------------------
Hp::Hp()
	:Parameter(this,0,100,100)
{
	/*not reached*/
	printf("ERROR : HP constractor\n");
}

Hp::Hp(void *p,int _min,int _now,int _max)
	:Parameter(p, _min, _now, _max)
{

}

//---------------------------------------------------------------------
//オーバーライド：HP最大値増加
//---------------------------------------------------------------------
void Hp::Event_MaxIncrement(int now, int x)
{
	Now(x);
}

//---------------------------------------------------------------------
//オーバーライド：HP現在値増加
//---------------------------------------------------------------------
void Hp::Event_NowIncrement(int now, int x)
{
	Character* cp = (Character*)owner;

	printf("%sはHPが%d回復した(HP:%d→%d)\n", cp->GetName(), x - now , now, x < Max() ? Max() : x);
}


//---------------------------------------------------------------------
//オーバーライド：HP現在値減少
//---------------------------------------------------------------------
void Hp::Event_NowDecrement(int now,int x)
{
	Character* cp = (Character*)owner;

	printf("%sは%dのダメージを受けた(HP:%d→%d)\n", cp->GetName(),now-x, now, x<Min()?Min():x);
}


//---------------------------------------------------------------------
//オーバーライド：死亡処理
//---------------------------------------------------------------------
void Hp::Event_NowBelowMin(int now,int x)
{
	Character* cp = (Character*)owner;

	cp->Dead();
}






