#include "Mp.h"
#include "Character.h"

//---------------------------------------------------------------------
//�R���X�g���N�^
//---------------------------------------------------------------------
Mp::Mp()
	:Parameter(nullptr, 0, 100, 100)
{
	/*not reached*/
}

Mp::Mp(void* p, int _min, int _now, int _max)
	:Parameter(p, _min, _now, _max)
{
	Min(_min);
	Now(_now);
	Max(_max);
}

