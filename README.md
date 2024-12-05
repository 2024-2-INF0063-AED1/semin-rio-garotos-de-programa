# Sistema de Gerenciamento de Consultas Médicas

---

## **Autores**

- **Thayckowisk Correia Campos** (202201668)
- **Henryque Oliveira Affiune** (202201634)
- **Rhadyja Almeida Barbosa** (202206136)

---

## **Resumo**

Este relatório apresenta o desenvolvimento de um **Sistema de Gerenciamento de Consultas Médicas**, implementado em linguagem C, para atender clínicas de médio e pequeno porte. A solução foi projetada para otimizar processos administrativos, como o agendamento de consultas, gerenciamento de filas de espera e registro de históricos médicos. Utilizando estruturas de dados dinâmicas, como filas de prioridade, listas encadeadas e tabelas hash, o sistema assegura eficiência, organização e rapidez no atendimento.

O sistema permite o cadastro de pacientes e médicos, organização de consultas e filas de prioridade com critérios de gravidade, além do armazenamento e consulta de históricos médicos. Este projeto destaca a importância da informatização nos serviços médicos para melhorar a experiência de pacientes e profissionais de saúde.

**Palavras-chave:** Agendamento, Filas de Espera, Estruturas de Dados, Linguagem C, Clínicas Médicas, Gestão de Consultas.

---

## **Seção I - Introdução**

O **Sistema de Gerenciamento de Consultas Médicas** foi criado para responder aos desafios enfrentados por clínicas de médio e pequeno porte no gerenciamento de seus processos administrativos. A demanda crescente por atendimentos organizados e a necessidade de minimizar erros humanos motivaram o desenvolvimento deste sistema. 

Entre os problemas mais comuns enfrentados por clínicas médicas estão:
- A **falta de organização em filas de espera**, que resulta em atrasos no atendimento.
- **Dificuldade no controle de prontuários e históricos médicos**, que prejudica a continuidade do cuidado ao paciente.
- **Erros administrativos em agendamentos e cadastros**, impactando diretamente a satisfação de pacientes e médicos.

O sistema foi projetado para oferecer uma interface intuitiva, garantindo que recepcionistas e administradores possam operar o programa com facilidade. Além disso, os pacientes e médicos se beneficiam de uma gestão mais ágil e confiável.

### **Objetivos**
- **Otimizar o agendamento de consultas.**
- **Melhorar a organização de filas de atendimento.**
- **Simplificar o acesso a históricos médicos.**
- **Reduzir a carga administrativa com uma ferramenta eficiente.**

### **Importância**
O uso de soluções computacionais para gerenciamento de consultas médicas é essencial em um ambiente onde eficiência e precisão são fundamentais. Este sistema busca contribuir para a melhoria do fluxo de trabalho, permitindo que clínicas ofereçam um atendimento mais ágil e satisfatório.

---

## **Seção II - Estruturas de Dados Utilizadas**

Para garantir o desempenho e a organização, o sistema utiliza as seguintes estruturas de dados:

| **Estrutura**        | **Descrição**                                                                                  | **Uso no Sistema**                                 |
|-----------------------|----------------------------------------------------------------------------------------------|--------------------------------------------------|
| **Fila de Prioridade**| Organiza pacientes por critérios de gravidade (0 = Verde, 1 = Amarelo, 2 = Vermelho).        | Gerenciamento de filas de espera.                |
| **Lista Encadeada**   | Estrutura dinâmica para armazenar dados de pacientes, médicos e consultas.                   | Cadastro de pacientes, médicos e consultas.      |
| **Tabelas Hash**      | Associam IDs únicos a pacientes e médicos, garantindo busca eficiente.                       | Busca rápida por cadastros e histórico médico.   |

---

## **Seção III - Funcionalidades Implementadas**

O sistema apresenta um conjunto de funcionalidades que abrangem desde o cadastro de dados até o gerenciamento completo de filas e consultas. As principais funcionalidades são:

| **Funcionalidade**             | **Descrição**                                                                                                 |
|--------------------------------|-------------------------------------------------------------------------------------------------------------|
| **Cadastro de Pacientes**      | Insere novos pacientes no sistema com ID único, nome e prioridade.                                          |
| **Cadastro de Médicos**        | Armazena médicos com ID único, nome e especialidade.                                                        |
| **Agendamento de Consultas**   | Associa médicos e pacientes a horários específicos, armazenados em listas encadeadas.                       |
| **Gerenciamento de Fila**      | Insere ou remove pacientes da fila de espera, organizando automaticamente por critérios de prioridade.       |
| **Histórico Médico**           | Registra todas as consultas realizadas por pacientes para consulta futura.                                  |
| **Listagem de Dados**          | Permite a visualização detalhada de pacientes, médicos, consultas e fila de espera.                         |

---

## **Seção IV - Metodologia**

### **1. Planejamento**
O desenvolvimento do sistema seguiu as seguintes etapas:
1. **Identificação de Problemas:** Mapeamento das dificuldades comuns em clínicas médicas, como filas desorganizadas e falta de acesso rápido a dados.
2. **Definição de Requisitos:** Seleção das funcionalidades mais importantes, como cadastro de pacientes, médicos, filas de espera e agendamento de consultas.
3. **Estruturação do Sistema:** Escolha das estruturas de dados adequadas para garantir eficiência e organização.

### **2. Implementação**
O sistema foi implementado em **linguagem C** devido à sua eficiência e controle sobre memória. Estruturas dinâmicas como listas encadeadas e filas de prioridade foram utilizadas para possibilitar o gerenciamento em tempo real. 

#### **Fluxo de Operações**
Ao iniciar o programa, o usuário interage com o menu principal, que apresenta as seguintes opções:

| **Opção** | **Descrição**                          |
|-----------|----------------------------------------|
| 1         | Adicionar paciente à fila de prioridade. |
| 2         | Atender o paciente com maior prioridade. |
| 3         | Listar a fila de espera.                |
| 4         | Cadastrar um médico.                   |
| 5         | Listar médicos cadastrados.            |
| 6         | Cadastrar um paciente.                 |
| 7         | Listar pacientes cadastrados.          |
| 8         | Agendar uma consulta.                  |
| 9         | Listar consultas agendadas.            |
| 0         | Encerrar o programa.                   |

---

## **Seção V - Avaliação e Resultados**

### **1. Testes Realizados**
Os seguintes cenários foram testados para validar o sistema:

| **Cenário de Teste**            | **Resultado Esperado**                                                              | **Resultado Obtido**                           |
|---------------------------------|------------------------------------------------------------------------------------|-----------------------------------------------|
| Cadastro de pacientes e médicos | Inclusão bem-sucedida em listas encadeadas.                                        | 100% de sucesso nos cadastros.               |
| Gerenciamento de filas          | Ordem de atendimento respeitando prioridades.                                      | Filas organizadas corretamente.               |
| Agendamento de consultas        | Registro de consultas associando pacientes e médicos por data e horário.           | Consultas armazenadas sem inconsistências.    |
| Listagem de dados               | Exibição de pacientes, médicos, consultas e filas em tempo real.                   | Informações exibidas corretamente.            |

### **2. Benefícios Observados**
- **Redução no Tempo de Atendimento:** As filas organizadas por prioridade otimizam o fluxo de trabalho.
- **Aumento da Precisão Administrativa:** Busca eficiente por cadastros e históricos médicos.
- **Facilidade de Uso:** Interface simples e intuitiva para usuários de diferentes níveis técnicos.

---

## **Seção VI - Conclusão**

O **Sistema de Gerenciamento de Consultas Médicas** oferece uma solução robusta para clínicas médicas, permitindo a otimização de processos administrativos e o aprimoramento do atendimento ao paciente. Sua implementação demonstrou eficiência em cenários de uso real, destacando-se como uma ferramenta confiável e de fácil utilização.

### **Perspectivas Futuras**
- **Armazenamento Persistente:** Implementação de um banco de dados para manter os registros.
- **Relatórios Analíticos:** Geração de relatórios gerenciais para análise de desempenho.
- **Interface Gráfica:** Expansão do sistema para um ambiente visual interativo.

---

## **Referências**

| **Fonte**                          | **Descrição**                                                                                         |
|------------------------------------|-----------------------------------------------------------------------------------------------------|
| Goodrich, M. & Tamassia, R.        | *Estruturas de Dados e Algoritmos em C*. Pearson, 2015.                                              |
| Revista Gestão e Saúde             | "Sistemas de Gestão em Clínicas de Saúde". 2021.                                                   |
| Coding Clinics                     | "Como Implementar um Sistema de Agendamento com C". YouTube, 2023.                                 |

---



