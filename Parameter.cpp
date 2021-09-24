#include "Parameter.h"
#include <cstdio>
#include <typeinfo>

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
void Parameter<T>::Event_MaxIncrement() {} //上限値が増えた時
template <class T>
void Parameter<T>::Event_MaxDecrement() {} //上限値が減った時
template <class T>
void Parameter<T>::Event_NowIncrement() {} //現在値が増えた時
template <class T>
void Parameter<T>::Event_NowDecrement() {} //現在値が減った時
template <class T>
void Parameter<T>::Event_MinIncrement() {} //下限値が増えた時
template <class T>
void Parameter<T>::Event_MinDecrement() {} //下限値が減った時
template <class T>
void Parameter<T>::Event_NowExceedMax() {} //現在値が上限値を上回った時
template <class T>
void Parameter<T>::Event_NowBelowMin() {}  //現在値が下限値を下回った時


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
    //更新値が元より高い値のとき
    if( max < x )
    {
        Event_MaxIncrement();
    }
    //更新値が元より低い値のとき
    else if( x < max )
    {
        Event_MaxDecrement();
    }
    max = x;
}

template <class T>
void Parameter<T>::Now(int x)
{
    //更新値が元より高い値のとき
    if( now < x )
    {
        Event_NowIncrement();
    }
    //更新値が元より低い値のとき
    else if( x < now )
    {
        Event_NowDecrement();
    }

    //更新値が上限値を超えようとしている場合
    if( max < x )
    {
        Event_NowExceedMax();
        x = max;
    }
    //更新値が下限値を下回わろうとしている場合
    else if( x < min )
    {
        Event_NowBelowMin();
        x = min;
    }
    now = x;    
}

template <class T>
void Parameter<T>::Min(int x)
{
    //更新値が元より高い値のとき
    if( min < x )
    {
        Event_MinIncrement();
    }
    //更新値が元より低い値のとき
    else if( x < min )
    {
        Event_MinDecrement();
    }
    min = x;
}

//---------------------------------------------------------------------
//演算子のオーバーロード
//---------------------------------------------------------------------
// 加算
template <class T>
int Parameter<T>::operator+(T obj)
{
    return this->Now() + obj.Now();
}

template <class T>
T& Parameter<T>::operator+=(T obj)
{
    Now(Now() + obj.Now());
    return *this;
}

template <class T>
T& Parameter<T>::operator+=(int i)
{
    Now(Now()+i);
    return *this;
}

template <class T>
T& Parameter<T>::operator++(int i)
{
    Now(Now() + i);
    return *this;
}

// 減算
template <class T>
int Parameter<T>::operator-(T obj)
{
    return this->Now() + obj.Now();
}

template <class T>
T& Parameter<T>::operator-=(T obj)
{
    Now(Now() - obj.Now());
    return *this;
}

template <class T>
T& Parameter<T>::operator-=(int i)
{
    Now(Now() - i);
    return *this;
}

// 代入
template <class T>
T& Parameter<T>::operator=(int i)
{
    this->Now(i);
    return *this;
}

//---------------------------------------------------------------------
//表示
//---------------------------------------------------------------------
template <class T>
void Parameter<T>::Show()
{
    printf("%s", Typeid(*this).name);
    Show("");
}

template <class T>
void Parameter<T>::Show(const char *msg)
{
    printf("%3s:(%3d,%3d,%3d)\n", msg, min, now, max);
}