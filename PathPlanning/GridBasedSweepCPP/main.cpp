#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#include <SFML/Graphics.hpp>

using namespace std;

struct Point
{
    int x, y;
    Point(int x, int y)
        : x(x)
        , y(y)
    {
    }
    bool operator==(const Point& other) const
    {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Point& other) const
    {
        return x != other.x && y != other.y;
    }
};

bool isPointInPolygon(const Point& p, const vector<Point>& polygon)
{
    int n       = polygon.size();
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].y > p.y) != (polygon[j].y > p.y))
            && (p.x < (polygon[j].x - polygon[i].x) * (p.y - polygon[i].y)
                        / (polygon[j].y - polygon[i].y)
                    + polygon[i].x))
        {
            inside = !inside;
        }
    }
    return inside;
}

vector<Point> planCoveragePath(const vector<Point>& polygon)
{
    vector<Point> path;
    queue<Point> q;
    vector<vector<bool>> visited(1001, vector<bool>(1001, false));

    q.push(polygon[0]);
    visited[polygon[0].x][polygon[0].y] = true;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();
        path.push_back(curr);

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0)
                    continue;
                Point neighbor(curr.x + dx, curr.y + dy);
                if (isPointInPolygon(neighbor, polygon)
                    && !visited[neighbor.x][neighbor.y]) {
                    visited[neighbor.x][neighbor.y] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    return path;
}

vector<Point> simplifyPath(const vector<Point>& path)
{
    vector<Point> simplifiedPath;
    if (path.empty()) {
        return simplifiedPath;
    }

    simplifiedPath.push_back(path[0]);
    Point prevDirection(0, 0);

    for (size_t i = 1; i < path.size(); i++) {
        Point currDirection(path[i].x - path[i - 1].x,
                            path[i].y - path[i - 1].y);
        if (currDirection != prevDirection) {
            simplifiedPath.push_back(path[i - 1]);
            prevDirection = currDirection;
        }
    }

    simplifiedPath.push_back(path.back());
    return simplifiedPath;
}

int main()
{
    vector<Point> complexPolygon = {Point(100, 100),
                                    Point(400, 300),
                                    Point(500, 500),
                                    Point(400, 600),
                                    Point(300, 500),
                                    Point(200, 600),
                                    Point(100, 400),
                                    Point(200, 300)};

    vector<Point> path           = planCoveragePath(complexPolygon);
    vector<Point> simplifiedPath = simplifyPath(path);

    sf::RenderWindow window(sf::VideoMode(800, 800), "Coverage Path Planner");
    sf::View view(sf::FloatRect(0, 0, 800, 800));
    window.setView(view);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        sf::ConvexShape polygonShape;
        polygonShape.setOutlineColor(sf::Color::Red);
        polygonShape.setOutlineThickness(2);
        polygonShape.setPointCount(complexPolygon.size());
        for (size_t i = 0; i < complexPolygon.size(); i++) {
            polygonShape.setPoint(
                i, sf::Vector2f(complexPolygon[i].x, complexPolygon[i].y));
        }
        window.draw(polygonShape);

        // Draw the start point
        sf::CircleShape startPoint(5.0);
        startPoint.setFillColor(sf::Color::Green);
        startPoint.setPosition(simplifiedPath[0].x - 5,
                               simplifiedPath[0].y - 5);
        window.draw(startPoint);

        for (size_t i = 0; i < simplifiedPath.size() - 1; i += 10) {
            sf::Vector2f start(simplifiedPath[i].x, simplifiedPath[i].y);
            sf::Vector2f end(simplifiedPath[i + 1].x, simplifiedPath[i + 1].y);
            sf::Vector2f direction = end - start;
            float angle = atan2(direction.y, direction.x) * 180 / M_PI;

            sf::RectangleShape line(sf::Vector2f(
                sqrt(direction.x * direction.x + direction.y * direction.y),
                4));
            line.setPosition(start.x, start.y);
            line.setRotation(angle);
            line.setFillColor(sf::Color::Green);
            window.draw(line);

            sf::ConvexShape arrowHead;
            arrowHead.setPointCount(3);
            arrowHead.setPoint(0, sf::Vector2f(0, 0));
            arrowHead.setPoint(1, sf::Vector2f(10, 5));
            arrowHead.setPoint(2, sf::Vector2f(10, -5));
            arrowHead.setPosition(end.x, end.y);
            arrowHead.setRotation(angle);
            arrowHead.setFillColor(sf::Color::Green);
            window.draw(arrowHead);
        }

        window.display();
    }

    return 0;
}