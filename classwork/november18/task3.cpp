#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>

struct Point {
    int x, y;
};

struct Segment {
    Point p1, p2;
    double length;

    Segment(Point a, Point b) : p1(a), p2(b) {
        length = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    }
};


std::vector<Point> parsePoints(const std::string& input) {
    std::vector<Point> points;
    std::istringstream stream(input);
    char ignore;
    int x, y;

    while (stream >> ignore >> x >> ignore >> y >> ignore) {
        points.push_back({x, y});
    }

    return points;
}

int main() {

    std::ifstream inputFile("/Users/lina/CLionProjects/proghome2/prog2coursecpp/classwork/november18/input2.txt");
    std::ofstream outputFile("/Users/lina/CLionProjects/proghome2/prog2coursecpp/classwork/november18/output2.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл!" << std::endl;
        return 1;
    }


    std::string inputData((std::istreambuf_iterator<char>(inputFile)),
                          std::istreambuf_iterator<char>());
    inputFile.close();


    std::vector<Point> points = parsePoints(inputData);


    std::vector<Segment> segments;
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            segments.emplace_back(points[i], points[j]);
        }
    }


    std::sort(segments.begin(), segments.end(), [](const Segment& a, const Segment& b) {
        return a.length < b.length;
    });


    for (const auto& segment : segments) {
        outputFile << "(" << segment.p1.x << ", " << segment.p1.y << ") -> ("
                   << segment.p2.x << ", " << segment.p2.y << ") : "
                   << segment.length << std::endl;
    }

    outputFile.close();

    std::cout << "Результати збережено у файлі output2.txt" << std::endl;
    return 0;
}
