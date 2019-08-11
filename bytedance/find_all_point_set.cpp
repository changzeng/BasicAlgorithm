#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point{
    explicit Point(int _x, int _y){
        x=_x, y=_y;
    };
    int x, y;
};

class Compare{
public:
    bool operator ()(const Point &p1, const Point &p2){
        return p1.x>p2.x;
    }
};

vector<Point> find_point_set(vector<Point> &all_points){
    vector<Point> result;

    sort(all_points.begin(), all_points.end(), Compare());
    vector<int> dp = vector<int>(all_points.size(), 0);
    dp[0] = all_points[0].y;

    result.push_back(all_points[0]);
    for(int i=1; i<(int)all_points.size(); i++){
        if(all_points[i].y > dp[i-1]) {
            result.push_back(all_points[i]);
            dp[i] = all_points[i].y;
        }else{
            dp[i] = dp[i-1];
        }
    }

    return result;
}

int main(){
    vector<Point> point_list = vector<Point>({Point(1, 1), Point(2, 2), Point(3, 4)});
    for(auto point:find_point_set(point_list)){
        cout<<point.x<<" "<<point.y<<endl;
    }
}
