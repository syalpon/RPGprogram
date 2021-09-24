#include "Exp.h"
#include "Character.h"

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
	Min(_min);
	Now(_now);
	Max(_max);
}

void Exp::Event_NowExceedMax()
{
	Character* cp = (Character*)owner;
	Now( Now() - Max() );

	cp->LevelUp();

	if ( Now() > Max() )
	{
		this->Event_NowExceedMax();
	}
}
