
#include <iostream>
#include <string>

using namespace std;

constexpr int MAXN = 10000;

class PilhaSeq1
{

public:
    char elementos[MAXN];
    int N;
    int error;

    void cria()
    {
        this->N = 0;
    }

    void libera()
    {
        // nenhum recurso dinamico para desalocar;
    }

    void empilhar(char dado)
    {
        error = 0;
        if (N < MAXN)
        {
            this->elementos[N++] = dado;
        }
        else
        {
            error = 1;
        }
    }

    char desempilhar()
    {
        error = 0;
        if (N > 0)
        {
            return this->elementos[--N];
        }
        else
        {
            error = 1;
            return '\0';
        }
    }
    char topo()
    {
        if (N == 0)
        {
            error = 1;
            return '\0';
        }
        return this->elementos[this->N - 1];
    }

    void imprimir()
    {
        cout << "\nPilha: ";
        for (int i = 0; i < N; i++)
        {
            cout << elementos[i];
        }
    }

    void imprimirInvertida()
    {
        cout << "\nPilha Invertida: ";
        for (int i = this->N - 1; i >= 0; i--)
        {
            cout << elementos[i];
        }
    }
};

/*
1. Inversão de uma String
Implemente uma função que inverta uma string usando uma pilha sequencial.
A função deve empilhar cada caractere da string e,
em seguida, desempilhar para formar a string invertida.
*/

PilhaSeq1 inverterString(string txt)
{
    PilhaSeq1 pilha;
    pilha.cria();

    int tamTxt = txt.length();

    for (int i = 0; i < tamTxt; i++)
    {
        pilha.empilhar(txt[i]);
    }

    PilhaSeq1 invs;
    invs.cria();
    for (int i = 0; i < tamTxt; i++)
    {
        invs.empilhar(pilha.desempilhar());
    }

    return invs;
}

/*
2. Verificação de Parênteses Balanceados
Escreva um programa que, dado uma expressao matemática
contendo (, {, [, verifique se
todos os parênteses estão corretamente balanceados,
 utilizando uma pilha sequencial

 */

bool verificaBalanceamento(const string &expr)
{
    PilhaSeq1 pilha;
    pilha.cria();

    for (char ch : expr)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            pilha.empilhar(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (pilha.N == 0)
                return false;
            char topo = pilha.desempilhar();
            if ((ch == ')' && topo != '(') ||
                (ch == '}' && topo != '{') ||
                (ch == ']' && topo != '['))
            {
                return false;
            }
        }
    }

    return pilha.N == 0;
}

int precedencia(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixaParaPosfixa(const string &expr)
{
    PilhaSeq1 pilha;
    pilha.cria();
    string posfixa;

    for (char ch : expr)
    {
        if (isdigit(ch) || isalpha(ch))
        {
            posfixa += ch;
        }
        else if (ch == '(')
        {
            pilha.empilhar(ch);
        }
        else if (ch == ')')
        {
            while (pilha.N > 0 && pilha.topo() != '(')
            {
                posfixa += pilha.desempilhar();
            }
            pilha.desempilhar(); // Remove '('
        }
        else
        {
            while (pilha.N > 0 && precedencia(pilha.topo()) >= precedencia(ch))
            {
                posfixa += pilha.desempilhar();
            }
            pilha.empilhar(ch);
        }
    }

    while (pilha.N > 0)
    {
        posfixa += pilha.desempilhar();
    }

    return posfixa;
}

/*
4. Avaliacao de Expressao Pós-fixa (RPN)
Escreva um programa para avaliar expressões pos-fixas (como 56+2*).
 Utilize uma pilha
sequencial para armazenar operandos e realizar as operações
 aritméticas.
 */
int avaliarPosfixa(const string &expr)
{
    PilhaSeq1 pilha;
    pilha.cria();

    for (char ch : expr)
    {
        if (isdigit(ch))
        {
            pilha.empilhar(ch - '0'); // Converte char para int
        }
        else
        {
            int op2 = pilha.desempilhar();
            int op1 = pilha.desempilhar();
            switch (ch)
            {
            case '+':
                pilha.empilhar(op1 + op2);
                break;
            case '-':
                pilha.empilhar(op1 - op2);
                break;
            case '*':
                pilha.empilhar(op1 * op2);
                break;
            case '/':
                pilha.empilhar(op1 / op2);
                break;
            }
        }
    }

    return pilha.desempilhar();
}

void moverDisco(PilhaSeq1 &origem, PilhaSeq1 &destino, char nomeOrigem, char nomeDestino)
{
    int disco = origem.desempilhar();
    destino.empilhar(disco);
    cout << "Mover disco " << disco << " de " << nomeOrigem << " para " << nomeDestino << endl;
}

void resolverTorresDeHanoi(int n, PilhaSeq1 &origem, PilhaSeq1 &destino, PilhaSeq1 &auxiliar, char nomeOrigem, char nomeDestino, char nomeAuxiliar)
{
    if (n == 1)
    {
        moverDisco(origem, destino, nomeOrigem, nomeDestino);
    }
    else
    {
        resolverTorresDeHanoi(n - 1, origem, auxiliar, destino, nomeOrigem, nomeAuxiliar, nomeDestino);
        moverDisco(origem, destino, nomeOrigem, nomeDestino);
        resolverTorresDeHanoi(n - 1, auxiliar, destino, origem, nomeAuxiliar, nomeDestino, nomeOrigem);
    }
}

int calcularFatorial(int n)
{
    PilhaSeq1 pilha;
    pilha.cria();

    // EMPILHAR N
    while (n > 1)
    {
        pilha.empilhar(n);
        n--;
    }

    int resultado = 1;

    while (pilha.N > 0)
    {
        resultado *= pilha.desempilhar();
    }

    return resultado;
}

int main()
{
    system("cls");

    cout << "\n***** Usando pilhas sequenciais *******\n";
    cout << "\n1 questao:\n";
    string txt = "Direita";
    cout << "\nTexto Normal: " << txt;
    PilhaSeq1 pilha_inv = inverterString(txt);
    cout << "Texto Invertido: ";
    pilha_inv.imprimir();
    cout << "\nFim da 1 questao.\n\n";

    cout << "2 questao:\n";
    string expressao = "{[()]}()";

    if (verificaBalanceamento(expressao))
    {
        cout << "Os parenteses estao balanceados!" << endl;
    }
    else
    {
        cout << "Os parenteses não estao balanceados." << endl;
    }

    cout << "\nFim da 2 questao.\n\n";

    cout << "Inicio da 3 Questao:\n\n";

    expressao = "A+B*C/C";
    string resultado = infixaParaPosfixa(expressao);
    cout << "Expressao Infixa: " << expressao << endl;
    cout << "Expressao Pós-fixa: " << resultado << endl;

    cout << "\nFim da 3 Questao.\n\n";

    cout << "Inicio da 4 Questao:\n\n";
    string expressaoInfixa = "A+B*C";
    string expressaoPosfixa = infixaParaPosfixa(expressaoInfixa);
    cout << "Expressao Infixa: " << expressaoInfixa << endl;
    cout << "Expressao Pós-fixa: " << expressaoPosfixa << endl;

    string exprPosfixaNumerica = "56+2*";
    // int resultado = avaliarPosfixa(exprPosfixaNumerica);
    // cout << "Avaliacao da expressao pos-fixa (" << exprPosfixaNumerica << "): " << resultado << endl;
    cout << "Avaliacao da expressao pos-fixa (" << exprPosfixaNumerica << "): " << avaliarPosfixa(exprPosfixaNumerica) << endl;

    cout << "\nFim da 4 Questao.\n\n";

    cout << "Inicio da 5 Questao:\n\n";
    { // Resolução das Torres de Hanói
        int numDiscos = 3;
        PilhaSeq1 torreOrigem, torreDestino, torreAuxiliar;
        torreOrigem.cria();
        torreDestino.cria();
        torreAuxiliar.cria();

        for (int i = numDiscos; i >= 1; i--)
        {
            torreOrigem.empilhar(i);
        }

        resolverTorresDeHanoi(
            numDiscos, torreOrigem, torreDestino,
            torreAuxiliar, 'A', 'C', 'B');
    }
    cout << "\nFim da 5 Questao.\n\n";

    cout << "Inicio da 6 Questao:\n\n";
    int fatorial = 5;

    cout << "O fatorial de " << fatorial
         << " = "
         << calcularFatorial(fatorial)
         << "\nFim da 6 Questao.\n\n";

    return 0;
}
