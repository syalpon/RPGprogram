#include "Exp.h"
#include "Character.h"

//---------------------------------------------------------------------
//コンストラクタ
//---------------------------------------------------------------------
Atk::Atk()
	:Parameter(nullptr, 0, 100, 100)
{
	/*not reached*/
}

Atk::Atk(void* p, int _min, int _now, int _max)
	:Parameter(p, _min, _now, _max)
{

}
