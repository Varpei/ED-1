#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool operador(const string& op) {
    return op == "+" || op == "-" || op == "*" || op == "/";
}

int RPN(const string& expressao) {
    stack<int>p;
    string str = "";

    for(char c : expressao) {
        if (c == ' ') {
            continue;
        } 
        else if(isdigit(c) || (c == '-' && str.empty())) 
        {
            str += c;
        } 
        else 
        {
            if(!str.empty()) 
            {
                int num = stoi(str);
                p.push(num);
                str = "";
            }

            if(operador(string(1, c))) 
            {
                if(p.size() < 2) 
                {
                    cout << "Erro: Expressão RPN inválida." << endl;
                    return 0;
                }

                int op2 = p.top();
                p.pop();
                int op1 = p.top();
                p.pop();

                switch(c) 
                {
                    case '+':
                        p.push(op1 + op2);
                        break;
                    case '-':
                        p.push(op1 - op2);
                        break;
                    case '*':
                        p.push(op1 * op2);
                        break;
                    case '/':
                        if(op2 == 0) 
                        {
                            cout << "Erro: Divisão por zero." << endl;
                            return 0;
                        }
                        p.push(op1 / op2);
                        break;
                    default:
                        cout << "Erro: Operador inválido." << endl;
                        return 0;
                }
            }
        }
    }

    if(!str.empty()) 
    {
        int num = stoi(str);
        p.push(num);
    }

    if(p.size() != 1) 
    {
        cout << "Erro: Expressão RPN inválida." << endl;
        return 0;
    }

    return p.top();
}

int main() {
    string expressao;
    cout << "Digite a expressao RPN: ";
    getline(cin, expressao);

    int result = RPN(expressao);
    if(result != 0) 
    {
        cout << "Resultado da expressao RPN: " << result << endl;
    }

    return 0;
}
