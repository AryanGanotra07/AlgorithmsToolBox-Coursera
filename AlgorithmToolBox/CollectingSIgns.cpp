#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;


struct Segment {
    int start, end;
};

bool compareSegment(Segment i1, Segment i2) 
{ 
    return (i1.end < i2.end); 
} 

vector<int> optimal_points(vector<Segment> &segments) {

    // sort the vector according to the end points
    std::sort(segments.begin(), segments.end(), compareSegment);

    vector<int> points; // create a vector to store the common points in the segments
    int point = segments[0].end; // set the point to the first end point i-e shortest end point
    points.push_back(point);

    for (size_t i = 1; i < segments.size(); ++i) {
        if (point < segments[i].start || point > segments[i].end) { // if the point is not in the segment
            point = segments[i].end; // update the point to the end point of the current segment
            points.push_back(point); // store it in the vector
        }
    }

    return points;
}

int main() {
    unsigned int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}