#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const double _0to200 = 93.3;
    const double _201to400 = 187.9;
    const double _401 = 280.6;
    int month; // 달
    int power; // 전력
    int basic_rate; // 기본요금
    int use_rate;
    double electric_rate,tax,electric_charge;
    double VAT,giban;
    // use_rate: 사용 요금, electric_rate: 전기 요금계, tax: 세금, electric_charge: 청구 요금계

    cout << "Please enter month (1-12) :";
    cin >> month;
    cout << "Please enter a kWh (integer) :";
    cin >> power;

    // 전기 요금계 계산

    // 성수기 + 전력 1000kWh 이상 사용한 경우
    if((power > 1000) && (month == 7 || month == 8 || month == 12 || month == 1 || month == 2)){
        basic_rate = 7300;
        use_rate = (200 * _0to200) + (200 * _201to400) + (600 * _401) + ((power - 1000) * 709.5);
        electric_rate = basic_rate + use_rate;
    }
        // 비성수기 + 성수기에 1000kWh 이상 사용하지 않았을 경우
    else{
        if(power <= 200){
            basic_rate = 910;
            use_rate = _0to200 * power;
            electric_rate = basic_rate + use_rate;
        }
        else if((power > 200) && (power <= 400)){
            basic_rate = 1600;
            use_rate = (200 * _0to200) + ((power - 200) * _201to400);
            electric_rate = basic_rate + use_rate;
        }
        else{
            basic_rate = 7300;
            use_rate = (200 * _0to200) + (200 * _201to400) + ((power - 400) * _401);
            electric_rate = basic_rate + use_rate;
        }

    }

    // 세금 계산
    VAT = round(electric_rate * 0.1);
    int before_giban;
    before_giban = (electric_rate * 0.037);
    if(before_giban % 10 == 0){
        giban = before_giban;
    }
    else{
        giban = before_giban - (before_giban % 10);
    }
    tax = VAT + giban;
    int before_electric_charge = electric_rate + tax;
    if (before_electric_charge % 10 == 0){
        electric_charge = before_electric_charge;
    }
    else{
        electric_charge = before_electric_charge - (before_electric_charge % 10);
    }

    cout << "Electric charge is " << electric_charge << endl;

    return 0;
}