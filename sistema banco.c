#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_ATENDIMENTOS 100

typedef struct {
    char nome[100];
    char cpf[15];
    int tipoAtendimento;
} Atendimento;

Atendimento atendimentos[MAX_ATENDIMENTOS];
int totalAtendimentos = 0;

void cadastrarAtendimento() {
    if (totalAtendimentos >= MAX_ATENDIMENTOS) {
        printf("Limite de atendimentos alcançado!\n");
        return;
    }

    Atendimento novoAtendimento;
    printf("Digite o nome do cliente: ");
    scanf("%99s", novoAtendimento.nome);
    printf("Digite o CPF do cliente: ");
    scanf("%14s", novoAtendimento.cpf);
    printf("Escolha o tipo de atendimento:\n");
    printf("1 - Abertura de Conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente Pessoa Física\n");
    printf("4 - Gerente Pessoa Jurídica\n");
    scanf("%d", &novoAtendimento.tipoAtendimento);

    atendimentos[totalAtendimentos] = novoAtendimento;
    totalAtendimentos++;

    printf("Atendimento registrado com sucesso!\n");
}

void listarAtendimentos() {
    for (int i = 0; i < totalAtendimentos; i++) {
        printf("Nome: %s\n", atendimentos[i].nome);
        printf("CPF: %s\n", atendimentos[i].cpf);
        printf("Tipo de Atendimento: ");
        switch (atendimentos[i].tipoAtendimento) {
            case 1:
                printf("Abertura de Conta\n");
                break;
            case 2:
                printf("Caixa\n");
                break;
            case 3:
                printf("Gerente Pessoa Física\n");
                break;
            case 4:
                printf("Gerente Pessoa Jurídica\n");
                break;
            default:
                printf("Desconhecido\n");
        }
        printf("===============================\n");
    }
}

void listarAtendimentosPorSetor() {
    int tipo;
    printf("Escolha o tipo de atendimento a ser listado:\n");
    printf("1 - Abertura de Conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente Pessoa Física\n");
    printf("4 - Gerente Pessoa Jurídica\n");
    scanf("%d", &tipo);

    for (int i = 0; i < totalAtendimentos; i++) {
        if (atendimentos[i].tipoAtendimento == tipo) {
            printf("Nome: %s\n", atendimentos[i].nome);
            printf("CPF: %s\n", atendimentos[i].cpf);
            printf("Tipo de Atendimento: ");
            switch (atendimentos[i].tipoAtendimento) {
                case 1:
                    printf("Abertura de Conta\n");
                    break;
                case 2:
                    printf("Caixa\n");
                    break;
                case 3:
                    printf("Gerente Pessoa Física\n");
                    break;
                case 4:
                    printf("Gerente Pessoa Jurídica\n");
                    break;
                default:
                    printf("Desconhecido\n");
            }
            printf("===============================\n");
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;
    while (1) {
        printf("Bem-vindo ao sistema de atendimento\n");
        printf("1 - Solicitar Atendimento\n");
        printf("2 - Listar Atendimentos Registrados\n");
        printf("3 - Listar Atendimento por Setor\n");
        printf("4 - Sair\n");

        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                cadastrarAtendimento();
                break;
            case 2:
                listarAtendimentos();
                break;
            case 3:
                listarAtendimentosPorSetor();
                break;
            case 4:
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

