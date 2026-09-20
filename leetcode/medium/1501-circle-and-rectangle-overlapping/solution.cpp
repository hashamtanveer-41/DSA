class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
         int XMin = min(x1, x2);
    int XMax = max(x1, x2);
    int YMin = min(y1, y2);
    int YMax = max(y1, y2);
    int PX = max(XMin, min(xCenter, XMax));
    int PY = max(YMin, min(yCenter, YMax));
    int finalRadius = sqrt(((xCenter-PX)*(xCenter-PX)) + ((yCenter - PY)*(yCenter - PY)));
    if (finalRadius<=radius)
        return true;
    return false;
    }
};