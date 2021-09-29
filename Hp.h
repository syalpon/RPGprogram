#ifndef HP_H
#define HP_H

#include "Parameter.h"

class Hp : public Parameter<Hp>
{
protected:
	//オーバーライド
	void Event_MaxIncrement(int, int); //上限値が増えた時
	void Event_NowIncrement(int, int); //現在値が増えた時
	void Event_NowDecrement(int, int);  //ダメージを受けた時
	void Event_NowBelowMin(int ,int);	//死亡時
	
public:
	//コンストラクタ
	Hp();
	Hp(void *,int,int,int);
};


#endif