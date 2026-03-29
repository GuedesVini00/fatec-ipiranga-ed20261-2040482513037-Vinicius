// AUTOR: Vinicius Guedes
#include <stdio.h>   // entrada e saída (printf, scanf)
#include <stdlib.h>  // uso do exit()
#include <ctype.h>   // função isdigit()

// ================= PILHA =================

// Definindo tamanho máximo da pilha
#define MAX 5

// Vetor que representa a pilha
int pilha[MAX];

// Variável que controla o topo da pilha
// Começa em -1 indicando pilha vazia
int topo = -1;

// Função para adicionar um elemento na pilha (push)
void push(int valor) {
    // Verifica se a pilha está cheia
    if (topo == MAX - 1) {
        printf("Erro: pilha cheia!\n");
        exit(1); // encerra o programa
    }

    // Incrementa o topo e adiciona o valor
    pilha[++topo] = valor;
}


// Função para remover um elemento da pilha (pop)
int pop() {
    // Verifica se a pilha está vazia
    if (topo == -1) {
        printf("Erro: pilha vazia!\n");
        exit(1);
    }

    // Retorna o valor do topo e decrementa
    return pilha[topo--];
}


// Função para mostrar todos os elementos da pilha
void mostrar() {
    // Se estiver vazia
    if (topo == -1) {
        printf("Pilha vazia\n");
        return;
    }

    // Percorre do início até o topo e mostra a pilha toda
    printf("Pilha: ");
    for (int i = 0; i <= topo; i++) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}


// Função para mostrar apenas o elemento do topo
void mostrarTopo() {
    // Se estiver vazia
    if (topo == -1) {
        printf("Topo: pilha vazia\n");
    } else {
        printf("Topo: %d\n", pilha[topo]);
    }
}


// ================= RPN =================

// Função que verifica se o caractere é um operador válido
int Operador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


// Função responsável por realizar os cálculos
int calcular(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;  // soma
        case '-': return a - b;  // subtração
        case '*': return a * b;  // multiplicação
        case '/': return a / b;  // divisão
    }
    return 0;
}


// Função principal
int main() {

    // Vetor que armazenará a expressão digitada
    char expr[100];

    // Entrada do usuário
    printf("Digite a RPN (ex: 34+2*): ");
    scanf("%s", expr);

    // Índice para percorrer a string
    int i = 0;

    // Loop que percorre a expressão caractere por caractere
    while (expr[i] != '\0') {

        printf("\nProcessando: %c\n", expr[i]);

        // ================= CASO 1: NÚMERO =================
        if (isdigit(expr[i])) {

            // Converte o caractere para inteiro
            int valor = expr[i] - '0';

            printf("Push(Adicionar): %d\n", valor);

            // Adiciona na pilha
            push(valor);
        }

        // ================= CASO 2: OPERADOR =================
        else if (Operador(expr[i])) {

            // Verifica se há pelo menos dois elementos na pilha
            if (topo < 1) {
                printf("Expressao invalida!\n");
                return 1;
            }

            // Remove os dois últimos elementos
            int b = pop();
            int a = pop();

            // Mostra a operação realizada
            printf("Operacao: %d %c %d\n", a, expr[i], b);

            // Calcula o resultado
            int resultado = calcular(a, b, expr[i]);

            printf("Resultado parcial: %d\n", resultado);

            // Insere o resultado de volta na pilha
            push(resultado);
        }

        // ================= CASO INVÁLIDO =================
        else {
            printf("Expressao invalida!\n");
            return 1;
        }

        // Mostra a pilha após cada operação
        mostrar();
        mostrarTopo();

        // Avança para o próximo caractere
        i++;
    }

    // ================= VALIDAÇÃO FINAL =================

    // Se sobrar mais de um elemento, a expressão é inválida
    if (topo != 0) {
        printf("Expressao invalida!\n");
    } 
    else {
        // Caso contrário, o resultado final está no topo
        printf("\nResultado final: %d\n", pop());
    }

    return 0;
}
