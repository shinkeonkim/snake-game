#include "Mission.h"
#include "GameSettings.h"

Mission::Mission(const int stage){
    total_mission_list = {
        {9,3,5,2},
        {7,5,9,3},
        {10,4,7,4},
        {5,1,2,1}
    };
    current_mission_list = total_mission_list[stage];

    window = newwin((MAP_Y + 1) / 2, MAP_X / 2, 11, 22);
}

bool Mission::isComplete(UserData &user_data){
    current_state = {user_data.getMaxLength(), user_data.getPoisonItemCount(), user_data.getGrowthItemCount(), user_data.getUsedGateCount()};
    for(int i = 0; i<4; i++){
        if(current_mission_list[i]>current_state[i]){
            return false;
        }
    }
    return true;
}

void Mission::Render()
{
    mvwprintw(window, 1, 1, "mission");
    wrefresh(window);
}