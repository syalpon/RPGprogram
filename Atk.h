#ifndef ATK_H
#define ATK_H

#include "Parameter.h"

class Atk : public Parameter<Atk>
{
protected:

public:
	//コンストラクタ
	Atk();
	Atk(void*, int, int, int);
};

#endif