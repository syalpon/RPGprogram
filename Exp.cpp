#include "Exp.h"
#include "Character.h"
#include <stdio.h>
//---------------------------------------------------------------------
//�R���X�g���N�^
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

	Now( x - Max() ); //�ő�l�𒴂����ꍇ�͍ő�l�����Z

	cp->LevelUp();

	//�܂����x���A�b�v�ł���Ƃ�
	if ( Now() > Max() )
	{
		this->Event_NowExceedMax(Max(), Now());
	}
	
}
