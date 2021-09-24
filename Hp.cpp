#include "Hp.h"
#include "Character.h"
#include <cstdio>
//---------------------------------------------------------------------
//コンストラクタ
//---------------------------------------------------------------------
Hp::Hp()
	:Parameter(nullptr,0,100,100)
{
	/*not reached*/
	printf("ERROR : HP constractor\n");
}

Hp::Hp(void *p,int _min,int _now,int _max)
	:Parameter(p, _min, _now, _max)
{
	Min(_min);
	Now(_now);
	Max(_max);
}

//---------------------------------------------------------------------
//オーバーライド：死亡処理
//---------------------------------------------------------------------
void Hp::Event_NowBelowMin()
{
	Character* cp = (Character*)owner;

	cp->Dead();
}






