#ifndef EXP_H
#define EXP_H

#include "Parameter.h"

class Exp : public Parameter<Exp>
{
protected:
	//現在値が上限値を上回った時
	void Event_NowExceedMax(int ,int );

public:
	//コンストラクタ
	Exp();
	Exp(void*, int, int, int);
};


#endif