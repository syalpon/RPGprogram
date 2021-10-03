#include "Exp.h"
#include "Character.h"

//---------------------------------------------------------------------
//コンストラクタ
//---------------------------------------------------------------------
Lv::Lv():Parameter(this, 0, 100, 100){}
Lv::Lv(void* p, int _min, int _now, int _max):Parameter(p, _min, _now, _max){}
