#include "Hp.h"
#include "Character.h"
#include <cstdio>
//---------------------------------------------------------------------
//�R���X�g���N�^
//---------------------------------------------------------------------
Hp::Hp():Parameter(this,0,100,100){}
Hp::Hp(void *p,int _min,int _now,int _max):Parameter(p, _min, _now, _max){}

//---------------------------------------------------------------------
//�I�[�o�[���C�h�FHP�ő�l����
//---------------------------------------------------------------------
void Hp::Event_MaxIncrease_Process(int now_value, int update_value)
{
	SetNow(update_value);
}

//---------------------------------------------------------------------
//�I�[�o�[���C�h�FHP���ݒl����
//---------------------------------------------------------------------
void Hp::Event_NowIncrease_Process(int now_value, int update_value)
{
	Character* cp = (Character*)owner;

	printf("%s��HP��%d�񕜂���(HP:%d��%d)\n", cp->GetName(), update_value - now_value, now_value, update_value < GetMax() ? GetMax() : update_value);
}


//---------------------------------------------------------------------
//�I�[�o�[���C�h�FHP���ݒl����
//---------------------------------------------------------------------
void Hp::Event_NowDecrease_Process(int now_value,int update_value)
{
	Character* cp = (Character*)owner;

	printf("%s��%d�̃_���[�W���󂯂�(HP:%d��%d)\n", cp->GetName(), now_value - update_value, now_value, update_value <GetMin()?GetMin(): update_value);
}


//---------------------------------------------------------------------
//�I�[�o�[���C�h�F���S����
//---------------------------------------------------------------------
void Hp::Event_NowBelowMin_Process(int now_value,int update_value)
{
	Character* cp = (Character*)owner;

	cp->Dead();
}
