//
// Created by Leonid Ivashinnikov (2382) on 04.11.2023.
//

#include <iostream>
#include <stdexcept>
#include "CLS.h"

std::vector<std::string> split(const std::string& s, const std::string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int main() {
    std::cout << "TYPE 'exit' TO LEAVE" << std::endl;
    std::cout << "TYPE FUNCTION NAME AND ARGUMENTS" << std::endl;
    std::string cmd;
    while (true) {
        std::cin >> cmd;
        if (cmd == "exit")
            break;

        try {
            bool was_executed = false;
            std::vector<std::string> command = split(cmd, "_");
            if (command.size() == 3) {
                std::string num1, num2;
                short digit;
                unsigned long long int k;
                std::cin >> num1;
                if (command[0] == "COM" && command[1] == "NN" && command[2] == "D") {
                    std::cin >> num2;
                    Natural a(num1);
                    Natural b(num2);
                    std::cout << cmd << "(" << a << ", " << b << "): " << a.COM_NN_D(b) << std::endl;
                    was_executed = true;
                } else if (command[0] == "NZER" && command[1] == "N" && command[2] == "B") {
                    Natural a(num1);
                    std::cout << cmd << "(" << a << "): " << a.NZER_N_B() << std::endl;
                    was_executed = true;
                } else if (command[0] == "ADD") {
                    if (command[2] == "N") {
                        Natural a(num1);
                        if (command[1] == "1N") {
                            std::cout << cmd << "(" << a << "): ";
                            a.ADD_1N_N();
                            std::cout << a << std::endl;
                            was_executed = true;
                        } else if (command[1] == "NN") {
                            std::cin >> num2;
                            Natural b(num2);
                            std::cout << cmd << "(" << a << ", " << b << "): ";
                            a.ADD_NN_N(b);
                            std::cout << a << std::endl;
                            was_executed = true;
                        }
                    } else if (command[1] == "ZZ" && command[2] == "Z") {
                        std::cin >> num2;
                        Integer a(num1);
                        Integer b(num2);
                        std::cout << cmd << "(" << a << ", " << b << "): ";
                        a.ADD_ZZ_Z(b);
                        std::cout << a << std::endl;
                        was_executed = true;
                    }

                } else if (command[0] == "SUB") {
                    std::cin >> num2;
                    if (command[2] == "N") {
                        Natural a(num1);
                        Natural b(num2);
                        if (command[1] == "NN") {
                            std::cout << cmd << "(" << a << ", " << b << "): ";
                            a.SUB_NN_N(b);
                            std::cout << a << std::endl;
                            was_executed = true;
                        } else if (command[1] == "NDN") {
                            std::cin >> digit;
                            std::cout << cmd << "(" << a << ", " << b << ", " << digit << "): ";
                            a.SUB_NDN_N(b, digit);
                            std::cout << a << std::endl;
                            was_executed = true;
                        }
                    } else if (command[1] == "ZZ" && command[2] == "Z") {
                        Integer a(num1);
                        Integer b(num2);
                        std::cout << cmd << "(" << a << ", " << b << "): ";
                        a.SUB_ZZ_Z(b);
                        std::cout << a << std::endl;
                        was_executed = true;
                    }
                } else if (command[0] == "MUL") {
                    if (command[2] == "N") {
                        Natural a(num1);
                        if (command[1] == "ND") {
                            std::cin >> digit;
                            std::cout << cmd << "(" << a << ", " << digit << "): ";
                            a.MUL_ND_N(digit);
                            std::cout << a << std::endl;
                            was_executed = true;
                        } else if (command[1] == "Nk") {
                            std::cin >> k;
                            std::cout << cmd << "(" << a << ", " << k << "): ";
                            a.MUL_Nk_N(k);
                            std::cout << a << std::endl;
                            was_executed = true;
                        } else if (command[1] == "NN") {
                            std::cin >> num2;
                            Natural b(num2);
                            std::cout << cmd << "(" << a << ", " << b << "): ";
                            a.MUL_NN_N(b);
                            std::cout << a << std::endl;
                            was_executed = true;
                        }
                    } else if (command[2] == "Z") {
                        Integer a(num1);
                        if (command[1] == "ZM") {
                            std::cout << cmd << "(" << a << "): ";
                            a.MUL_ZM_Z();
                            std::cout << a << std::endl;
                            was_executed = true;
                        } else if (command[1] == "ZZ") {
                            std::cin >> num2;
                            Integer b(num2);
                            std::cout << cmd << "(" << a << ", " << b << "): ";
                            a.MUL_ZZ_Z(b);
                            std::cout << a << std::endl;
                            was_executed = true;
                        }
                    }
                } else if (command[0] == "DIV") {
                    std::cin >> num2;
                    if (command[1] == "NN") {
                        Natural a(num1);
                        Natural b(num2);
                        if (command[2] == "Dk") {
                            std::cout << cmd << "(" << a << ", " << b << "): " << a.DIV_NN_Dk(b) << std::endl;
                            was_executed = true;
                        } else if (command[2] == "N") {
                            std::cout << cmd << "(" << a << ", " << b << "): " << a.DIV_NN_N(b) << std::endl;
                            was_executed = true;
                        }
                    } else if (command[1] == "ZZ" && command[2] == "Z") {
                        Integer a(num1);
                        Integer b(num2);
                        std::cout << cmd << "(" << a << ", " << b << "): " << a.DIV_ZZ_Z(b) << std::endl;
                        was_executed = true;
                    }
                } else if (command[0] == "MOD") {
                    std::cin >> num2;
                    if (command[1] == "NN" && command[2] == "N") {
                        Natural a(num1);
                        Natural b(num2);
                        std::cout << cmd << "(" << a << ", " << b << "): " << a.MOD_NN_N(b) << std::endl;
                        was_executed = true;
                    } else if (command[1] == "ZZ" && command[2] == "Z") {
                        Integer a(num1);
                        Integer b(num2);
                        std::cout << cmd << "(" << a << ", " << b << "): " << a.MOD_ZZ_Z(b) << std::endl;
                        was_executed = true;
                    }
                } else if (command[0] == "GCF" && command[1] == "NN" && command[2] == "N") {
                    std::cin >> num2;
                    Natural a(num1);
                    Natural b(num2);
                    std::cout << cmd << "(" << a << ", " << b << "): " << a.GCF_NN_N(b) << std::endl;
                    was_executed = true;
                } else if (command[0] == "LCM" && command[1] == "NN" && command[2] == "N") {
                    std::cin >> num2;
                    Natural a(num1);
                    Natural b(num2);
                    std::cout << cmd << "(" << a << ", " << b << "): " << a.LCM_NN_N(b) << std::endl;
                    was_executed = true;
                } else if (command[0] == "ABS" && command[1] == "Z" && command[2] == "Z") {
                    Integer a(num1);
                    std::cout << cmd << "(" << a << "): " << a.ABS_Z_Z() << std::endl;
                    was_executed = true;
                } else if (command[0] == "POZ" && command[1] == "Z" && command[2] == "D") {
                    Integer a(num1);
                    std::cout << cmd << "(" << a << "): " << a.POZ_Z_D() << std::endl;
                    was_executed = true;
                } else if (command[0] == "TRANS") {
                    if (command[1] == "N" && command[2] == "Z") {
                        Natural a(num1);
                        std::cout << cmd << "(" << a << "): " << Integer::TRANS_N_Z(a) << std::endl;
                        was_executed = true;
                    } else if (command[1] == "Z" && command[2] == "N") {
                        Integer a(num1);
                        std::cout << cmd << "(" << a << "): " << a.TRANS_Z_N() << std::endl;
                        was_executed = true;
                    }
                }
            }
            if (!was_executed)
                std::cout << "UNKNOWN COMMAND. TRY AGAIN." << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "ERROR: " << e.what() << std::endl;
        }
    }
    return 0;
}
