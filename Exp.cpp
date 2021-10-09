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
//前処理
void Exp::Event_Process_NowExceedMax(int now_value, int update_value)
{
	
}
//後処理
void Exp::Event_NowExceedMax_Process(int now_value,int update_value)
{
	int next_exp;
	next_exp = update_value - GetMax();
	((Character*)owner)->LevelUp();
	//printf("変更前:%d,%d,%d\n", now_value, update_value, next_exp);
	SetNow(next_exp); //最大値を超えた場合は最大値を減算
	//printf("変更後:%d,%d\n", now_value, next_exp);
	
}
