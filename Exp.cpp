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
//�O����
void Exp::Event_Process_NowExceedMax(int now_value, int update_value)
{
	
}
//�㏈��
void Exp::Event_NowExceedMax_Process(int now_value,int update_value)
{
	int next_exp;
	next_exp = update_value - GetMax();
	((Character*)owner)->LevelUp();
	//printf("�ύX�O:%d,%d,%d\n", now_value, update_value, next_exp);
	SetNow(next_exp); //�ő�l�𒴂����ꍇ�͍ő�l�����Z
	//printf("�ύX��:%d,%d\n", now_value, next_exp);
	
}
