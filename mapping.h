#pragma once
#ifndef MAPPING_H
#define MAPPING_H

#include <iostream>
#include <vector>
#include <cfloat>
#include <cmath>

#define MAP_ROWS 25
#define MAP_COLS 25
#define MAX_ROUTE 100

namespace sdds {
    class Point
    {
        int row;
        int col;

    public:
        Point();
        Point(int tmp_row, int tmp_col);

        int getRow() const;
        int getCol() const;

        bool isValid() const;
    };

    class Map
    {
    public:
        int squares[MAP_ROWS][MAP_COLS];

        Map();

        void populateMap();
        void printMap() const;
        const int getMap() const;

        bool isRoad(const Point& tmp_point) const;
    };

    struct cell
    {
        int parent_i, parent_j;
        double f, g, h;
    };

    class Route
    {
        Point points[MAX_ROUTE];
        int num_points;

    public:
        Route();

        int getNumPoints() const;

        Route& addPoint(const Point& tmp_point);
        Point getPoint(int i) const;

        Route getBlueRoute() const;
        Route getGreenRoute() const;
        Route getYellowRoute() const;

        double heuristics(Point start, Point end) const;
        bool isDestination(Point start, Point end) const;

        void reverse();
        Route tracePath(cell cells[][MAP_COLS], Point start, Point end);
        Route getShortestPath(Map& map, Point start, Point end);
    };
}  // namespace sdds

#endif
