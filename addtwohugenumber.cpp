
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;


int integerPow(int x, int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  int tmp = integerPow(x, p/2);
  if (p % 2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

int main () {
    const int BINSIZE = 3;
    string numStr1;
    string numStr2;
    cout << "First Number: " << endl;
    cin >> numStr1;
    cout << "Second Number: " << endl;
    cin >> numStr2;


    std::reverse(std::begin(numStr1), std::end(numStr1));
    std::reverse(std::begin(numStr2), std::end(numStr2));

    int lenStr1 = numStr1.length();
    int lenStr2 = numStr2.length();

    int lenDiff = lenStr1 - lenStr2;

    if( lenDiff > 0 ) {
        for(int i = 0; i < abs(lenDiff); i++)
            numStr2.append("0");
    }
    else if( lenDiff < 0 ) {
        for(int i = 0; i < abs(lenDiff); i++)
            numStr1.append("0");
    }
    
    lenStr1 = numStr1.length();
    int modNum = lenStr1 % BINSIZE;
    int fillZero = BINSIZE - modNum;
    for(int i = 0; i < fillZero; i++) {
        numStr1.append("0");
        numStr2.append("0");
    }

    lenStr1 = numStr1.length();
    int bins = lenStr1 / BINSIZE;
    std::reverse(std::begin(numStr1), std::end(numStr1));
    std::reverse(std::begin(numStr2), std::end(numStr2));

    string subStr1;
    string subStr2;

    vector<string> vecSubStr1;
    vector<string> vecSubStr2;
    for( int k = bins - 1; k >= 0 ; k-- ) {
        subStr1 = numStr1.substr( k * BINSIZE, BINSIZE );
        subStr2 = numStr2.substr( k * BINSIZE, BINSIZE );
        subStr1.empty();
        subStr2.empty();
        vecSubStr1.push_back(subStr1);
        vecSubStr2.push_back(subStr2);
    }

    vector<string> vecResStr;
    string resString;
    int resLen = 0;
    int diffRes = 0;
    int subNum1 = 0;
    int subNum2 = 0;
    int resSubNum = 0;
    int carry = 0;
    int numToSubtract = integerPow(10, BINSIZE);
    for( int k = 0; k < bins; k++ ) {
        subStr1 = vecSubStr1.at(k).substr(0, BINSIZE);
        subStr2 = vecSubStr2.at(k).substr(0, BINSIZE);
        subNum1 = atoi( subStr1.c_str() );
        subNum2 = atoi( subStr2.c_str() );
        resSubNum = subNum1 + subNum2;
        if (carry == 1 ) {
            resSubNum += 1;
            carry = 0;
        }
        if(resSubNum >= numToSubtract) {
            resSubNum -= numToSubtract;
            carry = 1;
        }
        resString = to_string(resSubNum);
        resLen = resString.length();
        diffRes = BINSIZE - resLen;
        if( diffRes > 0 && k != bins - 1) {
            std::reverse(std::begin(resString), std::end(resString));
            for(int i = 0; i < abs(diffRes); i++)
                resString.append("0");
            std::reverse(std::begin(resString), std::end(resString));
        }
        vecResStr.push_back(resString);
    }

    std::cout << "Result of Addition: ";
    for (int k = bins - 1; k >= 0 ; k-- ) {
        string str = vecResStr.at(k);
        cout << vecResStr.at(k);
        if(k != 0)
            cout << ",";
    }
    std::cout << endl;




    return 0;
}