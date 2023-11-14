# Created by Ulyanova Ekaterina (2382) on 14.11.2023.
# GUI.

import sys
import pybind11module
from PyQt6.QtCore import Qt
from PyQt6.QtGui import QAction
from PyQt6.QtWidgets import QApplication, QTextEdit, QVBoxLayout, QLabel, QStackedLayout, QLineEdit, QGridLayout, \
    QWidget, QMainWindow, QPushButton

DISPLAY_HEIGHT = 35
BUTTON_SIZE = 40
ERROR_MSG = "ERROR"


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Система компьютерной алгебры")
        self.resize(235, 235)
        self.centralWidget = QLabel("Для начала работы ознакомьтесь с инструкцией или выберите тип")
        self.centralWidget.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.layout = QVBoxLayout()
        self.stackedLayout = QStackedLayout()
        self.stackedLayout.addWidget(self.centralWidget)

        self._create_actions()
        self._create_menu_bar()
        self._connect_actions()

        self.page1 = QWidget()
        self.page1Layout = QVBoxLayout()
        self._createDisplay()
        self._createButtons()
        self.page1.setLayout(self.page1Layout)
        self.stackedLayout.addWidget(self.page1)

        self.page2 = QWidget()
        self.page2Layout = QVBoxLayout()
        self._createDisplayZ()
        self._createButtonsZ()
        self.page2.setLayout(self.page2Layout)
        self.stackedLayout.addWidget(self.page2)

        self.page3 = QWidget()
        self.page3Layout = QVBoxLayout()
        self._createDisplayR()
        self._createButtonsR()
        self.page3.setLayout(self.page3Layout)
        self.stackedLayout.addWidget(self.page3)

        self.page4 = QWidget()
        self.page4Layout = QVBoxLayout()
        self._createDisplayP()
        self._createButtonsP()
        self.page4.setLayout(self.page4Layout)
        self.stackedLayout.addWidget(self.page4)

        self.page5 = QWidget()
        self.page5Layout = QVBoxLayout()
        self.textEditN = QTextEdit()
        self.textEditN.setReadOnly(True)
        self.textEditN.setPlainText(
            "COM_NN_D - сравнение двух натуральных чисел. Для проверки введите 'n1Vn2' и нажмите '=' или клавишу enter, на экране появится верное равенство\n\n"
            "ADD_1N_N - добавление 1 к натуральному числу. Введите число и нажмите '+1', число на экране увеличится на 1\n\n"
            "ADD_NN_N - сложение натуральных чисел. Введите 'n1+n2', нажмите '=' или клавишу enter, на экране появится результат\n\n"
            "SUB_NN_N - вычитание из первого большего натурального числа второго меньшего или равного. Введите 'n1-n2', нажмите '=' или клавишу enter, на экране появится результат\n\n"
            "MUL_ND_N и MUL_NN_N - умножение на цифру и на натуральное число. Введите 'n1*n2' и нажмите'='\n\n"
            "MUL_Nk_N - умножение натурального числа на степень 10. Введите число, нажмите '0xk', после появившейся на экране 'e' введите степень 10 и нажмите '=' или клавишу enter\n\n"
            "SUB_NDN_N - вычисление выражения вида 'n1-k*n2'. Введите выражение в заданном виде, где k - цифра, и нажмите '-k*n'\n\n"
            "DIV_NN_N - нахождение неполного частного от деления. Введите 'n1/n2' и нажмите '=' или клавишу enter\n\n"
            "MOD_NN_N - нахождение остатка от деления. Введите 'n1%n2' и нажмите '=' или клавишу enter\n\n"
            "GCF_NN_N - НОД натуральных чисел. Введите 'n1;n2' и нажмите 'НОД'\n\n"
            "LCM_NN_N - НОК натуральных чисел. Введите 'n1;n2' и нажмите 'НОК'")
        self.page5Layout.addWidget(self.textEditN)
        self.page5.setLayout(self.page5Layout)
        self.stackedLayout.addWidget(self.page5)

        self.page6 = QWidget()
        self.page6Layout = QVBoxLayout()
        self.textEditI = QTextEdit()
        self.textEditI.setReadOnly(True)
        self.textEditI.setPlainText("ABS_Z_Z - абсолютная величина числа. Введите число и нажмите '| |'\n\n"
                                    "MUL_ZM_Z - умножение целого на -1. Введите число и нажмите '(-1)'\n\n"
                                    "ADD_ZZ_Z - сложение целых чисел. Введите 'z1+z2' и нажмите '=' или клавишу enter\n\n"
                                    "SUB_ZZ_Z - вычитание целых чиселю Введите 'z1-z2' и нажмите '=' или клавишу enter\n\n"
                                    "MULL_ZZ_Z - умножение целых чисел. Введите 'z1*z2' и нажмите '=' или клавишу enter\n\n"
                                    "DIV_ZZ_Z - частное от деления целых чисел. Введите 'z1/z2' и нажмите '=' или клавишу enter\n\n"
                                    "MOD_ZZ_Z - остаток от деления целого на целое. Введите 'z1%z2' и нажмите '=' или клавишу enter\n\n")
        self.page6Layout.addWidget(self.textEditI)
        self.page6.setLayout(self.page6Layout)
        self.stackedLayout.addWidget(self.page6)

        self.page7 = QWidget()
        self.page7Layout = QVBoxLayout()
        self.textEditR = QTextEdit()
        self.textEditR.setReadOnly(True)
        self.textEditR.setPlainText(
            "Числитель и знаменатель рациональных чисел вводятся через '/'. Далее r = z/n - обозначение дроби\n\n"
            "RED_Q_Q -сокращение дроби. Введите дробь и нажмите 'red'\n\n"
            "INV_Q_Q - переворачивание дроби. Введите дробь и нажмите 'inv'\n\n"
            "ADD_QQ_Q - сложение дробей. Введите 'r1+r2' и нажмите '=' или клавишу enter\n\n"
            "SUB_QQ_Q - вычитание дробей. Введите 'r1-r2' и нажмите '=' или клавишу enter\n\n"
            "MUL_QQ_Q - умножение дробей. Введите 'r1*r2' и нажмите '=' или клавишу enter\n\n"
            "DIV_QQ_Q - деление дробей. Введите 'r1:r2' и нажмите '=' или клавишу enter")
        self.page7Layout.addWidget(self.textEditR)
        self.page7.setLayout(self.page7Layout)
        self.stackedLayout.addWidget(self.page7)

        self.page8 = QWidget()
        self.page8Layout = QVBoxLayout()
        self.textEditP = QTextEdit()
        self.textEditP.setReadOnly(True)
        self.textEditP.setPlainText("Пример ввода многочлена: '43x^6-76x+x-2'. Далее p - обозначение многочлена\n\n"
                                    "ADD_PP_P - сложение многочленов. Введите 'p1;p2' и нажмите 'ADD'\n\n"
                                    "SUB_PP_P - вычитание многочленов. Введите 'p1;p2' и нажмите 'SUB'\n\n"
                                    "MUL_PQ_P и MUL_PP_P - умножение многочлена на рациональное число и умножение многочленов соответственно. Введите 'r;p' или 'p;r' или 'p1;p2' и нажмите '*' или введите этот символ с клавиатуры\n\n"
                                    "DEP_P_P - производная многочлена. Введите многочлен и нажмите 'd/dx'\n\n"
                                    "GCF_PP_P - НОД многочленов. Введите 'p1;p2' и нажмите 'НОД'\n\n"
                                    "FAC_P_Q - вынесение из многочлена НОК знаменателей и НОД числителей коэффициентов. Введите многочлен и нажмите 'FAC'\n\n"
                                    "Следующую функцию рекомендуется использовать тогда, когда точно известно о наличие корней, иначе вычисления займут слишком много времени\n\n"
                                    "NMR_P_P - преобразование многочлена - кратные корни в простые. Введуте многочлен и нажмите 'NMR'\n\n"
                                    "В следующих функциях не допускается разница старших степеней многочленов более, чем на 50, это связано с возможной временной задержкой и ограничением на количество символов вывода, но данные функции работают и для многочленов, разница степеней которых больше\n\n"
                                    "DIV_PP_P - частное от деления с остатком многочлена на многочлен. Введите 'p1;p2' и нажмите ':'\n\n"
                                    "MOD_PP_P - остаток от деления многочлена на многочлен при делении с остатком. Введите 'p1;p2' и нажмите '%'\n\n")
        self.page8Layout.addWidget(self.textEditP)
        self.page8.setLayout(self.page8Layout)
        self.stackedLayout.addWidget(self.page8)

        widget = QWidget()
        widget.setLayout(self.layout)
        self.layout.addLayout(self.stackedLayout)
        self.setCentralWidget(widget)

    def _createDisplay(self):
        self.display = QLineEdit()
        self.display.setFixedHeight(DISPLAY_HEIGHT)
        self.display.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.display.setReadOnly(True)
        self.page1Layout.addWidget(self.display)

    def _createDisplayZ(self):
        self.z_display = QLineEdit()
        self.z_display.setFixedHeight(DISPLAY_HEIGHT)
        self.z_display.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.z_display.setReadOnly(True)
        self.page2Layout.addWidget(self.z_display)

    def _createDisplayR(self):
        self.r_display = QLineEdit()
        self.r_display.setFixedHeight(DISPLAY_HEIGHT)
        self.r_display.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.r_display.setReadOnly(True)
        self.page3Layout.addWidget(self.r_display)

    def _createDisplayP(self):
        self.p_display = QLineEdit()
        self.p_display.setFixedHeight(DISPLAY_HEIGHT)
        self.p_display.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.p_display.setReadOnly(True)
        self.page4Layout.addWidget(self.p_display)

    def _createButtons(self):
        self.buttonMap = {}
        buttonsLayout = QGridLayout()
        keyBoard = [
            ["7", "8", "9", "+", "+1", ";"],
            ["4", "5", "6", "-", "%", "0"],
            ["1", "2", "3", "*", "НОД"],
            ["0xk", "-k*n", "V", "/", "НОК"],
        ]
        for row, keys in enumerate(keyBoard):
            for col, key in enumerate(keys):
                self.buttonMap[key] = QPushButton(key)
                self.buttonMap[key].setFixedSize(BUTTON_SIZE, BUTTON_SIZE)
                if key in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0", ";", "+", "-", "*", "/", "%"]:
                    self.buttonMap[key].setShortcut(key)
                if key == '-k*n':
                    self.buttonMap[key].clicked.connect(self.sub_ndn)
                elif key == '+1':
                    self.buttonMap[key].clicked.connect(self.add_one)
                elif key == 'НОД':
                    self.buttonMap[key].clicked.connect(self.gcf_nn)
                elif key == 'НОК':
                    self.buttonMap[key].clicked.connect(self.lsm_nn)
                else:
                    self.buttonMap[key].clicked.connect(lambda x, text=key: self.setDisplayText(text))
                buttonsLayout.addWidget(self.buttonMap[key], row, col)
        self.eq_button = QPushButton("=")
        self.eq_button.setFixedSize(BUTTON_SIZE, BUTTON_SIZE)
        self.eq_button.setShortcut('Return')
        self.eq_button.clicked.connect(self.evaluate)
        self.clear_button = QPushButton("C")
        self.clear_button.setFixedSize(BUTTON_SIZE, BUTTON_SIZE)
        self.clear_button.clicked.connect(self.clearDisplay)
        self.clear_button.setShortcut("Del")
        buttonsLayout.addWidget(self.eq_button, 2, 5)
        buttonsLayout.addWidget(self.clear_button, 3, 5)
        self.page1Layout.addLayout(buttonsLayout)

    def _createButtonsZ(self):
        self.buttonMapZ = {}
        buttonsLayoutZ = QGridLayout()
        keyBoardZ = [
            ["7", "8", "9", "+", "%"],
            ["4", "5", "6", "-"],
            ["1", "2", "3", "*"],
            ["0", "| |", "(-1)", "/"],
        ]
        for row, keys in enumerate(keyBoardZ):
            for col, key in enumerate(keys):
                self.buttonMapZ[key] = QPushButton(key)
                self.buttonMapZ[key].setFixedSize(BUTTON_SIZE, BUTTON_SIZE)
                if key in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "+", "-", "*", "/", "%"]:
                    self.buttonMapZ[key].setShortcut(key)
                if key == '| |':
                    self.buttonMapZ[key].clicked.connect(self.abs_zz)
                elif key == '(-1)':
                    self.buttonMapZ[key].clicked.connect(self.mul_zm)
                else:
                    self.buttonMapZ[key].clicked.connect(lambda x, text=key: self.setDisplayTextZ(text))
                buttonsLayoutZ.addWidget(self.buttonMapZ[key], row, col)
        self.eq_button_z = QPushButton("=")
        self.eq_button_z.setFixedSize(BUTTON_SIZE, 2 * BUTTON_SIZE)
        self.eq_button_z.setShortcut('Return')
        self.eq_button_z.clicked.connect(self.evaluate_z)
        self.clear_button_z = QPushButton("C")
        self.clear_button_z.setFixedSize(BUTTON_SIZE, BUTTON_SIZE)
        self.clear_button_z.clicked.connect(self.clearDisplayZ)
        self.clear_button_z.setShortcut("Del")
        buttonsLayoutZ.addWidget(self.eq_button_z, 2, 4, 2, 1)
        buttonsLayoutZ.addWidget(self.clear_button_z, 1, 4)
        self.page2Layout.addLayout(buttonsLayoutZ)

    def _createButtonsR(self):
        self.buttonMapR = {}
        buttonsLayoutR = QGridLayout()
        keyBoardR = [
            ["7", "8", "9", "+", "inv"],
            ["4", "5", "6", "-"],
            ["1", "2", "3", "*"],
            ["0", "/", "red", ":"],
        ]
        for row, keys in enumerate(keyBoardR):
            for col, key in enumerate(keys):
                self.buttonMapR[key] = QPushButton(key)
                self.buttonMapR[key].setFixedSize(BUTTON_SIZE, BUTTON_SIZE)
                if key in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "+", "-", "*", "/", ":"]:
                    self.buttonMapR[key].setShortcut(key)
                if key == 'inv':
                    self.buttonMapR[key].clicked.connect(self.inv_r)
                elif key == 'red':
                    self.buttonMapR[key].clicked.connect(self.red_r)
                else:
                    self.buttonMapR[key].clicked.connect(lambda x, text=key: self.setDisplayTextR(text))
                buttonsLayoutR.addWidget(self.buttonMapR[key], row, col)
        self.eq_button_r = QPushButton("=")
        self.eq_button_r.setFixedSize(BUTTON_SIZE, 2 * BUTTON_SIZE)
        self.eq_button_r.setShortcut('Return')
        self.eq_button_r.clicked.connect(self.evaluate_r)
        self.clear_button_r = QPushButton("C")
        self.clear_button_r.setFixedSize(BUTTON_SIZE, BUTTON_SIZE)
        self.clear_button_r.clicked.connect(self.clearDisplayR)
        self.clear_button_r.setShortcut("Del")
        buttonsLayoutR.addWidget(self.eq_button_r, 2, 4, 2, 1)
        buttonsLayoutR.addWidget(self.clear_button_r, 1, 4)
        self.page3Layout.addLayout(buttonsLayoutR)

    def _createButtonsP(self):
        self.buttonMapP = {}
        buttonsLayoutP = QGridLayout()
        keyBoardP = [
            ["7", "8", "9", "+", "%", "NMR"],
            ["4", "5", "6", "-", "^", "d/dx"],
            ["1", "2", "3", "*", "x", ":"],
            ["0", "НОД", "FAC", "/", ";"],
        ]
        for row, keys in enumerate(keyBoardP):
            for col, key in enumerate(keys):
                self.buttonMapP[key] = QPushButton(key)
                self.buttonMapP[key].setFixedSize(BUTTON_SIZE, BUTTON_SIZE)
                if key in ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0", ";", "+", "-", "*", "/", "%", ":", "x",
                           "^"]:
                    self.buttonMapP[key].setShortcut(key)
                if key == 'd/dx':
                    self.buttonMapP[key].clicked.connect(self.dep_p)
                elif key == 'FAC':
                    self.buttonMapP[key].clicked.connect(self.fac_p)
                elif key == 'НОД':
                    self.buttonMapP[key].clicked.connect(self.gcf_p)
                elif key == 'NMR':
                    self.buttonMapP[key].clicked.connect(self.nmr_p)
                elif key == '*':
                    self.buttonMapP[key].clicked.connect(self.mul_p)
                elif key == ':':
                    self.buttonMapP[key].clicked.connect(self.div_p)
                elif key == '%':
                    self.buttonMapP[key].clicked.connect(self.mod_p)
                else:
                    self.buttonMapP[key].clicked.connect(lambda x, text=key: self.setDisplayTextP(text))
                buttonsLayoutP.addWidget(self.buttonMapP[key], row, col)
        self.p_clear_button = QPushButton("C")
        self.p_clear_button.setFixedSize(BUTTON_SIZE, BUTTON_SIZE)
        self.p_clear_button.clicked.connect(self.clearDisplayP)
        self.p_clear_button.setShortcut("Del")
        self.add_button = QPushButton("ADD")
        self.add_button.setFixedSize(BUTTON_SIZE, 2 * BUTTON_SIZE)
        self.add_button.clicked.connect(self.add_p)
        buttonsLayoutP.addWidget(self.add_button, 0, 6, 2, 1)
        self.sub_button = QPushButton("SUB")
        self.sub_button.setFixedSize(BUTTON_SIZE, 2 * BUTTON_SIZE)
        self.sub_button.clicked.connect(self.sub_p)
        buttonsLayoutP.addWidget(self.sub_button, 2, 6, 2, 1)
        buttonsLayoutP.addWidget(self.p_clear_button, 3, 5)
        self.page4Layout.addLayout(buttonsLayoutP)

    def setDisplayText(self, text):
        if text == "":
            self.display.setText("")
        elif text == "0xk":
            self.display.setText(self.display.text() + "e")
        else:
            self.display.setText(self.display.text() + text)
        self.display.setFocus()

    def setDisplayTextZ(self, text):
        if text == "":
            self.z_display.setText("")
        else:
            self.z_display.setText(self.z_display.text() + text)
        self.z_display.setFocus()

    def setDisplayTextR(self, text):
        if text == "":
            self.r_display.setText("")
        else:
            self.r_display.setText(self.r_display.text() + text)
        self.r_display.setFocus()

    def setDisplayTextP(self, text):
        if text == "":
            self.p_display.setText("")
        else:
            self.p_display.setText(self.p_display.text() + text)
        self.p_display.setFocus()

    def add_one(self):
        try:
            n = pybind11module.Natural(self.display.text())
            self.clearDisplay()
            n.ADD_1N_N()
            self.setDisplayText(str(n))
        except:
            self.clearDisplay()
            self.setDisplayText(ERROR_MSG)

    def gcf_nn(self):
        try:
            nums = self.display.text().split(";")
            n = pybind11module.Natural(nums[0])
            n1 = pybind11module.Natural(nums[1])
            n2 = n.GCF_NN_N(n1)
            self.clearDisplay()
            self.setDisplayText(str(n2))
        except:
            self.clearDisplay()
            self.setDisplayText(ERROR_MSG)

    def lsm_nn(self):
        try:
            nums = self.display.text().split(";")
            n = pybind11module.Natural(nums[0])
            n1 = pybind11module.Natural(nums[1])
            n2 = n.LCM_NN_N(n1)
            self.clearDisplay()
            self.setDisplayText(str(n2))
        except:
            self.clearDisplay()
            self.setDisplayText(ERROR_MSG)

    def com_nn(self):
        try:
            nums = self.display.text().split("V")
            n = pybind11module.Natural(nums[0])
            n1 = pybind11module.Natural(nums[1])
            res = n.COM_NN_D(n1)
            if res == 0:
                str = self.display.text().replace('V', '=')
            elif res == 1:
                str = self.display.text().replace('V', '<')
            elif res == 2:
                str = self.display.text().replace('V', '>')
            self.clearDisplay()
            self.setDisplayText(str)
        except ValueError:
            self.clearDisplay()
            self.setDisplayText(ERROR_MSG)

    def mul_n(self):
        try:
            nums = self.display.text().split("*")
            n = pybind11module.Natural(nums[0])
            if '-' in nums[1]:
                self.clearDisplay()
                self.setDisplayText(ERROR_MSG)
            elif len(nums[1]) == 1:
                n.MUL_ND_N(int(nums[1]))
                self.clearDisplay()
                self.setDisplayText(str(n))
            else:
                n1 = pybind11module.Natural(nums[1])
                n.MUL_NN_N(n1)
                self.clearDisplay()
                self.setDisplayText(str(n))
        except ValueError:
            self.clearDisplay()
            self.setDisplayText(ERROR_MSG)

    def sub_ndn(self):
        try:
            nums = self.display.text().split("-")
            n = pybind11module.Natural(nums[0])
            subs = nums[1].split("*")
            n1 = pybind11module.Natural(subs[0])
            k = int(subs[1])
            n.SUB_NDN_N(n1, k)
            self.clearDisplay()
            self.setDisplayText(str(n))
        except:
            self.clearDisplay()
            self.setDisplayText(ERROR_MSG)

    def add_n(self):
        try:
            nums = self.display.text().split("+")
            n = pybind11module.Natural(nums[0])
            n1 = pybind11module.Natural(nums[1])
            n.ADD_NN_N(n1)
            self.clearDisplay()
            self.setDisplayText(str(n))
        except:
            self.clearDisplay()
            self.setDisplayText(ERROR_MSG)

    def div_n(self):
        try:
            nums = self.display.text().split("/")
            n = pybind11module.Natural(nums[0])
            n1 = pybind11module.Natural(nums[1])
            n2 = n.DIV_NN_N(n1)
            self.clearDisplay()
            self.setDisplayText(str(n2))
        except:
            self.clearDisplay()
            self.setDisplayText(ERROR_MSG)

    def mod_n(self):
        try:
            nums = self.display.text().split("%")
            n = pybind11module.Natural(nums[0])
            n1 = pybind11module.Natural(nums[1])
            n2 = n.MOD_NN_N(n1)
            self.clearDisplay()
            self.setDisplayText(str(n2))
        except:
            self.clearDisplay()
            self.setDisplayText(ERROR_MSG)

    def sub_n(self):
        try:
            nums = self.display.text().split("-")
            n = pybind11module.Natural(nums[0])
            n1 = pybind11module.Natural(nums[1])
            n.SUB_NN_N(n1)
            self.clearDisplay()
            self.setDisplayText(str(n))
        except:
            self.clearDisplay()
            self.setDisplayText(ERROR_MSG)

    def mul_nk(self):
        try:
            nums = self.display.text().split("e")
            n = pybind11module.Natural(nums[0])
            n.MUL_Nk_N(int(nums[1]))
            self.clearDisplay()
            self.setDisplayText(str(n))
        except:
            self.clearDisplay()
            self.setDisplayText(ERROR_MSG)

    def abs_zz(self):
        try:
            z = pybind11module.Integer(self.z_display.text())
            z1 = z.ABS_Z_Z()
            self.clearDisplayZ()
            self.setDisplayTextZ(str(z1))
        except:
            self.clearDisplayZ()
            self.setDisplayTextZ(ERROR_MSG)

    def mul_zm(self):
        try:
            z = pybind11module.Integer(self.z_display.text())
            z.MUL_ZM_Z()
            self.clearDisplayZ()
            self.setDisplayTextZ(str(z))
        except:
            self.clearDisplayZ()
            self.setDisplayTextZ(ERROR_MSG)

    def mul_z(self):
        try:
            nums = self.z_display.text().split('*')
            z = pybind11module.Integer(nums[0])
            z1 = pybind11module.Integer(nums[1])
            z.MUL_ZZ_Z(z1)
            self.clearDisplayZ()
            self.setDisplayTextZ(str(z))
        except:
            self.clearDisplayZ()
            self.setDisplayTextZ(ERROR_MSG)

    def add_z(self):
        try:
            nums = self.z_display.text().split('+')
            z = pybind11module.Integer(nums[0])
            z1 = pybind11module.Integer(nums[1])
            z.ADD_ZZ_Z(z1)
            self.clearDisplayZ()
            self.setDisplayTextZ(str(z))
        except:
            self.clearDisplayZ()
            self.setDisplayTextZ(ERROR_MSG)

    def div_z(self):
        try:
            nums = self.z_display.text().split('/')
            z = pybind11module.Integer(nums[0])
            z1 = pybind11module.Integer(nums[1])
            z2 = z.DIV_ZZ_Z(z1)
            self.clearDisplayZ()
            self.setDisplayTextZ(str(z2))
        except:
            self.clearDisplayZ()
            self.setDisplayTextZ(ERROR_MSG)

    def mod_z(self):
        try:
            nums = self.z_display.text().split('%')
            z = pybind11module.Integer(nums[0])
            z1 = pybind11module.Integer(nums[1])
            z2 = z.MOD_ZZ_Z(z1)
            self.clearDisplayZ()
            self.setDisplayTextZ(str(z2))
        except:
            self.clearDisplayZ()
            self.setDisplayTextZ(ERROR_MSG)

    def sub_z(self):
        try:
            nums = []
            if self.z_display.text()[0] == '-':
                num = 1
            else:
                num = 0
            while self.z_display.text()[num] != '-':
                num += 1
            nums.append(self.z_display.text()[:num])
            nums.append(self.z_display.text()[num + 1:])
            z = pybind11module.Integer(nums[0])
            z1 = pybind11module.Integer(nums[1])
            z.SUB_ZZ_Z(z1)
            self.clearDisplayZ()
            self.setDisplayTextZ(str(z))
        except:
            self.clearDisplayZ()
            self.setDisplayTextZ(ERROR_MSG)

    def inv_r(self):
        try:
            r = pybind11module.Rational(self.r_display.text())
            r1 = r.INV_Q_Q()
            self.clearDisplayR()
            self.setDisplayTextR(str(r1))
        except:
            self.clearDisplayR()
            self.setDisplayTextR(ERROR_MSG)

    def red_r(self):
        try:
            r = pybind11module.Rational(self.r_display.text())
            r.RED_Q_Q()
            self.clearDisplayR()
            self.setDisplayTextR(str(r))
        except:
            self.clearDisplayR()
            self.setDisplayTextR(ERROR_MSG)

    def mul_r(self):
        try:
            nums = self.r_display.text().split('*')
            r = pybind11module.Rational(nums[0])
            r1 = pybind11module.Rational(nums[1])
            r.MUL_QQ_Q(r1)
            self.clearDisplayR()
            self.setDisplayTextR(str(r))
        except:
            self.clearDisplayR()
            self.setDisplayTextR(ERROR_MSG)

    def div_r(self):
        try:
            nums = self.r_display.text().split(':')
            r = pybind11module.Rational(nums[0])
            r1 = pybind11module.Rational(nums[1])
            r.DIV_QQ_Q(r1)
            self.clearDisplayR()
            self.setDisplayTextR(str(r))
        except:
            self.clearDisplayR()
            self.setDisplayTextR(ERROR_MSG)

    def add_r(self):
        try:
            nums = self.r_display.text().split('+')
            r = pybind11module.Rational(nums[0])
            r1 = pybind11module.Rational(nums[1])
            r.ADD_QQ_Q(r1)
            self.clearDisplayR()
            self.setDisplayTextR(str(r))
        except:
            self.clearDisplayR()
            self.setDisplayTextR(ERROR_MSG)

    def sub_r(self):
        try:
            nums = []
            if self.r_display.text()[0] == '-':
                num = 1
            else:
                num = 0
            while self.r_display.text()[num] != '-':
                num += 1
            nums.append(self.r_display.text()[:num])
            nums.append(self.r_display.text()[num + 1:])
            r = pybind11module.Rational(nums[0])
            r1 = pybind11module.Rational(nums[1])
            r.SUB_QQ_Q(r1)
            self.clearDisplayR()
            self.setDisplayTextR(str(r))
        except:
            self.clearDisplayZ()
            self.setDisplayTextZ(ERROR_MSG)

    def dep_p(self):
        try:
            p = pybind11module.Polynomial(self.p_display.text())
            p1 = p.DEP_P_P()
            self.clearDisplayP()
            self.setDisplayTextP(str(p1))
        except:
            self.clearDisplayP()
            self.setDisplayTextP(ERROR_MSG)

    def fac_p(self):
        try:
            p = pybind11module.Polynomial(self.p_display.text())
            r = p.FAC_P_Q()
            self.clearDisplayP()
            self.setDisplayTextP(str(r))
        except:
            self.clearDisplayP()
            self.setDisplayTextP(ERROR_MSG)

    def gcf_p(self):
        try:
            pols = self.p_display.text().split(';')
            p = pybind11module.Polynomial(pols[0])
            p1 = pybind11module.Polynomial(pols[1])
            p2 = p.GCF_PP_P(p1)
            self.clearDisplayP()
            self.setDisplayTextP(str(p2))
        except:
            self.clearDisplayP()
            self.setDisplayTextP(ERROR_MSG)

    def nmr_p(self):
        try:
            p = pybind11module.Polynomial(self.p_display.text())
            p1 = p.NMR_P_P()
            self.clearDisplayP()
            self.setDisplayTextP(str(p1))
        except:
            self.clearDisplayP()
            self.setDisplayTextP(ERROR_MSG)

    def add_p(self):
        try:
            pols = self.p_display.text().split(';')
            p = pybind11module.Polynomial(pols[0])
            p1 = pybind11module.Polynomial(pols[1])
            p.ADD_PP_P(p1)
            self.clearDisplayP()
            self.setDisplayTextP(str(p))
        except:
            self.clearDisplayP()
            self.setDisplayTextP(ERROR_MSG)

    def sub_p(self):
        try:
            pols = self.p_display.text().split(';')
            p = pybind11module.Polynomial(pols[0])
            p1 = pybind11module.Polynomial(pols[1])
            p.SUB_PP_P(p1)
            self.clearDisplayP()
            self.setDisplayTextP(str(p))
        except:
            self.clearDisplayP()
            self.setDisplayTextP(ERROR_MSG)

    def mul_p(self):
        try:
            pols = self.p_display.text().split(';')
            str1 = pols[0]
            str2 = pols[1]
            if str1.replace('/', '0').isdigit():
                p = pybind11module.Polynomial(pols[1])
                r = pybind11module.Rational(pols[0])
                p.MUL_PQ_P(r)
            elif str2.replace('/', '0').isdigit():
                p = pybind11module.Polynomial(pols[0])
                r = pybind11module.Rational(pols[1])
                p.MUL_PQ_P(r)
            else:
                p = pybind11module.Polynomial(pols[0])
                p1 = pybind11module.Polynomial(pols[1])
                p.MUL_PP_P(p1)
            self.clearDisplayP()
            self.setDisplayTextP(str(p))
        except:
            self.clearDisplayP()
            self.setDisplayTextP(ERROR_MSG)

    def div_p(self):
        try:
            pols = self.p_display.text().split(';')
            p = pybind11module.Polynomial(pols[0])
            p1 = pybind11module.Polynomial(pols[1])
            if abs(p.DEG_P_N() - p1.DEG_P_N()) > 50:
                self.clearDisplayP()
                self.setDisplayTextP("Разность степеней мн-ов больше 50, прочитайте инструкцию")
            else:
                p2 = p.DIV_PP_P(p1)
                self.clearDisplayP()
                self.setDisplayTextP(str(p2))
        except:
            self.clearDisplayP()
            self.setDisplayTextP(ERROR_MSG)

    def mod_p(self):
        try:
            pols = self.p_display.text().split(';')
            p = pybind11module.Polynomial(pols[0])
            p1 = pybind11module.Polynomial(pols[1])
            if abs(p.DEG_P_N() - p1.DEG_P_N()) > 50:
                self.clearDisplayP()
                self.setDisplayTextP("Разность степеней мн-ов больше 50, прочитайте инструкцию")
            else:
                p2 = p.MOD_PP_P(p1)
                self.clearDisplayP()
                self.setDisplayTextP(str(p2))
        except:
            self.clearDisplayP()
            self.setDisplayTextP(ERROR_MSG)

    def evaluate(self):
        if self.display.text()[0] == '-':
            self.clearDisplay()
            self.setDisplayText(ERROR_MSG)
        if 'V' in self.display.text():
            self.com_nn()
        if 'e' in self.display.text():
            self.mul_nk()
        if '*' in self.display.text():
            self.mul_n()
        if '+' in self.display.text():
            self.add_n()
        if '/' in self.display.text():
            self.div_n()
        if '%' in self.display.text():
            self.mod_n()
        if '-' in self.display.text():
            self.sub_n()

    def evaluate_z(self):
        if '*' in self.z_display.text():
            self.mul_z()
        elif '+' in self.z_display.text():
            self.add_z()
        elif '/' in self.z_display.text():
            self.div_z()
        elif '%' in self.z_display.text():
            self.mod_z()
        else:
            self.sub_z()

    def evaluate_r(self):
        if '*' in self.r_display.text():
            self.mul_r()
        elif '+' in self.r_display.text():
            self.add_r()
        elif ':' in self.r_display.text():
            self.div_r()
        else:
            self.sub_r()

    def clearDisplay(self):
        self.setDisplayText("")

    def clearDisplayZ(self):
        self.setDisplayTextZ("")

    def clearDisplayR(self):
        self.setDisplayTextR("")

    def clearDisplayP(self):
        self.setDisplayTextP("")

    def _create_actions(self):
        self.natAction = QAction("&Натуральные числа", self)
        self.intAction = QAction("&Целые числа", self)
        self.ratAction = QAction("&Рациональные числа", self)
        self.polAction = QAction("&Многочлены", self)
        self.instructionNAction = QAction("&Инструкция для натуральных чисел", self)
        self.instructionIAction = QAction("&Инструкция для целых чисел", self)
        self.instructionRAction = QAction("&Инструкция для рациональных чисел", self)
        self.instructionPAction = QAction("&Инструкция для многочленов", self)

    def _connect_actions(self):
        self.natAction.triggered.connect(self.nat)
        self.intAction.triggered.connect(self.int)
        self.ratAction.triggered.connect(self.rat)
        self.polAction.triggered.connect(self.pol)
        self.instructionNAction.triggered.connect(self.insN)
        self.instructionIAction.triggered.connect(self.insI)
        self.instructionRAction.triggered.connect(self.insR)
        self.instructionPAction.triggered.connect(self.insP)

    def nat(self):
        self.stackedLayout.setCurrentIndex(1)

    def int(self):
        self.stackedLayout.setCurrentIndex(2)

    def rat(self):
        self.stackedLayout.setCurrentIndex(3)

    def pol(self):
        self.stackedLayout.setCurrentIndex(4)

    def insN(self):
        self.stackedLayout.setCurrentIndex(5)

    def insI(self):
        self.stackedLayout.setCurrentIndex(6)

    def insR(self):
        self.stackedLayout.setCurrentIndex(7)

    def insP(self):
        self.stackedLayout.setCurrentIndex(8)

    def _create_menu_bar(self):
        menuBar = self.menuBar()
        mode_menu = menuBar.addMenu("&Тип")
        mode_menu.addAction(self.natAction)
        mode_menu.addAction(self.intAction)
        mode_menu.addAction(self.ratAction)
        mode_menu.addAction(self.polAction)
        help_menu = menuBar.addMenu("&Помощь")
        help_menu.addAction(self.instructionNAction)
        help_menu.addAction(self.instructionIAction)
        help_menu.addAction(self.instructionRAction)
        help_menu.addAction(self.instructionPAction)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    app.exec()
