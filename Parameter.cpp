#include "Parameter.h"
#include <cstdio>
//---------------------------------------------------------------------
//コンストラクタ
//---------------------------------------------------------------------
Parameter::Parameter()
    :Parameter(nullptr,0,100,100)
{
    /* 引数付きコンストラクタに委譲 */
}

Parameter::Parameter(void* p, int _min, int _now, int _max)
{
    owner = p;
    min = _min;
    now = _now;
    max = _max;
}

//---------------------------------------------------------------------
//イベント
//---------------------------------------------------------------------
//前処理：下限値、現在値、上限値の更新イベントハンドラ
void Parameter::Event_Process_MaxIncrease (int now_value, int update_value) {}
void Parameter::Event_Process_MaxDecrease (int now_value, int update_value) {}
void Parameter::Event_Process_MaxBelowNow (int now_value, int update_value) {}
void Parameter::Event_Process_MaxBelowMin (int now_value, int update_value) {}
void Parameter::Event_Process_NowExceedMax(int now_value, int update_value) {}
void Parameter::Event_Process_NowIncrease (int now_value, int update_value) {}
void Parameter::Event_Process_NowDecrease (int now_value, int update_value) {}
void Parameter::Event_Process_NowBelowMin (int now_value, int update_value) {}
void Parameter::Event_Process_MinExceedMax(int now_value, int update_value) {}
void Parameter::Event_Process_MinExceedNow(int now_value, int update_value) {}
void Parameter::Event_Process_MinIncrease (int now_value, int update_value) {}
void Parameter::Event_Process_MinDecrease (int now_value, int update_value) {}
//後処理：下限値、現在値、上限値の更新イベントハンドラ
void Parameter::Event_MaxIncrease_Process (int now_value, int update_value) {}
void Parameter::Event_MaxDecrease_Process (int now_value, int update_value) {}
void Parameter::Event_MaxBelowNow_Process (int now_value, int update_value) { SetNow(update_value); }
void Parameter::Event_MaxBelowMin_Process (int now_value, int update_value) { SetNow(GetMin()); max = GetMin(); }
void Parameter::Event_NowExceedMax_Process(int now_value, int update_value) { now = GetMax(); }
void Parameter::Event_NowIncrease_Process (int now_value, int update_value) {}
void Parameter::Event_NowDecrease_Process (int now_value, int update_value) {}
void Parameter::Event_NowBelowMin_Process (int now_value, int update_value) { now = GetMin(); }
void Parameter::Event_MinExceedMax_Process(int now_value, int update_value) { SetNow(GetMax()); min = GetMax(); }
void Parameter::Event_MinExceedNow_Process(int now_value, int update_value) { SetNow(update_value); }
void Parameter::Event_MinIncrease_Process (int now_value, int update_value) {}
void Parameter::Event_MinDecrease_Process (int now_value, int update_value) {}



//---------------------------------------------------------------------
//ゲッター
//---------------------------------------------------------------------
int Parameter::GetMax()
{
    return max;
}

int Parameter::GetNow()
{
    return now;
}

int Parameter::GetMin()
{
    return min;
}


//---------------------------------------------------------------------
//セッター
//---------------------------------------------------------------------
void Parameter::SetMax(int x)
{  
    //更新前の上限値を保存
    int old = max;

    //更新値が元の値と同じ時
    if (old == x)
    {
        // do nothing
    }
    //更新値が元より高い値のとき
    else if (old < x)
    {
        Event_Process_MaxIncrease(old, x);
        max = x;
        Event_MaxIncrease_Process(old, x);
    }
    //更新値が元より低い値のとき　かつ　現在値を下回らないとき
    else if (GetNow() < x)
    {
        Event_Process_MaxDecrease(old, x);
        max = x;
        Event_MaxDecrease_Process(old, x);
    }
    //更新値がが現在値を下回り、下限値を下回らないとき
    else if (GetMin() < x)
    {
        Event_Process_MaxBelowNow(old, x);
        max = x;
        Event_MaxBelowNow_Process(old, x);
    }
    //更新値が下限値を下回るとき
    else
    {
        Event_Process_MaxBelowMin(old, x);
        max = x;
        Event_MaxBelowMin_Process(old, x);
    }
}

void Parameter::SetNow(int x)
{
    //更新前の上限値を保存
    int old = now;

    //更新値が元の値と同じ時
    if (old == x)
    {
        // do nothing
    }
    //更新値が最大値を上回るとき
    else if (GetMax() < x)
    {
        Event_Process_NowExceedMax(old, x);
        now = x;
        Event_NowExceedMax_Process(old, x);
    }
    //更新値が増え　かつ　最大値を上回らないとき
    else if (old < x)
    {
        Event_Process_NowIncrease(old, x);
        now = x;
        Event_NowIncrease_Process(old, x);
    }
    //更新値が減り　かつ　下限値を下回わらないとき
    else if (GetMin() < x)
    {
        Event_Process_NowDecrease(old, x);
        now = x;
        Event_NowDecrease_Process(old, x);

    }
    //更新値が下限値を下回るとき
    else
    {
        Event_Process_NowBelowMin(old, x);
        now = x;
        Event_NowBelowMin_Process(old, x);
    }
}

void Parameter::SetMin(int x)
{
    //更新前の上限値を保存
    int old = min;

    //更新値が元の値と同じ時
    if (old == x)
    {
        // do nothing
    }
    //更新値が上限値を上回るとき
    else if (GetMax() < x)
    {
        Event_Process_MinExceedMax(old, x);
        min = x;
        Event_MinExceedMax_Process(old, x);
    }
    //更新値が上限値を上回らず　かつ　現在値を上回るとき
    else if (GetNow() < x)
    {
        Event_Process_MinExceedNow(old, x);
        min = x;
        Event_MinExceedNow_Process(old, x);
    }
    //更新値が現在値を上回らず　かつ　増える時
    else if (old < x)
    {
        Event_Process_MinIncrease(old, x);
        min = x;
        Event_MinIncrease_Process(old, x);
    }
    //更新値が下限値を下回るとき
    else
    {
        Event_Process_MinDecrease(old, x);
        min = x;
        Event_MinDecrease_Process(old, x);
    }
}


//---------------------------------------------------------------------
//表示
//---------------------------------------------------------------------
void Parameter::Show()
{
    Show("");
}

void Parameter::Show(const char *msg)
{
    printf("%3s:(%3d,%3d,%3d)\n", msg, min, now, max);
}


