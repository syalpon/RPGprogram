#include "Parameter.h"
#include <cstdio>
//---------------------------------------------------------------------
//コンストラクタ
//---------------------------------------------------------------------
template <class T>
Parameter<T>::Parameter()
    :Parameter(nullptr,0,100,100)
{
    /* 引数付きコンストラクタに委譲 */
}

template <class T>
Parameter<T>::Parameter(void* p, int _min, int _now, int _max)
{
    owner = p;
    min = _min;
    now = _now;
    max = _max;
}

//---------------------------------------------------------------------
//イベント
//---------------------------------------------------------------------
template <class T>
void Parameter<T>::Event_MaxIncrement(int ,int ) {} //上限値が増えた時
template <class T>
void Parameter<T>::Event_MaxDecrement(int, int ) {} //上限値が減った時
template <class T>
void Parameter<T>::Event_NowIncrement(int, int ) {} //現在値が増えた時
template <class T>
void Parameter<T>::Event_NowDecrement(int, int ) {} //現在値が減った時
template <class T>
void Parameter<T>::Event_MinIncrement(int, int ) {} //下限値が増えた時
template <class T>
void Parameter<T>::Event_MinDecrement(int, int ) {} //下限値が減った時
template <class T>
void Parameter<T>::Event_NowExceedMax(int, int ) {} //現在値が上限値を上回った時
template <class T>
void Parameter<T>::Event_NowBelowMin(int, int ) {}  //現在値が下限値を下回った時


//---------------------------------------------------------------------
//ゲッター
//---------------------------------------------------------------------
template <class T>
int Parameter<T>::Max()
{
    return max;
}

template <class T>
int Parameter<T>::Now()
{
    return now;
}

template <class T>
int Parameter<T>::Min()
{
    return min;
}



//---------------------------------------------------------------------
//セッター
//---------------------------------------------------------------------
template <class T>
void Parameter<T>::Max(int x)
{  
    int old = max;
    max = x;
    //更新値が元より高い値のとき
    if(old < x )
    {
        Event_MaxIncrement(max,x);
    }
    //更新値が元より低い値のとき
    else if( x < old)
    {
        Event_MaxDecrement(max,x);
    }
}

template <class T>
void Parameter<T>::Now(int x)
{
    //更新値が元より高い値のとき
    if( now < x )
    {
        Event_NowIncrement(now,x);
    }
    //更新値が元より低い値のとき
    else if( x < now )
    {
        Event_NowDecrement(now, x);
    }

    //更新値が上限値を超えようとしている場合
    if( max < x )
    {
        Event_NowExceedMax(now, x);
        x = max;
    }
    //更新値が下限値を下回わろうとしている場合
    else if( x < min )
    {
        Event_NowBelowMin(now,x);
        x = min;
    }
    now = x;    
}

template <class T>
void Parameter<T>::Min(int x)
{
    int old = min;
    min = x;
    //更新値が元より高い値のとき
    if(old < x )
    {
        Event_MinIncrement(old,x);
    }
    //更新値が元より低い値のとき
    else if( x < old)
    {
        Event_MinDecrement(old,x);
    }
}


//---------------------------------------------------------------------
//表示
//---------------------------------------------------------------------
template <class T>
void Parameter<T>::Show()
{
    Show("");
}

template <class T>
void Parameter<T>::Show(const char *msg)
{
    printf("%3s:(%3d,%3d,%3d)\n", msg, min, now, max);
}




//-- リンクエラー対策 : explicit instantiation ------------------------
// ダサいけどヘッダを分けてテンプレートクラスを使用した場合、翻訳単位の都合上
// 特殊化された関数のプロトタイプ宣言がないのでリンクエラー(undefined referece...)となる
// よって以下に使用する各クラスごとのメソッドのプロトタイプ宣言を用意
#include "Hp.h"
#include "Mp.h"
#include "Exp.h"
#include "Lv.h"
#include "Atk.h"

template Parameter<Hp> ::Parameter();
template Parameter<Mp> ::Parameter();
template Parameter<Exp>::Parameter();
template Parameter<Lv> ::Parameter();
template Parameter<Atk>::Parameter();

template Parameter<Hp> ::Parameter(void *,int ,int ,int );
template Parameter<Mp> ::Parameter(void *,int ,int ,int );
template Parameter<Exp>::Parameter(void *,int ,int ,int );
template Parameter<Lv> ::Parameter(void *,int ,int ,int );
template Parameter<Atk>::Parameter(void *,int ,int ,int );

template void Parameter<Hp> ::Event_MaxIncrement(int ,int );
template void Parameter<Mp> ::Event_MaxIncrement(int ,int );
template void Parameter<Exp>::Event_MaxIncrement(int ,int );
template void Parameter<Lv> ::Event_MaxIncrement(int ,int );
template void Parameter<Atk>::Event_MaxIncrement(int ,int );

template void Parameter<Hp> ::Event_MaxDecrement(int, int);
template void Parameter<Mp> ::Event_MaxDecrement(int, int);
template void Parameter<Exp>::Event_MaxDecrement(int, int);
template void Parameter<Lv> ::Event_MaxDecrement(int, int);
template void Parameter<Atk>::Event_MaxDecrement(int, int);

template void Parameter<Hp> ::Event_NowIncrement(int, int);
template void Parameter<Mp> ::Event_NowIncrement(int, int);
template void Parameter<Exp>::Event_NowIncrement(int, int);
template void Parameter<Lv> ::Event_NowIncrement(int, int);
template void Parameter<Atk>::Event_NowIncrement(int, int);

template void Parameter<Hp> ::Event_NowDecrement(int, int);
template void Parameter<Mp> ::Event_NowDecrement(int, int);
template void Parameter<Exp>::Event_NowDecrement(int, int);
template void Parameter<Lv> ::Event_NowDecrement(int, int);
template void Parameter<Atk>::Event_NowDecrement(int, int);

template void Parameter<Hp> ::Event_MinIncrement(int, int);
template void Parameter<Mp> ::Event_MinIncrement(int, int);
template void Parameter<Exp>::Event_MinIncrement(int, int);
template void Parameter<Lv> ::Event_MinIncrement(int, int);
template void Parameter<Atk>::Event_MinIncrement(int, int);

template void Parameter<Hp> ::Event_MinDecrement(int, int);
template void Parameter<Mp> ::Event_MinDecrement(int, int);
template void Parameter<Exp>::Event_MinDecrement(int, int);
template void Parameter<Lv> ::Event_MinDecrement(int, int);
template void Parameter<Atk>::Event_MinDecrement(int, int);

template void Parameter<Hp> ::Event_NowExceedMax(int, int);
template void Parameter<Mp> ::Event_NowExceedMax(int, int);
template void Parameter<Exp>::Event_NowExceedMax(int, int);
template void Parameter<Lv> ::Event_NowExceedMax(int, int);
template void Parameter<Atk>::Event_NowExceedMax(int, int);

template void Parameter<Hp> ::Event_NowBelowMin(int, int);
template void Parameter<Mp> ::Event_NowBelowMin(int, int);
template void Parameter<Exp>::Event_NowBelowMin(int, int);
template void Parameter<Lv> ::Event_NowBelowMin(int, int);
template void Parameter<Atk>::Event_NowBelowMin(int, int);

template int Parameter<Hp> ::Max();
template int Parameter<Mp> ::Max();
template int Parameter<Exp>::Max();
template int Parameter<Lv> ::Max();
template int Parameter<Atk>::Max();

template int Parameter<Hp> ::Now();
template int Parameter<Mp> ::Now();
template int Parameter<Exp>::Now();
template int Parameter<Lv> ::Now();
template int Parameter<Atk>::Now();

template int Parameter<Hp> ::Min();
template int Parameter<Mp> ::Min();
template int Parameter<Exp>::Min();
template int Parameter<Lv> ::Min();
template int Parameter<Atk>::Min();

template void Parameter<Hp> ::Max(int);
template void Parameter<Mp> ::Max(int);
template void Parameter<Exp>::Max(int);
template void Parameter<Lv> ::Max(int);
template void Parameter<Atk>::Max(int);

template void Parameter<Hp> ::Now(int);
template void Parameter<Mp> ::Now(int);
template void Parameter<Exp>::Now(int);
template void Parameter<Lv> ::Now(int);
template void Parameter<Atk>::Now(int);

template void Parameter<Hp> ::Min(int);
template void Parameter<Mp> ::Min(int);
template void Parameter<Exp>::Min(int);
template void Parameter<Lv> ::Min(int);
template void Parameter<Atk>::Min(int);

template void Parameter<Hp> ::Show();
template void Parameter<Mp> ::Show();
template void Parameter<Exp>::Show();
template void Parameter<Lv> ::Show();
template void Parameter<Atk>::Show();

template void Parameter<Hp> ::Show(char const*);
template void Parameter<Mp> ::Show(char const*);
template void Parameter<Exp>::Show(char const*);
template void Parameter<Lv> ::Show(char const*);
template void Parameter<Atk>::Show(char const*);