#ifndef LV_H
#define LV_H

#include "Parameter.h"

class Lv : public Parameter<Lv>
{
protected:

public:
	//コンストラクタ
	Lv();
	Lv(void*, int, int, int);
};

#endif