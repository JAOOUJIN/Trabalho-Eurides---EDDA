#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int oab;                // Número da OAB
    char nomeadv[50];       // Nome do advogado
    char celularadv[12];    // Celular do advogado
    char emailadv[50];      // Email do advogado
    char especialidade[30]; // Especialidade do advogado
    char anoingresso[5];    // Ano de ingresso na OAB
    char cpfadv[12];        // CPF do advogado
} Advogado;

typedef struct
{
    int codestag;          // Código do estagiário
    char nomestag[50];     // Nome do estagiário
    char celularestag[12]; // Celular do estagiário
    char Emailestag[50];   // Email do estagiário
    char tipo[3];          // Tipo de estagiário
} Estagiario;

typedef struct
{
    int id;                              // Código do atendimento - preenchido automaticamente
    char data[11];                       // Data - preenchido automaticamente (formato: DD/MM/AAAA)
    char horario_chegada[6];             // Horário de chegada (formato: HH:MM)
    char horario_atendimento[6];         // Horário de atendimento - preenchido automaticamente (formato: HH:MM)
    char como_soube[50];                 // Como ficou sabendo do nosso serviço
    char nome_atendente[50];             // Nome do atendente responsável pela Triagem
    char tipo_pessoa[3];                 // Pessoa física ou jurídica (PF/PJ)
    char nome[50];                       // Nome da pessoa
    char genero[2];                      // Gênero
    char lgbtqia[2];                     // Pertence à comunidade LGBTQIA+ (Sim/Não)
    char cor_raca[20];                   // Cor-raça
    char data_nascimento[11];            // Data de nascimento (formato: DD/MM/AAAA)
    char nacionalidade[20];              // Nacionalidade
    char naturalidade[20];               // Naturalidade
    char cpf[12];                        // CPF
    char rg[20];                         // RG
    char endereco[100];                  // Endereço
    char celular[15];                    // Celular
    char usa_whatsapp[4];                // Usa WhatsApp (Sim/Não)
    char telefone_alternativo[15];       // Telefone para contato alternativo
    char email[50];                      // E-mail
    char escolaridade[30];               // Escolaridade
    char profissao[30];                  // Profissão
    char situacao_emprego[20];           // Situação de emprego (empregado/autônomo/desempregado)
    char estado_civil[20];               // Estado civil
    char tem_filhos[2];                  // Tem filhos (Sim/Não)
    int filhos_moram_com_voce;           // Quantos filhos moram com você
    int total_membros_familia;           // Total de membros da sua entidade familiar
    char recebe_beneficio[2];            // Recebe benefício assistencial ou rendimentos concedidos por programa oficial de transferência de renda (Sim/Não)
    float valor_beneficio;               // Qual valor do benefício
    float renda_mensal;                  // Qual o valor da sua renda mensal
    float renda_membros_familia;         // Qual o valor total de ganhos mensais de outros membros da sua entidade familiar, excetuando menores de 16 anos
    char gastos_tratamento[2];           // Tem gastos com tratamento médico por doença grave ou para o atendimento de necessidade especial com qualquer membro da entidade familiar (Sim/Não)
    float valor_gastos_tratamento;       // Qual valor
    char possui_investimentos[2];        // Possui investimentos (Sim/Não)
    float valor_investimento;            // Qual valor do investimento
    char possui_casa_propria[2];         // Possui casa própria (Sim/Não)
    float valor_casa_propria;            // Qual valor
    char possui_apartamento[2];          // Possui apartamento (Sim/Não)
    float valor_apartamento;             // Qual valor
    char possui_terreno[2];              // Possui terreno (Sim/Não)
    float valor_terreno;                 // Qual valor
    char possui_imovel_comercial[2];     // Possui imóvel comercial (Sim/Não)
    float valor_imovel_comercial;        // Qual valor
    char possui_automovel[2];            // Possui automóvel (Sim/Não)
    float valor_automovel;               // Qual valor
    char envolve_violencia_domestica[2]; // A demanda envolve violência doméstica (Sim/Não)
    char resumo_caso[500];               // Resumo do caso
    char materia_relacionada[30];        // Matéria relacionada à demanda solicitada (Cível/Família e Sucessões/Trabalhista/Penal/Previdenciário/Outro)
    char enquadrado_lei_1060[2];         // Pessoa enquadrada no perfil da Lei 1.060/50 (Sim/Não) - preenchido automaticamente após verificação da admissibilidade
} Triagem;

typedef struct
{
    char cpf[12];          // CPF do cliente
    int codestag;          // Código do estagiário
    char datatribuido[11]; // Data da atribuição
    char horatribuido[6];  // Hora da atribuição
} CasosAtribuidos;

typedef struct
{
    int oabdispo; // Número da OAB
    char diasemana[50];
    char hrfim[6];
    char hrinicio[6];
    char formaatendimento[2];
} DisponibilidadeAdvogado;

typedef struct
{
    int codestag;             // Código do estagiário
    int oab;                  // Número da OAB
    char dataatend[11];       // Data agendado para atendimento
    char horarioatend[6];     // Horário AGENDADO para atendimento
    char datainsc[11];        // Data em que a inscrição foi feita
    char horains[6];          // Hora em que a inscrição foi feita
    char area_direito[30];    // Área do direito
    char tipo_orientacao[50]; // Tipo de orientação buscada
    char prazofatal[2];       // Prazo fatal
    char observacoes[500];    // Observações
    char numprocesso[20];     // Número do processo
    char foiatend[2];         // Foi atendido
} Agendamento;

typedef struct
{
    char numprocesso[21];   // Número do processo
    char tema[51];          // Assunto da ação
    char cpf[12];           // CPF do cliente
    char polo[21];          // Reclamante/Reclamado/Exequente/Executado
    int codestag;           // Código do estagiário
    char dtcontrole[11];    // Próxima data em que será feito novo controle
    char proxtarefa[51];    // Próxima atividade a ser realizada
    char temprazodobro[2];  // Se foi deferido prazo em dobro para o DJe
    char obsprazo[501];     // Observação sobre o prazo a cumprir
    char audiencia[51];     // Se está marcada audiência e dados sobre ela
    char prazosimples[11];  // Data do prazo simples
    char prazodobrado[11];  // Data do prazo em dobro
    char movimentacao[501]; // Registro da movimentação processual
    int diasproxcontrole;   // Quantos dias até o próximo controle
    char dtproposicao[11];  // Data em que a ação foi protocolada num dos sistemas judiciários
} ControleCasos;

typedef struct
{
    int codestag;           // Código do estagiário
    char dtcircula[11];     // Data de circulação (DD/MM/AAAA)
    char hrcircula[6];      // Hora de circulação (HH:MM)
    char numprocesso[21];   // Número do processo
    char tipoacao[50];      // Tipo de ação
    char varajuizo[50];     // Vara ou juízo
    char foro[50];          // Foro
    char cpf[15];           // CPF do cliente
    char reclamado[50];     // Nome do reclamado
    char advreclamante[50]; // Advogado do reclamante
    char advreclamado[50];  // Advogado do reclamado
    char movimentacao[500]; // Movimentação processual
} Publicacao;

typedef struct NoFila
{
    Agendamento agendamento;
    struct NoFila *proximo;
} NoFila;

typedef struct
{
    NoFila *inicio;
    NoFila *fim;
} FilaAgendamentos;

// Inicializa uma fila vazia
void inicializarFila(FilaAgendamentos *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Adiciona um agendamento na fila
void enfileirar(FilaAgendamentos *fila, Agendamento agendamento)
{
    NoFila *novoNo = (NoFila *)malloc(sizeof(NoFila));
    if (novoNo == NULL)
    {
        printf("Erro ao alocar memória para a fila.\n");
        return;
    }

    // Copia o agendamento para o novo nó
    novoNo->agendamento = agendamento;
    novoNo->proximo = NULL;

    // Atualiza o fim da fila
    if (fila->fim == NULL)
    { // Fila vazia
        fila->inicio = novoNo;
    }

    // Se a fila não estiver vazia, atualiza o próximo do último nó
    else
    {
        fila->fim->proximo = novoNo;
    }

    // Atualiza o fim da fila
    fila->fim = novoNo;
}

// Verifica se a fila está vazia
int filaVazia(FilaAgendamentos *fila)
{
    return (fila->inicio == NULL);
}

// Remove o primeiro agendamento da fila
Agendamento desenfileirar(FilaAgendamentos *fila)
{
    Agendamento agendamentoVazio;                      // Estrutura para retornar caso a fila esteja vazia
    memset(&agendamentoVazio, 0, sizeof(Agendamento)); // Inicializa com valores nulos

    // Verificação para garantir que a fila não está vazia
    if (filaVazia(fila))
    {
        printf("Não há agendamentos para este advogado.\n");
        return agendamentoVazio; // Retorna um agendamento vazio
    }
    NoFila *temp = fila->inicio;
    Agendamento agendamento = temp->agendamento;

    // Atualiza o início da fila
    fila->inicio = fila->inicio->proximo;

    // Se o início da fila for NULL, atualiza o fim da fila
    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }

    free(temp);
    return agendamento;
}

// Fila de agendamentos para cada advogado
FilaAgendamentos *filasAdvogados;

void inicializarFilas(int num_advogados)
{
    // Aloca memória para as filas de agendamentos
    filasAdvogados = (FilaAgendamentos *)malloc(num_advogados * sizeof(FilaAgendamentos));
    for (int i = 0; i < num_advogados; i++)
    {
        inicializarFila(&filasAdvogados[i]);
    }
}

int buscaBinariaAdvogados(Advogado advogados[], int tamanho, int oab)
{
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        // Verifica se o número da OAB está no meio
        if (advogados[meio].oab == oab)
            return meio;

        // Se o número da OAB for maior, ignora a metade esquerda
        if (advogados[meio].oab < oab)
            esquerda = meio + 1;

        // Se o número da OAB for menor, ignora a metade direita
        else
            direita = meio - 1;
    }

    // Retorna -1 se o advogado não for encontrado
    return -1;
}

void carregarFilas(Advogado *advogados, int num_advogados, FilaAgendamentos *filasAdvogados)
{
    FILE *arquivo_agendamento = fopen("AGENDA.dat", "rb");
    if (arquivo_agendamento == NULL)
    {
        printf("Erro ao abrir o arquivo de agendamentos!\n");
        return;
    }

    // Lê os agendamentos do arquivo e enfileira para o advogado correspondente
    Agendamento agendamento;
    while (fread(&agendamento, sizeof(Agendamento), 1, arquivo_agendamento))
    {
        // Verifica se o agendamento não foi atendido
        if (strcmp(agendamento.foiatend, "S") != 0)
        {
            int indexAdvogado = buscaBinariaAdvogados(advogados, num_advogados, agendamento.oab);
            if (indexAdvogado != -1)
            {
                enfileirar(&filasAdvogados[indexAdvogado], agendamento);
            }
        }
    }

    fclose(arquivo_agendamento);
}

void carregarAdvogados(Advogado **advogados, int *num_advogados)
{
    FILE *arquivo_advogados = fopen("ADVOG_ORD.dat", "rb");
    if (arquivo_advogados == NULL)
    {
        printf("Erro ao abrir o arquivo de advogados!\n");
        return;
    }

    // Obtém a quantidade de advogados no arquivo
    fseek(arquivo_advogados, 0, SEEK_END);
    *num_advogados = ftell(arquivo_advogados) / sizeof(Advogado);
    rewind(arquivo_advogados);

    // Aloca memória para os advogados
    *advogados = (Advogado *)malloc(*num_advogados * sizeof(Advogado));
    if (*advogados == NULL)
    {
        printf("Erro ao alocar memória para advogados!\n");
        fclose(arquivo_advogados);
        return;
    }

    fread(*advogados, sizeof(Advogado), *num_advogados, arquivo_advogados);
    fclose(arquivo_advogados);
}

void liberarFilas(FilaAgendamentos *filasAdvogados, int num_advogados)
{
    for (int i = 0; i < num_advogados; i++)
    {
        // Enquanto a fila não estiver vazia, desenfileira e libera a memória
        while (!filaVazia(&filasAdvogados[i]))
        {
            desenfileirar(&filasAdvogados[i]);
        }
    }

    // Libera a memória alocada para as filas
    free(filasAdvogados);
}

void trocarEst(Estagiario *a, Estagiario *b)
{
    Estagiario temp = *a;
    *a = *b;
    *b = temp;
}

int particionarEst(Estagiario arr[], int baixo, int alto)
{
    Estagiario pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++)
    {
        if (arr[j].codestag < pivo.codestag)
        {
            i++;
            trocarEst(&arr[i], &arr[j]);
        }
    }
    trocarEst(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSortEst(Estagiario arr[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionarEst(arr, baixo, alto);
        quickSortEst(arr, baixo, pi - 1);
        quickSortEst(arr, pi + 1, alto);
    }
}

void ordenarEstagiarios()
{

    FILE *arquivo_estagiarios = fopen("ESTAG.dat", "rb");
    if (arquivo_estagiarios == NULL)
    {
        printf("Erro ao abrir o arquivo de estagiários!\n");
        return;
    }

    fseek(arquivo_estagiarios, 0, SEEK_END);
    int tamanho = ftell(arquivo_estagiarios) / sizeof(Estagiario);
    rewind(arquivo_estagiarios);

    Estagiario *estagiarios = (Estagiario *)malloc(tamanho * sizeof(Estagiario));
    if (estagiarios == NULL)
    {
        printf("Erro ao alocar memória!\n");
        fclose(arquivo_estagiarios);
        return;
    }

    fread(estagiarios, sizeof(Estagiario), tamanho, arquivo_estagiarios);
    fclose(arquivo_estagiarios);

    quickSortEst(estagiarios, 0, tamanho - 1);

    FILE *arquivo_ordenado = fopen("ESTAG_ORD.dat", "wb");
    if (arquivo_ordenado == NULL)
    {
        printf("Erro ao abrir o arquivo de estagiários!\n");
        free(estagiarios);
        return;
    }

    fwrite(estagiarios, sizeof(Estagiario), tamanho, arquivo_ordenado);
    fclose(arquivo_ordenado);
    free(estagiarios);

    printf("Estagiários ordenados com sucesso!\n");
}

void trocarAdv(Advogado *a, Advogado *b)
{
    Advogado temp = *a;
    *a = *b;
    *b = temp;
}

int particionarAdv(Advogado arr[], int baixo, int alto)
{
    Advogado pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++)
    {
        if (arr[j].oab < pivo.oab)
        {
            i++;
            trocarAdv(&arr[i], &arr[j]);
        }
    }
    trocarAdv(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSortAdv(Advogado arr[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionarAdv(arr, baixo, alto);
        quickSortAdv(arr, baixo, pi - 1);
        quickSortAdv(arr, pi + 1, alto);
    }
}

void ordenarAdvogados()
{
    FILE *arquivo_advogados = fopen("ADVOG.dat", "rb");
    if (arquivo_advogados == NULL)
    {
        printf("Erro ao abrir o arquivo de advogados!\n");
        return;
    }

    fseek(arquivo_advogados, 0, SEEK_END);
    int tamanho = ftell(arquivo_advogados) / sizeof(Advogado);
    rewind(arquivo_advogados);

    Advogado *advogados = (Advogado *)malloc(tamanho * sizeof(Advogado));
    if (advogados == NULL)
    {
        printf("Erro ao alocar memória!\n");
        fclose(arquivo_advogados);
        return;
    }

    fread(advogados, sizeof(Advogado), tamanho, arquivo_advogados);
    fclose(arquivo_advogados);

    quickSortAdv(advogados, 0, tamanho - 1);

    FILE *arquivo_ordenado = fopen("ADVOG_ORD.dat", "wb");
    if (arquivo_ordenado == NULL)
    {
        printf("Erro ao abrir o arquivo de advogados!\n");
        free(advogados);
        return;
    }

    fwrite(advogados, sizeof(Advogado), tamanho, arquivo_ordenado);
    fclose(arquivo_ordenado);
    free(advogados);

    printf("Advogados ordenados com sucesso!\n");
}

void trocarDisponibilidade(DisponibilidadeAdvogado *a, DisponibilidadeAdvogado *b)
{
    DisponibilidadeAdvogado temp = *a;
    *a = *b;
    *b = temp;
}

int particionarDisponibilidade(DisponibilidadeAdvogado arr[], int baixo, int alto)
{
    DisponibilidadeAdvogado pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++)
    {
        if (arr[j].oabdispo < pivo.oabdispo)
        {
            i++;
            trocarDisponibilidade(&arr[i], &arr[j]);
        }
    }
    trocarDisponibilidade(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSortDisponibilidade(DisponibilidadeAdvogado arr[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionarDisponibilidade(arr, baixo, alto);
        quickSortDisponibilidade(arr, baixo, pi - 1);
        quickSortDisponibilidade(arr, pi + 1, alto);
    }
}

void ordenarDisponibilidade()
{
    FILE *arquivo_disponibilidade = fopen("DISPOADV.dat", "rb");
    if (arquivo_disponibilidade == NULL)
    {
        printf("Erro ao abrir o arquivo de disponibilidade!\n");
        return;
    }

    fseek(arquivo_disponibilidade, 0, SEEK_END);
    int tamanho = ftell(arquivo_disponibilidade) / sizeof(DisponibilidadeAdvogado);
    rewind(arquivo_disponibilidade);

    DisponibilidadeAdvogado *disponibilidade = (DisponibilidadeAdvogado *)malloc(tamanho * sizeof(DisponibilidadeAdvogado));
    if (disponibilidade == NULL)
    {
        printf("Erro ao alocar memória!\n");
        fclose(arquivo_disponibilidade);
        return;
    }

    fread(disponibilidade, sizeof(DisponibilidadeAdvogado), tamanho, arquivo_disponibilidade);

    quickSortDisponibilidade(disponibilidade, 0, tamanho - 1);

    FILE *arquivo_ordenado = fopen("DISPOADV_ORD.dat", "wb");
    if (arquivo_ordenado == NULL)
    {
        printf("Erro ao abrir o arquivo de disponibilidade!\n");
        free(disponibilidade);
        return;
    }

    fwrite(disponibilidade, sizeof(DisponibilidadeAdvogado), tamanho, arquivo_ordenado);
    fclose(arquivo_ordenado);
    free(disponibilidade);

    printf("Disponibilidade ordenada com sucesso!\n");
}

void trocarCasosAtribuidos(CasosAtribuidos *a, CasosAtribuidos *b)
{
    CasosAtribuidos temp = *a;
    *a = *b;
    *b = temp;
}

int particionarCasosAtribuidos(CasosAtribuidos arr[], int baixo, int alto)
{
    CasosAtribuidos pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++)
    {
        if (arr[j].codestag < pivo.codestag)
        {
            i++;
            trocarCasosAtribuidos(&arr[i], &arr[j]);
        }
    }
    trocarCasosAtribuidos(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSortCasosAtribuidos(CasosAtribuidos arr[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionarCasosAtribuidos(arr, baixo, alto);
        quickSortCasosAtribuidos(arr, baixo, pi - 1);
        quickSortCasosAtribuidos(arr, pi + 1, alto);
    }
}

void ordenarCasosAtribuidos()
{
    FILE *arquivo_casos_atribuidos = fopen("CASOSATRIBUIDOS.dat", "rb");
    if (arquivo_casos_atribuidos == NULL)
    {
        printf("Erro ao abrir o arquivo de casos atribuidos!\n");
        return;
    }

    fseek(arquivo_casos_atribuidos, 0, SEEK_END);
    int tamanho = ftell(arquivo_casos_atribuidos) / sizeof(CasosAtribuidos);
    rewind(arquivo_casos_atribuidos);

    CasosAtribuidos *casos_atribuidos = (CasosAtribuidos *)malloc(tamanho * sizeof(CasosAtribuidos));
    if (casos_atribuidos == NULL)
    {
        printf("Erro ao alocar memória!\n");
        fclose(arquivo_casos_atribuidos);
        return;
    }

    fread(casos_atribuidos, sizeof(CasosAtribuidos), tamanho, arquivo_casos_atribuidos);
    fclose(arquivo_casos_atribuidos);

    quickSortCasosAtribuidos(casos_atribuidos, 0, tamanho - 1);

    FILE *arquivo_ordenado = fopen("CASOSATRIBUIDOS_ORD.dat", "wb");
    if (arquivo_ordenado == NULL)
    {
        printf("Erro ao abrir o arquivo de casos atribuidos!\n");
        free(casos_atribuidos);
        return;
    }

    fwrite(casos_atribuidos, sizeof(CasosAtribuidos), tamanho, arquivo_ordenado);
    fclose(arquivo_ordenado);
    free(casos_atribuidos);

    printf("Casos atribuidos ordenados com sucesso!\n");
}

void trocarControleCasos(ControleCasos *a, ControleCasos *b)
{
    ControleCasos temp = *a;
    *a = *b;
    *b = temp;
}

int particionarControleCasos(ControleCasos arr[], int baixo, int alto)
{
    ControleCasos pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++)
    {
        if (strcmp(arr[j].numprocesso, pivo.numprocesso) < 0)
        {
            i++;
            trocarControleCasos(&arr[i], &arr[j]);
        }
    }
    trocarControleCasos(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quickSortControleCasos(ControleCasos arr[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = particionarControleCasos(arr, baixo, alto);
        quickSortControleCasos(arr, baixo, pi - 1);
        quickSortControleCasos(arr, pi + 1, alto);
    }
}

void ordenarControleCasos()
{
    FILE *arquivo_controle_casos = fopen("CONTROLE.dat", "rb");
    if (arquivo_controle_casos == NULL)
    {
        printf("Erro ao abrir o arquivo de controle de casos!\n");
        return;
    }

    fseek(arquivo_controle_casos, 0, SEEK_END);
    int tamanho = ftell(arquivo_controle_casos) / sizeof(ControleCasos);
    rewind(arquivo_controle_casos);

    ControleCasos *controle_casos = (ControleCasos *)malloc(tamanho * sizeof(ControleCasos));
    if (controle_casos == NULL)
    {
        printf("Erro ao alocar memória!\n");
        fclose(arquivo_controle_casos);
        return;
    }

    fread(controle_casos, sizeof(ControleCasos), tamanho, arquivo_controle_casos);
    fclose(arquivo_controle_casos);

    quickSortControleCasos(controle_casos, 0, tamanho - 1);

    FILE *arquivo_ordenado = fopen("CONTROLE_ORD.dat", "wb");
    if (arquivo_ordenado == NULL)
    {
        printf("Erro ao abrir o arquivo de controle de casos!\n");
        free(controle_casos);
        return;
    }

    fwrite(controle_casos, sizeof(ControleCasos), tamanho, arquivo_ordenado);
    fclose(arquivo_ordenado);
    free(controle_casos);

    printf("Controle de casos ordenado com sucesso!\n");
}

int buscaBinariaEstagiarios(Estagiario estagiarios[], int tamanho, int codestag)
{
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        // Verifica se o código do estagiário está no meio
        if (estagiarios[meio].codestag == codestag)
            return meio;

        // Se o código for maior, ignora a metade esquerda
        if (estagiarios[meio].codestag < codestag)
            esquerda = meio + 1;

        // Se o código for menor, ignora a metade direita
        else
            direita = meio - 1;
    }

    // Retorna -1 se o estagiário não for encontrado
    return -1;
}

int buscaBinariaCasosAtribuidos(CasosAtribuidos casos_atribuidos[], int tamanho, int codestag, const char *cpf)
{
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        // Verifica se o código do estagiário e o CPF do cliente estão no meio
        if (casos_atribuidos[meio].codestag == codestag && strcmp(casos_atribuidos[meio].cpf, cpf) == 0)
            return meio;

        // Se o código do estagiário for maior, ignora a metade esquerda
        if (casos_atribuidos[meio].codestag < codestag)
            esquerda = meio + 1;

        // Se o código do estagiário for menor, ignora a metade direita
        else
            direita = meio - 1;
    }

    // Retorna -1 se o caso atribuído não for encontrado
    return -1;
}

int buscaBinariaControleCasos(ControleCasos controle_casos[], int tamanho, const char *numprocesso)
{
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        // Verifica se o número do processo está no meio
        if (strcmp(controle_casos[meio].numprocesso, numprocesso) == 0)
            return meio;

        // Se o número do processo for maior, ignora a metade esquerda
        if (strcmp(controle_casos[meio].numprocesso, numprocesso) < 0)
            esquerda = meio + 1;

        // Se o número do processo for menor, ignora a metade direita
        else
            direita = meio - 1;
    }

    // Retorna -1 se o controle de caso não for encontrado
    return -1;
}

int valida_tempo(const char *tempo)
{
    if (strlen(tempo) != 5 || tempo[2] != ':')
    {
        return 0;
    }
    for (int i = 0; i < 5; i++)
    {
        if (i != 2 && !isdigit(tempo[i]))
        {
            return 0;
        }
    }
    int hora = (tempo[0] - '0') * 10 + (tempo[1] - '0');
    int minuto = (tempo[3] - '0') * 10 + (tempo[4] - '0');
    if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59)
    {
        return 0;
    }
    return 1;
}

int valida_cpf(const char *cpf)
{
    if (strlen(cpf) != 11)
    {
        return 0;
    }
    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(cpf[i]))
        {
            return 0;
        }
    }
    return 1;
}

int valida_data(const char *data)
{
    if (strlen(data) != 10 || data[2] != '/' || data[5] != '/')
    {
        return 0;
    }
    for (int i = 0; i < 10; i++)
    {
        if ((i != 2 && i != 5) && !isdigit(data[i]))
        {
            return 0;
        }
    }
    int dia = (data[0] - '0') * 10 + (data[1] - '0');
    int mes = (data[3] - '0') * 10 + (data[4] - '0');
    int ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + (data[8] - '0') * 10 + (data[9] - '0');

    if (mes < 1 || mes > 12)
    {
        return 0;
    }
    if (dia < 1 || dia > 31)
    {
        return 0;
    }
    if (mes == 2)
    {
        int bissexto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
        if (dia > 29 || (dia == 29 && !bissexto))
        {
            return 0;
        }
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if (dia > 30)
        {
            return 0;
        }
    }
    return 1;
}

int verificarDisponibilidade(const char *data, const char *horario)
{
    FILE *arquivo_agendamento = fopen("AGENDA.dat", "rb");
    if (arquivo_agendamento == NULL)
    {
        printf("Erro ao abrir o arquivo de agendamentos!\n");
        return 0;
    }

    Agendamento agendamento;
    while (fread(&agendamento, sizeof(Agendamento), 1, arquivo_agendamento) == 1)
    {
        if (strcmp(agendamento.dataatend, data) == 0 && strcmp(agendamento.horarioatend, horario) == 0)
        {
            fclose(arquivo_agendamento);
            return 1;
        }
    }

    fclose(arquivo_agendamento);
    return 0;
}

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void registrarDisponibilidade()
{
    DisponibilidadeAdvogado disponibilidadeadvogado;
    int oab;
    char op;

    FILE *arquivo_disponibilidade = fopen("DISPOADV.dat", "ab");
    if (arquivo_disponibilidade == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    FILE *arquivo_advogados = fopen("ADVOG_ORD.dat", "rb");
    if (arquivo_advogados == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        fclose(arquivo_disponibilidade);
        return;
    }

    fseek(arquivo_advogados, 0, SEEK_END);
    int tamanho = ftell(arquivo_advogados) / sizeof(Advogado);
    rewind(arquivo_advogados);

    Advogado *advogados = (Advogado *)malloc(tamanho * sizeof(Advogado));
    if (advogados == NULL)
    {
        printf("Erro ao alocar memória!\n");
        fclose(arquivo_disponibilidade);
        fclose(arquivo_advogados);
        return;
    }

    fread(advogados, sizeof(Advogado), tamanho, arquivo_advogados);
    fclose(arquivo_advogados);

    do
    {
        printf("Registrar Disponibilidade\n");
        printf("Preencha os dados da disponibilidade:\n");

        int advogado_encontrado = 0;
        for (int tentativas_advogado = 0; tentativas_advogado < 3; tentativas_advogado++)
        {
            printf("Número da OAB: ");
            scanf("%d", &oab);
            limpar_buffer();

            int indice = buscaBinariaAdvogados(advogados, tamanho, oab);
            if (indice != -1)
            {
                disponibilidadeadvogado.oabdispo = oab;
                advogado_encontrado = 1;
                break;
            }

            printf("Número da OAB não encontrado! Tentativas restantes: %d\n", 2 - tentativas_advogado);
        }

        if (!advogado_encontrado)
        {
            printf("Número máximo de tentativas alcançado.\n");
            free(advogados);
            fclose(arquivo_disponibilidade);
            return;
        }

        printf("Dia da semana que atende: (Se tiver mais de um dia, separar por vírgula)\n");
        scanf(" %[^\n]", disponibilidadeadvogado.diasemana);
        limpar_buffer();

        printf("Horário de início do atendimento (HH:MM): ");
        scanf("%6s", disponibilidadeadvogado.hrinicio);
        limpar_buffer();

        while (!valida_tempo(disponibilidadeadvogado.hrinicio))
        {
            printf("Formato inválido! Digite novamente (HH:MM): ");
            scanf("%6s", disponibilidadeadvogado.hrinicio);
            limpar_buffer();
        }

        printf("Horário de término do atendimento (HH:MM): ");
        scanf("%6s", disponibilidadeadvogado.hrfim);
        limpar_buffer();

        while (!valida_tempo(disponibilidadeadvogado.hrfim))
        {
            printf("Formato inválido! Digite novamente (HH:MM): ");
            scanf("%6s", disponibilidadeadvogado.hrfim);
            limpar_buffer();
        }

        printf("Formato de atendimento (P-Presencial/R-Remoto): ");
        scanf("%s", disponibilidadeadvogado.formaatendimento);
        limpar_buffer();

        while (strcmp(disponibilidadeadvogado.formaatendimento, "P") != 0 && strcmp(disponibilidadeadvogado.formaatendimento, "R") != 0)
        {
            printf("Opção inválida! Digite novamente (P-Presencial/R-Remoto): ");
            scanf("%s", disponibilidadeadvogado.formaatendimento);
            limpar_buffer();
        }

        printf("Deseja salvar a disponibilidade? (S-Sim/N-Não): ");
        scanf("%c", &op);
        limpar_buffer();

        if (op == 'S')
        {
            fwrite(&disponibilidadeadvogado, sizeof(DisponibilidadeAdvogado), 1, arquivo_disponibilidade);
        }
        else
        {
            printf("Cadastro cancelado!\n");
            fclose(arquivo_disponibilidade);
            free(advogados);
            return;
        }

        fclose(arquivo_disponibilidade);
        free(advogados);

    } while (op != 'S' && op != 'N');
    printf("Disponibilidade registrada com sucesso!\n");
}

void triagem()
{
    Triagem cliente;
    static int id = 1;
    cliente.id = id++;
    float salario_minimo = 1412.0;
    char op;

    FILE *arquivo;

    arquivo = fopen("clientes.dat", "ab");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    do
    {
        printf("Preencha os dados do cliente:\n");
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);

        strftime(cliente.data, sizeof(cliente.data), "%d/%m/%Y", tm);

        strftime(cliente.horario_atendimento, sizeof(cliente.horario_atendimento), "%H:%M", tm);

        printf("Horário de chegada (HH:MM): ");
        scanf("%6s", cliente.horario_chegada);
        while (!valida_tempo(cliente.horario_chegada))
        {
            printf("Formato inválido! Digite novamente (HH:MM): ");
            scanf("%6s", cliente.horario_chegada);
            limpar_buffer();
        }

        printf("Como ficou sabendo do nosso serviço: ");
        scanf(" %[^\n]", cliente.como_soube);
        limpar_buffer();

        printf("Nome do atendente responsável pela Triagem: ");
        scanf(" %[^\n]", cliente.nome_atendente);
        limpar_buffer();

        printf("Pessoa física ou jurídica (PF/PJ): ");
        scanf("%s", cliente.tipo_pessoa);
        limpar_buffer();

        while (strcmp(cliente.tipo_pessoa, "PF") != 0 && strcmp(cliente.tipo_pessoa, "PJ") != 0)
        {
            printf("Opção inválida! Digite novamente (PF/PJ): ");
            scanf("%s", cliente.tipo_pessoa);
            limpar_buffer();
        }

        printf("Nome: ");
        scanf(" %[^\n]", cliente.nome);
        limpar_buffer();

        printf("Gênero: ");
        scanf(" %[^\n]", cliente.genero);
        limpar_buffer();

        printf("Pertence à comunidade LGBTQIA+ (S-Sim/N-Não): ");
        scanf("%s", cliente.lgbtqia);
        limpar_buffer();

        while (strcmp(cliente.lgbtqia, "S") != 0 && strcmp(cliente.lgbtqia, "N") != 0)
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf("%s", cliente.lgbtqia);
            limpar_buffer();
        }

        printf("Cor-raça: ");
        scanf(" %[^\n]", cliente.cor_raca);
        limpar_buffer();

        printf("Data de nascimento (DD/MM/AAAA): ");
        scanf("%s", cliente.data_nascimento);
        limpar_buffer();

        while (!valida_data(cliente.data_nascimento))
        {
            printf("Data inválida! Digite novamente (DD/MM/AAAA): ");
            scanf("%s", cliente.data_nascimento);
            limpar_buffer();
        }

        printf("Nacionalidade: ");
        scanf(" %[^\n]", cliente.nacionalidade);
        limpar_buffer();

        printf("Naturalidade: ");
        scanf(" %[^\n]", cliente.naturalidade);
        limpar_buffer();

        printf("CPF: ");
        scanf("%s", cliente.cpf);
        limpar_buffer();

        while (!valida_cpf(cliente.cpf))
        {
            printf("CPF inválido! Digite novamente: ");
            scanf("%s", cliente.cpf);
            limpar_buffer();
        }

        printf("RG: ");
        scanf(" %[^\n]", cliente.rg);
        limpar_buffer();

        printf("Endereço: ");
        scanf(" %[^\n]", cliente.endereco);
        limpar_buffer();

        printf("Celular: ");
        scanf("%s", cliente.celular);
        limpar_buffer();

        printf("Usa WhatsApp (S-Sim/N-Não): ");
        scanf("%s", cliente.usa_whatsapp);
        limpar_buffer();

        while (strcmp(cliente.usa_whatsapp, "S") != 0 && strcmp(cliente.usa_whatsapp, "N") != 0)
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf("%s", cliente.usa_whatsapp);
            limpar_buffer();
        }

        printf("Telefone para contato alternativo: ");
        scanf("%s", cliente.telefone_alternativo);
        limpar_buffer();

        printf("E-mail: ");
        scanf("%s", cliente.email);
        limpar_buffer();

        printf("Escolaridade: ");
        scanf(" %[^\n]", cliente.escolaridade);
        limpar_buffer();

        printf("Profissão: ");
        scanf(" %[^\n]", cliente.profissao);
        limpar_buffer();

        printf("Situação de emprego (Empregado/Autônomo/Desempregado): ");
        scanf(" %[^\n]", cliente.situacao_emprego);
        limpar_buffer();

        printf("Estado civil: ");
        scanf(" %[^\n]", cliente.estado_civil);
        limpar_buffer();

        printf("Tem filhos (S-Sim/N-Não): ");
        scanf("%s", cliente.tem_filhos);
        limpar_buffer();

        while (strcmp(cliente.tem_filhos, "S") != 0 && strcmp(cliente.tem_filhos, "N") != 0)
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf("%s", cliente.tem_filhos);
            limpar_buffer();
        }

        if (strcmp(cliente.tem_filhos, "S") == 0)
        {
            printf("Quantos filhos moram com você: ");
            scanf("%d", &cliente.filhos_moram_com_voce);
            limpar_buffer();
        }
        else
        {
            cliente.filhos_moram_com_voce = 0;
        }

        printf("Total de membros da sua entidade familiar: ");
        scanf("%d", &cliente.total_membros_familia);
        limpar_buffer();

        printf("Recebe benefício assistencial ou rendimentos concedidos por programa oficial de transferência de renda (S-Sim/N-Não): ");
        scanf("%s", cliente.recebe_beneficio);
        limpar_buffer();

        while (strcmp(cliente.recebe_beneficio, "S") != 0 && strcmp(cliente.recebe_beneficio, "N") != 0)
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf("%s", cliente.recebe_beneficio);
            limpar_buffer();
        }

        if (strcmp(cliente.recebe_beneficio, "S") == 0)
        {
            printf("Qual valor do benefício: ");
            scanf("%f", &cliente.valor_beneficio);
            limpar_buffer();
        }
        else
        {
            cliente.valor_beneficio = 0;
        }

        printf("Qual o valor da sua renda mensal: ");
        scanf("%f", &cliente.renda_mensal);
        limpar_buffer();

        printf("Qual o valor total de ganhos mensais de outros membros da sua entidade familiar, excetuando menores de 16 anos: ");
        scanf("%f", &cliente.renda_membros_familia);
        limpar_buffer();

        printf("Tem gastos com tratamento médico por doença grave ou para o atendimento de necessidade especial com qualquer membro da entidade familiar (S-Sim/N-Não): ");
        scanf("%s", cliente.gastos_tratamento);
        limpar_buffer();

        while (strcmp(cliente.gastos_tratamento, "S") != 0 && strcmp(cliente.gastos_tratamento, "N") != 0)
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf("%s", cliente.gastos_tratamento);
            limpar_buffer();
        }

        if (strcmp(cliente.gastos_tratamento, "S") == 0)
        {
            printf("Qual valor: ");
            scanf("%f", &cliente.valor_gastos_tratamento);
            limpar_buffer();
        }
        else
        {
            cliente.valor_gastos_tratamento = 0;
        }

        printf("Possui investimentos (S-Sim/N-Não): ");
        scanf("%2s", cliente.possui_investimentos);
        limpar_buffer();

        while (strcmp(cliente.possui_investimentos, "S") != 0 && strcmp(cliente.possui_investimentos, "N") != 0)
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf("%2s", cliente.possui_investimentos);
            limpar_buffer();
        }

        if (strcmp(cliente.possui_investimentos, "S") == 0)
        {
            printf("Qual valor do investimento: ");
            scanf("%f", &cliente.valor_investimento);
            limpar_buffer();
        }
        else
        {
            cliente.valor_investimento = 0;
        }

        printf("Possui casa própria (S-Sim/N-Não): ");
        scanf("%s", cliente.possui_casa_propria);
        limpar_buffer();

        while (strcmp(cliente.possui_casa_propria, "S") != 0 && strcmp(cliente.possui_casa_propria, "N") != 0)
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf("%s", cliente.possui_casa_propria);
            limpar_buffer();
        }

        if (strcmp(cliente.possui_casa_propria, "S") == 0)
        {
            printf("Qual valor: ");
            scanf("%f", &cliente.valor_casa_propria);
            limpar_buffer();
        }
        else
        {
            cliente.valor_casa_propria = 0;
        }

        printf("Possui apartamento (S-Sim/N-Não): ");
        scanf("%s", cliente.possui_apartamento);
        limpar_buffer();

        while (strcmp(cliente.possui_apartamento, "S") != 0 && strcmp(cliente.possui_apartamento, "N") != 0)
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf("%s", cliente.possui_apartamento);
            limpar_buffer();
        }

        if (strcmp(cliente.possui_apartamento, "S") == 0)
        {
            printf("Qual valor: ");
            scanf("%f", &cliente.valor_apartamento);
            limpar_buffer();
        }
        else
        {
            cliente.valor_apartamento = 0;
        }

        printf("Possui terreno (S-Sim/N-Não): ");
        scanf("%s", cliente.possui_terreno);
        limpar_buffer();

        while (strcmp(cliente.possui_terreno, "S") != 0 && strcmp(cliente.possui_terreno, "N") != 0)
        {
            printf("Opção inválida! Digite novamente (Sim/Não): ");
            scanf("%s", cliente.possui_terreno);
            limpar_buffer();
        }

        if (strcmp(cliente.possui_terreno, "S") == 0)
        {
            printf("Qual valor: ");
            scanf("%f", &cliente.valor_terreno);
            limpar_buffer();
        }
        else
        {
            cliente.valor_terreno = 0;
        }

        printf("Possui imóvel comercial (S-Sim/N-Não): ");
        scanf("%s", cliente.possui_imovel_comercial);
        limpar_buffer();

        while (strcmp(cliente.possui_imovel_comercial, "S") != 0 && strcmp(cliente.possui_imovel_comercial, "N") != 0)
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf("%s", cliente.possui_imovel_comercial);
            limpar_buffer();
        }

        if (strcmp(cliente.possui_imovel_comercial, "S") == 0)
        {
            printf("Qual valor: ");
            scanf("%f", &cliente.valor_imovel_comercial);
            limpar_buffer();
        }
        else
        {
            cliente.valor_imovel_comercial = 0;
        }

        printf("Possui automóvel (S-Sim/N-Não): ");
        scanf("%s", cliente.possui_automovel);
        limpar_buffer();

        while (strcmp(cliente.possui_automovel, "S") != 0 && strcmp(cliente.possui_automovel, "N") != 0)
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf("%s", cliente.possui_automovel);
            limpar_buffer();
        }

        if (strcmp(cliente.possui_automovel, "S") == 0)
        {
            printf("Qual valor: ");
            scanf("%f", &cliente.valor_automovel);
            limpar_buffer();
        }
        else
        {
            cliente.valor_automovel = 0;
        }

        printf("A demanda envolve violência doméstica (S-Sim/N-Não): ");
        scanf("%s", cliente.envolve_violencia_domestica);
        limpar_buffer();

        while (strcmp(cliente.envolve_violencia_domestica, "S") != 0 && strcmp(cliente.envolve_violencia_domestica, "N") != 0)
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf("%s", cliente.envolve_violencia_domestica);
            limpar_buffer();
        }

        printf("Resumo do caso: ");
        scanf(" %[^\n]", cliente.resumo_caso);
        limpar_buffer();

        printf("Matéria relacionada à demanda solicitada (Cível/Família e Sucessões/Trabalhista/Penal/Previdenciário/Outro): ");
        scanf(" %[^\n]", cliente.materia_relacionada);
        limpar_buffer();

        if (cliente.renda_membros_familia <= (3 * salario_minimo))
        {
            printf("A pessoa foi admitida para ser patrocinada pelo DJa.\n");
            strcpy(cliente.enquadrado_lei_1060, "S");
        }
        else if (cliente.renda_membros_familia <= (4 * salario_minimo))
        {
            int criterio_admissao = 0;

            if (cliente.total_membros_familia > 5)
            {
                criterio_admissao = 1;
            }

            if (strcmp(cliente.gastos_tratamento, "S") == 0)
            {
                criterio_admissao = 1;
            }

            int possui_pessoa_com_deficiencia_ou_idosa;
            printf("A entidade familiar possui pessoa com deficiência, transtorno global do desenvolvimento, pessoa idosa ou egressa do sistema prisional? (1 para Sim / 0 para Não): ");
            scanf("%d", &possui_pessoa_com_deficiencia_ou_idosa);
            limpar_buffer();

            if (possui_pessoa_com_deficiencia_ou_idosa == 1 && cliente.total_membros_familia >= 4)
            {
                criterio_admissao = 1;
            }

            if (criterio_admissao == 1)
            {
                printf("A pessoa foi admitida para ser patrocinada pelo DJa.\n");
                strcpy(cliente.enquadrado_lei_1060, "S");
            }
            else
            {
                printf("A pessoa não foi admitida para ser patrocinada pelo DJa.\n");
                strcpy(cliente.enquadrado_lei_1060, "N");
            }
        }

        printf("Deseja salvar os dados da triagem? (S-Sim/N-Não): ");
        scanf("%c", &op);
        limpar_buffer();

        if (op == 'S')
        {
            fwrite(&cliente, sizeof(Triagem), 1, arquivo);
        }
        else
        {
            printf("Triagem cancelada!\n");
            return;
        }
    } while (op != 'S' && op != 'N');

    fclose(arquivo);

    printf("Triagem realizada com sucesso!\n");
}

void mostrarDisponibilidade()
{
    ordenarDisponibilidade();

    DisponibilidadeAdvogado disponibilidadeadvogado;
    Advogado advogado;

    FILE *arquivo_disponibilidade;
    arquivo_disponibilidade = fopen("DISPOADV_ORD.dat", "rb");
    if (arquivo_disponibilidade == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    FILE *arquivo_advogados;
    arquivo_advogados = fopen("ADVOG_ORD.dat", "rb");
    if (arquivo_advogados == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        fclose(arquivo_advogados);
        return;
    }

    if (fread(&advogado, sizeof(Advogado), 1, arquivo_advogados) == 0)
    {
        printf("Não há advogados cadastrados!\n");
        fclose(arquivo_disponibilidade);
        fclose(arquivo_advogados);
        return;
    }

    rewind(arquivo_advogados);

    if (fread(&disponibilidadeadvogado, sizeof(DisponibilidadeAdvogado), 1, arquivo_disponibilidade) == 0)
    {
        printf("Não há disponibilidade cadastrada!\n");
        fclose(arquivo_disponibilidade);
        fclose(arquivo_advogados);
        return;
    }

    rewind(arquivo_disponibilidade);

    printf("Disponibilidade dos Advogados\n");
    printf("%-10s %-30s %-20s %-30s %-10s %-10s %-15s\n", "OAB", "Nome", "Email", "Dias", "Início", "Fim", "Formato");

    while (fread(&disponibilidadeadvogado, sizeof(DisponibilidadeAdvogado), 1, arquivo_disponibilidade) == 1)
    {
        rewind(arquivo_advogados);
        while (fread(&advogado, sizeof(Advogado), 1, arquivo_advogados) == 1)
        {
            if (disponibilidadeadvogado.oabdispo == advogado.oab)
            {
                printf("%-10d %-30s %-20s %-30s %-10s %-10s %-15s\n", disponibilidadeadvogado.oabdispo, advogado.nomeadv, advogado.emailadv, disponibilidadeadvogado.diasemana, disponibilidadeadvogado.hrinicio, disponibilidadeadvogado.hrfim, disponibilidadeadvogado.formaatendimento);
                break;
            }
        }
    }

    fclose(arquivo_disponibilidade);
    fclose(arquivo_advogados);

    printf("Pressione Enter para continuar...\n");
    getchar();
}

void plantaoAdvogados(Advogado *advogados, int num_advogados, FilaAgendamentos *filasAdvogados)
{
    mostrarDisponibilidade();

    Agendamento agendamento;
    Estagiario *estagiarios = NULL;
    int num_estagiarios = 0;
    char op;
    int tentativas = 0;

    FILE *arquivo_agendamento;
    arquivo_agendamento = fopen("AGENDA.dat", "ab");
    if (arquivo_agendamento == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    FILE *arquivo_estagiarios;
    arquivo_estagiarios = fopen("ESTAG_ORD.dat", "rb");
    if (arquivo_estagiarios == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        fclose(arquivo_estagiarios);
        return;
    }

    fseek(arquivo_estagiarios, 0, SEEK_END);
    num_estagiarios = ftell(arquivo_estagiarios) / sizeof(Estagiario);
    rewind(arquivo_estagiarios);

    estagiarios = (Estagiario *)malloc(num_estagiarios * sizeof(Estagiario));
    if (estagiarios == NULL)
    {
        printf("Erro ao alocar memória!\n");
        fclose(arquivo_agendamento);
        fclose(arquivo_estagiarios);
        return;
    }
    fread(estagiarios, sizeof(Estagiario), num_estagiarios, arquivo_estagiarios);

    do
    {

        printf("Agendamento de Plantão\n");
        printf("Preencha os dados do agendamento:\n");

        tentativas = 0;
        int estagiario_encontrado = 0;
        while (tentativas < 2 && !estagiario_encontrado)
        {
            printf("Código do estagiário: ");
            scanf("%d", &agendamento.codestag);
            limpar_buffer();

            for (int i = 0; i < num_estagiarios; i++)
            {
                if (agendamento.codestag == estagiarios[i].codestag)
                {
                    estagiario_encontrado = 1;
                    break;
                }
            }

            if (!estagiario_encontrado)
            {
                tentativas++;
                printf("Código do estagiário não encontrado! Tentativas restantes: %d\n", 2 - tentativas);
            }
        }

        if (!estagiario_encontrado)
        {
            printf("Código do estagiário incorreto. Retornando ao menu.\n");
            free(estagiarios);
            fclose(arquivo_agendamento);
            fclose(arquivo_estagiarios);
            return;
        }

        tentativas = 0;
        int advogado_encontrado = 0;
        while (tentativas < 2 && !advogado_encontrado)
        {
            printf("Número da OAB: ");
            scanf("%d", &agendamento.oab);
            limpar_buffer();

            for (int i = 0; i < num_advogados; i++)
            {
                if (agendamento.oab == advogados[i].oab)
                {
                    advogado_encontrado = 1;
                    strcpy(agendamento.area_direito, advogados[i].especialidade); // Preencher automaticamente
                    break;
                }
            }

            if (!advogado_encontrado)
            {
                tentativas++;
                printf("Número da OAB não encontrado! Tentativas restantes: %d\n", 2 - tentativas);
            }
        }

        if (!advogado_encontrado)
        {
            printf("Número da OAB incorreto. Retornando ao menu.\n");
            free(estagiarios);
            fclose(arquivo_agendamento);
            fclose(arquivo_estagiarios);
            return;
        }

        printf("Data do agendamento (DD/MM/AAAA): ");
        scanf("%11s", agendamento.dataatend);
        limpar_buffer();

        while (!valida_data(agendamento.dataatend))
        {
            printf("Data inválida! Digite novamente (DD/MM/AAAA): ");
            scanf("%11s", agendamento.dataatend);
            limpar_buffer();
        }

        printf("Horário do agendamento (HH:MM): ");
        scanf("%6s", agendamento.horarioatend);
        limpar_buffer();

        while (!valida_tempo(agendamento.horarioatend))
        {
            printf("Formato inválido! Digite novamente (HH:MM): ");
            scanf("%6s", agendamento.horarioatend);
            limpar_buffer();
        }

        if (verificarDisponibilidade(agendamento.dataatend, agendamento.horarioatend))
        {
            printf("Horário indisponível! Escolha outro horário.\n");
            free(estagiarios);
            fclose(arquivo_agendamento);
            system("pause");
            fclose(arquivo_estagiarios);
            return;
        }

        time_t t = time(NULL);
        struct tm *tm = localtime(&t);

        strftime(agendamento.datainsc, sizeof(agendamento.datainsc), "%d/%m/%Y", tm);
        strftime(agendamento.horains, sizeof(agendamento.horains), "%H:%M", tm);

        printf("Tipo de orientação buscada (correção de petição simples, correção de inicial, correção de contestação, correção de réplica, correção de recurso, correção de resposta ao recurso, dúvida, correção de petição complexa): ");
        scanf(" %[^\n]", agendamento.tipo_orientacao);

        printf("O prazo judicial para manifestação é prescricional (S-Sim/N-Não): ");
        scanf("%s", agendamento.prazofatal);
        limpar_buffer();

        while (strcmp(agendamento.prazofatal, "S") != 0 && strcmp(agendamento.prazofatal, "N") != 0)
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf("%s", agendamento.prazofatal);
            limpar_buffer();
        }

        printf("Observações: ");
        scanf(" %[^\n]", agendamento.observacoes);
        limpar_buffer();

        printf("Número dos autos (Numero de Processo): ");
        scanf(" %[^\n]", agendamento.numprocesso);
        limpar_buffer();

        printf("Deseja salvar o agendamento? (S-Sim/N-Não): ");
        scanf("%c", &op);
        limpar_buffer();

        if (op == 'S')
        {
            // Adiciona o agendamento à fila do advogado
            for (int i = 0; i < num_advogados; i++)
            {
                if (advogados[i].oab == agendamento.oab)
                {
                    enfileirar(&filasAdvogados[i], agendamento);
                    printf("Agendamento adicionado à fila do advogado %s.\n", advogados[i].nomeadv);
                    fwrite(&agendamento, sizeof(Agendamento), 1, arquivo_agendamento); // Salva no arquivo
                    break;
                }
            }
        }
        else
        {
            printf("Agendamento cancelado!\n");
            free(estagiarios);
            fclose(arquivo_agendamento);
            fclose(arquivo_estagiarios);
            return;
        }

        printf("Agendamento realizado com sucesso!\n");

    } while (op != 'S' && op != 'N');

    printf("Pressione Enter para sair...\n");
    getchar();

    free(estagiarios);
    fclose(arquivo_agendamento);
    fclose(arquivo_estagiarios);
}

void atendimentoAdvogados(Advogado *advogados, int num_advogados, FilaAgendamentos *filasAdvogados)
{
    int oab, tentativas = 0;
    Agendamento agendamento;

    printf("Digite o número da sua OAB: ");
    scanf("%d", &oab);
    limpar_buffer();

    // Verificar a OAB com até 2 tentativas
    int indexAdvogado = -1;
    while (tentativas < 2)
    {
        for (int i = 0; i < num_advogados; i++)
        {
            if (advogados[i].oab == oab)
            {
                indexAdvogado = i;
                break;
            }
        }

        if (indexAdvogado != -1)
        {
            break;
        }
        else
        {
            tentativas++;
            if (tentativas < 2)
            {
                printf("OAB não encontrada! Tente novamente: ");
                scanf("%d", &oab);
                limpar_buffer();
            }
        }
    }

    if (indexAdvogado == -1)
    {
        printf("Número da OAB não encontrado após 2 tentativas. Retornando ao menu principal.\n");
        printf("Pressione Enter para continuar...\n");
        getchar();
        return;
    }

    // verifiar se a fila está vazia
    if (filaVazia(&filasAdvogados[indexAdvogado]))
    {
        printf("Não há agendamentos para o advogado %s.\n", advogados[indexAdvogado].nomeadv);
        printf("Pressione Enter para continuar...\n");
        getchar();
        return;
    }

    // Atender o primeiro agendamento da fila
    agendamento = desenfileirar(&filasAdvogados[indexAdvogado]);
    printf("Atendendo agendamento:\n");
    printf("Estagiário: %d\n", agendamento.codestag);
    printf("Área de Direito: %s\n", agendamento.area_direito);
    printf("Tipo de Orientação: %s\n", agendamento.tipo_orientacao);
    printf("Número do Processo: %s\n", agendamento.numprocesso);
    printf("Prazo Fatal: %s\n", agendamento.prazofatal);
    printf("Observações: %s\n", agendamento.observacoes);
    printf("Pressione Enter para continuar...\n");
    getchar();

    // Marcar como atendido e salvar alterações
    printf("Foi atendido (S-Sim/N-Não ou comentário breve): ");
    scanf(" %[^\n]", agendamento.foiatend);
    limpar_buffer();

    while (strcmp(agendamento.foiatend, "S") != 0 && strcmp(agendamento.foiatend, "N") != 0)
    {
        printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
        scanf(" %[^\n]", agendamento.foiatend);
        limpar_buffer();
    }

    FILE *arquivo_agendamento = fopen("AGENDA.dat", "rb+");
    if (arquivo_agendamento == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Agendamento agendamentoTemp;
    int encontrado = 0;

    while (fread(&agendamentoTemp, sizeof(Agendamento), 1, arquivo_agendamento))
    {
        if (agendamentoTemp.codestag == agendamento.codestag &&
            strcmp(agendamentoTemp.numprocesso, agendamento.numprocesso) == 0)
        {
            encontrado = 1;
            // Voltar o ponteiro para o início deste registro
            fseek(arquivo_agendamento, -(long)sizeof(Agendamento), SEEK_CUR);
            fwrite(&agendamento, sizeof(Agendamento), 1, arquivo_agendamento);
            fflush(arquivo_agendamento);
            break;
        }
    }

    fclose(arquivo_agendamento);

    if (encontrado)
    {
        printf("Agendamento atendido com sucesso!\n");
        printf("Pressione Enter para continuar...\n");
        getchar();
    }
    else
    {
        printf("Erro: Agendamento não encontrado no arquivo!\n");
        system("pause");
    }
}

void adicionarPublicacoes()
{
    Publicacao publicacao;
    CasosAtribuidos casosatribuidos[100];
    int num_casos = 0;
    char op;

    FILE *arquivo_publicacao;
    arquivo_publicacao = fopen("PUBLICACAO.dat", "ab");
    if (arquivo_publicacao == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    FILE *arquivo_casosatribuidos;
    arquivo_casosatribuidos = fopen("CASOSATRIBUIDOS_ORD.dat", "rb");
    if (arquivo_casosatribuidos == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        fclose(arquivo_casosatribuidos);
        return;
    }

    while (fread(&casosatribuidos[num_casos], sizeof(CasosAtribuidos), 1, arquivo_casosatribuidos))
    {
        num_casos++;
    }

    fclose(arquivo_casosatribuidos);

    do
    {
        printf("Adicionar Publicações\n");
        printf("Preencha os dados da publicação:\n");

        printf("Número do processo: ");
        scanf("%20s", publicacao.numprocesso);
        limpar_buffer();

        printf("Codigo do estagiário: ");
        scanf("%d", &publicacao.codestag);
        limpar_buffer();

        printf("CPF do cliente: ");
        scanf("%[^\n]", publicacao.cpf);
        limpar_buffer();

        while (!valida_cpf(publicacao.cpf))
        {
            printf("CPF inválido! Digite novamente: ");
            scanf("%s", publicacao.cpf);
            limpar_buffer();
        }

        if (buscaBinariaCasosAtribuidos(casosatribuidos, num_casos, publicacao.codestag, publicacao.cpf) == -1)
        {
            printf("Estagiário e CPF não encontrados nos casos atribuídos!\n");
            printf("Voltando ao menu principal...\n");
            fclose(arquivo_publicacao);
            return; // Encerra a função e retorna ao menu
        }

        printf("Data da publicação (DD/MM/AAAA): ");
        scanf("%11s", publicacao.dtcircula);
        limpar_buffer();

        while (!valida_data(publicacao.dtcircula))
        {
            printf("Data inválida! Digite novamente (DD/MM/AAAA): ");
            scanf("%11s", publicacao.dtcircula);
            limpar_buffer();
        }

        printf("Hora de circulação (HH:MM): ");
        scanf("%6s", publicacao.hrcircula);
        limpar_buffer();

        while (!valida_tempo(publicacao.hrcircula))
        {
            printf("Formato inválido! Digite novamente (HH:MM): ");
            scanf("%6s", publicacao.hrcircula);
            limpar_buffer();
        }

        printf("Tipo de publicação (Petição Inicial/Contestação/Recurso/Outro): ");
        scanf("%[^\n]", publicacao.tipoacao);
        limpar_buffer();

        printf("Vara/Juízo: ");
        scanf("%[^\n]", publicacao.varajuizo);
        limpar_buffer();

        printf("Foro: ");
        scanf("%[^\n]", publicacao.foro);
        limpar_buffer();

        printf("Nome do Reclamado: ");
        scanf("%[^\n]", publicacao.reclamado);
        limpar_buffer();

        printf("Advogado do Reclamante: ");
        scanf("%[^\n]", publicacao.advreclamante);
        limpar_buffer();

        printf("Advogado do Reclamado: ");
        scanf("%[^\n]", publicacao.advreclamado);
        limpar_buffer();

        printf("Movimentação Processual: ");
        scanf("%[^\n]", publicacao.movimentacao);
        limpar_buffer();

        printf("Deseja salvar a publicação? (S-Sim/N-Não): ");
        scanf("%c", &op);
        limpar_buffer();

        if (op == 'S')
        {
            fwrite(&publicacao, sizeof(Publicacao), 1, arquivo_publicacao);
        }
        else
        {
            printf("Publicação cancelada!\n");
            fclose(arquivo_publicacao);
            fclose(arquivo_casosatribuidos);
            return;
        }
    } while (op != 'S' && op != 'N');

    fclose(arquivo_publicacao);
}

void mostrarPublicacoes()
{
    Publicacao publicacao;

    FILE *arquivo_publicacao;
    arquivo_publicacao = fopen("PUBLICACAO.dat", "rb");
    if (arquivo_publicacao == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("----------------------------------------\n");
    printf("Publicações\n");
    printf("----------------------------------------\n");
    while (fread(&publicacao, sizeof(Publicacao), 1, arquivo_publicacao))
    {
        printf("========================================\n");
        printf("Número do processo: %s\n", publicacao.numprocesso);
        printf("Código do estagiário: %d\n", publicacao.codestag);
        printf("CPF do cliente: %s\n", publicacao.cpf);
        printf("Data da publicação: %s\n", publicacao.dtcircula);
        printf("Hora de circulação: %s\n", publicacao.hrcircula);
        printf("Tipo de publicação: %s\n", publicacao.tipoacao);
        printf("Vara/Juízo: %s\n", publicacao.varajuizo);
        printf("Foro: %s\n", publicacao.foro);
        printf("Nome do Reclamado: %s\n", publicacao.reclamado);
        printf("Advogado do Reclamante: %s\n", publicacao.advreclamante);
        printf("Advogado do Reclamado: %s\n", publicacao.advreclamado);
        printf("Movimentação Processual: %s\n", publicacao.movimentacao);
        printf("========================================\n");
    }

    fclose(arquivo_publicacao);
}

void acompanhamentoCasos()
{
    ControleCasos controlecasos;
    CasosAtribuidos casosatribuidos[100];
    char op;
    int num_casos = 0;

    FILE *arquivo_controle = fopen("CONTROLE.dat", "ab");
    if (arquivo_controle == NULL)
    {
        printf("Erro ao abrir o arquivo de controle!\n");
        return;
    }

    FILE *arquivo_casosatribuidos = fopen("CASOSATRIBUIDOS_ORD.dat", "rb");
    if (arquivo_casosatribuidos == NULL)
    {
        printf("Erro ao abrir o arquivo de casos atribuídos!\n");
        fclose(arquivo_controle);
        return;
    }

    while (fread(&casosatribuidos[num_casos], sizeof(CasosAtribuidos), 1, arquivo_casosatribuidos))
    {
        num_casos++;
    }
    fclose(arquivo_casosatribuidos);

    do
    {
        printf("\nAcompanhamento de Casos\n");
        printf("Preencha os dados do acompanhamento:\n");

        printf("Número do processo: ");
        scanf(" %20[^\n]", controlecasos.numprocesso);
        limpar_buffer();

        printf("Tema: ");
        scanf(" %50[^\n]", controlecasos.tema);
        limpar_buffer();

        printf("CPF do cliente: ");
        scanf(" %11[^\n]", controlecasos.cpf);
        limpar_buffer();

        printf("Código do estagiário: ");
        scanf("%d", &controlecasos.codestag);
        limpar_buffer();

        if (buscaBinariaCasosAtribuidos(casosatribuidos, num_casos, controlecasos.codestag, controlecasos.cpf) == -1)
        {
            printf("Estagiário e CPF não encontrados nos casos atribuídos!\n");
            printf("Voltando ao menu principal...\n");
            fclose(arquivo_controle);
            return;
        }

        printf("Polo (Reclamante/Reclamado/Exequente/Executado): ");
        scanf(" %20[^\n]", controlecasos.polo);
        limpar_buffer();

        printf("Data do próximo controle (DD/MM/AAAA): ");
        scanf(" %10s", controlecasos.dtcontrole);
        limpar_buffer();
        while (!valida_data(controlecasos.dtcontrole))
        {
            printf("Data inválida! Digite novamente (DD/MM/AAAA): ");
            scanf(" %10s", controlecasos.dtcontrole);
            limpar_buffer();
        }

        printf("Próxima tarefa (Peticionar/Acompanhar/Renúncia/Encerrar atendimento/Audiência/Diligência/Transferir): ");
        scanf(" %50[^\n]", controlecasos.proxtarefa);
        limpar_buffer();

        printf("Foi deferido prazo em dobro (S-Sim/N-Não): ");
        scanf(" %1s", controlecasos.temprazodobro);
        limpar_buffer();
        while (strcmp(controlecasos.temprazodobro, "S") != 0 && strcmp(controlecasos.temprazodobro, "N") != 0)
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf(" %1s", controlecasos.temprazodobro);
            limpar_buffer();
        }

        printf("Observação sobre o prazo a cumprir: ");
        scanf(" %500[^\n]", controlecasos.obsprazo);
        limpar_buffer();

        printf("Está marcada audiência (S-Sim/N-Não): ");
        scanf(" %1s", controlecasos.audiencia);
        limpar_buffer();
        while (strcmp(controlecasos.audiencia, "S") != 0 && strcmp(controlecasos.audiencia, "N") != 0)
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf(" %1s", controlecasos.audiencia);
            limpar_buffer();
        }

        printf("Data do prazo simples (DD/MM/AAAA): ");
        scanf(" %10s", controlecasos.prazosimples);
        limpar_buffer();
        while (!valida_data(controlecasos.prazosimples))
        {
            printf("Data inválida! Digite novamente (DD/MM/AAAA): ");
            scanf(" %10s", controlecasos.prazosimples);
            limpar_buffer();
        }

        printf("Data do prazo dobrado (DD/MM/AAAA): ");
        scanf(" %10s", controlecasos.prazodobrado);
        limpar_buffer();
        while (!valida_data(controlecasos.prazodobrado))
        {
            printf("Data inválida! Digite novamente (DD/MM/AAAA): ");
            scanf(" %10s", controlecasos.prazodobrado);
            limpar_buffer();
        }

        printf("Movimentação processual: ");
        scanf(" %500[^\n]", controlecasos.movimentacao);
        limpar_buffer();

        printf("Dias até o próximo controle: ");
        scanf("%d", &controlecasos.diasproxcontrole);
        limpar_buffer();

        printf("Data da proposição da ação (DD/MM/AAAA): ");
        scanf(" %10s", controlecasos.dtproposicao);
        limpar_buffer();
        while (!valida_data(controlecasos.dtproposicao))
        {
            printf("Data inválida! Digite novamente (DD/MM/AAAA): ");
            scanf(" %10s", controlecasos.dtproposicao);
            limpar_buffer();
        }

        printf("Deseja salvar o acompanhamento? (S-Sim/N-Não): ");
        scanf(" %c", &op);
        limpar_buffer();

        if (op == 'S')
        {
            fwrite(&controlecasos, sizeof(ControleCasos), 1, arquivo_controle);
            printf("Acompanhamento salvo com sucesso!\n");
        }
        else
        {
            printf("Acompanhamento cancelado!\n");
        }

    } while (op != 'S' && op != 'N');

    fclose(arquivo_controle);

    ordenarControleCasos();
    printf("Pressione Enter para continuar...\n");
    getchar();
}

void editarAcompanhamentoCasos()
{
    Publicacao publicacao;
    int op_tarefa;
    char op_urgente;
    char op;
    char numprocesso[20];
    char movimentacao[100];
    char data[11];
    char ciente;

    FILE *arquivo_publicacao;
    arquivo_publicacao = fopen("PUBLICACAO.dat", "rb");
    if (arquivo_publicacao == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        fclose(arquivo_publicacao);
        return;
    }

    FILE *arquivo_controle;
    arquivo_controle = fopen("CONTROLE_ORD.dat", "rb+");
    if (arquivo_controle == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fseek(arquivo_controle, 0, SEEK_END);
    int tamanho = ftell(arquivo_controle) / sizeof(ControleCasos);
    rewind(arquivo_controle);

    ControleCasos *controle_casos = (ControleCasos *)malloc(tamanho * sizeof(ControleCasos));
    if (controle_casos == NULL)
    {
        printf("Erro ao alocar memória!\n");
        fclose(arquivo_controle);
        return;
    }

    fread(controle_casos, sizeof(ControleCasos), tamanho, arquivo_controle);
    fclose(arquivo_controle);

    do
    {
        printf("Digite o número do processo que deseja editar: ");
        scanf("%20s", numprocesso);
        limpar_buffer();

        // Procurar o número do processo no arquivo de publicações
        int encontrou_publicacao = 0;
        while (fread(&publicacao, sizeof(Publicacao), 1, arquivo_publicacao) == 1)
        {
            printf("Comparando com processo: %s\n", publicacao.numprocesso); // Debug

            if (strcmp(publicacao.numprocesso, numprocesso) == 0)
            {
                encontrou_publicacao = 1;
                break;
            }
        }

        fclose(arquivo_publicacao);

        if (!encontrou_publicacao)
        {
            printf("Não existem atualizações para o processo %s.\n", numprocesso);
            free(controle_casos);
            return;
        }

        int index = buscaBinariaControleCasos(controle_casos, tamanho, numprocesso);

        if (index == -1)
        {
            printf("Número do processo não encontrado!\n");
            free(controle_casos);
            return;
        }

        printf("Existem alterações disponíveis para o processo %s.\n", numprocesso);
        printf("Digite o texto da nova movimentação: ");
        scanf("%100[^\n]", movimentacao);
        limpar_buffer();

        strcat(controle_casos[index].movimentacao, "\n");
        strcat(controle_casos[index].movimentacao, movimentacao);

        printf("Digite a data da movimentação (dd/mm/aaaa): ");
        scanf("%11s", data);
        limpar_buffer();

        while (!valida_data(data))
        {
            printf("Data inválida! Digite novamente (dd/mm/aaaa): ");
            scanf("%11s", data);
            limpar_buffer();
        }

        strcat(controle_casos[index].movimentacao, " - Data: ");
        strcat(controle_casos[index].movimentacao, data);

        printf("O estagiário está ciente da movimentação? (S-Sim/N-Não): ");
        scanf("%c", &ciente);
        limpar_buffer();

        while (ciente != 'S' && ciente != 'N')
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf("%c", &ciente);
            limpar_buffer();
        }

        if (ciente == 'S')
        {
            strcat(controle_casos[index].movimentacao, " - Estagiário ciente");
        }
        else
        {
            strcat(controle_casos[index].movimentacao, " - Estagiário não ciente");
        }

        printf("Selecione a próxima tarefa:\n");
        printf("================================\n");
        printf("1 - Peticionar\n");
        printf("2 - Acompanhar\n");
        printf("3 - Renúncia\n");
        printf("4 - Encerrar atendimento\n");
        printf("5 - Audiência\n");
        printf("6 - Diligência\n");
        printf("7 - Transferir\n");
        printf("================================\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &op_tarefa);
        limpar_buffer();

        switch (op_tarefa)
        {
        case 1:
            strcpy(controle_casos[index].proxtarefa, "Peticionar");
            break;
        case 2:
            strcpy(controle_casos[index].proxtarefa, "Acompanhar");
            break;
        case 3:
            strcpy(controle_casos[index].proxtarefa, "Renúncia");
            break;
        case 4:
            strcpy(controle_casos[index].proxtarefa, "Encerrar atendimento");
            break;
        case 5:
            strcpy(controle_casos[index].proxtarefa, "Audiência");
            break;
        case 6:
            strcpy(controle_casos[index].proxtarefa, "Diligência");
            break;
        case 7:
            strcpy(controle_casos[index].proxtarefa, "Transferir");
            break;
        default:
            printf("Opção inválida! Retornando ao menu principal.\n");
            free(controle_casos);
            return;
        }

        if (strcmp(controle_casos[index].proxtarefa, "Peticionar") == 0)
        {
            printf("Digite o prazo simples (dd/mm/aaaa): ");
            scanf("%11s", controle_casos[index].prazosimples);
            limpar_buffer();

            while (!valida_data(controle_casos[index].prazosimples))
            {
                printf("Data inválida! Digite novamente (dd/mm/aaaa): ");
                scanf("%11s", controle_casos[index].prazosimples);
                limpar_buffer();
            }

            printf("Digite o prazo dobrado (dd/mm/aaaa): ");
            scanf("%11s", controle_casos[index].prazodobrado);
            limpar_buffer();

            while (!valida_data(controle_casos[index].prazodobrado))
            {
                printf("Data inválida! Digite novamente (dd/mm/aaaa): ");
                scanf("%11s", controle_casos[index].prazodobrado);
                limpar_buffer();
            }
        }
        else
        {
            strcpy(controle_casos[index].prazosimples, "");
            strcpy(controle_casos[index].prazodobrado, "");
        }

        printf("É necessário que o DJa se manifeste urgentemente? (S-Sim/N-Não): ");
        scanf("%c", &op_urgente);
        limpar_buffer();

        while (op_urgente != 'S' && op_urgente != 'N')
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf("%c", &op_urgente);
            limpar_buffer();
        }

        if (op_urgente == 'S')
        {
            printf("Digite o novo prazo para manifestação: ");
            scanf("%99[^\n]", controle_casos[index].obsprazo);
            limpar_buffer();
        }

        if (strcmp(controle_casos[index].proxtarefa, "Renúncia") == 0 || strcmp(controle_casos[index].proxtarefa, "Encerrar atendimento") == 0)
        {
            strcat(controle_casos[index].movimentacao, " - Caso encerrado por ");
            strcat(controle_casos[index].movimentacao, controle_casos[index].proxtarefa);
        }

        printf("Deseja salvar as alterações? (S-Sim/N-Não): ");
        scanf("%c", &op);
        limpar_buffer();

        if (op == 'S')
        {
            FILE *arquivo_controle_atualizado;
            arquivo_controle_atualizado = fopen("CONTROLE_ORD.dat", "rb+");
            if (arquivo_controle == NULL)
            {
                printf("Erro ao abrir o arquivo!\n");
                free(controle_casos);
                return;
            }

            fseek(arquivo_controle_atualizado, index * sizeof(ControleCasos), SEEK_SET);
            fwrite(&controle_casos[index], sizeof(ControleCasos), 1, arquivo_controle_atualizado);
            fclose(arquivo_controle_atualizado);
        }
        else
        {
            printf("Alterações canceladas!\n");
            free(controle_casos);
            return;
        }

    } while (op != 'S' && op != 'N');

    printf("Alterações realizadas com sucesso!\n");
    free(controle_casos);
}

void mostrarAcompanhamentoCasos()
{
    ControleCasos controlecasos;
    FILE *arquivo;
    arquivo = fopen("CONTROLE_ORD.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if (fread(&controlecasos, sizeof(ControleCasos), 1, arquivo) == 0)
    {
        printf("Não há acompanhamentos de casos cadastrados!\n");
        fclose(arquivo);
        return;
    }
    rewind(arquivo);

    printf("--------------------------------\n");
    printf("Controle de Casos:\n");
    printf("--------------------------------\n");
    while (fread(&controlecasos, sizeof(ControleCasos), 1, arquivo) == 1)
    {
        printf("========================================================\n");
        printf("Número do processo: %s\n", controlecasos.numprocesso);
        printf("Tema: %s\n", controlecasos.tema);
        printf("CPF do cliente: %s\n", controlecasos.cpf);
        printf("Código do estagiário: %d\n", controlecasos.codestag);
        printf("Polo: %s\n", controlecasos.polo);
        printf("Data do próximo controle: %s\n", controlecasos.dtcontrole);
        printf("Próxima tarefa: %s\n", controlecasos.proxtarefa);
        printf("Prazo em dobro: %s\n", controlecasos.temprazodobro);
        printf("Observação sobre o prazo: %s\n", controlecasos.obsprazo);
        printf("Audiência marcada: %s\n", controlecasos.audiencia);
        printf("Prazo simples: %s\n", controlecasos.prazosimples);
        printf("Prazo dobrado: %s\n", controlecasos.prazodobrado);
        printf("Movimentação processual: %s\n", controlecasos.movimentacao);
        printf("Dias até o próximo controle: %d\n", controlecasos.diasproxcontrole);
        printf("Data da proposição da ação: %s\n", controlecasos.dtproposicao);
        printf("========================================================\n");
        getchar();
    }
    printf("Pressione Enter para continuar...\n");
    getchar();
    fclose(arquivo);
    return;
}

void menuAcompanhamentoCasos()
{
    int op;

    do
    {
        system("cls");
        printf("================================\n");
        printf("Menu de Acompanhamento de Casos\n");
        printf("================================\n");
        printf("1 - Adicionar Controle de Casos\n");
        printf("2 - Editar Controle de Casos\n");
        printf("3 - Mostrar Controle de Casos\n");
        printf("4 - Voltar ao Menu Principal\n");
        printf("================================\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &op);
        limpar_buffer();

        switch (op)
        {
        case 1:
            system("cls");
            acompanhamentoCasos();
            break;
        case 2:
            system("cls");
            mostrarPublicacoes();
            editarAcompanhamentoCasos();
            break;
        case 3:
            system("cls");
            mostrarAcompanhamentoCasos();
            break;
        case 4:
            return;
        default:
            printf("Opção inválida! Digite novamente.\n");
            break;
        }
    } while (op != 4);
}

void adicionarEstagiarios()
{
    Estagiario estagiario;
    FILE *arquivo;
    char op;

    arquivo = fopen("ESTAG.dat", "ab");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    do
    {
        printf("Adicionar Estagiários\n");
        printf("Preencha os dados do estagiário:\n");

        printf("Código do estagiário: ");
        scanf("%d", &estagiario.codestag);
        limpar_buffer();

        printf("Nome do estagiário: ");
        scanf(" %[^\n]", estagiario.nomestag);
        limpar_buffer();

        printf("Celular do estagiário: ");
        scanf("%s", estagiario.celularestag);
        limpar_buffer();

        printf("Email do estagiário: ");
        scanf("%s", estagiario.Emailestag);
        limpar_buffer();

        printf("Tipo do estagiário (P-Plantonista/A-Atendente/V-Vareiro): ");
        scanf("%s", estagiario.tipo);
        limpar_buffer();

        while (strcmp(estagiario.tipo, "P") != 0 && strcmp(estagiario.tipo, "A") != 0 && strcmp(estagiario.tipo, "V") != 0)
        {
            printf("Opção inválida! Digite novamente (P-Plantonista/A-Atendente/V-Vareiro): ");
            scanf("%s", estagiario.tipo);
            limpar_buffer();
        }

        fwrite(&estagiario, sizeof(Estagiario), 1, arquivo);

        printf("Deseja salvar o estagiário? (S-Sim/N-Não): ");
        scanf("%c", &op);
        limpar_buffer();

        if (op == 'S')
        {
            fwrite(&estagiario, sizeof(Estagiario), 1, arquivo);
        }
        else
        {
            printf("Cadastro cancelado!\n");
            fclose(arquivo);
            return;
        }

        fclose(arquivo);

    } while (op != 'S' && op != 'N');
    printf("Estagiário cadastrado com sucesso!\n");
}

void mostrarClientes()

{
    // Mostra Somente os clientes que foram admitidos
    Triagem cliente;
    FILE *arquivo;
    arquivo = fopen("clientes.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if (fread(&cliente, sizeof(Triagem), 1, arquivo) == 0)
    {
        printf("Não há clientes cadastrados!\n");
        fclose(arquivo);
        return;
    }
    rewind(arquivo);

    printf("--------------------------------\n");
    printf("Clientes:\n");
    printf("--------------------------------\n");
    while (fread(&cliente, sizeof(Triagem), 1, arquivo) == 1)
    {
        if (strcmp(cliente.enquadrado_lei_1060, "N") == 0)
        {
            continue;
        }

        printf("================================================\n");
        printf("ID: %d\n", cliente.id);
        printf("Data: %s\n", cliente.data);
        printf("Horário de chegada: %s\n", cliente.horario_chegada);
        printf("Horário de atendimento: %s\n", cliente.horario_atendimento);
        printf("Como soube: %s\n", cliente.como_soube);
        printf("Nome do atendente: %s\n", cliente.nome_atendente);
        printf("Tipo de pessoa: %s\n", cliente.tipo_pessoa);
        printf("Nome: %s\n", cliente.nome);
        printf("Gênero: %s\n", cliente.genero);
        printf("LGBTQIA+: %s\n", cliente.lgbtqia);
        printf("Cor-raça: %s\n", cliente.cor_raca);
        printf("Data de nascimento: %s\n", cliente.data_nascimento);
        printf("Nacionalidade: %s\n", cliente.nacionalidade);
        printf("Naturalidade: %s\n", cliente.naturalidade);
        printf("CPF: %s\n", cliente.cpf);
        printf("RG: %s\n", cliente.rg);
        printf("Endereço: %s\n", cliente.endereco);
        printf("Celular: %s\n", cliente.celular);
        printf("WhatsApp: %s\n", cliente.usa_whatsapp);
        printf("Telefone alternativo: %s\n", cliente.telefone_alternativo);
        printf("E-mail: %s\n", cliente.email);
        printf("Escolaridade: %s\n", cliente.escolaridade);
        printf("Profissão: %s\n", cliente.profissao);
        printf("Situação de emprego: %s\n", cliente.situacao_emprego);
        printf("Estado civil: %s\n", cliente.estado_civil);
        printf("Tem filhos: %s\n", cliente.tem_filhos);
        printf("Filhos moram com você: %d\n", cliente.filhos_moram_com_voce);
        printf("Total membros da família: %d\n", cliente.total_membros_familia);
        printf("Recebe benefício: %s\n", cliente.recebe_beneficio);
        printf("Valor do benefício: %.2f\n", cliente.valor_beneficio);
        printf("Renda mensal: %.2f\n", cliente.renda_mensal);
        printf("Renda membros da família: %.2f\n", cliente.renda_membros_familia);
        printf("Gastos tratamento: %s\n", cliente.gastos_tratamento);
        printf("Valor gastos tratamento: %.2f\n", cliente.valor_gastos_tratamento);
        printf("Possui investimentos: %s\n", cliente.possui_investimentos);
        printf("Valor investimento: %.2f\n", cliente.valor_investimento);
        printf("Possui casa própria: %s\n", cliente.possui_casa_propria);
        printf("Valor casa própria: %.2f\n", cliente.valor_casa_propria);
        printf("Possui apartamento: %s\n", cliente.possui_apartamento);
        printf("Valor apartamento: %.2f\n", cliente.valor_apartamento);
        printf("Possui terreno: %s\n", cliente.possui_terreno);
        printf("Valor terreno: %.2f\n", cliente.valor_terreno);
        printf("Possui imóvel comercial: %s\n", cliente.possui_imovel_comercial);
        printf("Valor imóvel comercial: %.2f\n", cliente.valor_imovel_comercial);
        printf("Possui automóvel: %s\n", cliente.possui_automovel);
        printf("Valor automóvel: %.2f\n", cliente.valor_automovel);
        printf("Resumo do caso: %s\n", cliente.resumo_caso);
        printf("Matéria relacionada: %s\n", cliente.materia_relacionada);
        printf("Enquadrado na Lei 1060: %s\n", cliente.enquadrado_lei_1060);
        printf("================================================\n");
        printf("\n");

        printf("Pressione Enter para continuar...\n");
        getchar();
    }
    fclose(arquivo);
}

void mostrarEstagiarios()
{
    ordenarEstagiarios();

    Estagiario estagiario;
    FILE *arquivo;

    arquivo = fopen("ESTAG_ORD.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if (fread(&estagiario, sizeof(Estagiario), 1, arquivo) == 0)
    {
        printf("Não há estagiários cadastrados!\n");
        getchar();
        fclose(arquivo);
        return;
    }

    printf("--------------------------------\n");
    printf("Estagiários:\n");
    printf("--------------------------------\n");
    while (fread(&estagiario, sizeof(Estagiario), 1, arquivo) == 1)
    {
        printf("================================================\n");
        printf("Código: %d\n", estagiario.codestag);
        printf("Nome: %s\n", estagiario.nomestag);
        printf("Celular: %s\n", estagiario.celularestag);
        printf("Email: %s\n", estagiario.Emailestag);
        printf("Tipo: %s\n", estagiario.tipo);
        printf("================================================\n");
    }
    fclose(arquivo);
    getchar();
}

void mostrarAdvogados()
{
    ordenarAdvogados();

    Advogado advogado;
    FILE *arquivo;
    arquivo = fopen("ADVOG_ORD.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if (fread(&advogado, sizeof(Advogado), 1, arquivo) == 0)
    {
        printf("Não há advogados cadastrados!\n");
        fclose(arquivo);
        return;
    }
    rewind(arquivo);

    printf("--------------------------------\n");
    printf("Advogados:\n");
    printf("--------------------------------\n");

    while (fread(&advogado, sizeof(Advogado), 1, arquivo) == 1)
    {
        printf("================================================\n");
        printf("OAB: %d\n", advogado.oab);
        printf("Nome: %s\n", advogado.nomeadv);
        printf("Celular: %s\n", advogado.celularadv);
        printf("Email: %s\n", advogado.emailadv);
        printf("Especialidade: %s\n", advogado.especialidade);
        printf("================================================\n");

        printf("Pressione Enter para continuar...\n");
        getchar();
    }

    fclose(arquivo);
}

void atribuicaoEstagiarios()
{
    CasosAtribuidos casos;
    Triagem cliente;

    int codestag;
    int id;
    char op;

    FILE *arquivo_casos = fopen("CASOSATRIBUIDOS.dat", "ab");
    if (arquivo_casos == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    FILE *arquivo_clientes = fopen("clientes.dat", "rb");
    if (arquivo_clientes == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        fclose(arquivo_casos);
        return;
    }

    FILE *arquivo_estagiarios = fopen("ESTAG_ORD.dat", "rb");
    if (arquivo_estagiarios == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        fclose(arquivo_casos);
        fclose(arquivo_clientes);
        return;
    }

    if (fread(&cliente, sizeof(Triagem), 1, arquivo_clientes) == 0)
    {
        printf("Não há clientes cadastrados!\n");
        fclose(arquivo_casos);
        fclose(arquivo_clientes);
        fclose(arquivo_estagiarios);
        return;
    }

    // Carregar todos os estagiários em um array para fazer a busca binária
    fseek(arquivo_estagiarios, 0, SEEK_END);
    int tamanho = ftell(arquivo_estagiarios) / sizeof(Estagiario);
    rewind(arquivo_estagiarios);

    Estagiario *estagiarios = (Estagiario *)malloc(tamanho * sizeof(Estagiario));
    if (estagiarios == NULL)
    {
        printf("Erro ao alocar memória!\n");
        fclose(arquivo_casos);
        fclose(arquivo_clientes);
        fclose(arquivo_estagiarios);
        return;
    }

    fread(estagiarios, sizeof(Estagiario), tamanho, arquivo_estagiarios);
    fclose(arquivo_estagiarios);

    do
    {
        printf("Atribuição de Estagiários\n");
        printf("Preencha os dados do caso:\n");

        int estagiario_encontrado = 0;
        for (int tentativas_estagiario = 0; tentativas_estagiario < 3; tentativas_estagiario++)
        {
            printf("Código do estagiário: ");
            scanf("%d", &codestag);
            limpar_buffer();

            int indice = buscaBinariaEstagiarios(estagiarios, tamanho, codestag);
            if (indice != -1 && strcmp(estagiarios[indice].tipo, "P") == 0)
            {
                casos.codestag = codestag;
                estagiario_encontrado = 1;
                break;
            }

            printf("Código do estagiário não encontrado ou não é um plantonista! Tentativas restantes: %d\n", 2 - tentativas_estagiario);
        }

        if (!estagiario_encontrado)
        {
            printf("Número máximo de tentativas alcançado.\n");
            free(estagiarios);
            fclose(arquivo_casos);
            fclose(arquivo_clientes);
            return;
        }

        int cliente_encontrado = 0;
        for (int tentativas_cliente = 0; tentativas_cliente < 3; tentativas_cliente++)
        {
            printf("ID do cliente: ");
            scanf("%d", &id);
            limpar_buffer();

            rewind(arquivo_clientes);
            while (fread(&cliente, sizeof(Triagem), 1, arquivo_clientes) == 1)
            {
                if (cliente.id == id && strcmp(cliente.enquadrado_lei_1060, "S") == 0)
                {
                    strcpy(casos.cpf, cliente.cpf);
                    cliente_encontrado = 1;
                    break;
                }
            }

            if (cliente_encontrado)
                break;

            printf("ID do cliente não encontrado ou não foi admitido! Tentativas restantes: %d\n", 2 - tentativas_cliente);
        }

        if (!cliente_encontrado)
        {
            printf("Número máximo de tentativas alcançado.\n");
            free(estagiarios);
            fclose(arquivo_casos);
            fclose(arquivo_clientes);
            return;
        }

        // Pega a data e hora atual automaticamente
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);

        strftime(casos.datatribuido, sizeof(casos.datatribuido), "%d/%m/%Y", tm);
        strftime(casos.horatribuido, sizeof(casos.horatribuido), "%H:%M", tm);

        printf("Deseja salvar a atribuição? (S-Sim/N-Não): ");
        scanf("%c", &op);
        limpar_buffer();

        while (op != 'S' && op != 'N')
        {
            printf("Opção inválida! Digite novamente (S-Sim/N-Não): ");
            scanf("%c", &op);
            limpar_buffer();
        }

        if (op == 'S')
        {
            fwrite(&casos, sizeof(CasosAtribuidos), 1, arquivo_casos);
        }
        else
        {
            printf("Atribuição cancelada!\n");
            system("pause");
            free(estagiarios);
            fclose(arquivo_casos);
            fclose(arquivo_clientes);
            return;
        }

        free(estagiarios);
        fclose(arquivo_casos);
        fclose(arquivo_clientes);

    } while (op != 'S' && op != 'N');

    printf("Atribuição realizada com sucesso!\n");
    printf("Pressione Enter para continuar...\n");
    getchar();
    return;
}

void mostrarAtribuicao()
{
    ordenarCasosAtribuidos();

    CasosAtribuidos casos;
    FILE *arquivo;
    arquivo = fopen("CASOSATRIBUIDOS_ORD.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        getchar();
        return;
    }

    if (fread(&casos, sizeof(CasosAtribuidos), 1, arquivo) == 0)
    {
        printf("Não há casos atribuídos!\n");
        getchar();
        fclose(arquivo);
        return;
    }

    printf("--------------------------------\n");
    printf("Casos Atribuídos:\n");
    printf("--------------------------------\n");
    while (fread(&casos, sizeof(CasosAtribuidos), 1, arquivo) == 1)
    {
        printf("================================\n");
        printf("Código do estagiário: %d\n", casos.codestag);
        printf("CPF do cliente: %s\n", casos.cpf);
        printf("Data atribuído: %s\n", casos.datatribuido);
        printf("Hora atribuído: %s\n", casos.horatribuido);
        printf("================================\n");
    }
    printf("Pressione Enter para continuar...\n");
    getchar();
    fclose(arquivo);
}

void mostrarAgendamento()
{
    Agendamento agendamento;
    FILE *arquivo;
    arquivo = fopen("AGENDA.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if (fread(&agendamento, sizeof(Agendamento), 1, arquivo) == 0)
    {
        printf("Não há agendamentos cadastrados!\n");
        fclose(arquivo);
        return;
    }
    rewind(arquivo);

    printf("--------------------------------\n");
    printf("Agendamentos:\n");
    printf("--------------------------------\n");
    while (fread(&agendamento, sizeof(Agendamento), 1, arquivo) == 1)
    {
        printf("================================================\n");
        printf("Código do estagiário: %d\n", agendamento.codestag);
        printf("Número da OAB: %d\n", agendamento.oab);
        printf("Data agendado para atendimento: %s\n", agendamento.dataatend);
        printf("Horário AGENDADO para atendimento: %s\n", agendamento.horarioatend);
        printf("Data em que a inscrição foi feita: %s\n", agendamento.datainsc);
        printf("Hora em que a inscrição foi feita: %s\n", agendamento.horains);
        printf("Área do direito: %s\n", agendamento.area_direito);
        printf("Tipo de orientação buscada: %s\n", agendamento.tipo_orientacao);
        printf("Prazo fatal: %s\n", agendamento.prazofatal);
        printf("Observações: %s\n", agendamento.observacoes);
        printf("Número do processo: %s\n", agendamento.numprocesso);
        printf("Foi atendido: %s\n", agendamento.foiatend);
        printf("================================================\n");

        printf("Pressione Enter para continuar...\n");
        getchar();
    }
    fclose(arquivo);
}

void adicionarAdvogados()
{
    Advogado advogado;
    char op;

    FILE *arquivo;
    arquivo = fopen("ADVOG.dat", "ab");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    do
    {
        printf("Adicionar Advogados\n");
        printf("Preencha os dados do advogado:\n");

        printf("Número da OAB: ");
        scanf("%d", &advogado.oab);
        limpar_buffer();

        printf("Nome do advogado: ");
        scanf(" %[^\n]", advogado.nomeadv);
        limpar_buffer();

        printf("Celular do advogado: ");
        scanf("%s", advogado.celularadv);
        limpar_buffer();

        printf("Email do advogado: ");
        scanf("%s", advogado.emailadv);
        limpar_buffer();

        printf("Especialidade do advogado:");
        scanf(" %[^\n]", advogado.especialidade);
        limpar_buffer();

        printf("Ano de ingresso na OAB: ");
        scanf("%s", advogado.anoingresso);
        limpar_buffer();

        printf("CPF do advogado: ");
        scanf("%s", advogado.cpfadv);
        limpar_buffer();

        printf("Deseja Salvar os dados do advogado? (S-Sim/N-Não): ");
        scanf("%c", &op);
        limpar_buffer();

        if (op == 'S')
        {
            fwrite(&advogado, sizeof(Advogado), 1, arquivo);
        }
        else
        {
            printf("Cadastro cancelado!\n");
            return;
        }

        fclose(arquivo);

    } while (op != 'S' && op != 'N');
    printf("Advogado cadastrado com sucesso!\n");
}

void menu()
{
    Advogado *advogados = NULL;
    int num_advogados = 0;

    // Carregar advogados
    carregarAdvogados(&advogados, &num_advogados);

    // Filas de atendimento
    inicializarFilas(num_advogados);

    // Carregar filas de atendimento
    carregarFilas(advogados, num_advogados, filasAdvogados);

    int op;

    do
    {
        system("cls");
        printf("=========================================\n");
        printf("Departamento Jurídico Acadêmico - Menu\n");
        printf("=========================================\n");
        printf("1. Triagem\n");
        printf("2. Mostrar Clientes\n");
        printf("3. Atribuição de Estagiários\n");
        printf("4. Mostrar Advogados\n");
        printf("5. Registrar Disponibilidade\n");
        printf("6. Plantão de Advogados\n");
        printf("7. Atendimento Advogados\n");
        printf("8. Adicionar Publicações\n");
        printf("9. Acompanhamento de Casos\n");
        printf("10. Adicionar Advogados\n");
        printf("11. Adicionar Estagiários\n");
        printf("12. Mostrar Estagiarios\n");
        printf("13. Mostrar Atribuição\n");
        printf("14. Mostrar Agendamento\n");
        printf("0. Sair\n");
        printf("=========================================\n");
        printf("Opção: ");
        scanf("%d", &op);
        limpar_buffer();

        switch (op)
        {
        case 1:
            system("cls");
            triagem();
            break;
        case 2:
            system("cls");
            mostrarClientes();
            break;
        case 3:
            system("cls");
            atribuicaoEstagiarios();
            break;
        case 4:
            system("cls");
            mostrarAdvogados();
            break;
        case 5:
            system("cls");
            registrarDisponibilidade();
            break;
        case 6:
            system("cls");
            plantaoAdvogados(advogados, num_advogados, filasAdvogados);
            break;
        case 7:
            system("cls");
            atendimentoAdvogados(advogados, num_advogados, filasAdvogados);
            break;
        case 8:
            system("cls");
            adicionarPublicacoes();
            break;
        case 9:
            system("cls");
            menuAcompanhamentoCasos();
            break;
        case 10:
            system("cls");
            adicionarAdvogados();
            break;
        case 11:
            system("cls");
            adicionarEstagiarios();
            break;
        case 12:
            system("cls");
            mostrarEstagiarios();
            break;
        case 13:
            system("cls");
            mostrarAtribuicao();
            break;
        case 14:
            system("cls");
            mostrarAgendamento();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção Inválida!\n");
        }
    } while (op != 0);
    liberarFilas(filasAdvogados, num_advogados);
    free(advogados);
}

void menu();
void limpar_buffer();
void triagem();
void atribuicaoEstagiarios();
void mostrarAtribuicao();
void plantaoAdvogados(Advogado *advogados, int num_advogados, FilaAgendamentos *filasAdvogados);
void atendimentoAdvogados(Advogado *advogados, int num_advogados, FilaAgendamentos *filasAdvogados);
void adicionarPublicacoes();
void gerarEMostrarPublicacoesTxt();
void acompanhamentoCasos();
void editarAcompanhamentoCasos();
void menuAcompanhamentoCasos();
void adicionarEstagiarios();
void adicionarAdvogados();
void mostrarClientes();
void mostrarAdvogados();
void mostrarAcompanhamentoCasos();
void registrarDisponibilidade();
void mostrarDisponibilidade();
void mostrarEstagiarios();
void mostrarAgendamentos();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    menu();

    return 0;
}