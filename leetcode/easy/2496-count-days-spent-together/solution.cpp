class Solution {
public:
   int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
    vector<int> year = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int alArrMonth =(( arriveAlice[0]-'0') * 10)+(arriveAlice[1]-'0');
    int alArrDay = (( arriveAlice[3]-'0') * 10)+(arriveAlice[4]-'0');
    int alDDay = (( leaveAlice[3]-'0') * 10)+(leaveAlice[4]-'0');
    int alDMonth =(( leaveAlice[0]-'0') * 10)+(leaveAlice[1]-'0');
    int bobArrMonth = (( arriveBob[0]-'0') * 10)+(arriveBob[1]-'0');
    int bobArrDay = (( arriveBob[3]-'0') * 10)+(arriveBob[4]-'0');
    int bobDMonth =(( leaveBob[0]-'0') * 10)+(leaveBob[1]-'0');
    int bobDDay = (( leaveBob[3]-'0') * 10)+(leaveBob[4]-'0');
    int alStart = 0;
    int alEnd = 0;
    int bStart = 0;
    int bEnd = 0;
    for (int i=0; i<alArrMonth-1; i++)
        alStart+=year[i];
    alEnd += alDDay+alStart;
    for (int i=alArrMonth-1; i<alDMonth-1;i++ )
        alEnd +=year[i];
    alStart += alArrDay;
    for (int i=0; i<bobArrMonth-1; i++)
        bStart+=year[i];
    bEnd += bobDDay + bStart;
    for (int i=bobArrMonth-1; i<bobDMonth-1;i++ )
        bEnd +=year[i];
    bStart += bobArrDay;
    if (bEnd<alStart || bStart>alEnd)
        return 0;
    return 1+min(alEnd, bEnd)-max(alStart, bStart);
}

};