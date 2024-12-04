#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

// Definições de cores para o terminal (melhoram a visualização no console)
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define CYAN "\033[36m"

// Estruturas de Dados
typedef struct Fila {
    int idPaciente;             // ID do paciente
    int prioridade;             // 0 = Verde, 1 = Amarelo, 2 = Vermelho
    struct Fila *proximo;       // Próximo elemento na fila
} Fila;

typedef struct Paciente {
    int id;                     // ID do paciente
    char nome[50];              // Nome do paciente
    struct Paciente *proximo;   // Próximo elemento na lista de pacientes
} Paciente;

typedef struct Medico {
    int id;                     // ID do médico
    char nome[50];              // Nome do médico
    char especialidade[30];     // Especialidade do médico
    struct Medico *proximo;     // Próximo elemento na lista de médicos
} Medico;

typedef struct Consulta {
    int id;                     // ID da consulta
    char data[11];              // Data da consulta (formato DD/MM/AAAA)
    char hora[6];               // Hora da consulta (formato HH:MM)
    int idPaciente;             // ID do paciente associado
    int idMedico;               // ID do médico associado
    struct Consulta *proxima;   // Próxima consulta na lista
} Consulta;

// Protótipos das Funções
void exibirMenu(); // Exibe o menu principal
void adicionarPacienteFilaPrioridade(Fila **inicio, Fila **fim, int idPaciente, int prioridade); // Adiciona um paciente na fila de prioridade
void atenderPacienteFilaPrioridade(Fila **inicio, Fila **fim); // Atende o paciente com maior prioridade
void listarFilaPrioridade(Fila *inicio); // Lista os pacientes na fila de prioridade
void cadastrarPaciente(Paciente **lista); // Cadastra um novo paciente
void listarPacientes(Paciente *lista); // Lista todos os pacientes cadastrados
void cadastrarMedico(Medico **lista); // Cadastra um novo médico
void listarMedicos(Medico *lista); // Lista todos os médicos cadastrados
void agendarConsulta(Consulta **lista); // Agenda uma nova consulta
void listarConsultas(Consulta *lista); // Lista todas as consultas agendadas
void liberarMemoria(Fila **inicioFila, Paciente **listaPacientes, Medico **listaMedicos, Consulta **listaConsultas); // Libera memória alocada dinamicamente

// Funções

// Exibe o menu principal do sistema
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

// Adiciona um paciente à fila de atendimento com base na prioridade
void adicionarPacienteFilaPrioridade(Fila **inicio, Fila **fim, int idPaciente, int prioridade) {
    if (prioridade < 0 || prioridade > 2) { // Valida a prioridade
        printf(RED "Erro: Prioridade inválida! Use 0 (Verde), 1 (Amarelo) ou 2 (Vermelho).\n" RESET);
        return;
    }

    Fila *novo = (Fila *)malloc(sizeof(Fila)); // Aloca memória para um novo elemento na fila
    if (!novo) {
        printf(RED "Erro: Falha na alocação de memória.\n" RESET);
        return;
    }

    // Define os dados do paciente
    novo->idPaciente = idPaciente;
    novo->prioridade = prioridade;
    novo->proximo = NULL;

    // Insere o paciente na fila de forma ordenada pela prioridade
    if (!(*inicio) || (*inicio)->prioridade < prioridade) {
        novo->proximo = *inicio;
        *inicio = novo;
        if (!(*fim)) *fim = novo; // Atualiza o ponteiro de fim se necessário
    } else {
        Fila *atual = *inicio;
        while (atual->proximo && atual->proximo->prioridade >= prioridade) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
        if (!novo->proximo) *fim = novo; // Atualiza o fim se necessário
    }
    printf(GREEN "Paciente adicionado à fila com sucesso!\n" RESET);
}

// Atende o paciente com maior prioridade na fila
void atenderPacienteFilaPrioridade(Fila **inicio, Fila **fim) {
    if (!(*inicio)) { // Verifica se a fila está vazia
        printf(RED "A fila está vazia!\n" RESET);
        return;
    }

    Fila *atual = *inicio;
    printf(GREEN "Atendendo paciente ID: %d com prioridade %d.\n" RESET, atual->idPaciente, atual->prioridade);

    *inicio = (*inicio)->proximo; // Atualiza o início da fila
    if (!(*inicio)) *fim = NULL; // Atualiza o fim se a fila estiver vazia
    free(atual); // Libera memória
}

// Lista todos os pacientes na fila de prioridade
void listarFilaPrioridade(Fila *inicio) {
    if (!inicio) { // Verifica se a fila está vazia
        printf(RED "A fila está vazia!\n" RESET);
        return;
    }

    printf(CYAN "\n=== Fila de Atendimento ===\n" RESET);
    Fila *atual = inicio;
    while (atual) { // Percorre a fila e imprime cada paciente
        printf("Paciente ID: %d | Prioridade: %d\n", atual->idPaciente, atual->prioridade);
        atual = atual->proximo;
    }
}

// Cadastra um novo paciente
void cadastrarPaciente(Paciente **lista) {
    Paciente *novo = (Paciente *)malloc(sizeof(Paciente)); // Aloca memória para o novo paciente
    if (!novo) {
        printf(RED "Erro: Falha na alocação de memória.\n" RESET);
        return;
    }

    // Coleta os dados do paciente
    printf("Digite o ID do paciente: ");
    if (scanf("%d", &novo->id) != 1) {
        printf(RED "Erro: Entrada inválida para ID.\n" RESET);
        free(novo);
        return;
    }
    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", novo->nome);

    // Insere o paciente na lista
    novo->proximo = *lista;
    *lista = novo;
    printf(GREEN "Paciente cadastrado com sucesso!\n" RESET);
}
// Lista todos os pacientes cadastrados
void listarPacientes(Paciente *lista) {
    if (!lista) { // Verifica se há pacientes cadastrados
        printf(RED "Nenhum paciente cadastrado.\n" RESET);
        return;
    }

    printf(CYAN "Lista de Pacientes:\n" RESET);
    Paciente *atual = lista;
    while (atual) { // Percorre a lista de pacientes e imprime cada um
        printf("ID: %d | Nome: %s\n", atual->id, atual->nome);
        atual = atual->proximo;
    }
}

// Cadastra um novo médico
void cadastrarMedico(Medico **lista) {
    Medico *novo = (Medico *)malloc(sizeof(Medico)); // Aloca memória para o novo médico
    if (!novo) {
        printf(RED "Erro: Falha na alocação de memória.\n" RESET);
        return;
    }

    // Coleta os dados do médico
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

    // Insere o médico na lista
    novo->proximo = *lista;
    *lista = novo;
    printf(GREEN "Médico cadastrado com sucesso!\n" RESET);
}

// Lista todos os médicos cadastrados
void listarMedicos(Medico *lista) {
    if (!lista) { // Verifica se há médicos cadastrados
        printf(RED "Nenhum médico cadastrado.\n" RESET);
        return;
    }

    printf(CYAN "Lista de Médicos:\n" RESET);
    Medico *atual = lista;
    while (atual) { // Percorre a lista de médicos e imprime cada um
        printf("ID: %d | Nome: %s | Especialidade: %s\n", atual->id, atual->nome, atual->especialidade);
        atual = atual->proximo;
    }
}

// Agenda uma nova consulta
void agendarConsulta(Consulta **lista) {
    Consulta *nova = (Consulta *)malloc(sizeof(Consulta)); // Aloca memória para a nova consulta
    if (!nova) {
        printf(RED "Erro: Falha na alocação de memória.\n" RESET);
        return;
    }

    // Coleta os dados da consulta
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

    // Insere a consulta na lista
    nova->proxima = *lista;
    *lista = nova;
    printf(GREEN "Consulta agendada com sucesso!\n" RESET);
}

// Lista todas as consultas agendadas
void listarConsultas(Consulta *lista) {
    if (!lista) { // Verifica se há consultas cadastradas
        printf(RED "Nenhuma consulta agendada.\n" RESET);
        return;
    }

    printf(CYAN "Lista de Consultas:\n" RESET);
    Consulta *atual = lista;
    while (atual) { // Percorre a lista de consultas e imprime cada uma
        printf("ID: %d | Data: %s | Hora: %s | Paciente ID: %d | Médico ID: %d\n",
               atual->id, atual->data, atual->hora, atual->idPaciente, atual->idMedico);
        atual = atual->proxima;
    }
}

// Libera memória alocada dinamicamente para as estruturas
void liberarMemoria(Fila **inicioFila, Paciente **listaPacientes, Medico **listaMedicos, Consulta **listaConsultas) {
    // Libera os elementos da fila
    Fila *filaAtual = *inicioFila;
    while (filaAtual) {
        Fila *prox = filaAtual->proximo;
        free(filaAtual);
        filaAtual = prox;
    }

    // Libera os elementos da lista de pacientes
    Paciente *pacienteAtual = *listaPacientes;
    while (pacienteAtual) {
        Paciente *prox = pacienteAtual->proximo;
        free(pacienteAtual);
        pacienteAtual = prox;
    }

    // Libera os elementos da lista de médicos
    Medico *medicoAtual = *listaMedicos;
    while (medicoAtual) {
        Medico *prox = medicoAtual->proximo;
        free(medicoAtual);
        medicoAtual = prox;
    }

    // Libera os elementos da lista de consultas
    Consulta *consultaAtual = *listaConsultas;
    while (consultaAtual) {
        Consulta *prox = consultaAtual->proxima;
        free(consultaAtual);
        consultaAtual = prox;
    }

    printf(GREEN "Memória liberada com sucesso.\n" RESET);
}

// Função principal
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura a localidade para suporte a caracteres especiais
    SetConsoleOutputCP(CP_UTF8); // Configura o terminal para exibir UTF-8

    // Ponteiros para as estruturas de dados
    Fila *inicioFila = NULL, *fimFila = NULL;
    Paciente *listaPacientes = NULL;
    Medico *listaMedicos = NULL;
    Consulta *listaConsultas = NULL;

    int opcao; // Variável para armazenar a escolha do usuário
    do {
        exibirMenu(); // Exibe o menu principal
        if (scanf("%d", &opcao) != 1) { // Valida a entrada do usuário
            printf(RED "Erro: Entrada inválida. Digite um número.\n" RESET);
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        // Realiza a operação escolhida pelo usuário
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
    } while (opcao != 0); // Continua até o usuário escolher sair

        return 0; // Encerra o programa
    }