#ifndef EXP_H
#define EXP_H

#include "Parameter.h"

class Exp : public Parameter
{
protected:
	//現在値が上限値を上回った時
	void Event_Process_NowExceedMax(int, int);
	void Event_NowExceedMax_Process(int ,int );

public:
	//コンストラクタ
	Exp();
	Exp(void*, int, int, int);
};


#endif