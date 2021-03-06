#include "SnakeMap.h"
#include "Point.h"

SnakeMap::SnakeMap(const int stage) {
    total_map = {
            {
                {4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,3},
                {3,0,0,0,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {4,3,3,3,4,3,3,3,0,0,0,3,3,3,3,3,0,0,0,0,3},
                {3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,3},
                {3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,3},
                {3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4},
            },
            {
                {4,3,3,3,3,3,3,3,3,3,4,3,3,3,3,3,3,3,3,3,4},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4},
            },
            {
                {4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,3,3,3,3,3,4,3,3,3,3,3,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,3,0,0,0,0,0,3,0,0,0,0,0,0,3},
                {4,3,3,3,3,3,3,4,3,3,3,3,3,4,3,3,3,3,3,3,4},
            },
            {
                {4,3,3,3,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4},
                {3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,3,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,3,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,3,0,0,0,3},
                {3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {4,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
                {4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4},
            }

        };
    setCurrentMap(stage);
}

int SnakeMap::getTotalStageCount() {
    return total_stage_count;
}

std::vector<std::vector<int> > SnakeMap::getCurrentMap() {
    return current_map;
}
int SnakeMap::getPositionInfo(const int x, const int y) {
    return current_map[x][y];
}

void SnakeMap::setCurrentMap(const int stage) {
    current_map = total_map[stage];
}

void SnakeMap::setPositionInfo(const int x, const int y, const int info) {
    current_map[x][y] = info;
}