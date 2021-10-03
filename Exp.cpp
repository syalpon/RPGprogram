#include "Exp.h"
#include "Character.h"
#include <stdio.h>
//---------------------------------------------------------------------
//コンストラクタ
//---------------------------------------------------------------------
Exp::Exp():Parameter(this, 0, 100, 100){}
Exp::Exp(void* p, int _min, int _now, int _max):Parameter(p, _min, _now, _max){}


//---------------------------------------------------------------------
//更新値が上限値を超えようとしている場合
//---------------------------------------------------------------------
void Exp::Event_Process_NowExceedMax(int now_value,int update_value)
{
	Character* cp = (Character*)owner;
	int next_exp = update_value - GetMax();
	printf("変更前:%d,%d\n", GetNow(), update_value);
	cp->LevelUp();

	printf("変更後:%d,%d\n", GetNow(), now_value);
	SetNow(next_exp); //最大値を超えた場合は最大値を減算

	printf("LV:%d,%d\n", GetNow(), update_value);
}
