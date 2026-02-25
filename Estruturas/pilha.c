#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} NASCIMENTO;

typedef struct
{
    char nome[50];
    char sexo;
    char nacionalidade[35];
    NASCIMENTO data_nascimento;
} PESSOA;

typedef struct no
{
    PESSOA pessoa;
    struct no *proximo;
} NO;

void imprimirPessoa(PESSOA pessoa)
{
    printf("\n Nome: %s Sexo: %c \n Nacionalidade: %s Data de nascimento: %02d/%02d/%02d", pessoa.nome, pessoa.sexo, pessoa.nacionalidade, pessoa.data_nascimento.dia, pessoa.data_nascimento.mes, pessoa.data_nascimento.ano);
}

PESSOA criarPessoa()
{
    PESSOA pessoa;
    printf("Digite o nome: ");
    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
    printf("Digite o sexo: ");
    scanf("%c", &pessoa.sexo);
    getchar();
    printf("Digite a nacionalidade: ");
    fgets(pessoa.nacionalidade, 50, stdin);
    printf("Digite a data de nascimento: dd mm aaaa:\n");
    scanf("%d %d %d", &pessoa.data_nascimento.dia, &pessoa.data_nascimento.mes, &pessoa.data_nascimento.ano);
    return pessoa;
}

NO *inserirPessoa(NO *topo)
{
    NO *novo = malloc(sizeof(NO));
    if (novo)
    {
        novo->pessoa = criarPessoa();
        printf("\n");
        novo->proximo = topo;
        return novo;
    }
    else
        printf("Alocação de Memória malsucedida");
    return topo;
}

NO *removerPessoa(NO **topo)
{
    if (*topo != NULL)
    {
        NO *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else
        printf("Pilha vazia");
    return NULL;
}

void imprimirPilha(NO *topo)
{
    printf("\n\n =-=-=-=-=-=-=-= Pilha =-=-=-=-=-=-=-=\n");
    while (topo != NULL)
    {
        imprimirPessoa(topo->pessoa);
        topo = topo->proximo;
    }
}

void salvarPilha(FILE *arq, NO *topo)
{
    NO *aux = topo;
    int tam = 0;
    arq = fopen("listaPilha.txt", "w");

    if (topo)
    {
        printf("Arquivo aberto com sucesso!");
    }
    else
        printf("Erro: Ponteiro = NULL");

    while (aux != NULL)
    {
        tam++;
        aux = aux->proximo;
    }

    for (int i = 0; i < tam; i++)
    {
        printf("Quantidade de pessoas: %d", tam);
        fprintf(arq, "%s%c\n%s%02d/%02d/%02d\n\n", topo->pessoa.nome, topo->pessoa.sexo, topo->pessoa.nacionalidade, topo->pessoa.data_nascimento.dia, topo->pessoa.data_nascimento.mes, topo->pessoa.data_nascimento.ano);
        topo = topo->proximo;
    }
    fclose(arq);
}

int main(void)
{
    int opcao;
    NO *remover, *topo = NULL;
    FILE *arq;

    printf("Iniciando o programa...\n");

    do
    {
        printf("\n\n=-=-=-=-=-=-=-=-=-= @ =-=-=-=-=-=-=-=-=-=\n");
        printf("Selecione uma opcao: \n");
        printf("[0] Finalizar Programa\n[1] Inserir Nova Pessoa\n[2] Excluir Pessoa\n[3] Imprimir Pilha\n[4] Salvar Pilha Em Arquivo\n[5] Carregar Pilha Em Arquivo\n[6] Excluir Lista\n");
        printf("=-=-=-=-=-=-=-=-=-= @ =-=-=-=-=-=-=-=-=-=\n\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 0:
            return 0;
            break;

        case 1:
            topo = inserirPessoa(topo);
            break;

        case 2:
            remover = removerPessoa(&topo);
            if (remover != NULL)
            {
                printf("pessoa a ser removida: ");
                imprimirPessoa(remover->pessoa);
                free(remover);
                printf("Pessoa removida com sucesso!");
            }
            break;

        case 3:
            imprimirPilha(topo);
            break;

        case 4:
            salvarPilha(arq, topo);
            break;

        case 5:
            break;
        case 6:
            break;

        default:
            printf("Opcao invalida");
            break;
        }
    } while (opcao != 0);

    return 0;
}