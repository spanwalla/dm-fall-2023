//
// Created by Leonid Ivashinnikov (2382) on 04.11.2023.
//

#include <iostream>
#include <stdexcept>
#include <map>
#include <vector>
#include <string>
#include <functional>
#include "CLS.h"

#define NOT_ENOUGH_ERROR "NOT ENOUGH ARGUMENTS. TRY AGAIN."

class CommandProcessor {
public:
    void COM_NN_D(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Natural a(args[1]);
        Natural b(args[2]);
        std::cout << "COM_NN_D(" << a << ", " << b << "): " << a.COM_NN_D(b) << std::endl;
    }

    void NZER_N_B(const std::vector<std::string>& args) {
        if (args.size() < 2)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Natural a(args[1]);
        std::cout << "NZER_N_B(" << a << "): " << a.NZER_N_B() << std::endl;
    }

    void ADD_1N_N(const std::vector<std::string>& args) {
        if (args.size() < 2)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Natural a(args[1]);
        std::cout << "ADD_1N_N(" << a << "): ";
        a.ADD_1N_N();
        std::cout << a << std::endl;
    }

    void ADD_NN_N(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Natural a(args[1]);
        Natural b(args[2]);
        std::cout << "ADD_NN_N(" << a << ", " << b << "): ";
        a.ADD_NN_N(b);
        std::cout << a << std::endl;
    }

    void SUB_NN_N(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Natural a(args[1]);
        Natural b(args[2]);
        std::cout << "SUB_NN_N(" << a << ", " << b << "): ";
        a.SUB_NN_N(b);
        std::cout << a << std::endl;
    }

    void MUL_ND_N(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Natural a(args[1]);
        auto b = stoi(args[2]);
        std::cout << "MUL_ND_N(" << a << ", " << b << "): ";
        a.MUL_ND_N((short)b);
        std::cout << a << std::endl;
    }

    void MUL_Nk_N(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Natural a(args[1]);
        auto b = stoi(args[2]);
        std::cout << "MUL_Nk_N(" << a << ", " << b << "): ";
        a.MUL_Nk_N(b);
        std::cout << a << std::endl;
    }

    void MUL_NN_N(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Natural a(args[1]);
        Natural b(args[2]);
        std::cout << "MUL_NN_N(" << a << ", " << b << "): ";
        a.MUL_NN_N(b);
        std::cout << a << std::endl;
    }

    void SUB_NDN_N(const std::vector<std::string>& args) {
        if (args.size() < 4)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Natural a(args[1]);
        Natural b(args[2]);
        auto c = stoi(args[3]);
        std::cout << "SUB_NDN_N(" << a << ", " << b << ", " << c << "): ";
        a.SUB_NDN_N(b, (short)c);
        std::cout << a << std::endl;
    }

    void DIV_NN_Dk(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Natural a(args[1]);
        Natural b(args[2]);
        std::cout << "DIV_NN_Dk(" << a << ", " << b << "): " << a.DIV_NN_Dk(b) << std::endl;
    }

    void DIV_NN_N(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Natural a(args[1]);
        Natural b(args[2]);
        std::cout << "DIV_NN_N(" << a << ", " << b << "): " << a.DIV_NN_N(b) << std::endl;
    }

    void MOD_NN_N(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Natural a(args[1]);
        Natural b(args[2]);
        std::cout << "MOD_NN_N(" << a << ", " << b << "): " << a.MOD_NN_N(b) << std::endl;
    }

    void GCF_NN_N(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Natural a(args[1]);
        Natural b(args[2]);
        std::cout << "GCF_NN_N(" << a << ", " << b << "): " << a.GCF_NN_N(b) << std::endl;
    }

    void LCM_NN_N(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Natural a(args[1]);
        Natural b(args[2]);
        std::cout << "LCM_NN_N(" << a << ", " << b << "): " << a.LCM_NN_N(b) << std::endl;
    }

    void ABS_Z_Z(const std::vector<std::string>& args) {
        if (args.size() < 2)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Integer a(args[1]);
        std::cout << "ABS_Z_Z(" << a << "): " << a.ABS_Z_Z() << std::endl;
    }

    void POZ_Z_D(const std::vector<std::string>& args) {
        if (args.size() < 2)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Integer a(args[1]);
        std::cout << "POZ_Z_D(" << a << "): " << a.POZ_Z_D() << std::endl;
    }

    void MUL_ZM_Z(const std::vector<std::string>& args) {
        if (args.size() < 2)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Integer a(args[1]);
        std::cout << "MUL_ZM_Z(" << a << "): ";
        a.MUL_ZM_Z();
        std::cout << a << std::endl;
    }

    void TRANS_N_Z(const std::vector<std::string>& args) {
        if (args.size() < 2)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Natural a(args[1]);
        std::cout << "TRANS_N_Z(" << a << "): " << Integer::TRANS_N_Z(a) << std::endl;
    }

    void TRANS_Z_N(const std::vector<std::string>& args) {
        if (args.size() < 2)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Integer a(args[1]);
        std::cout << "TRANS_Z_N(" << a << "): " << a.TRANS_Z_N() << std::endl;
    }

    void ADD_ZZ_Z(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Integer a(args[1]);
        Integer b(args[2]);
        std::cout << "ADD_ZZ_Z(" << a << ", " << b << "): ";
        a.ADD_ZZ_Z(b);
        std::cout << a << std::endl;
    }

    void SUB_ZZ_Z(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Integer a(args[1]);
        Integer b(args[2]);
        std::cout << "SUB_ZZ_Z(" << a << ", " << b << "): ";
        a.SUB_ZZ_Z(b);
        std::cout << a << std::endl;
    }

    void MUL_ZZ_Z(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Integer a(args[1]);
        Integer b(args[2]);
        std::cout << "MUL_ZZ_Z(" << a << ", " << b << "): ";
        a.MUL_ZZ_Z(b);
        std::cout << a << std::endl;
    }

    void DIV_ZZ_Z(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Integer a(args[1]);
        Integer b(args[2]);
        std::cout << "DIV_ZZ_Z(" << a << ", " << b << "): " << a.DIV_ZZ_Z(b) << std::endl;
    }

    void MOD_ZZ_Z(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Integer a(args[1]);
        Integer b(args[2]);
        std::cout << "MOD_ZZ_Z(" << a << ", " << b << "): " << a.MOD_ZZ_Z(b) << std::endl;
    }

    void RED_Q_Q(const std::vector<std::string>& args) {
        if (args.size() < 2)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Rational a(args[1]);
        std::cout << "RED_Q_Q(" << a << "): ";
        a.RED_Q_Q();
        std::cout << a << std::endl;
    }

    void INT_Q_B(const std::vector<std::string>& args) {
        if (args.size() < 2)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Rational a(args[1]);
        std::cout << "INT_Q_B(" << a << "): " << a.INT_Q_B() << std::endl;
    }

    void TRANS_Z_Q(const std::vector<std::string>& args) {
        if (args.size() < 2)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Integer a(args[1]);
        std::cout << "TRANS_Z_Q(" << a << "): " << Rational::TRANS_Z_Q(a) << std::endl;
    }

    void TRANS_Q_Z(const std::vector<std::string>& args) {
        if (args.size() < 2)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Rational a(args[1]);
        std::cout << "TRANS_Q_Z(" << a << "): " << a.TRANS_Q_Z() << std::endl;
    }

    void ADD_QQ_Q(const std::vector<std::string>& args) {
        if (args.size() < 3)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Rational a(args[1]);
        Rational b(args[2]);
        std::cout << "ADD_QQ_Q(" << a << ", " << b << "): ";
        a.ADD_QQ_Q(b);
        std::cout << a << std::endl;
    }

    void MUL_Pxk_P(const std::vector<std::string>& args) {
        if (args.size() < 2)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Polynomial a({Rational("1"), Rational("2"), Rational("1")});
        unsigned long long int k = std::stoi(args[2]);
        std::cout << "MUL_Pxk_P(" << a << ", " << k << "): ";
        a.MUL_Pxk_P(k);
        std::cout << a << std::endl;
    }
  
    void DEG_P_N(const std::vector<std::string>& args) {
        if (args.size() < 2)
            throw std::invalid_argument(NOT_ENOUGH_ERROR);

        Polynomial a({Rational("1"), Rational("2"), Rational("1")});
        std::cout << "DEG_P_N(" << a << "): " << a.DEG_P_N() << std::endl;
    }
  
    void ProcessCommand(const std::string& s, const std::string& delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        std::string token;
        std::vector<std::string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
            token = s.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr (pos_start));

        // Проверяем, существует ли функция для данной команды и вызываем её
        auto it = commandMap.find(res[0]);
        if (it != commandMap.end()) {
            it->second(res);
        } else {
            std::cout << "UNKNOWN COMMAND: " << res[0] << std::endl;
        }
    }

private:
    std::map<std::string, std::function<void(const std::vector<std::string>&)>> commandMap {
            {"COM_NN_D", [this](auto && PH1) { COM_NN_D(std::forward<decltype(PH1)>(PH1)); }},
            {"NZER_N_B", [this](auto && PH1) { NZER_N_B(std::forward<decltype(PH1)>(PH1)); }},
            {"ADD_1N_N", [this](auto && PH1) { ADD_1N_N(std::forward<decltype(PH1)>(PH1)); }},
            {"ADD_NN_N", [this](auto && PH1) { ADD_NN_N(std::forward<decltype(PH1)>(PH1)); }},
            {"SUB_NN_N", [this](auto && PH1) { SUB_NN_N(std::forward<decltype(PH1)>(PH1)); }},
            {"MUL_ND_N", [this](auto && PH1) { MUL_ND_N(std::forward<decltype(PH1)>(PH1)); }},
            {"MUL_Nk_N", [this](auto && PH1) { MUL_Nk_N(std::forward<decltype(PH1)>(PH1)); }},
            {"MUL_NN_N", [this](auto && PH1) { MUL_NN_N(std::forward<decltype(PH1)>(PH1)); }},
            {"SUB_NDN_N", [this](auto && PH1) { SUB_NDN_N(std::forward<decltype(PH1)>(PH1)); }},
            {"DIV_NN_Dk", [this](auto && PH1) { DIV_NN_Dk(std::forward<decltype(PH1)>(PH1)); }},
            {"DIV_NN_N", [this](auto && PH1) { DIV_NN_N(std::forward<decltype(PH1)>(PH1)); }},
            {"MOD_NN_N", [this](auto && PH1) { MOD_NN_N(std::forward<decltype(PH1)>(PH1)); }},
            {"GCF_NN_N", [this](auto && PH1) { GCF_NN_N(std::forward<decltype(PH1)>(PH1)); }},
            {"LCM_NN_N", [this](auto && PH1) { LCM_NN_N(std::forward<decltype(PH1)>(PH1)); }},
            {"ABS_Z_Z", [this](auto && PH1) { ABS_Z_Z(std::forward<decltype(PH1)>(PH1)); }},
            {"POZ_Z_D", [this](auto && PH1) { POZ_Z_D(std::forward<decltype(PH1)>(PH1)); }},
            {"MUL_ZM_Z", [this](auto && PH1) { MUL_ZM_Z(std::forward<decltype(PH1)>(PH1)); }},
            {"TRANS_N_Z", [this](auto && PH1) { TRANS_N_Z(std::forward<decltype(PH1)>(PH1)); }},
            {"TRANS_Z_N", [this](auto && PH1) { TRANS_Z_N(std::forward<decltype(PH1)>(PH1)); }},
            {"ADD_ZZ_Z", [this](auto && PH1) { ADD_ZZ_Z(std::forward<decltype(PH1)>(PH1)); }},
            {"SUB_ZZ_Z", [this](auto && PH1) { SUB_ZZ_Z(std::forward<decltype(PH1)>(PH1)); }},
            {"MUL_ZZ_Z", [this](auto && PH1) { MUL_ZZ_Z(std::forward<decltype(PH1)>(PH1)); }},
            {"DIV_ZZ_Z", [this](auto && PH1) { DIV_ZZ_Z(std::forward<decltype(PH1)>(PH1)); }},
            {"MOD_ZZ_Z", [this](auto && PH1) { MOD_ZZ_Z(std::forward<decltype(PH1)>(PH1)); }},
            {"RED_Q_Q", [this](auto && PH1) { RED_Q_Q(std::forward<decltype(PH1)>(PH1)); }},
            {"INT_Q_B", [this](auto && PH1) { INT_Q_B(std::forward<decltype(PH1)>(PH1)); }},
            {"TRANS_Z_Q", [this](auto && PH1) { TRANS_Z_Q(std::forward<decltype(PH1)>(PH1)); }},
            {"TRANS_Q_Z", [this](auto && PH1) { TRANS_Q_Z(std::forward<decltype(PH1)>(PH1)); }},
            {"ADD_QQ_Q", [this](auto && PH1) { ADD_QQ_Q(std::forward<decltype(PH1)>(PH1)); }},
            {"MUL_Pxk_P", [this](auto && PH1) { MUL_Pxk_P(std::forward<decltype(PH1)>(PH1)); }},
            {"DEG_P_N", [this](auto && PH1) { DEG_P_N(std::forward<decltype(PH1)>(PH1)); }}
    };
};

int main() {
    CommandProcessor processor;
    std::string input;

    std::cout << "TYPE 'exit' TO LEAVE" << std::endl;
    std::cout << "TYPE FUNCTION NAME AND ARGUMENTS" << std::endl;
    while (true) {
        std::getline(std::cin, input);
        if (input == "exit")
            break;
        try {
            processor.ProcessCommand(input, " ");
        } catch (const std::exception& e) {
            std::cout << "ERROR: " << e.what() << std::endl;
        }
    }
    return 0;
}