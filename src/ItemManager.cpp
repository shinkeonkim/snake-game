#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Item.h"
#include "Point.h"
#include "ItemManager.h"
using namespace std;
class ItemManager{
private:
    
    int current_tick = 0;
    int last_made_tick;
    int delay = 3;
    int rand_x;
    int rand_y;
    int temp;
    int growth_odd = 6;
    int disappear_tick = 20;
    int kind;
    Point create_location;
    vector<Item> items = {};

public:
    ItemManager::ItemManager(){
        ;
    }
    void ItemManager::makeItem(int current_tick, vector<vector<int>> map){
        if(items.size()<3 && current_tick == last_made_tick + delay){
            last_made_tick = current_tick;
            do{
                srand((unsigned int)time(NULL));
                temp = rand();
                rand_x = temp%21;
                temp = rand();
                rand_y = temp%21;
            }
            while(map[create_location.x][create_location.y]==0);
            Point create_location = Point(rand_x,rand_y);
            temp = rand()%10;
            if(temp<=growth_odd){
                kind = 1;
            }else{
                kind = 2;
            }
            Item add_item = Item(create_location, kind, current_tick);
            items.push_back(add_item);
        }
    }
    int ItemManager::eatItem(Point next_head_point){
        for(int i = 0; i<items.size(); i++){
            
            if(items[i].getKinds() == 1){
                items.erase(items.begin()+i);
                return 1;
            }        
            else{
                items.erase(items.begin()+i);
                return 2;
            }       
        }
        return 0;
    }
    void ItemManager::deleteItem(int current_tick){
        for(int i = 0; i<items.size(); i++){
            if(items[i].getCreatedTick() == current_tick - disappear_tick){
                items.erase(items.begin()+i);
                break;
            }
        }
    }
    void ItemManager::update(GameData &game_data, UserData &user_data){
        int current_tick = game_data.getCurrentTick();
        Point next_head_point = game_data.getNextHeadPoint();
        vector<vector<int>> map = game_data.getMap();

        makeItem(current_tick, map);
        deleteItem(current_tick);
        switch(eatItem(next_head_point))
        {
            case 0:
            case 1:
            user_data.GrowthItemIncrease();
            break;
            case 2:
            user_data.PoisonItemIncrease();
            break;
        }
        vector<Point> items_pos = {};
        vector<int> items_type = {};
        for(int i = 0; i<items.size(); i++){
            items_pos.push_back(items[i].getPos());
            items_type.push_back(items[i].getKinds());
        }
        game_data.updateItemPosition(items_pos, items_type);
    }
};