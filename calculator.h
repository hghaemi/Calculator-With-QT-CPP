#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QPushButton>
#include <QObject>
#include <QLineEdit>
#include "button.h"

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Button *createButton(const QString &text , const char *member);

    void abortOperation(); // for example 5 devide by 0 and others exceptions

    bool calculate(double rightOperand , const QString &pendingOperator);
    double sumInMemory;  // stores calcutor memory
    double sumSoFar;   // stores far and previous memory
    double factorSoFar;  // stores current value
    QString pendingAdditiveOperator;
    QString pendingMultiplicativeOperator;
    bool waitingForOperand;  // at first it's waiting for an operand that user enter!
    QLineEdit *display;
    enum { NumDigitButtons = 10 };  // an array includes numbers 0 to 9
    Button *digitButtons[NumDigitButtons];  // assign this array to buttons

private slots :
    void digitClicked();  // numbers : 0-9
    void unaryOperatorClicked(); // sqrt , power
    void additiveOperatorClicked();  // + , -
    void multiplicativeOperatorClicked(); // * , /
    void equalClicked(); // =
    void pointClicked(); // 3.5
    void changeSignClicked();  // change 3 to -3
    void backspaceClicked();  // change 325 to 32
    void clear();  // clear before using operator
    void clearAll(); // clear after using operator
    void clearMemory();
    void readMemory();
    void setMemory();
    void addToMemory();

};
#endif // CALCULATOR_H
