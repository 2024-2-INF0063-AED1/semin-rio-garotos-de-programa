#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

// Definições de cores para o terminal
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define CYAN "\033[36m"

// Estruturas de Dados
typedef struct Fila {
    int idPaciente;
    int prioridade; // 0 = Verde, 1 = Amarelo, 2 = Vermelho
    struct Fila *proximo;
} Fila;

typedef struct Paciente {
    int id;
    char nome[50];
    struct Paciente *proximo;
} Paciente;

typedef struct Medico {
    int id;
    char nome[50];
    char especialidade[30];
    struct Medico *proximo;
} Medico;

typedef struct Consulta {
    int id;
    char data[11];
    char hora[6];
    int idPaciente;
    int idMedico;
    struct Consulta *proxima;
} Consulta;

// Protótipos das Funções
void exibirMenu();
void adicionarPacienteFilaPrioridade(Fila **inicio, Fila **fim, int idPaciente, int prioridade);
void atenderPacienteFilaPrioridade(Fila **inicio, Fila **fim);
void listarFilaPrioridade(Fila *inicio);
void cadastrarPaciente(Paciente **lista);
void listarPacientes(Paciente *lista);
void cadastrarMedico(Medico **lista);
void listarMedicos(Medico *lista);
void agendarConsulta(Consulta **lista);
void listarConsultas(Consulta *lista);
void liberarMemoria(Fila **inicioFila, Paciente **listaPacientes, Medico **listaMedicos, Consulta **listaConsultas);

// Funções
void exibirMenu() {
    printf(CYAN "\n=============================================\n" RESET);
    printf(CYAN "=== " GREEN "Sistema de Gerenciamento de Consultas" CYAN " ===\n" RESET);
    printf(CYAN "=============================================\n" RESET);
    printf(YELLOW "1. " RESET GREEN "Adicionar Paciente à Fila\n" RESET);
    printf(YELLOW "2. " RESET GREEN "Atender Paciente\n" RESET);
    printf(YELLOW "3. " RESET GREEN "Listar Fila\n" RESET);
    printf(YELLOW "4. " RESET GREEN "Cadastrar Médico\n" RESET);
    printf(YELLOW "5. " RESET GREEN "Listar Médicos\n" RESET);
    printf(YELLOW "6. " RESET GREEN "Cadastrar Paciente\n" RESET);
    printf(YELLOW "7. " RESET GREEN "Listar Pacientes\n" RESET);
    printf(YELLOW "8. " RESET GREEN "Agendar Consulta\n" RESET);
    printf(YELLOW "9. " RESET GREEN "Listar Consultas\n" RESET);
    printf(YELLOW "0. " RESET RED "Sair\n" RESET);
    printf(CYAN "=============================================\n" RESET);
    printf(YELLOW "Escolha uma opção: " RESET);
}

void adicionarPacienteFilaPrioridade(Fila **inicio, Fila **fim, int idPaciente, int prioridade) {
    if (prioridade < 0 || prioridade > 2) {
        printf(RED "Erro: Prioridade inválida! Use 0 (Verde), 1 (Amarelo) ou 2 (Vermelho).\n" RESET);
        return;
    }

    Fila *novo = (Fila *)malloc(sizeof(Fila));
    if (!novo) {
        printf(RED "Erro: Falha na alocação de memória.\n" RESET);
        return;
    }

    novo->idPaciente = idPaciente;
    novo->prioridade = prioridade;
    novo->proximo = NULL;

    if (!(*inicio) || (*inicio)->prioridade < prioridade) {
        novo->proximo = *inicio;
        *inicio = novo;
        if (!(*fim)) *fim = novo;
    } else {
        Fila *atual = *inicio;
        while (atual->proximo && atual->proximo->prioridade >= prioridade) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
        if (!novo->proximo) *fim = novo;
    }
    printf(GREEN "Paciente adicionado à fila com sucesso!\n" RESET);
}

void atenderPacienteFilaPrioridade(Fila **inicio, Fila **fim) {
    if (!(*inicio)) {
        printf(RED "A fila está vazia!\n" RESET);
        return;
    }

    Fila *atual = *inicio;
    printf(GREEN "Atendendo paciente ID: %d com prioridade %d.\n" RESET, atual->idPaciente, atual->prioridade);

    *inicio = (*inicio)->proximo;
    if (!(*inicio)) *fim = NULL;
    free(atual);
}

void listarFilaPrioridade(Fila *inicio) {
    if (!inicio) {
        printf(RED "A fila está vazia!\n" RESET);
        return;
    }

    printf(CYAN "\n=== Fila de Atendimento ===\n" RESET);
    Fila *atual = inicio;
    while (atual) {
        printf("Paciente ID: %d | Prioridade: %d\n", atual->idPaciente, atual->prioridade);
        atual = atual->proximo;
    }
}

void cadastrarPaciente(Paciente **lista) {
    Paciente *novo = (Paciente *)malloc(sizeof(Paciente));
    if (!novo) {
        printf(RED "Erro: Falha na alocação de memória.\n" RESET);
        return;
    }

    printf("Digite o ID do paciente: ");
    if (scanf("%d", &novo->id) != 1) {
        printf(RED "Erro: Entrada inválida para ID.\n" RESET);
        free(novo);
        return;
    }
    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", novo->nome);

    novo->proximo = *lista;
    *lista = novo;
    printf(GREEN "Paciente cadastrado com sucesso!\n" RESET);
}

void listarPacientes(Paciente *lista) {
    if (!lista) {
        printf(RED "Nenhum paciente cadastrado.\n" RESET);
        return;
    }

    printf(CYAN "Lista de Pacientes:\n" RESET);
    Paciente *atual = lista;
    while (atual) {
        printf("ID: %d | Nome: %s\n", atual->id, atual->nome);
        atual = atual->proximo;
    }
}

void cadastrarMedico(Medico **lista) {
    Medico *novo = (Medico *)malloc(sizeof(Medico));
    if (!novo) {
        printf(RED "Erro: Falha na alocação de memória.\n" RESET);
        return;
    }

    printf("Digite o ID do médico: ");
    if (scanf("%d", &novo->id) != 1) {
        printf(RED "Erro: Entrada inválida para ID.\n" RESET);
        free(novo);
        return;
    }
    printf("Digite o nome do médico: ");
    scanf(" %[^\n]", novo->nome);
    printf("Digite a especialidade do médico: ");
    scanf(" %[^\n]", novo->especialidade);

    novo->proximo = *lista;
    *lista = novo;
    printf(GREEN "Médico cadastrado com sucesso!\n" RESET);
}

void listarMedicos(Medico *lista) {
    if (!lista) {
        printf(RED "Nenhum médico cadastrado.\n" RESET);
        return;
    }

    printf(CYAN "Lista de Médicos:\n" RESET);
    Medico *atual = lista;
    while (atual) {
        printf("ID: %d | Nome: %s | Especialidade: %s\n", atual->id, atual->nome, atual->especialidade);
        atual = atual->proximo;
    }
}

void agendarConsulta(Consulta **lista) {
    Consulta *nova = (Consulta *)malloc(sizeof(Consulta));
    if (!nova) {
        printf(RED "Erro: Falha na alocação de memória.\n" RESET);
        return;
    }

    printf("Digite o ID da consulta: ");
    if (scanf("%d", &nova->id) != 1) {
        printf(RED "Erro: Entrada inválida para ID.\n" RESET);
        free(nova);
        return;
    }
    printf("Digite a data (DD/MM/AAAA): ");
    scanf(" %[^\n]", nova->data);
    printf("Digite o horário (HH:MM): ");
    scanf(" %[^\n]", nova->hora);
    printf("Digite o ID do paciente: ");
    if (scanf("%d", &nova->idPaciente) != 1) {
        printf(RED "Erro: Entrada inválida para ID do paciente.\n" RESET);
        free(nova);
        return;
    }
    printf("Digite o ID do médico: ");
    if (scanf("%d", &nova->idMedico) != 1) {
        printf(RED "Erro: Entrada inválida para ID do médico.\n" RESET);
        free(nova);
        return;
    }

    nova->proxima = *lista;
    *lista = nova;
    printf(GREEN "Consulta agendada com sucesso!\n" RESET);
}

void listarConsultas(Consulta *lista) {
    if (!lista) {
        printf(RED "Nenhuma consulta agendada.\n" RESET);
        return;
    }

    printf(CYAN "Lista de Consultas:\n" RESET);
    Consulta *atual = lista;
    while (atual) {
        printf("ID: %d | Data: %s | Hora: %s | Paciente ID: %d | Médico ID: %d\n",
               atual->id, atual->data, atual->hora, atual->idPaciente, atual->idMedico);
        atual = atual->proxima;
    }
}

void liberarMemoria(Fila **inicioFila, Paciente **listaPacientes, Medico **listaMedicos, Consulta **listaConsultas) {
    Fila *filaAtual = *inicioFila;
    while (filaAtual) {
        Fila *prox = filaAtual->proximo;
        free(filaAtual);
        filaAtual = prox;
    }

    Paciente *pacienteAtual = *listaPacientes;
    while (pacienteAtual) {
        Paciente *prox = pacienteAtual->proximo;
        free(pacienteAtual);
        pacienteAtual = prox;
    }

    Medico *medicoAtual = *listaMedicos;
    while (medicoAtual) {
        Medico *prox = medicoAtual->proximo;
        free(medicoAtual);
        medicoAtual = prox;
    }

    Consulta *consultaAtual = *listaConsultas;
    while (consultaAtual) {
        Consulta *prox = consultaAtual->proxima;
        free(consultaAtual);
        consultaAtual = prox;
    }

    printf(GREEN "Memória liberada com sucesso.\n" RESET);
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    SetConsoleOutputCP(CP_UTF8);

    Fila *inicioFila = NULL, *fimFila = NULL;
    Paciente *listaPacientes = NULL;
    Medico *listaMedicos = NULL;
    Consulta *listaConsultas = NULL;

    int opcao;
    do {
        exibirMenu();
        if (scanf("%d", &opcao) != 1) {
            printf(RED "Erro: Entrada inválida. Digite um número.\n" RESET);
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        switch (opcao) {
            case 1: {
                int idPaciente, prioridade;
                printf("Digite o ID do paciente: ");
                if (scanf("%d", &idPaciente) != 1) {
                    printf(RED "Erro: Entrada inválida para ID.\n" RESET);
                    while (getchar() != '\n');
                    break;
                }
                printf("Digite a prioridade (0 = Verde, 1 = Amarelo, 2 = Vermelho): ");
                if (scanf("%d", &prioridade) != 1) {
                    printf(RED "Erro: Entrada inválida para prioridade.\n" RESET);
                    while (getchar() != '\n');
                    break;
                }
                adicionarPacienteFilaPrioridade(&inicioFila, &fimFila, idPaciente, prioridade);
                break;
            }
            case 2:
                atenderPacienteFilaPrioridade(&inicioFila, &fimFila);
                break;
            case 3:
                listarFilaPrioridade(inicioFila);
                break;
            case 4:
                cadastrarMedico(&listaMedicos);
                break;
            case 5:
                listarMedicos(listaMedicos);
                break;
            case 6:
                cadastrarPaciente(&listaPacientes);
                break;
            case 7:
                listarPacientes(listaPacientes);
                break;
            case 8:
                agendarConsulta(&listaConsultas);
                break;
            case 9:
                listarConsultas(listaConsultas);
                break;
            case 0:
                printf(GREEN "Saindo do sistema...\n" RESET);
                liberarMemoria(&inicioFila, &listaPacientes, &listaMedicos, &listaConsultas);
                break;
            default:
                printf(RED "Opção inválida! Digite um número de 0 a 9.\n" RESET);
        }
    } while (opcao != 0);

    return 0;
}
