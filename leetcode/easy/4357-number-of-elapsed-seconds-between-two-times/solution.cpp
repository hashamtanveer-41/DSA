class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
    string endSeconds1 = {endTime[6], endTime[7]};
    string startSeconds1 = {startTime[6], startTime[7]};
    int seconds=stoi(endSeconds1) - stoi(startSeconds1);
    string endMin1 = {endTime[3], endTime[4]};
    string startMin1 = {startTime[3], startTime[4]};
    int min=stoi(endMin1) - stoi(startMin1);
    string endH1 = {endTime[0], endTime[1]};
    string startH1 = {startTime[0], startTime[1]};
    int hours=stoi(endH1) - stoi(startH1);
    return hours*3600 + min*60 + seconds;
    }
};