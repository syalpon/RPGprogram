#include "Hp.h"
#include "Character.h"
#include <cstdio>
//---------------------------------------------------------------------
//�R���X�g���N�^
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
//�I�[�o�[���C�h�FHP�ő�l����
//---------------------------------------------------------------------
void Hp::Event_MaxIncrement(int now, int x)
{
	Now(x);
}

//---------------------------------------------------------------------
//�I�[�o�[���C�h�FHP���ݒl����
//---------------------------------------------------------------------
void Hp::Event_NowIncrement(int now, int x)
{
	Character* cp = (Character*)owner;

	printf("%s��HP��%d�񕜂���(HP:%d��%d)\n", cp->GetName(), x - now , now, x < Max() ? Max() : x);
}


//---------------------------------------------------------------------
//�I�[�o�[���C�h�FHP���ݒl����
//---------------------------------------------------------------------
void Hp::Event_NowDecrement(int now,int x)
{
	Character* cp = (Character*)owner;

	printf("%s��%d�̃_���[�W���󂯂�(HP:%d��%d)\n", cp->GetName(),now-x, now, x<Min()?Min():x);
}


//---------------------------------------------------------------------
//�I�[�o�[���C�h�F���S����
//---------------------------------------------------------------------
void Hp::Event_NowBelowMin(int now,int x)
{
	Character* cp = (Character*)owner;

	cp->Dead();
}






