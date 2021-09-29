#ifndef MP_H
#define MP_H

#include "Parameter.h"

class Mp : public Parameter<Mp>
{
protected:
	//オーバーライド
	void Event_MaxIncrement(int, int); //上限値が増えた時
public:
	//コンストラクタ
	Mp();
	Mp(void*, int, int, int);
};



#endif