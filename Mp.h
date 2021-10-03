#ifndef MP_H
#define MP_H

#include "Parameter.h"

class Mp : public Parameter
{
protected:
	//上限値が増えた時
	void Event_MaxIncrease_Process(int, int); 

public:
	//コンストラクタ
	Mp();
	Mp(void*, int, int, int);
};



#endif