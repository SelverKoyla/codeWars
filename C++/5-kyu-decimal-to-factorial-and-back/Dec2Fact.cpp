#include <string>
#include <map>


class Dec2Fact {
public:
    static std::string dec2FactString(long long nb) {
        std::string output;

        for (long long iter = 36, temp = nb, count = 0LL; iter >= 0 ; iter--, count = 0LL) {
            if (temp >= factorial(iter)) {
                count = temp / factorial(iter);
                temp -= factorial(iter) * count;
            }

            output += (count < 10LL) ? char(count + '0') : char('A' + (int) count - 10);
        }

        return output.erase(0, output.find_first_not_of('0'));
    }

    static long long factString2Dec(const std::string &str) {
        long long output = 0;

        for (int i = 0; i < str.length(); output += factorial(str.length() - i - 1) * (long long) (str[i] - '0'), i++);

        return output;
    }

private:
    /*static void factorial(std::map<int, long long> &factDict) { factorial(36LL, factDict); }
    static long long factorial(int x, std::map<int, long long> &factDict) {

        if (x > 0) {
            long long num = x * factorial(x - 1, factDict);
            factDict.emplace(x, num);
            return num;
        } else {
            factDict.emplace(0, 1LL);
            return 1;
        }
    }*/

    static long long factorial(long long x) {
        return (x <= 1) ? 1 : x * factorial(x - 1);
    }
};