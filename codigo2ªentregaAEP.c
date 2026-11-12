#include <stdio.h>
#include <stdlib.h>

void cadastrar(int dados[], int numeros[100][4], char escolas[100][50], char temas[100][50], char datas[100][15], char publicos[100][50], char responsaveis[100][50]){
    int codigo, i, encontrado, posicao;
printf(
"==================================\n"
"         CADASTRAR ACAO           \n"
"==================================\n"
"+--------------------------------+\n"
"|     ____________________       |\n"
"|    |  FICHA DA ACAO     |      |\n"
"|    |  ________________  |      |\n"
"|    |  ________________  |      |\n"
"|    |  ________________  |   /  |\n"
"|    |  ________________  |  /   |\n"
"|    |____________________| /    |\n"
"|                          /     |\n"
"+--------------------------------+\n"
);
    if(dados[0] >= dados[1]){
        printf("\nLimite de acoes atingido!\n");
    }else{
        printf("\nCodigo da acao: ");
        scanf("%d", &codigo);

        encontrado = 0;
        for(i = 0; i < dados[0]; i++){
            if(numeros[i][0] == codigo){
                encontrado = 1;
            }
        }

        if(encontrado == 1){
            printf("\nEsse codigo ja existe!\n");
        }else{
            posicao = dados[0];
            numeros[posicao][0] = codigo;

            printf("Nome da escola: ");
            scanf(" %49[^\n]", escolas[posicao]);
            printf("Tema da acao: ");
            scanf(" %49[^\n]", temas[posicao]);
            printf("Data (DD/MM/AAAA): ");
            scanf(" %14s", datas[posicao]);
            printf("Publico-alvo: ");
            scanf(" %49[^\n]", publicos[posicao]);
            printf("Responsavel: ");
            scanf(" %49[^\n]", responsaveis[posicao]);

            do{
                printf("Quantidade prevista: ");
                scanf("%d", &numeros[posicao][1]);
                if(numeros[posicao][1] < 0){
                    printf("Quantidade invalida!\n");
                }
            }while(numeros[posicao][1] < 0);

            numeros[posicao][2] = 0;
            numeros[posicao][3] = 1;
            dados[0] = dados[0] + 1;

            printf("\nAcao cadastrada com sucesso!!\n");
        }
    }
}

void listar(int dados[], int numeros[100][4], char escolas[100][50], char temas[100][50], char datas[100][15], char publicos[100][50], char responsaveis[100][50]){
    int i;
printf(
"==================================\n"
"          LISTA DE ACOES          \n"
"==================================\n"
);
    if(dados[0] == 0){
        printf("\nNenhuma acao cadastrada.\n");
    }else{
        for(i = 0; i < dados[0]; i++){
            printf("\n----------- ACAO %d -----------\n", i + 1);
            printf("Codigo: %d\n", numeros[i][0]);
            printf("Escola: %s\n", escolas[i]);
            printf("Tema: %s\n", temas[i]);
            printf("Data: %s\n", datas[i]);
            printf("Publico: %s\n", publicos[i]);
            printf("Responsavel: %s\n", responsaveis[i]);
            printf("Previstos: %d\n", numeros[i][1]);
            printf("Participantes: %d\n", numeros[i][2]);
            if(numeros[i][3] == 1){
                printf("Situacao: Planejada\n");
            }else if(numeros[i][3] == 2){
                printf("Situacao: Realizada\n");
            }else{
                printf("Situacao: Cancelada\n");
            }
        }
        printf("-------------------------------\n");
    }
}

void pesquisar(int dados[], int numeros[100][4], char escolas[100][50], char temas[100][50], char datas[100][15]){
    int opPesquisa, codigo, i, k, encontrado, igual, fim;
    char busca[50];
printf(
"==================================\n"
"          PESQUISAR ACAO          \n"
"==================================\n"
"+--------------------------------+\n"
"|           _______              |\n"
"|          /       \\             |\n"
"|         |    ?    |            |\n"
"|          \\_______/             |\n"
"|                  \\\\            |\n"
"|                   \\\\           |\n"
"+--------------------------------+\n"
);
    printf("\nPesquisar por:\n1- Codigo\n2- Escola\n3- Tema\nEscolha: ");
    scanf("%d", &opPesquisa);

    encontrado = 0;
    if(opPesquisa == 1){
        printf("Digite o codigo: ");
        scanf("%d", &codigo);
        for(i = 0; i < dados[0]; i++){
            if(numeros[i][0] == codigo){
                encontrado = 1;
                printf("\nAcao encontrada!\n");
                printf("Escola: %s\n", escolas[i]);
                printf("Tema: %s\n", temas[i]);
                printf("Data: %s\n", datas[i]);
            }
        }
    }else if(opPesquisa == 2){
        printf("Digite o nome da escola: ");
        scanf(" %49[^\n]", busca);
        for(i = 0; i < dados[0]; i++){
            igual = 1;
            fim = 0;
            for(k = 0; k < 50; k++){
                if(fim == 0){
                    if(escolas[i][k] != busca[k]){
                        igual = 0;
                        fim = 1;
                    }else if(busca[k] == '\0'){
                        fim = 1;
                    }
                }
            }
            if(igual == 1){
                encontrado = 1;
                printf("\nCodigo: %d\n", numeros[i][0]);
                printf("Tema: %s\n", temas[i]);
            }
        }
    }else if(opPesquisa == 3){
        printf("Digite o tema: ");
        scanf(" %49[^\n]", busca);
        for(i = 0; i < dados[0]; i++){
            igual = 1;
            fim = 0;
            for(k = 0; k < 50; k++){
                if(fim == 0){
                    if(temas[i][k] != busca[k]){
                        igual = 0;
                        fim = 1;
                    }else if(busca[k] == '\0'){
                        fim = 1;
                    }
                }
            }
            if(igual == 1){
                encontrado = 1;
                printf("\nCodigo: %d\n", numeros[i][0]);
                printf("Escola: %s\n", escolas[i]);
            }
        }
    }else{
        printf("\nOpcao invalida!\n");
        encontrado = 1;
    }

    if(encontrado == 0){
        printf("\nNenhuma acao encontrada!\n");
    }
}

void atualizar(int dados[], int numeros[100][4]){
    int codigo, i, encontrado, situacao;
printf(
"==================================\n"
"        ATUALIZAR SITUACAO        \n"
"==================================\n"
);
    printf("\nDigite o codigo da acao: ");
    scanf("%d", &codigo);

    encontrado = 0;
    for(i = 0; i < dados[0]; i++){
        if(numeros[i][0] == codigo){
            encontrado = 1;
            printf("\nNova situacao:\n1- Planejada\n2- Realizada\n3- Cancelada\nEscolha: ");
            scanf("%d", &situacao);

            if(situacao < 1){
                printf("\nOpcao invalida!\n");
            }else if(situacao > 3){
                printf("\nOpcao invalida!\n");
            }else{
                numeros[i][3] = situacao;
                if(situacao == 2){
                    do{
                        printf("Quantidade de participantes: ");
                        scanf("%d", &numeros[i][2]);
                        if(numeros[i][2] < 0){
                            printf("Quantidade invalida!\n");
                        }
                    }while(numeros[i][2] < 0);
                }else{
                    numeros[i][2] = 0;
                }
                printf("\nSituacao atualizada!!\n");
            }
        }
    }

    if(encontrado == 0){
        printf("\nAcao nao encontrada!\n");
    }
}

void resumo(int dados[], int numeros[100][4]){
    int i, planejadas, realizadas, canceladas, totalParticipantes, totalPrevistos;
    float percentual;

    planejadas = 0;
    realizadas = 0;
    canceladas = 0;
    totalParticipantes = 0;
    totalPrevistos = 0;

    for(i = 0; i < dados[0]; i++){
        if(numeros[i][3] == 1){
            planejadas = planejadas + 1;
        }else if(numeros[i][3] == 2){
            realizadas = realizadas + 1;
            totalParticipantes = totalParticipantes + numeros[i][2];
            totalPrevistos = totalPrevistos + numeros[i][1];
        }else{
            canceladas = canceladas + 1;
        }
    }

    if(totalPrevistos > 0){
        percentual = (float) totalParticipantes / totalPrevistos * 100;
    }else{
        percentual = 0;
    }

printf(
"==================================\n"
"           RESUMO GERAL           \n"
"==================================\n"
"+--------------------------------+\n"
"|                        ___     |\n"
"|              ___      |   |    |\n"
"|     ___     |   |     |   |    |\n"
"|    |   |    |   |     |   |    |\n"
"|    |___|____|___|_____|___|__  |\n"
"+--------------------------------+\n"
);
    printf("Acoes planejadas: %d\n", planejadas);
    printf("Acoes realizadas: %d\n", realizadas);
    printf("Acoes canceladas: %d\n", canceladas);
    printf("Total de participantes: %d\n", totalParticipantes);
    printf("Percentual de participacao: %.2f%%\n", percentual);
    printf("----------------------------------\n");
}

int main()
{
    int opMENU;
    int dados[2];
    int numeros[100][4];
    char escolas[100][50], temas[100][50], datas[100][15], publicos[100][50], responsaveis[100][50];

    dados[0] = 0;
    dados[1] = 100;

    do{
    printf(
"\n============================================================\n"
"                       PSE EM ACAO\n"
"              Programa Saude na Escola\n"
"============================================================\n"
"\n"
"            +-----------------+          +---+\n"
"            |     ESCOLA      |          |   |\n"
"            |   []  []  []    |       +--+   +--+\n"
"            |   []  []  []    |  <->  |  SAUDE  |\n"
"            |     _______     |       +--+   +--+\n"
"            |    |   |   |    |          |   |\n"
"            +----+---+---+----+          +---+\n"
"\n"
"============================================================\n"
);
        printf("Acoes cadastradas: %d de %d\n", dados[0], dados[1]);
        printf("\n1-Cadastrar acao\n2-Listar acoes\n3-Pesquisar acao\n4-Atualizar situacao\n5-Gerar resumo geral\n0-Encerrar\nEscolha: ");
        scanf("%d", &opMENU);

        if(opMENU < 0){
            printf("Opcao invalida! Tente novamente.\n");
        }else if(opMENU > 5){
            printf("Opcao invalida! Tente novamente.\n");
        }else{
            switch(opMENU){
                case 0:
                printf("\nEncerrando o programa...\n");
                break;

                case 1:
                cadastrar(dados, numeros, escolas, temas, datas, publicos, responsaveis);
                break;

                case 2:
                listar(dados, numeros, escolas, temas, datas, publicos, responsaveis);
                break;

                case 3:
                pesquisar(dados, numeros, escolas, temas, datas);
                break;

                case 4:
                atualizar(dados, numeros);
                break;

                case 5:
                resumo(dados, numeros);
                break;
            }
        }
    }while(opMENU != 0);

    return 0;
}
