#include <iostream>
#include <string>

using namespace std;

int main() {
    int y, m, d;
    string day_of_week;
    string errorMessage;

    // 데이터 입력 받기 + 윤년 판단
    cout << "Enter Gregorian year (year >= 1583):";
    cin >> y;
    cout << "Enter Gregorian month (month: 1..12):";
    cin >> m;
    cout << "Enter Gregorian day (1..28|29|30|31):";
    cin >> d;

    bool leap_year = ((y % 4 == 0) && (y % 100 != 0)) || (y % 400); // 윤년인지 확인 true / false

    // 잘못된 입력을 했을 경우
    if (y < 1583) {
        errorMessage = "year";
    } else if (m > 13) {
        errorMessage = "month";
    } else if ((d > 31) && ((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12))) {
        errorMessage = "day";
    } else if (((m == 2) && (leap_year) && (d > 29)) || ((m == 2) && (!leap_year) && (d > 28))) {
        errorMessage = "day";
    } else if (((m == 4) || (m == 6) || (m == 9) || (m == 11)) && (d > 30)) {
        errorMessage = "day";
    }

    if (!errorMessage.empty()) { // 에러 메세지가 비어있지 않으면 에러 메세지 출력
        cout << "Wrong " << errorMessage << "! Try again!" << endl;
        return 0;
    }

    int julian_y = y + 8000;
    int julian_m = m;

    if (m < 3) {
        julian_y--;
        julian_m += 12;
    }

    long julian = (julian_y * 365) + (julian_y / 4) - (julian_y / 100) + (julian_y / 400) - 1200820 +
                  ((julian_m * 153 + 3) / 5) - 92 + (d - 1);
    julian = julian % 7;

    switch (julian) {
        case 0:
            day_of_week = "Monday";
            break;
        case 1:
            day_of_week = "Tuesday";
            break;
        case 2:
            day_of_week = "Wednesday";
            break;
        case 3:
            day_of_week = "Thursday";
            break;
        case 4:
            day_of_week = "Friday";
            break;
        case 5:
            day_of_week = "Saturday";
            break;
        case 6:
            day_of_week = "Sunday";
            break;
        default:
            break;
    }

    cout << y << "-" << m << "-" << d << " is " << day_of_week << endl;

    return 0;
}