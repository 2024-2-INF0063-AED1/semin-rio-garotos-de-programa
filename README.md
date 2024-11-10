# 📋 Relatório do Projeto: Sistema de Atendimento e Gerenciamento de Consultas para Clínica Médica

## Equipe - Garotos de Programa 💻
- 202201668 - Thayckowisk Correia Campos
- 202201634 - Henryque Oliveira Affiune
- 202206136 - Rhadyja Almeida Barbosa

## 🏥 Seção I - Introdução
O **Sistema de Atendimento e Gerenciamento de Consultas para Clínica Médica** é uma solução desenvolvida para facilitar o gerenciamento de consultas médicas e a organização do atendimento em clínicas de médio e pequeno porte. Com o aumento da demanda por atendimentos e a necessidade de otimizar processos administrativos, clínicas enfrentam desafios como a gestão eficiente das consultas, controle de prontuários, agendamento de pacientes e administração de filas de espera. Esse projeto visa criar um sistema que simplifique esses processos, tornando o atendimento mais ágil e organizado.

A implementação do **Sistema de Atendimento e Gerenciamento de Consultas** beneficia recepcionistas, médicos e pacientes, proporcionando uma interface intuitiva e funcionalidades que agilizam o fluxo de trabalho, desde o agendamento até o atendimento final.

## 📚 Seção II - Fundamentos Teóricos
O **Sistema de Atendimento e Gerenciamento de Consultas** será desenvolvido com base em conceitos fundamentais de estrutura de dados e algoritmos, aplicando a linguagem C para garantir desempenho e controle de memória durante a execução das operações. Este sistema utiliza técnicas e estruturas eficientes para organizar informações e garantir assim uma experiência fluida para os usuários. Abaixo, descrevemos as principais técnicas e estruturas aplicadas no sistema:

- **🗂️ Filas**: Para organizar a ordem de atendimento dos pacientes, possibilitando um fluxo de atendimento baseado no horário ou prioridade.
- **🔗 Listas Encadeadas**: Para gerenciar os prontuários e o histórico de consultas de cada paciente, permitindo fácil inserção, remoção e busca de informações.
- **🔍 Tabelas Hash**: Para armazenar dados dos médicos e pacientes, possibilitando consultas rápidas e eficiente recuperação de informações.

## 🔧 Seção III - Metodologia

Para o desenvolvimento do **Sistema de Atendimento e Gerenciamento de Consultas**, foram seguidos os seguintes passos:

1. **📝 Planejamento e Levantamento de Requisitos**:
   - Inicialmente, foi realizada uma análise dos problemas comuns no gerenciamento de clínicas médicas, como a gestão de agendamentos e o controle de prontuários.
   - Foram identificadas as funcionalidades essenciais do sistema, incluindo:
     - 📋 Cadastro de pacientes e médicos;
     - 📅 Agendamento e reprogramação de consultas;
     - 🕒 Gerenciamento de fila de espera para o atendimento;
     - 📂 Registro e consulta do histórico médico dos pacientes.

2. **🗃️ Definição das Estruturas de Dados**:
   - Para representar os dados dos pacientes, médicos e consultas, foram definidas estruturas de dados em C, visando a organização e recuperação eficiente das informações. As principais estruturas foram:
     - **👤 Paciente**: contendo informações como nome, idade, histórico médico e ID único.
     - **👨‍⚕️ Médico**: com dados como nome, especialidade, horários de atendimento e ID.
     - **📅 Consulta**: com data, horário, status (agendada, concluída ou cancelada) e IDs de paciente e médico.
   - A fila de espera para consultas foi organizada utilizando uma fila, e as listas encadeadas foram usadas para armazenar o histórico de consultas de cada paciente.

3. **💻 Desenvolvimento do Sistema**:
   - O sistema será implementado na linguagem de programação C, escolhida pela sua eficiência e controle direto sobre o gerenciamento de memória.
   - Serão criadas as principais funções que compõem o sistema:
     - **📅 Agendar Consulta**: permite o agendamento de uma nova consulta, registrando o paciente e o médico, e adicionando à fila de atendimento.
     - **♻️ Reprogramar Consulta**: possibilita a alteração de data e hora de uma consulta agendada.
     - **🕒 Gerenciar Fila de Espera**: organiza e controla a fila de espera para o atendimento, incluindo ou removendo pacientes conforme necessário.
     - **📜 Registro de Histórico**: armazena o histórico de consultas de cada paciente, permitindo consultas rápidas sobre atendimentos anteriores.
     - **📂 Consulta de Prontuário**: possibilita a busca rápida de informações dos pacientes, histórico de consultas e anotações médicas.

4. **✅ Testes e Validação**:
   - Serão realizados testes em cenários variados para garantir a eficácia das funcionalidades implementadas. Os testes abrangeram a criação de novos cadastros, agendamento e reprogramação de consultas, além do gerenciamento da fila de espera e consultas de prontuário. Testes de performance também serão realizados para avaliar a velocidade do sistema na recuperação de informações, especialmente em situações de alta demanda.

## 📈 Seção IV - Resultados Esperados
O **Sistema de Atendimento e Gerenciamento de Consultas para Clínica Médica** foi projetado para otimizar o fluxo de trabalho em clínicas e proporcionar um atendimento mais ágil e organizado aos pacientes. Com a implementação e validação do sistema, espera-se que:

- ⚡ O processo de agendamento e reprogramação de consultas seja mais eficiente e menos suscetível a erros.
- 📋 A fila de espera seja organizada de maneira justa, respeitando a ordem de chegada ou critérios de prioridade.
- 🩺 O histórico médico dos pacientes seja registrado de maneira confiável e acessível, facilitando o acompanhamento contínuo.
- 👩‍💼 A carga administrativa dos profissionais de recepção seja reduzida, permitindo um atendimento mais focado nas necessidades dos pacientes.

### 🏆 Conclusão
O **Sistema de Atendimento e Gerenciamento de Consultas para Clínica Médica** apresenta-se como uma ferramenta robusta e de fácil uso, possibilitando a administração eficaz das consultas e o controle de prontuários e filas de espera em clínicas. Através de estruturas de dados otimizadas, o sistema permite a rápida recuperação de informações, tornando o atendimento mais rápido e organizado, e beneficiando tanto os profissionais da clínica quanto os pacientes.
