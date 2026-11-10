#include <stdio.h>
#include <string.h>

struct Acao {
    int codigo;
    char escola[50];
    char tema[50];
    char data[15];
    char publico[50];
    char responsavel[50];
    int previstos;
    int participantes;
    int situacao;
};

int main() {

    struct Acao acoes[100];

    int quantidade = 0;
    int opcao, i, j;
    int codigo, encontrado;
    int situacao;
    int planejadas, realizadas, canceladas;
    int totalParticipantes, totalPrevistos;
    float percentual;

    char escolaBusca[50];
    char temaBusca[50];

    do {

        printf("\n===== PSE EM ACAO =====\n");
        printf("1 - Cadastrar acao\n");
        printf("2 - Listar acoes\n");
        printf("3 - Pesquisar acao\n");
        printf("4 - Atualizar situacao\n");
        printf("5 - Gerar resumo geral\n");
        printf("0 - Encerrar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:

                if (quantidade < 100) {

                    printf("\nCodigo da acao: ");
                    scanf("%d", &codigo);

                    encontrado = 0;

                    for (i = 0; i < quantidade; i++) {
                        if (acoes[i].codigo == codigo) {
                            encontrado = 1;
                        }
                    }

                    if (encontrado == 1) {

                        printf("\nEsse codigo ja existe!\n");

                    } else {

                        acoes[quantidade].codigo = codigo;

                        printf("Nome da escola: ");
                        scanf(" %49[^\n]", acoes[quantidade].escola);

                        printf("Tema da acao: ");
                        scanf(" %49[^\n]", acoes[quantidade].tema);

                        printf("Data (DD/MM/AAAA): ");
                        scanf(" %14s", acoes[quantidade].data);

                        printf("Publico-alvo: ");
                        scanf(" %49[^\n]", acoes[quantidade].publico);

                        printf("Responsavel: ");
                        scanf(" %49[^\n]", acoes[quantidade].responsavel);

                        do {
                            printf("Quantidade prevista: ");
                            scanf("%d", &acoes[quantidade].previstos);

                            if (acoes[quantidade].previstos < 0) {
                                printf("Quantidade invalida!\n");
                            }

                        } while (acoes[quantidade].previstos < 0);

                        acoes[quantidade].participantes = 0;

                        acoes[quantidade].situacao = 1;

                        quantidade++;

                        printf("\nAcao cadastrada com sucesso!\n");
                    }

                } else {

                    printf("\nLimite de acoes atingido!\n");

                }

                break;

            case 2:

                if (quantidade == 0) {

                    printf("\nNenhuma acao cadastrada.\n");

                } else {

                    for (i = 0; i < quantidade; i++) {

                        printf("\nCodigo: %d\n", acoes[i].codigo);
                        printf("Escola: %s\n", acoes[i].escola);
                        printf("Tema: %s\n", acoes[i].tema);
                        printf("Data: %s\n", acoes[i].data);
                        printf("Publico: %s\n", acoes[i].publico);
                        printf("Responsavel: %s\n", acoes[i].responsavel);
                        printf("Previstos: %d\n", acoes[i].previstos);
                        printf("Participantes: %d\n", acoes[i].participantes);

                        if (acoes[i].situacao == 1) {
                            printf("Situacao: Planejada\n");
                        } else if (acoes[i].situacao == 2) {
                            printf("Situacao: Realizada\n");
                        } else {
                            printf("Situacao: Cancelada\n");
                        }

                    }

                }

                break;

            case 3:

                printf("\nPesquisar por:\n");
                printf("1 - Codigo\n");
                printf("2 - Escola\n");
                printf("3 - Tema\n");
                printf("Escolha: ");
                scanf("%d", &situacao);

                encontrado = 0;

                if (situacao == 1) {

                    printf("Digite o codigo: ");
                    scanf("%d", &codigo);

                    for (i = 0; i < quantidade; i++) {

                        if (acoes[i].codigo == codigo) {

                            encontrado = 1;

                            printf("\nAcao encontrada!\n");
                            printf("Escola: %s\n", acoes[i].escola);
                            printf("Tema: %s\n", acoes[i].tema);
                            printf("Data: %s\n", acoes[i].data);

                        }

                    }

                } else if (situacao == 2) {

                    printf("Digite o nome da escola: ");
                    scanf(" %49[^\n]", escolaBusca);

                    for (i = 0; i < quantidade; i++) {

                        if (strcmp(acoes[i].escola, escolaBusca) == 0) {

                            encontrado = 1;

                            printf("\nCodigo: %d\n", acoes[i].codigo);
                            printf("Tema: %s\n", acoes[i].tema);

                        }

                    }

                } else if (situacao == 3) {

                    printf("Digite o tema: ");
                    scanf(" %49[^\n]", temaBusca);

                    for (i = 0; i < quantidade; i++) {

                        if (strcmp(acoes[i].tema, temaBusca) == 0) {

                            encontrado = 1;

                            printf("\nCodigo: %d\n", acoes[i].codigo);
                            printf("Escola: %s\n", acoes[i].escola);

                        }

                    }

                } else {

                    printf("\nOpcao invalida!\n");

                    break;

                }

                if (encontrado == 0) {
                    printf("\nNenhuma acao encontrada!\n");
                }

                break;

            case 4:

                printf("\nDigite o codigo da acao: ");
                scanf("%d", &codigo);

                encontrado = 0;

                for (i = 0; i < quantidade; i++) {

                    if (acoes[i].codigo == codigo) {

                        encontrado = 1;

                        printf("\nNova situacao:\n");
                        printf("1 - Planejada\n");
                        printf("2 - Realizada\n");
                        printf("3 - Cancelada\n");
                        printf("Escolha: ");
                        scanf("%d", &situacao);

                        if (situacao >= 1 && situacao <= 3) {

                            acoes[i].situacao = situacao;

                            if (situacao == 2) {

                                do {

                                    printf("Quantidade de participantes: ");
                                    scanf("%d", &acoes[i].participantes);

                                    if (acoes[i].participantes < 0) {
                                        printf("Quantidade invalida!\n");
                                    }

                                } while (acoes[i].participantes < 0);

                            } else {

                                acoes[i].participantes = 0;

                            }

                            printf("\nSituacao atualizada!\n");

                        } else {

                            printf("\nOpcao invalida!\n");

                        }

                    }

                }

                if (encontrado == 0) {
                    printf("\nAcao nao encontrada!\n");
                }

                break;

            case 5:

                planejadas = 0;
                realizadas = 0;
                canceladas = 0;
                totalParticipantes = 0;
                totalPrevistos = 0;

                for (i = 0; i < quantidade; i++) {

                    if (acoes[i].situacao == 1) {

                        planejadas++;

                    } else if (acoes[i].situacao == 2) {

                        realizadas++;

                        totalParticipantes += acoes[i].participantes;
                        totalPrevistos += acoes[i].previstos;

                    } else {

                        canceladas++;

                    }

                }

                if (totalPrevistos > 0) {
                    percentual = (float) totalParticipantes / totalPrevistos * 100;
                } else {
                    percentual = 0;
                }

                printf("\n===== RESUMO GERAL =====\n");
                printf("Acoes planejadas: %d\n", planejadas);
                printf("Acoes realizadas: %d\n", realizadas);
                printf("Acoes canceladas: %d\n", canceladas);
                printf("Total de participantes: %d\n", totalParticipantes);
                printf("Percentual de participacao: %.2f%%\n", percentual);

                break;

            case 0:

                printf("\nEncerrando o programa...\n");

                break;

            default:

                printf("\nOpcao invalida! Tente novamente.\n");

        }

    } while (opcao != 0);

    return 0;
}
