#include "mapping.h"

using namespace sdds;

int main(int argc, char *argv[])
{
    Map map;
    map.populateMap();
    map.printMap();

    Route res;
    res = res.getShortestPath(map, Point(17, 17), Point(6, 24));

    for (int i = 0; i < res.getNumPoints(); i++) {
        std::cout << "(" << res.getPoint(i).getRow() << ";" << res.getPoint(i).getCol() << ")\n";
    }
    return 0;
}
