#ifndef _USERDATA_
#define _USERDATA_
#include "Renderable.h"

class UserData : public Renderable
{
private:
    int current_length;
    int max_length;
    int growth_item_count;
    int poison_item_count;
    int used_gate_count;
    int current_tick;

public:
    UserData();
    //UserData(int current_length, int max_length, int growth_item_count, int posion_item_count, int used_gate_count) {}
    int getCurrentLength();
    void setCurrentLength(const int current_length);
    int getMaxLength();
    void setMaxLength(const int current_length);
    int getGrowthItemCount();
    void setGrowthItemCount(const int growth_item_count);
    int getPoisonItemCount();
    void setPoisonItemCount(const int poison_item_count);
    void growthItemIncrease();
    void poisonItemIncrease();
    void usedGateCountIncrease();
    int getScore();
    void setUsedGateCount(const int used_gate_count);
    int getUsedGateCount();
    void setCurrentTick(int current_tick);
    void render();
};

#endif