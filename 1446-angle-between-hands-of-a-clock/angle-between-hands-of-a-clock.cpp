class Solution {
public:
    double angleClock(int h, int m) {
        int mAngle = 6 * m;

        double hAngle = 30*h + 0.5*m;
        double angle = abs(hAngle - mAngle);
        double ans = 0;
        ans = min(angle,360- angle);
        return ans;


    }
};