#include <stdio.h>

struct Acao {
    int codigo;
    char escola[50];
    char tema[50];
    char data[20];
    char publico[50];
    char responsavel[50];
    int participantesEsperados;
    int participantesReais;
    int status;
};

struct Acao acoes[100];
int total = 0;

void lerTexto(char texto[], int tamanho) {
    int contador = 0;
    char letra;

    while ((letra = getchar()) != '\n' && letra != EOF) {
        if (contador < tamanho - 1) {
            texto[contador] = letra;
            contador++;
        }
    }

    texto[contador] = '\0';
}

int compararTexto(char texto1[], char texto2[]) {
    int contador = 0;

    while (texto1[contador] == texto2[contador] &&
           texto1[contador] != '\0') {
        contador++;
    }

    if (texto1[contador] == texto2[contador]) {
        return 1;
    }

    return 0;
}

int procurarCodigo(int codigo) {
    int contador = 0;

    while (contador < total) {
        if (acoes[contador].codigo == codigo) {
            return contador;
        }

        contador++;
    }

    return -1;
}

void cadastrar() {
    int codigo;

    if (total >= 100) {
        printf("\nLimite de cadastros atingido!\n");
        return;
    }

    printf("\nDigite o codigo da acao: ");
    scanf("%d", &codigo);
    getchar();

    if (codigo <= 0 || procurarCodigo(codigo) != -1) {
        printf("Codigo invalido ou ja cadastrado!\n");
        return;
    }

    acoes[total].codigo = codigo;

    printf("Digite o nome da escola: ");
    lerTexto(acoes[total].escola, 50);

    printf("Digite o tema da acao: ");
    lerTexto(acoes[total].tema, 50);

    printf("Digite a data: ");
    lerTexto(acoes[total].data, 20);

    printf("Digite o publico-alvo: ");
    lerTexto(acoes[total].publico, 50);

    printf("Digite o responsavel: ");
    lerTexto(acoes[total].responsavel, 50);

    printf("Quantidade de participantes esperados: ");
    scanf("%d", &acoes[total].participantesEsperados);
    getchar();

    if (acoes[total].participantesEsperados < 0) {
        printf("Quantidade invalida!\n");
        return;
    }

    acoes[total].participantesReais = 0;
    acoes[total].status = 1;

    total++;

    printf("\nAcao cadastrada com sucesso!\n");
}

void listar() {
    int contador = 0;

    if (total == 0) {
        printf("\nNenhuma acao cadastrada.\n");
        return;
    }

    while (contador < total) {
        printf("\n-------------------------\n");
        printf("Codigo: %d\n", acoes[contador].codigo);
        printf("Escola: %s\n", acoes[contador].escola);
        printf("Tema: %s\n", acoes[contador].tema);
        printf("Data: %s\n", acoes[contador].data);
        printf("Publico: %s\n", acoes[contador].publico);
        printf("Responsavel: %s\n", acoes[contador].responsavel);
        printf("Participantes esperados: %d\n",
               acoes[contador].participantesEsperados);
        printf("Participantes reais: %d\n",
               acoes[contador].participantesReais);

        if (acoes[contador].status == 1) {
            printf("Status: Planejada\n");
        } else if (acoes[contador].status == 2) {
            printf("Status: Realizada\n");
        } else {
            printf("Status: Cancelada\n");
        }

        contador++;
    }
}

void pesquisar() {
    int opcao;
    int codigo;
    int posicao;
    int contador = 0;
    char nome[50];

    printf("\n--- PESQUISAR ACAO ---\n");
    printf("1 - Pesquisar por codigo\n");
    printf("2 - Pesquisar por escola\n");
    printf("3 - Pesquisar por tema\n");
    printf("Escolha: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
        case 1:
            printf("Digite o codigo: ");
            scanf("%d", &codigo);
            getchar();

            posicao = procurarCodigo(codigo);

            if (posicao != -1) {
                printf("Acao encontrada: %s - %s\n",
                       acoes[posicao].escola,
                       acoes[posicao].tema);
            } else {
                printf("Acao nao encontrada!\n");
            }
            break;

        case 2:
            printf("Digite o nome da escola: ");
            lerTexto(nome, 50);

            while (contador < total) {
                if (compararTexto(acoes[contador].escola, nome)) {
                    printf("Acao encontrada! Codigo: %d\n",
                           acoes[contador].codigo);
                }

                contador++;
            }
            break;

        case 3:
            printf("Digite o tema: ");
            lerTexto(nome, 50);

            while (contador < total) {
                if (compararTexto(acoes[contador].tema, nome)) {
                    printf("Acao encontrada! Codigo: %d\n",
                           acoes[contador].codigo);
                }

                contador++;
            }
            break;

        default:
            printf("Opcao invalida!\n");
    }
}

void atualizarStatus() {
    int codigo;
    int posicao;
    int novoStatus;

    printf("\nDigite o codigo da acao: ");
    scanf("%d", &codigo);
    getchar();

    posicao = procurarCodigo(codigo);

    if (posicao == -1) {
        printf("Acao nao encontrada!\n");
        return;
    }

    printf("\n1 - Planejada\n");
    printf("2 - Realizada\n");
    printf("3 - Cancelada\n");
    printf("Novo status: ");
    scanf("%d", &novoStatus);
    getchar();

    if (novoStatus < 1 || novoStatus > 3) {
        printf("Status invalido!\n");
        return;
    }

    acoes[posicao].status = novoStatus;

    if (novoStatus == 2) {
        printf("Quantidade de participantes reais: ");
        scanf("%d", &acoes[posicao].participantesReais);
        getchar();

        if (acoes[posicao].participantesReais < 0) {
            acoes[posicao].participantesReais = 0;
            printf("Quantidade invalida!\n");
            return;
        }
    }

    printf("Status atualizado com sucesso!\n");
}

void resumo() {
    int contador = 0;
    int planejadas = 0;
    int realizadas = 0;
    int canceladas = 0;
    int participantes = 0;
    int esperados = 0;
    float porcentagem;

    while (contador < total) {
        if (acoes[contador].status == 1) {
            planejadas++;
            esperados += acoes[contador].participantesEsperados;
        } else if (acoes[contador].status == 2) {
            realizadas++;
            esperados += acoes[contador].participantesEsperados;
            participantes += acoes[contador].participantesReais;
        } else {
            canceladas++;
        }

        contador++;
    }

    printf("\n------ RESUMO GERAL ------\n");
    printf("Total de acoes: %d\n", total);
    printf("Acoes planejadas: %d\n", planejadas);
    printf("Acoes realizadas: %d\n", realizadas);
    printf("Acoes canceladas: %d\n", canceladas);
    printf("Participantes reais: %d\n", participantes);
    printf("Participantes esperados: %d\n", esperados);

    if (esperados > 0) {
        porcentagem = (float) participantes / esperados * 100;
        printf("Percentual de participacao: %.2f%%\n", porcentagem);
    } else {
        printf("Percentual de participacao: 0%%\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\n====== SISTEMA PSE EM ACAO ======\n");
        printf("1 - Cadastrar acao\n");
        printf("2 - Listar acoes\n");
        printf("3 - Pesquisar acao\n");
        printf("4 - Atualizar status\n");
        printf("5 - Exibir resumo\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrar();
                break;

            case 2:
                listar();
                break;

            case 3:
                pesquisar();
                break;

            case 4:
                atualizarStatus();
                break;

            case 5:
                resumo();
                break;

            case 0:
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}