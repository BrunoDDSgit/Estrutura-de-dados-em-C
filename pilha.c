#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}NASCIMENTO;

typedef struct{
    char nome[50];
    char sexo;
    char nacionalidade[35];
    NASCIMENTO data_nascimento;
}PESSOA;

typedef struct no{
    PESSOA pessoa;
    struct no *proximo;
}NO;

void imprimirPessoa(PESSOA pessoa){
    printf("\n Nome: %s Sexo: %c \n Nacionalidade: %s Data de nascimento: %02d/%02d/%02d", pessoa.nome, pessoa.sexo, pessoa.nacionalidade, pessoa.data_nascimento.dia,pessoa.data_nascimento.mes,pessoa.data_nascimento.ano);
}

PESSOA criarPessoa() {
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

NO* inserirPessoa(NO* topo){
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

NO* removerPessoa(NO **topo){
    if (*topo!=NULL){
        NO *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else
        printf("Pilha vazia");
    return NULL;
    
}

void imprimirPilha(NO *topo){
    printf("\n\n =-=-=-=-=-=-=-= Pilha =-=-=-=-=-=-=-=\n");
    while (topo!=NULL)
    {
        imprimirPessoa(topo->pessoa);
        topo = topo->proximo;
    }
    
}

int main(void){
    int opcao;
    NO *remover, *topo = NULL;

    printf("Iniciando o programa...\n");

    do
    {
        opcao = 0;
        printf("\n\n=-=-=-=-=-=-=-=-=-= @ =-=-=-=-=-=-=-=-=-=\n");
        printf("Selecione uma opcao: \n");
        printf("[1] Inserir Nova Pessoa\n[2] Excluir Pessoa\n[3] Imprimir Pilha\n[4] Finalizar Programa\n");
        printf("=-=-=-=-=-=-=-=-=-= @ =-=-=-=-=-=-=-=-=-=\n\n");
        scanf("%d", &opcao);
        getchar();


        switch (opcao)
        {
        case 1:
            topo = inserirPessoa(topo);
            break;
        
        case 2:
            remover = removerPessoa(&topo);
            if (remover!=NULL)
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
            return 0;
            break;
        
        default:
            printf("Opcao invalida");
            break;
        }
    } while (opcao!=4);
    
    

    return 0;
}