#include <iostream>
#include <string>
using namespace std;

class Solution{
    int reverse(int num) {
        int res = 0;
        while(num != 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }

    int toNum(const string& s) {
        int res = 0;
        for(int i = 0; i < 2; i++) {
            res = res * 10 + s[i] - '0';
        }
        return res;
    }

    string toStr(int num) {
        string s;
        if (num == 0) {
            s = "00";
            return s;
        }
        while (num != 0) {
            s.push_back(num % 10 + '0');
            num /= 10;
        }
        swap(s[0], s[1]);
        return s;
    }
public:
    string nextSymmetricTime(string& time) {
        string hour(time.begin(), time.begin() + 2);
        string minute(time.begin() + 3, time.end());
        int hourNum = toNum(hour);
        int minuteNum = toNum(minute);
        int newHour = hourNum;
        int newMinute = reverse(hourNum);
        string res;
        while (true) {
            if (newMinute <= 59 && newMinute >= 0) {
                if (newHour != hourNum || newMinute > minuteNum && newHour == hourNum) {
                    res = toStr(newHour) + ':' + toStr(newMinute);
                    break;
                }
            }
            newHour = (newHour + 1) % 24;
            newMinute = reverse(newHour);
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    string nowTime = "22:23";
    Solution solution;
    string nextTime = solution.nextSymmetricTime(nowTime);
    cout << "nextTime: " << nextTime << '\n';
    return 0;
}
