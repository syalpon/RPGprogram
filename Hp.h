#ifndef HP_H
#define HP_H

#include "Parameter.h"

class Hp : public Parameter
{
protected:
	//オーバーライド
	void Event_MaxIncrease_Process(int, int); //上限値が増えた時
	void Event_NowIncrease_Process(int, int); //現在値が増えた時
	void Event_NowDecrease_Process(int, int);  //ダメージを受けた時
	void Event_NowBelowMin_Process(int ,int);	//死亡時
	
public:
	//コンストラクタ
	Hp();
	Hp(void *,int,int,int);
};


#endif