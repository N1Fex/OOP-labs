#include <iostream>
#include <string>

bool is_number(std::string& str) {
    if (str[0] == '.') str = "0" + str;
    else if (str[0] == '-' && str[1] == '.') {
        str = "-" + str;
        str[1] = '0';
    }
    for (const auto i : str) {
        if (!std::isdigit(i) && i != '.' && i != '-') return false;
    }
    return true;
}

bool is_natural(std::string& str) {
    for (const auto i : str) {
        if (!std::isdigit(i) && i != '-') return false;
    }
    return true;
}

double calcRow(double x, int n) {
    if (n < 1) {
        std::cout << "n must be greater than 0!\n";
        return 0;
    }
    if (x == 0) {
        std::cout << "x cannot be zero!\n";
        return 0;
    }
    double mult = 1.0;
    for (int i = 1; i <= n; i++) {
        mult *= pow(1+0.8/x + cos(x*i),(double)1/i);
    }
    return 4.2 * x + mult;
}

int main()
{
    std::string input1,input2;
    double x;
    int n;
    while (true) {
        std::cout << "Enter x: ";
        std::getline(std::cin, input1);
        if (!is_number(input1) || input1 == "") continue;
        std::cout << "Enter n: ";
        std::getline(std::cin, input2);
        if (!is_natural(input2) || input2 == "") {
            std::cout << "n must be integer number!\n";
            continue;
        }
        x = stod(input1);
        n = std::stoi(input2);
        printf("Result: %f\n", calcRow(x,n));
        printf("---------------------\n");
    }   
   
    system("pause");
}
