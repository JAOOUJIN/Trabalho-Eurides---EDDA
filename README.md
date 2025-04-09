# Sistema de Atendimento Jurídico - DJa

Este projeto foi desenvolvido como parte de um trabalho acadêmico da disciplina de Estrutura de Dados e Desenvolvimento de Algoritmos (EDDA). O sistema simula um atendimento jurídico gratuito realizado por um Departamento Jurídico Acadêmico (DJa), incluindo funcionalidades como triagem de assistidos, agendamento de plantões com advogados e atribuição de estagiários aos casos.

## 📌 Funcionalidades

- Triagem socioeconômica do assistido
- Cadastro de assistidos e advogados
- Agendamento de plantões jurídicos
- Atribuição de estagiários aos atendimentos
- Acompanhamento dos casos

## 🛠️ Tecnologias Utilizadas

- Linguagem C
- Manipulação de arquivos `.DAT` para armazenamento dos dados
- Terminal (interface simples em linha de comando)

## 🧠 Conceitos Aplicados

- Estrutura de dados: structs, arrays e manipulação de ponteiros
- Modularização de código
- Leitura e escrita em arquivos binários
- Organização por responsabilidades (cada módulo representa uma parte do sistema)

## 📂 Organização dos Arquivos

```
📁 Trabalho-Eurides---EDDA
├── triagem.c
├── estagiarios.c
├── advogados.c
├── plantao.c
├── casos.c
├── main.c
├── README.md
└── *.DAT (arquivos de dados)
```

## 🚀 Como Executar

1. Compile o projeto:
   ```bash
   gcc main.c -o dja_app
   ```

2. Execute:
   ```bash
   ./dja_app
   ```

> Obs: para funcionamento completo, mantenha os arquivos `.DAT` no mesmo diretório do executável.

## 💡 Aprendizados

Este projeto me ajudou a consolidar conceitos de linguagem C, especialmente em relação ao uso de ponteiros e manipulação de arquivos. Também aprendi a organizar um sistema em múltiplos arquivos para manter a clareza e modularidade.
