// Created by Ulyanova Ekaterina (2382) on 14.11.2023.
// Обёртка функций С++ для использования в Python.

#include <pybind11/pybind11.h>
#include <string>
#include <vector>
#include <stdexcept>
#include <ranges>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>

namespace py = pybind11;

class Natural {
public:
    explicit Natural(const std::string& number) {
        for (auto c : std::ranges::reverse_view(number)) {
            if (!std::isdigit(c))
                throw std::invalid_argument("Natural number expects a sequence of digits.");
            this->digits.push_back(short(c - '0'));
        }
        if (digits.empty())
            this->digits.push_back(0);
        clean_zero(); // Убрать незначащие нули.
    }
    explicit Natural(long long int num) {
        if (num < 0)
            throw std::invalid_argument("Number must be greater than or equal to 0.");

        while (num > 0) {
            this->digits.push_back(short(num % 10));
            num /= 10;
        }

        if (digits.empty())
            this->digits.push_back(0);
    }
    Natural() {
        this->digits = { 0 };
    }
    virtual void putMembers(std::ostream& out) const {
        for (short digit : std::ranges::reverse_view(digits))
            out << digit;
    }
    virtual std::string toString() const {
        std::ostringstream out;
        putMembers(out);
        return out.str();
    }
    friend std::ostream& operator << (std::ostream& out, const Natural& number) {
        out << number.toString();
        return out;
    }
    Natural& operator=(const Natural& number) {
        if (this == &number)
            return *this;
        digits.clear();
        std::copy(number.digits.begin(), number.digits.end(), std::back_inserter(digits));
        return *this;
    }
    friend bool operator==(const Natural& number1, const Natural& number2);
    friend bool operator!=(const Natural& number1, const Natural& number2);
    friend bool operator>=(const Natural& number1, const Natural& number2);
    friend bool operator<=(const Natural& number1, const Natural& number2);
    friend bool operator>(const Natural& number1, const Natural& number2);
    friend bool operator<(const Natural& number1, const Natural& number2);
    Natural& operator++() {
        this->ADD_1N_N();
        return *this;
    }

    Natural operator++(int) {
        Natural tmp(*this);
        ++(*this);
        return tmp;
    }

    Natural& operator--() {
        this->SUB_NN_N(Natural(1));
        return *this;
    }

    Natural operator--(int) {
        Natural tmp(*this);
        --(*this);
        return tmp;
    }
    void ADD_1N_N() {
        size_t ind = 0;
        int summ = 0;
        if (this->digits[ind] + 1 == 10) {
            while (ind < this->digits.size()) {
                summ = this->digits[ind] + 1;
                if (summ == 10) {
                    summ %= 10;
                    this->digits[ind] = summ;
                    ind++;
                }
                else {
                    this->digits[ind] = summ;
                    break;
                }
            }
            if (ind == this->digits.size()) this->digits.push_back(1);
        }
        else
            this->digits[ind]++;
    }
    void ADD_NN_N(const Natural& number) {
        Natural addable_number = number;

        unsigned carry = 0;
        size_t index = 0;

        while (this->digits.size() < addable_number.digits.size())
            this->digits.push_back(0);
        while (addable_number.digits.size() < this->digits.size())
            addable_number.digits.push_back(0);

        while (index < this->digits.size()) {
            auto digitsum = this->digits[index] + addable_number.digits[index] + carry;
            carry = digitsum / 10;
            if (digitsum >= 10)
                digitsum %= 10;

            this->digits[index] = digitsum;
            index++;
        }

        if (carry != 0)
            this->digits.push_back(carry);
    }
    [[nodiscard]] int COM_NN_D(const Natural& cmp) const{
        if (cmp.digits.size() == this->digits.size()) {
            for (int i = cmp.digits.size() - 1; i >= 0; --i) {
                if (cmp.digits[i] != this->digits[i])
                    return (this->digits[i] > cmp.digits[i] ? 2 : 1);
            }
            return 0;
        }
        return (this->digits.size() > cmp.digits.size() ? 2 : 1);
    }
    [[nodiscard]] bool NZER_N_B() const {
        return std::ranges::any_of(digits.cbegin(), digits.cend(), [](auto i) { return i != 0; });
    }
    void SUB_NN_N(const Natural& number) {
        Natural temp = number;
        short carry = 0;
        if (COM_NN_D(temp) == 1)
            throw std::logic_error("The first number must be less than the second");
        temp.zfill(len() - temp.len()); // заполняет нулями с конца
        for (int i = 0; i < len(); i++) {
            auto difference = short(digits[i] - temp.digits[i] - carry);
            carry = difference < 0 ? 1 : 0;
            difference = difference < 0 ? difference += 10 : difference;
            digits[i] = difference;
        }
        clean_zero(); // очищает нули в начале
    }
    void MUL_ND_N(short digit) {
        int carry = 0;
        int tmp = 0;
        if (digit == 0) {
            this->digits = { 0 };
        }
        else {
            if (digit > 1 && digit < 10) {
                for (int i{ 0 }; i < this->digits.size(); ++i) {
                    tmp = (this->digits[i] * digit) + carry;
                    this->digits[i] = tmp % 10;
                    carry = tmp / 10;
                }
                if (carry != 0) {
                    this->digits.push_back(carry);
                }
            }
        }
    }
    void MUL_Nk_N(unsigned long long int k) {
        if (this->digits[digits.size() - 1] != 0)
            this->digits.insert(digits.begin(), k, 0);
        else {
            this->digits.clear();
            this->digits.push_back(0);
        }
    }
    void MUL_NN_N(Natural number) {
        if ((this->NZER_N_B() == false) || (number.NZER_N_B() == false)) { // проверка обоих чисел на 0
            this->digits = { 0 };
        }
        else if (this->COM_NN_D(Natural(1)) == 0) { // проверка первого множителя на 1
            this->digits = number.digits;
        }
        else {
            Natural res;
            Natural tmp;
            if (this->COM_NN_D(number) == 1) {
                std::swap(*this, number); // меняем местами this и number, если this < number
            }
            for (int i{ 0 }; i < number.digits.size(); ++i) {
                tmp.digits = this->digits;
                tmp.MUL_ND_N(number.digits[i]); // умножение на цифру из number
                tmp.MUL_Nk_N(i); // учет смещения на i разрядов
                res.ADD_NN_N(tmp);
            }
            this->digits = res.digits;
        }
    }
    void SUB_NDN_N(const Natural& number, short digit)
    {
        Natural temp = number;
        temp.MUL_ND_N(digit);
        SUB_NN_N(temp);
    }
    [[nodiscard]] Natural DIV_NN_Dk(const Natural& number) const {
        Natural first_number;
        if (COM_NN_D(number) == 1)
            throw std::logic_error("The first number must be greater than the second"); // выкидываем ошибку, если 2 число больше 1

        if (!number.NZER_N_B())
            throw std::invalid_argument("The number must not be zero!");

        std::size_t index_last_one = len() - 1;
        Natural buffer;
        buffer.digits[0] = digits[index_last_one]; // добавляем в буффер старшую цифру числа, которое делим
        while (buffer.COM_NN_D(number) == 1)
            buffer.digits.insert(buffer.digits.begin(), digits[--index_last_one]); // увеличиваем число в буффере, пока оно не станет больше делителя

        while (buffer.COM_NN_D(number) != 1)
        {
            buffer.SUB_NN_N(number);
            first_number.digits[0]++; // тут мы считаем количество делителей, содержащихся в буффере
        }
        first_number.MUL_Nk_N(index_last_one);
        return first_number;
    }
    [[nodiscard]] Natural DIV_NN_N(const Natural& number) const {
        if (this->COM_NN_D(number) == 0) // если числа равны, их неполное частное равно 1
            return Natural(1);
        else if (this->COM_NN_D(number) == 1) // если делимое меньше делителя, их неполное частное 0
            return Natural(0);
        else if (number.COM_NN_D(Natural(1)) == 0) // если делитель равен 1, неполное частное равно this
            return *this;
        else {
            Natural res;
            Natural tmp1 = *this;
            Natural tmp2;
            while (tmp1.COM_NN_D(number) == 2 || tmp1.COM_NN_D(number) == 0) {
                tmp2 = tmp1.DIV_NN_Dk(number); // находим первую цифру частного * 10^k (k - позиция)
                res.ADD_NN_N(tmp2); // прибавляем промежуточный результат к общему
                tmp2.MUL_NN_N(number);
                tmp1.SUB_NN_N(tmp2);
            }
            return res;
        }
    }
    [[nodiscard]] Natural MOD_NN_N(const Natural& number) const {
        if (!number.NZER_N_B())
            throw std::logic_error("The number must not be zero!");

        if (COM_NN_D(number) == 0 || !NZER_N_B() || number.COM_NN_D(Natural(1)) == 0) // случаи, когда остаток равен 0
            return Natural(0);
        else if (COM_NN_D(number) == 1) // если делимое меньше делителя, остаток равен делимому
            return *this;
        else if (COM_NN_D(Natural(1)) == 0) // если делимое равно 1, остаток всегда 1
            return Natural(1);
        else {
            Natural tmp1 = *this;
            Natural tmp2 = tmp1.DIV_NN_N(number); // вычисляем неполное частное
            tmp2.MUL_NN_N(number);
            tmp1.SUB_NN_N(tmp2); // считаем остаток
            return tmp1;
        }
    }
    [[nodiscard]] Natural GCF_NN_N(const Natural& number) const {
        if (!NZER_N_B() && !number.NZER_N_B())
            throw std::logic_error("One of the numbers must have non-zero value.");
        Natural temp_one = *this;
        Natural temp_two = number;
        while (temp_one.NZER_N_B() && temp_two.NZER_N_B()) {
            if (temp_one.COM_NN_D(temp_two) == 2)
                temp_one = temp_one.MOD_NN_N(temp_two);
            else
                temp_two = temp_two.MOD_NN_N(temp_one);
        }
        temp_one.ADD_NN_N(temp_two);
        return temp_one;
    }
    [[nodiscard]] Natural LCM_NN_N(const Natural& number) const {
        Natural temp_one = *this;
        const Natural& temp_two = number;
        Natural nod = temp_one.GCF_NN_N(temp_two);
        temp_one.MUL_NN_N(temp_two);
        return temp_one.DIV_NN_N(nod);
    }
private:
    std::vector<short> digits; // массив цифр, цифры записаны в обратном порядке
    
    void zfill(unsigned count) {
        digits.insert(digits.end(), count, 0);
    }
    void clean_zero() {
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
    }
    [[nodiscard]] std::size_t len() const {
        return digits.size();
    }
};

class Integer {
public:
    Integer() 
        : sign(false), number(Natural(0)) {}
    explicit Integer(const std::string& number) {
        if (number.empty())
            Integer(); // вызываем конструктор по умолчанию для пустых строк
        if (number[0] == '-' || number[0] == '+') { // если указан знак
            if (number.size() == 1)
                throw std::invalid_argument("You can't just give us a sign, lol.");
            this->number = Natural(number.substr(1));
            this->sign = this->number.NZER_N_B() && number[0] == '-'; // чтобы не создавать -0.
        }
        else {
            this->number = Natural(number);
            this->sign = false;
        }
    }

    explicit Integer(long long int number) : sign(number < 0), number(Natural(std::abs(number))) {}
    explicit Integer(const Natural& number) : sign(false), number(number) {}
    virtual void putMembers(std::ostream& out) const {
        if (number.NZER_N_B()) {
            if (sign)
                out << "-";
            out << number;
        }
        else
            out << "0";
    }
    virtual std::string toString() const {
        std::ostringstream out;
        putMembers(out);
        return out.str();
    }
    Integer& operator++() {
        this->ADD_ZZ_Z(Integer(1));
        return *this;
    }

    Integer operator++(int) {
        Integer tmp(*this);
        ++(*this);
        return tmp;
    }

    Integer& operator--() {
        this->SUB_ZZ_Z(Integer(1));
        return *this;
    }

    Integer operator--(int) {
        Integer tmp(*this);
        --(*this);
        return tmp;
    }
    friend std::ostream& operator << (std::ostream& out, const Integer& number);
    friend bool operator==(const Integer& number1, const Integer& number2);
    friend bool operator!=(const Integer& number1, const Integer& number2);
    friend bool operator>=(const Integer& number1, const Integer& number2);
    friend bool operator<=(const Integer& number1, const Integer& number2);
    friend bool operator>(const Integer& number1, const Integer& number2);
    friend bool operator<(const Integer& number1, const Integer& number2);

    [[nodiscard]] Integer ABS_Z_Z() const {
        Integer abs = *this;
        abs.sign = false;
        return abs;
    }
    [[nodiscard]] int POZ_Z_D() const {
        if (number.NZER_N_B())
            return this->sign ? 1 : 2;
        else
            return 0;
    }
    void MUL_ZM_Z() {
        if (number.NZER_N_B())
            this->sign = !this->sign;
    }
    static Integer TRANS_N_Z(const Natural& nat) {
        return Integer(nat);
    }
    [[nodiscard]] Natural TRANS_Z_N() const {
        if (!this->sign)
            return this->number;
        else
            throw std::logic_error("Integer must be non-negative");
    }
    void ADD_ZZ_Z(Integer b) {
        if (this->POZ_Z_D() == b.POZ_Z_D()) // this->sign == b.sign
            this->number.ADD_NN_N(b.number);
        else {
            if (this->number.COM_NN_D(b.number) == 2)
                this->number.SUB_NN_N(b.number);

            else {
                this->sign = b.sign;
                b.number.SUB_NN_N(this->number);
                this->number = b.number;
            }
        }
    }
    void MUL_ZZ_Z(const Integer& num) {
        this->number.MUL_NN_N(num.number);
        this->sign = !(this->sign == num.sign || this->POZ_Z_D() == 0 || num.POZ_Z_D() == 0);
    }
    [[nodiscard]] Integer DIV_ZZ_Z(const Integer& divisor) const {
        if (!divisor.number.NZER_N_B())
            throw std::logic_error("The divisor must not be zero!");
        Natural nat = this->number.DIV_NN_N(divisor.number);
        Integer quotient(nat);
        quotient.sign = !(this->sign == divisor.sign || this->POZ_Z_D() == 0);
        // добавляем единицу по модулю, если делимое - отрицательное с остатком от деления, отличным от нуля
        if (this->sign == 1 && this->number.MOD_NN_N(divisor.number).NZER_N_B())
            quotient.number.ADD_1N_N();
        return quotient;
    }
    void SUB_ZZ_Z(Integer b) {
        if (this->sign == b.sign) {
            if (this->number.COM_NN_D(b.number) != 1) { // a>=b
                this->number.SUB_NN_N(b.number);
            }
            else {
                this->sign = !b.sign;
                b.number.SUB_NN_N(this->number);
                this->number = b.number;
            }
        }
        else {
            this->number.ADD_NN_N(b.number);
        }
    }
    [[nodiscard]] Integer MOD_ZZ_Z(const Integer& num) const {
        Natural nat = this->number.MOD_NN_N(num.number);
        Integer remainder(nat);
        // Если делимое отрицательное и остаток отличен от нуля, то остаток равен (делитель - остаток).
        if (this->sign && remainder.number.NZER_N_B()) {
            // (остаток минус делитель) по модулю
            remainder.SUB_ZZ_Z(num.ABS_Z_Z());
            remainder.sign = false;
        }
        return remainder;
    }
private:
    Natural number;
    bool sign;
};

class Rational {
public:

    explicit Rational(const std::string& number) {
        if (number.find('/') == std::string::npos)
        this->denominator = Natural("1");
        else
            this->denominator = Natural(number.substr(number.find('/') + 1));
        this->numerator = Integer(number.substr(0, number.find('/')));
        if (!this->denominator.NZER_N_B())
            throw std::invalid_argument("The denominator cannot be zero.");
    }
    explicit Rational(Integer number) : numerator(std::move(number)), denominator(Natural("1")) {}
    Rational(Integer numerator, const Natural& denominator) : numerator(std::move(numerator)), denominator(denominator) {
        if (!this->denominator.NZER_N_B())
            throw std::invalid_argument("The denominator cannot be zero.");
    }
    Rational() : numerator("0"), denominator("1") {}
    [[nodiscard]] bool is_zero() const { return this->numerator.POZ_Z_D() == 0; }
    [[nodiscard]] bool is_sign() const { return this->numerator.POZ_Z_D() == 1; }
    [[nodiscard]] Integer get_numerator() const { return this->numerator; }
    [[nodiscard]] Natural get_denominator() const { return this->denominator; }

    virtual void putMembers(std::ostream& out) const {
        if (numerator.POZ_Z_D() == 0)
            out << 0;
        else if (denominator.COM_NN_D(Natural(1)) == 0)
            out << numerator;
        else
            out << numerator << "/" << denominator;
    }
    virtual std::string toString() const {
        std::ostringstream out;
        putMembers(out);
        return out.str();
    }

    void RED_Q_Q() {
        Natural GCF = this->denominator.GCF_NN_N(this->numerator.ABS_Z_Z().TRANS_Z_N()); // находим НОД числителя и знаменателя
        this->numerator = this->numerator.DIV_ZZ_Z(Integer(GCF)); // делим числитель на НОД
        this->denominator = this->denominator.DIV_NN_N(GCF); // делим знаменатель на НОД
    }
    [[nodiscard]] bool INT_Q_B() const {
        return this->denominator.COM_NN_D(Natural(1)) == 0; // возвращаем, равен ли знаменатель единице
    }
    static Rational TRANS_Z_Q(const Integer& number) {
        return Rational(number);
    }
    [[nodiscard]] Integer TRANS_Q_Z() const {
        if (!this->INT_Q_B())
            throw std::invalid_argument("The denominator must be 1.");
        return this->numerator; // возвращаем числитель
    }
    [[nodiscard]] Rational INV_Q_Q() const {
        if (this->is_zero())
            return Rational("0");
        Rational inverted = Rational(Integer::TRANS_N_Z(this->denominator), this->numerator.ABS_Z_Z().TRANS_Z_N());
        if (this->is_sign())
            inverted.numerator.MUL_ZM_Z();
        inverted.RED_Q_Q();
        return inverted;
    }
    void ADD_QQ_Q(const Rational& number) {
        Integer this_denominator(this->denominator);// знаменатель 1 дроби
        Integer number_denominator(number.denominator); // знаменатель 2 дроби
        Integer buf_numerator(number.numerator); // числитель 2 дроби
        buf_numerator.MUL_ZZ_Z(this_denominator); // умножаем числитель 2 дроби на знаменатель 1 дроби
        this->numerator.MUL_ZZ_Z(number_denominator);
        this->numerator.ADD_ZZ_Z(buf_numerator); // складываем числители
        this->denominator.MUL_NN_N(number.denominator); // умножаем знаменатели
        this->RED_Q_Q(); // сокращаем дробь
    }
    void SUB_QQ_Q(const Rational& number) {
        Rational buffer(number.numerator); // временная переменная для хранения number
        buffer.denominator = number.denominator;// добавляем знаменатель
        buffer.numerator.MUL_ZM_Z(); // умножаем числитель на -1
        this->ADD_QQ_Q(buffer); // складываем дроби
    }
    void MUL_QQ_Q(const Rational& number) {
        this->numerator.MUL_ZZ_Z(number.numerator);
        this->denominator.MUL_NN_N(number.denominator);
        this->RED_Q_Q(); // сокращаем дробь
    }
    void DIV_QQ_Q(const Rational& number) {
        if (number.numerator.POZ_Z_D() == 0) // Проверка деления на ноль.
            throw std::logic_error("Division by zero.");

        this->MUL_QQ_Q(number.INV_Q_Q()); // Умножаем дробь на обратную.
    }

    friend std::ostream& operator << (std::ostream& out, const Rational& number); // Оператор вывода в поток.
    friend Rational operator+(const Rational& num1, const Rational& num2);
    friend Rational operator-(const Rational& num);
    friend Rational operator-(const Rational& num1, const Rational& num2);
    friend Rational operator*(const Rational& num1, const Rational& num2);
    friend Rational operator/(const Rational& num1, const Rational& num2);
    Rational& operator+=(const Rational& other) {
        *this = *this + other;
        return *this;
    }
    Rational& operator-=(const Rational& other) {
        *this = *this - other;
        return *this;
    }
    Rational& operator*=(const Rational& other) {
        *this = *this * other;
        return *this;
    }
    Rational& operator/=(const Rational& other) {
        *this = *this / other;
        return *this;
    }
    friend bool operator>(const Rational& num1, const Rational& num2);
    friend bool operator<(const Rational& num1, const Rational& num2);
    friend bool operator>=(const Rational& num1, const Rational& num2);
    friend bool operator<=(const Rational& num1, const Rational& num2);
    friend bool operator==(const Rational& num1, const Rational& num2);
    friend bool operator!=(const Rational& num1, const Rational& num2);

private:
    Integer numerator; // числитель
    Natural denominator; // знаменатель
};

class Polynomial {
public:

    explicit Polynomial(const std::string& content) {
        std::string pol(content);

        std::vector<std::string> substr_pol;
        size_t size = 0;

        while (!pol.empty()) {
            size_t index_sub = std::min(pol.find('-', 1), pol.find('+', 1));
            substr_pol.push_back(pol.substr(0, index_sub));

            size_t index_degree = pol.find('^');
            if (index_degree == std::string::npos && pol.find('x') != std::string::npos)
                size = std::max(size, (size_t)1);
            else if (pol.find('^') != std::string::npos)
                size = std::max(size, (size_t)std::stoi(pol.substr(pol.find('^') + 1, index_sub)));

            if (index_sub == std::string::npos)
                pol = "";
            else
                pol = pol.substr(index_sub);
        }

        std::vector<Rational> input_coefficients(size + 1, Rational());
        for (const auto& singelton : substr_pol) {
            size_t index_sub_left = std::min(singelton.find('x'), singelton.find('*'));
            size_t index_sub_right = singelton.find('^');
            Rational coefficient;

            if (index_sub_left == std::string::npos) {
                coefficient = Rational(singelton);
            }
            else
                coefficient = Rational((singelton.substr(0, index_sub_left).empty() || singelton.substr(0, index_sub_left) == "-" || singelton.substr(0, index_sub_left) == "+") ? (singelton.substr(0, index_sub_left) + "1") : singelton.substr(0, index_sub_left));

            if (index_sub_right != std::string::npos)
                input_coefficients[std::stoi(singelton.substr(index_sub_right + 1, singelton.size()))] += coefficient;
            else if (singelton.find('x') == std::string::npos)
                input_coefficients[0] += coefficient;
            else
                input_coefficients[1] += coefficient;

        }
        this->coefficients = std::move(input_coefficients);
        this->clean_zero();
    }
    explicit Polynomial(std::vector<Rational> coefficients) : coefficients(std::move(coefficients)) {
        this->clean_zero();
    }
    Polynomial() : Polynomial({ Rational() }) {}
    virtual void putMembers(std::ostream& out) const {
        bool flag_zero = true;
        for (size_t i = coefficients.size() - 1; i != -1; --i) {
            if (!coefficients[i].is_zero()) {
                flag_zero = false;
                if (i != coefficients.size() - 1)
                    out << (coefficients[i].is_sign() ? "" : "+");
                if (coefficients[i] != Rational("1") && coefficients[i] != Rational("-1") || i == 0)
                    out << coefficients[i];
                if (coefficients[i] == Rational("-1") && i != 0)
                    out << "-";
                if (i > 0) {
                    out << (i == 1 ? "x" : "x^" + std::to_string(i));
                }
            }
        }
        if (flag_zero)
            out << 0;
    }
    virtual std::string toString() const {
        std::ostringstream out;
        putMembers(out);
        return out.str();
    }
    [[nodiscard]] bool is_zero() const {
        return std::ranges::all_of(coefficients.cbegin(), coefficients.cend(), [](auto i) { return i.is_zero(); });
    }
    friend std::ostream& operator << (std::ostream& out, const Polynomial& polynomial); // Оператор вывода в поток.
    friend bool operator==(const Polynomial& first, const Polynomial& second);
    friend bool operator!=(const Polynomial& first, const Polynomial& second);

    void ADD_PP_P(const Polynomial& polynomial) {
        std::size_t i;
        for (i = 0; i < this->coefficients.size() && i < polynomial.coefficients.size(); ++i) // цикл проходящий от 0 до конца this, либо  до конца polynomial в зависимости от размеров
            this->coefficients[i].ADD_QQ_Q(polynomial.coefficients[i]);

        for (;i < polynomial.coefficients.size(); ++i) // на случай если polynomial оказался больше чем this
            this->coefficients.push_back(polynomial.coefficients[i]);

        this->clean_zero();
    }
    void SUB_PP_P(const Polynomial& other) {
        if (!other.is_zero()) {
            for (int i = 0; i <= other.DEG_P_N(); ++i) {
                if (i > this->DEG_P_N())
                    this->coefficients.emplace_back("0");
                this->coefficients[i].SUB_QQ_Q(other.coefficients[i]);
            }
        }
        this->clean_zero();
    }
    void MUL_PQ_P(const Rational& number) {
        if (number.is_zero() || this->is_zero()) { // Что-то равно нулю.
            this->coefficients.clear(); // Очистим коэффициенты.
            this->coefficients.emplace_back("0");
        }
        else { // Можем добавить сравнение number с единицей.
            for (auto& coefficient : coefficients)
                coefficient.MUL_QQ_Q(number); // Сокращение результата отрабатывается в MUL_QQ_Q.
        }
    }
    void MUL_Pxk_P(unsigned long long int k) {
        if (!this->is_zero()) {
            this->coefficients.insert(coefficients.begin(), k, Rational("0"));
        }
    }
    [[nodiscard]] Rational LED_P_Q() const {
        for (auto& coefficient : std::ranges::reverse_view(coefficients)) { // Проходимся с конца массива
            if (!coefficient.is_zero()) // Встретили ненулевой элемент
                return coefficient;
        }
        return Rational("0");
    }
    [[nodiscard]] int DEG_P_N() const {
        int last_index = -1;
        for (auto it = coefficients.rbegin(); it != coefficients.rend(); ++it) { // Проходимся с конца массива
            if (!it->is_zero()) { // Встретили ненулевой элемент
                last_index = int(coefficients.rend() - it - 1); // Определение индекса на основе итератора
                break;
            }
        }
        return last_index; // Если не нашли, то многочлен тождественен нулю, его степень не определена, но мы считаем -1.
    }
    void MUL_PP_P(Polynomial polynomial) {
        if (!polynomial.is_zero()) {
            // Определим многочлен большей степени и будем считать, что многочлен большей степени находится в нашем объекте.
            if (polynomial.DEG_P_N() > DEG_P_N())
                std::swap(this->coefficients, polynomial.coefficients);

            int first_degree = DEG_P_N();
            int second_degree = polynomial.DEG_P_N();

            std::vector<Rational> result(first_degree + second_degree + 1, Rational("0"));

            for (int k = 0; k <= second_degree; ++k) {
                for (int j = 0; j <= k; ++j) {
                    Rational multiply_result(coefficients[j]);
                    multiply_result.MUL_QQ_Q(polynomial.coefficients[k - j]);
                    result[k].ADD_QQ_Q(multiply_result);
                }
            }

            for (int k = second_degree + 1; k <= first_degree; ++k) {
                for (int j = k - second_degree; j <= k; ++j) {
                    Rational multiply_result(coefficients[j]);
                    multiply_result.MUL_QQ_Q(polynomial.coefficients[k - j]);
                    result[k].ADD_QQ_Q(multiply_result);
                }
            }

            for (int k = first_degree + 1; k <= first_degree + second_degree; ++k) {
                for (int j = k - second_degree; j <= first_degree; ++j) {
                    Rational multiply_result(coefficients[j]);
                    multiply_result.MUL_QQ_Q(polynomial.coefficients[k - j]);
                    result[k].ADD_QQ_Q(multiply_result);
                }
            }

            this->coefficients = result;
            clean_zero();
        }
        else {
            this->coefficients.clear();
            this->coefficients.emplace_back("0");
        }
    }
    [[nodiscard]] Polynomial DIV_PP_P(const Polynomial& divisor) const {
        if (divisor.is_zero())
            throw std::invalid_argument("Division by zero");

        Polynomial quotient("0");
        Polynomial remainder(*this);

        int deg_dividend = remainder.DEG_P_N();
        int deg_divisor = divisor.DEG_P_N();

        while (deg_dividend >= deg_divisor) {
            Rational coeff = remainder.LED_P_Q();
            Rational tmp_coeff = divisor.LED_P_Q();
            coeff.DIV_QQ_Q(tmp_coeff);

            int degree_difference = deg_dividend - deg_divisor;

            std::vector<Rational> temp(degree_difference + 1, Rational("0"));
            temp[degree_difference] = coeff;

            Polynomial temp_polynomial(temp);
            quotient.ADD_PP_P(temp_polynomial);

            Polynomial product = divisor;
            product.MUL_Pxk_P(degree_difference);
            product.MUL_PQ_P(coeff);

            remainder.SUB_PP_P(product);

            deg_dividend = remainder.DEG_P_N();
        }

        return std::move(quotient);
    }
    [[nodiscard]] Polynomial MOD_PP_P(const Polynomial& divisor) const {
        if (divisor.is_zero()) {
            throw std::invalid_argument("Division by zero");
        }

        Polynomial remainder(*this);

        int deg_dividend = remainder.DEG_P_N();
        int deg_divisor = divisor.DEG_P_N();

        while (deg_dividend >= deg_divisor) {
            Rational coeff = remainder.LED_P_Q();
            Rational tmp_coeff = divisor.LED_P_Q();
            coeff.DIV_QQ_Q(tmp_coeff);

            int degree_difference = deg_dividend - deg_divisor;

            Polynomial product = divisor;
            product.MUL_Pxk_P(degree_difference);
            product.MUL_PQ_P(coeff);

            remainder.SUB_PP_P(product);

            deg_dividend = remainder.DEG_P_N();
        }

        return std::move(remainder);
    }
    [[nodiscard]] Rational FAC_P_Q() const {
        Natural numerator = LED_P_Q().get_numerator().ABS_Z_Z().TRANS_Z_N();
        Natural denominator = LED_P_Q().get_denominator();

        for (size_t i = 0; i < this->coefficients.size() - 1; ++i) {
            numerator = numerator.GCF_NN_N(this->coefficients[i].get_numerator().ABS_Z_Z().TRANS_Z_N());
            denominator = denominator.LCM_NN_N(this->coefficients[i].get_denominator());
        }

        return { Integer::TRANS_N_Z(numerator), denominator };
    }
    [[nodiscard]] Polynomial GCF_PP_P(const Polynomial& polynomial) const {
        Polynomial dividend = *this; // делимое
        Polynomial divisor = polynomial; // делитель
        Rational multiplier;
        while (dividend.DEG_P_N() != -1 && divisor.DEG_P_N() != -1) {
            Polynomial tmp = divisor;
            divisor = dividend.MOD_PP_P(divisor);
            dividend = tmp;
        }
        Polynomial result = divisor.DEG_P_N() > dividend.DEG_P_N() ? divisor : dividend;
        result.clean_zero();
        multiplier = result.FAC_P_Q();
        if (result.LED_P_Q().is_sign()) // Поменяем знаки у многочлена, если старший коэффициент отрицательный.
            multiplier.MUL_QQ_Q(Rational("-1"));
        result.MUL_PQ_P(multiplier.INV_Q_Q());
        return result;
    }
    [[nodiscard]] Polynomial DEP_P_P() const {
        std::vector<Rational> new_coefficients(this->DEG_P_N() > 0 ? this->DEG_P_N() : 1); // Коэффициенты производного многочлена.
        for (int i = 1; i <= this->DEG_P_N(); ++i) { // Цикл, проходящий по всем индексам вектора коэффициентов многочлена.
            new_coefficients[i - 1] = this->coefficients[i];
            new_coefficients[i - 1].MUL_QQ_Q(Rational(std::to_string(i))); // Умножаем текущий коэффициент на значение позиции в векторе, т.е. на степень.
        }
        return Polynomial(new_coefficients);
    }
    [[nodiscard]] Polynomial NMR_P_P() const { return std::move(this->DIV_PP_P(this->GCF_PP_P(this->DEP_P_P()))); }

    friend Polynomial operator+(const Polynomial& first, const Polynomial& second);
    friend Polynomial operator-(const Polynomial& first, const Polynomial& second);
    friend Polynomial operator*(const Polynomial& first, const Polynomial& second);
    friend Polynomial operator/(const Polynomial& first, const Polynomial& second);
    friend Polynomial operator%(const Polynomial& first, const Polynomial& second);

    Polynomial& operator+=(const Polynomial& other) {
        this->ADD_PP_P(other);
        return *this;
    }
    Polynomial& operator-=(const Polynomial& other) {
        this->SUB_PP_P(other);
        return *this;
    }
    Polynomial& operator*=(const Polynomial& other) {
        this->MUL_PP_P(other);
        return *this;
    }

    Polynomial& operator/=(const Polynomial& other) {
        *this = this->DIV_PP_P(other);
        return *this;
    }
    Polynomial& operator%=(const Polynomial& other) {
        *this = this->MOD_PP_P(other);
        return *this;
    }


private:
    std::vector<Rational> coefficients; // вектор, хранящий рациональные коэффициенты, индекс - степень члена
    void clean_zero() {
        while (coefficients.size() > 1 && coefficients.back().is_zero())
            coefficients.pop_back();
    }
};

std::ostream& operator << (std::ostream& out, const Polynomial& polynomial) {
    bool flag_zero = true;
    for (size_t i = polynomial.coefficients.size() - 1; i != -1; --i) {
        if (!polynomial.coefficients[i].is_zero()) {
            flag_zero = false;
            if (i != polynomial.coefficients.size() - 1)
                out << (polynomial.coefficients[i].is_sign() ? "" : "+");
            if (polynomial.coefficients[i] != Rational("1") && polynomial.coefficients[i] != Rational("-1") || i == 0)
                out << polynomial.coefficients[i];
            if (polynomial.coefficients[i] == Rational("-1") && i != 0)
                out << "-";
            if (i > 0) {
                out << (i == 1 ? "x" : "x^" + std::to_string(i));
            }
        }
    }
    if (flag_zero)
        out << 0;
    return out;
}

bool operator==(const Polynomial& first, const Polynomial& second) {
    Polynomial a = first;
    Polynomial b = second;
    a.clean_zero();
    b.clean_zero();
    return a.coefficients == b.coefficients;
}

bool operator!=(const Polynomial& first, const Polynomial& second) {
    return !(first == second);
}

Polynomial operator+(const Polynomial& first, const Polynomial& second) {
    Polynomial new_polynom(first);
    new_polynom.ADD_PP_P(second);
    return std::move(new_polynom);
}

Polynomial operator-(const Polynomial& first, const Polynomial& second) {
    Polynomial new_polynom(first);
    new_polynom.SUB_PP_P(second);
    return std::move(new_polynom);
}

Polynomial operator*(const Polynomial& first, const Polynomial& second) {
    Polynomial new_polynom(first);
    new_polynom.MUL_PP_P(second);
    return std::move(new_polynom);
}

Polynomial operator/(const Polynomial& first, const Polynomial& second) { return std::move(first.DIV_PP_P(second)); }

Polynomial operator%(const Polynomial& first, const Polynomial& second) { return std::move(first.MOD_PP_P(second)); }

std::ostream& operator << (std::ostream& out, const Rational& number) {
    if (number.is_zero())
        out << 0;
    else if (number.denominator.COM_NN_D(Natural(1)) == 0)
        out << number.numerator;
    else
        out << number.numerator << "/" << number.denominator;
    return out;
}

Rational operator+(const Rational& num1, const Rational& num2) {
    Rational new_rational(num2);
    new_rational.ADD_QQ_Q(num1);
    return std::move(new_rational);
}

Rational operator-(const Rational& num) {
    Rational new_rational(num);
    new_rational.numerator.MUL_ZM_Z();
    return std::move(new_rational);
}

Rational operator-(const Rational& num1, const Rational& num2) { return num1 + (-num2); }

Rational operator*(const Rational& num1, const Rational& num2) {
    Rational new_rational(num2);
    new_rational.MUL_QQ_Q(num1);
    return std::move(new_rational);
}

Rational operator/(const Rational& num1, const Rational& num2) {
    Rational new_rational(num1);
    new_rational.DIV_QQ_Q(num2);
    return std::move(new_rational);
}

bool operator>(const Rational& num1, const Rational& num2) {
    if (num1.numerator.POZ_Z_D() != num2.numerator.POZ_Z_D()) {
        if (num1.numerator.POZ_Z_D() == 2 && num2.numerator.POZ_Z_D() != 2)
            return true;
        if (num1.numerator.POZ_Z_D() == 0 && num2.numerator.POZ_Z_D() == 1)
            return true;
        return false;
    }

    Natural this_val(num1.numerator.ABS_Z_Z().TRANS_Z_N());
    Natural other_val(num2.numerator.ABS_Z_Z().TRANS_Z_N());
    this_val.MUL_NN_N(num2.denominator);
    other_val.MUL_NN_N(num1.denominator);
    return this_val.COM_NN_D(other_val) == 2;
}

bool operator<(const Rational& num1, const Rational& num2) {
    if (num1.numerator.POZ_Z_D() != num2.numerator.POZ_Z_D()) {
        if (num1.numerator.POZ_Z_D() == 1 && num2.numerator.POZ_Z_D() != 1)
            return true;
        if (num1.numerator.POZ_Z_D() == 0 && num2.numerator.POZ_Z_D() == 2)
            return true;
        return false;
    }

    Natural this_val(num1.numerator.ABS_Z_Z().TRANS_Z_N());
    Natural other_val(num2.numerator.ABS_Z_Z().TRANS_Z_N());
    this_val.MUL_NN_N(num2.denominator);
    other_val.MUL_NN_N(num1.denominator);
    return this_val.COM_NN_D(other_val) == 1;
}

bool operator>=(const Rational& num1, const Rational& num2) { return !(num1 < num2); }

bool operator<=(const Rational& num1, const Rational& num2) { return !(num1 > num2); }

bool operator==(const Rational& num1, const Rational& num2) {
    if (num1.numerator.POZ_Z_D() != num2.numerator.POZ_Z_D())
        return false;

    if (num1.denominator.COM_NN_D(num2.denominator))
        return false;

    if (num1.numerator.ABS_Z_Z().TRANS_Z_N().COM_NN_D(num2.numerator.ABS_Z_Z().TRANS_Z_N()))
        return false;

    return true;
}

bool operator!=(const Rational& num1, const Rational& num2) { return !(num1 == num2); }

std::ostream& operator << (std::ostream& out, const Integer& object) {
    if (object.number.NZER_N_B()) {
        if (object.sign)
            out << "-";
        out << object.number;
    }
    else
        out << "0";
    return out;
}

bool operator==(const Integer& number1, const Integer& number2) {
    return ((number1.number.COM_NN_D(number2.number) == 0) && (number1.sign == number2.sign));
}

bool operator!=(const Integer& number1, const Integer& number2) {
    return (number1.number.COM_NN_D(number2.number) != 0 || number1.sign != number2.sign);
}

bool operator>(const Integer& number1, const Integer& number2) {
    Integer tmp(number1);
    tmp.SUB_ZZ_Z(number2);
    return (!tmp.sign);
}
bool operator<(const Integer& number1, const Integer& number2) {
    return (!(number1 > number2) && !(number1 == number2));
}

bool operator>=(const Integer& number1, const Integer& number2) {
    return ((number1 > number2) || (number1 == number2));
}

bool operator<=(const Integer& number1, const Integer& number2) {
    return (!(number1 > number2) || (number1 == number2));
}

bool operator==(const Natural& number1, const Natural& number2) {
    return (number1.COM_NN_D(number2) == 0);
}

bool operator!=(const Natural& number1, const Natural& number2) {
    return (number1.COM_NN_D(number2) != 0);
}

bool operator>(const Natural& number1, const Natural& number2) {
    return (number1.COM_NN_D(number2) == 2);
}

bool operator<(const Natural& number1, const Natural& number2) {
    return (number1.COM_NN_D(number2) == 1);
}

bool operator>=(const Natural& number1, const Natural& number2) {
    return (number1 > number2 || number1 == number2);
}
bool operator<=(const Natural& number1, const Natural& number2) {
    return (number1 < number2 || number1 == number2);
}

PYBIND11_MODULE(pybind11module, m) {
	m.doc() = "PyBindModule";

    py::class_<Natural>(m, "Natural")
        .def(py::init<const std::string&>())
        .def(py::init<long long int>())
        .def(py::init<>())
        .def("__repr__", [](const Natural& n) {
            return n.toString();
        })
        .def("__str__", [](const Natural& n) {
            return n.toString();
        })
        .def("MUL_NN_N", &Natural::MUL_NN_N)
        .def("MUL_Nk_N", &Natural::MUL_Nk_N)
        .def("DIV_NN_Dk", &Natural::DIV_NN_Dk)
        .def("ADD_1N_N", &Natural::ADD_1N_N)
        .def("ADD_NN_N", &Natural::ADD_NN_N)
        .def("COM_NN_D", &Natural::COM_NN_D)
        .def("NZER_N_B", &Natural::NZER_N_B)
        .def("SUB_NN_N", &Natural::SUB_NN_N)
        .def("MUL_ND_N", &Natural::MUL_ND_N)
        .def("SUB_NDN_N", &Natural::SUB_NDN_N)
        .def("DIV_NN_N", &Natural::DIV_NN_N)
        .def("MOD_NN_N", &Natural::MOD_NN_N)
        .def("GCF_NN_N", &Natural::GCF_NN_N)
        .def("LCM_NN_N", &Natural::LCM_NN_N);
    py::class_<Integer>(m, "Integer")
        .def(py::init<const std::string&>())
        .def(py::init<long long int>())
        .def(py::init<const Natural&>())
        .def(py::init<>())
        .def("__repr__", [](const Integer& n) {
            return n.toString();
        })
        .def("__str__", [](const Integer& n) {
            return n.toString();
        })
        .def("ABS_Z_Z", &Integer::ABS_Z_Z)
        .def("POZ_Z_D", &Integer::POZ_Z_D)
        .def("MUL_ZM_Z", &Integer::MUL_ZM_Z)
        .def("TRANS_N_Z", &Integer::TRANS_N_Z)
        .def("TRANS_Z_N", &Integer::TRANS_Z_N)
        .def("ADD_ZZ_Z", &Integer::ADD_ZZ_Z)
        .def("MUL_ZZ_Z", &Integer::MUL_ZZ_Z)
        .def("DIV_ZZ_Z", &Integer::DIV_ZZ_Z)
        .def("SUB_ZZ_Z", &Integer::SUB_ZZ_Z)
        .def("MOD_ZZ_Z", &Integer::MOD_ZZ_Z);
    py::class_<Rational>(m, "Rational")
        .def(py::init<const std::string&>())
        .def(py::init<Integer>())
        .def(py::init<Integer, const Natural&>())
        .def(py::init<>())
        .def("__repr__", [](const Rational& n) {
            return n.toString();
        })
        .def("__str__", [](const Rational& n) {
            return n.toString();
        })
        .def("RED_Q_Q", &Rational::RED_Q_Q)
        .def("INV_Q_Q", &Rational::INV_Q_Q)
        .def("ADD_QQ_Q", &Rational::ADD_QQ_Q)
        .def("SUB_QQ_Q", &Rational::SUB_QQ_Q)
        .def("MUL_QQ_Q", &Rational::MUL_QQ_Q)
        .def("DIV_QQ_Q", &Rational::DIV_QQ_Q);
    py::class_<Polynomial>(m, "Polynomial")
        .def(py::init<const std::string&>())
        .def(py::init<std::vector<Rational>>())
        .def(py::init<>())
        .def("__repr__", [](const Polynomial& n) {
            return n.toString();
        })
        .def("__str__", [](const Polynomial& n) {
                return n.toString();
        })
        .def("ADD_PP_P", &Polynomial::ADD_PP_P)
        .def("SUB_PP_P", &Polynomial::SUB_PP_P)
        .def("MUL_PQ_P", &Polynomial::MUL_PQ_P)
        .def("MUL_Pxk_P", &Polynomial::MUL_Pxk_P)
        .def("LED_P_Q", &Polynomial::LED_P_Q)
        .def("DEG_P_N", &Polynomial::DEG_P_N)
        .def("MUL_PP_P", &Polynomial::MUL_PP_P)
        .def("DIV_PP_P", &Polynomial::DIV_PP_P)
        .def("MOD_PP_P", &Polynomial::MOD_PP_P)
        .def("FAC_P_Q", &Polynomial::FAC_P_Q)
        .def("GCF_PP_P", &Polynomial::GCF_PP_P)
        .def("DEP_P_P", &Polynomial::DEP_P_P)
        .def("NMR_P_P", &Polynomial::NMR_P_P);
}
