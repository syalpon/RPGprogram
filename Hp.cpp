#include "Hp.h"
#include "Character.h"
#include <cstdio>
//---------------------------------------------------------------------
//�R���X�g���N�^
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
//�I�[�o�[���C�h�F���S����
//---------------------------------------------------------------------
void Hp::Event_NowBelowMin()
{
	Character* cp = (Character*)owner;

	cp->Dead();
}






