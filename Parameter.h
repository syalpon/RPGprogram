#ifndef PARAMETER_H
#define PARAMETER_H

class Parameter
{
private:
    //フィールド
    int max;
    int now;
    int min;

protected:
    //自クラスを持つオブジェクトのポインタ
    void* owner;

    //--- イベントハンドラ
    //第一引数は更新前の値、第二引数は更新しようとしている値を受け取る
    //前処理：下限値、現在値、上限値の更新イベントハンドラ
    virtual void Event_Process_MaxIncrease (int, int);
    virtual void Event_Process_MaxDecrease (int, int);
    virtual void Event_Process_MaxBelowNow (int, int);
    virtual void Event_Process_MaxBelowMin (int, int);
    virtual void Event_Process_NowExceedMax(int, int);
    virtual void Event_Process_NowIncrease (int, int);
    virtual void Event_Process_NowDecrease (int, int);
    virtual void Event_Process_NowBelowMin (int, int);
    virtual void Event_Process_MinExceedMax(int, int);
    virtual void Event_Process_MinExceedNow(int, int);
    virtual void Event_Process_MinIncrease (int, int);
    virtual void Event_Process_MinDecrease (int, int);
    //後処理：下限値、現在値、上限値の更新イベントハンドラ
    virtual void Event_MaxIncrease_Process (int, int);
    virtual void Event_MaxDecrease_Process (int, int);
    virtual void Event_MaxBelowNow_Process (int, int);
    virtual void Event_MaxBelowMin_Process (int, int);
    virtual void Event_NowExceedMax_Process(int, int);
    virtual void Event_NowIncrease_Process (int, int);
    virtual void Event_NowDecrease_Process (int, int);
    virtual void Event_NowBelowMin_Process (int, int);
    virtual void Event_MinExceedMax_Process(int, int);
    virtual void Event_MinExceedNow_Process(int, int);
    virtual void Event_MinIncrease_Process (int, int);
    virtual void Event_MinDecrease_Process (int, int);

public :
    //コンストラクタ
    Parameter();
    Parameter(void *,int ,int ,int );

    //ゲッター
    virtual int GetMax();
    virtual int GetNow();
    virtual int GetMin();
    //セッター
    virtual void SetMax(int);
    virtual void SetNow(int);
    virtual void SetMin(int);

    //表示関数
    virtual void Show();
    virtual void Show(const char *);
};

#endif