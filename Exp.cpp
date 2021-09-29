#include "Exp.h"
#include "Character.h"
#include <stdio.h>
//---------------------------------------------------------------------
//コンストラクタ
//---------------------------------------------------------------------
Exp::Exp()
	:Parameter(nullptr, 0, 100, 100)
{
	/*not reached*/
}

Exp::Exp(void* p, int _min, int _now, int _max)
	:Parameter(p, _min, _now, _max)
{

}

void Exp::Event_NowExceedMax(int now ,int x)
{
	Character* cp = (Character*)owner;

	Now( x - Max() ); //最大値を超えた場合は最大値を減算

	cp->LevelUp();

	//まだレベルアップできるとき
	if ( Now() > Max() )
	{
		this->Event_NowExceedMax(Max(), Now());
	}
	
}
