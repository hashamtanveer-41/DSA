class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
       double a = sides[0], b = sides[1], c= sides[2];
    vector<double> res;
    if (a+b<=c || b+c<=a || c+a<=b)return res;
    const double PI = 3.14159265358979323846;
    double cosA = acos((b*b + c*c - a*a) / (2*b*c)) * (180.0 / PI);
    double cosB = acos((c*c + a*a - b*b) / (2*a*c)) * (180.0 / PI);
    double cosC = acos((b*b + a*a - c*c) / (2*a*b)) * (180.0 / PI);
    if (cosA == cosB == cosC)return {90.00000, 90.00000, 90.00000};
    res.push_back(cosA);
    res.push_back(cosC);
    res.push_back(cosB);
    sort(res.begin(), res.end());
    return res;
    }
};