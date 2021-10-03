#include "Exp.h"
#include "Character.h"
#include <stdio.h>
//---------------------------------------------------------------------
//�R���X�g���N�^
//---------------------------------------------------------------------
Exp::Exp():Parameter(this, 0, 100, 100){}
Exp::Exp(void* p, int _min, int _now, int _max):Parameter(p, _min, _now, _max){}


//---------------------------------------------------------------------
//�X�V�l������l�𒴂��悤�Ƃ��Ă���ꍇ
//---------------------------------------------------------------------
void Exp::Event_Process_NowExceedMax(int now_value,int update_value)
{
	Character* cp = (Character*)owner;
	int next_exp = update_value - GetMax();
	printf("�ύX�O:%d,%d\n", GetNow(), update_value);
	cp->LevelUp();

	printf("�ύX��:%d,%d\n", GetNow(), now_value);
	SetNow(next_exp); //�ő�l�𒴂����ꍇ�͍ő�l�����Z

	printf("LV:%d,%d\n", GetNow(), update_value);
}
