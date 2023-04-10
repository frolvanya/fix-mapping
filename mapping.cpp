#include "mapping.h"

using namespace std;

namespace sdds {
    Point::Point() : row(0), col(0) {}
    Point::Point(int tmp_row, int tmp_col) : row(tmp_row), col(tmp_col) {}

    int Point::getRow() const { return row; }
    int Point::getCol() const { return col; }

    bool Point::isValid() const { return row >= 0 && col >= 0 && row < MAP_ROWS && col < MAP_COLS; }

    Map::Map() { populateMap(); }

    void Map::populateMap()
    {
        int tmp_map[40][40] = {
            //0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
            //A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
            {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //0
            {0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},  //1
            {0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},  //2
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //3
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //4
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //5
            {1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},  //6
            {1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},  //7
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},  //8
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //9
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //10
            {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},  //11
            {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},  //12
            {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},  //13
            {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},  //14
            {1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},  //15
            {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //16
            {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //17
            {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},  //18
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //19
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  //20
            {0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},  //21
            {0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},  //22
            {0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},  //23
            {0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}   //24
        };

        for (int i = 0; i < MAP_ROWS; i++) {
            for (int j = 0; j < MAP_COLS; j++) {
                squares[i][j] = tmp_map[i][j];
            }
        }
    }

    void Map::printMap() const
    {
        for (int i = 0; i < MAP_ROWS; i++) {
            for (int j = 0; j < MAP_COLS; j++) {
                if (squares[i][j] == 0) {
                    cout << "\033[32m" << squares[i][j] << "\033[0m"
                         << " ";
                } else {
                    cout << "\033[31m" << squares[i][j] << "\033[0m"
                         << " ";
                }
            }
            cout << endl;
        }
    }

    bool Map::isRoad(const Point& tmp_point) const
    {
        return squares[tmp_point.getRow()][tmp_point.getCol()] == 0;
    }

    Route::Route() {}

    int Route::getNumPoints() const { return num_points; }

    Route& Route::addPoint(const Point& tmp_point)
    {
        if (num_points < 99) {
            points[num_points++] = tmp_point;
        }

        return *this;
    }

    Point Route::getPoint(int i) const { return points[i]; }

    double Route::heuristics(Point start, Point end) const
    {
        return sqrt(pow((start.getCol() - end.getCol()), 2) +
                    pow((start.getRow() - end.getRow()), 2));
    }
    bool Route::isDestination(Point start, Point end) const
    {
        return start.getRow() == end.getRow() && start.getCol() == end.getCol();
    }

    void Route::reverse()
    {
        int i = 0;
        int j = num_points - 1;
        while (i < j) {
            std::swap(points[i], points[j]);
            i++;
            j--;
        }
    }

    Route Route::tracePath(cell cells[][MAP_COLS], Point start, Point end)
    {
        Route result;

        int row = end.getRow();
        int col = end.getCol();

        while (!(cells[row][col].parent_i == row && cells[row][col].parent_j == col)) {
            result.addPoint(Point(row, col));

            int tmp_row = cells[row][col].parent_i;
            int tmp_col = cells[row][col].parent_j;

            row = tmp_row;
            col = tmp_col;
        }

        result.addPoint(start);
        result.reverse();

        return result;
    }

    Route Route::getShortestPath(Map& map, Point start, Point end)
    {
        if (!start.isValid() || !end.isValid()) {
            return Route();
        }

        if (!map.isRoad(start) || !map.isRoad(end)) {
            return Route();
        }

        if (start.getRow() == end.getRow() && start.getCol() == end.getCol()) {
            return Route();
        }

        bool closedList[MAP_ROWS][MAP_COLS];
        memset(closedList, false, sizeof(closedList));

        cell cells[MAP_ROWS][MAP_COLS];
        int i, j;
        for (i = 0; i < MAP_ROWS; i++) {
            for (j = 0; j < MAP_COLS; j++) {
                cells[i][j].f = FLT_MAX;
                cells[i][j].g = FLT_MAX;
                cells[i][j].h = FLT_MAX;
                cells[i][j].parent_i = -1;
                cells[i][j].parent_j = -1;
            }
        }

        i = start.getRow();
        j = start.getCol();
        cells[i][j].f = 0.0;
        cells[i][j].g = 0.0;
        cells[i][j].h = 0.0;
        cells[i][j].parent_i = i;
        cells[i][j].parent_j = j;

        std::vector<std::pair<double, std::pair<int, int>>> openList;
        openList.emplace_back(0.0, std::make_pair(i, j));

        bool destinationFound = false;

        while (!openList.empty()) {
            std::pair<double, std::pair<int, int>> p = openList[0];
            openList.erase(openList.begin());

            i = p.second.first;
            j = p.second.second;
            closedList[i][j] = true;

            double gNew, hNew, fNew;

            for (int row = -1; row <= 1; row++) {
                for (int col = -1; col <= 1; col++) {
                    if ((row == 0 && col == 0) || (row != 0 && col != 0)) {
                        continue;
                    }
                    int iNew = i + row;
                    int jNew = j + col;
                    if (iNew >= 0 && iNew < MAP_ROWS && jNew >= 0 && jNew < MAP_COLS &&
                        map.isRoad(Point(iNew, jNew))) {
                        if (isDestination(Point(iNew, jNew), end)) {
                            cells[iNew][jNew].parent_i = i;
                            cells[iNew][jNew].parent_j = j;
                            destinationFound = true;

                            return tracePath(cells, start, end);
                        } else if (!closedList[iNew][jNew]) {
                            gNew = cells[i][j].g + 1.0;
                            hNew = heuristics(Point(iNew, jNew), end);
                            fNew = gNew + hNew;
                            if (cells[iNew][jNew].f == FLT_MAX || cells[iNew][jNew].f > fNew) {
                                openList.emplace_back(fNew, std::make_pair(iNew, jNew));
                                cells[iNew][jNew].f = fNew;
                                cells[iNew][jNew].g = gNew;
                                cells[iNew][jNew].h = hNew;
                                cells[iNew][jNew].parent_i = i;
                                cells[iNew][jNew].parent_j = j;
                            }
                        }
                    }
                }
            }
        }

        return Route();
    }
}  // namespace sdds
