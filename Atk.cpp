#include "Exp.h"
#include "Character.h"

//---------------------------------------------------------------------
//コンストラクタ
//---------------------------------------------------------------------
Atk::Atk():Parameter(this, 0, 100, 100) {}
Atk::Atk(void* p, int _min, int _now, int _max):Parameter(p, _min, _now, _max) {}
