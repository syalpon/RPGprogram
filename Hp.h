#ifndef HP_H
#define HP_H

#include "Parameter.h"

class Hp : public Parameter<Hp>
{
protected:
	//オーバーライド
	void Event_NowBelowMin();


public:
	//コンストラクタ
	Hp();
	Hp(void *,int,int,int);
};


#endif