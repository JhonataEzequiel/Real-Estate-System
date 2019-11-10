#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct{
    char nomedrua[256], bairro[256], cidade[256];
    char cep[256];
    int num;
} tEndereco;
typedef struct{
    char titulo[256];
    int pavimentos;
    int quartos;
    double areaTerrenoCasa;
    double areaConstruida;
} tCasa;
typedef struct{
    char titulo2[256];
    double areaAp;
    int quartosap;
    char position[256];
    int andar;
    int garagem;
} tAp;
typedef struct{
    char titulo3[256];
    double areaTerreno;
} tTerreno;
typedef struct{
    int i, a, c, t;
    char disp[256];
    double valor;
    tEndereco end;
    tAp apartamento;
    tTerreno terreno;
    tCasa casa;
} tImovel;

void ApresentaMenu()
{
    printf("\t\t\t*Bem Vindo*\n\t\tO que deseja fazer?\n\t\t1 - Cadastrar Imovel\n\t\t2 - Visualizar imoveis cadastrados\n\t\t3 - Buscar imovel por titulo\n\t\t4 - Buscar imovel por tipo\n\t\t5 - Remover imovel\n\t\t6 - Consultar imoveis a partir de um determinado valor\n\t\t7 - Editar imovel\n\t\t8 - Buscar por bairro\n\t\t9 - Sair\n");
}

tImovel CadastraImovel(int op)
{
    tEndereco endereco;
    tCasa casa;
    tTerreno terreno;
    tAp ap;
    tImovel imovel;

    imovel.i = 0;
    imovel.c = 0;
    imovel.a = 0;
    imovel.t = 0;

    printf("Comece pelo Endereco:\n");
    printf("Digite o nome da rua:\n");
    fgets(endereco.nomedrua, 256, stdin);
    fgets(endereco.nomedrua, 256, stdin);
    endereco.nomedrua[strlen(endereco.nomedrua)-1] = '\0';
    printf("Digite o Bairro:\n");
    fgets(endereco.bairro, 256, stdin);
    endereco.bairro[strlen(endereco.bairro)-1] = '\0';
    printf("Digite a Cidade:\n");
    fgets(endereco.cidade, 256, stdin);
    endereco.cidade[strlen(endereco.cidade)-1] = '\0';
    printf("Digite o Cep:\n");
    fgets(endereco.cep, 256, stdin);
    endereco.cep[strlen(endereco.cep)-1] = '\0';
    printf("Digite o Numero do Imovel:\n");
    scanf("%d", &endereco.num);

    if(op == 1)
    {
        printf("Qual o titulo do Anuncio?\n");
        fgets(casa.titulo, 256, stdin);
        fgets(casa.titulo, 256, stdin);
        casa.titulo[strlen(casa.titulo) - 1] = '\0';
        printf("Qual a area do terreno da casa?\n");
        scanf("%lf", &casa.areaTerrenoCasa);
        printf("Qual a area construida desse terreno?\n");
        scanf("%lf", &casa.areaConstruida);
        printf("Quantos quartos tem?\n");
        scanf("%d", &casa.quartos);
        printf("Quantos pavimentos tem?\n");
        scanf("%d", &casa.pavimentos);
        printf("Digite o Valor do imovel:\n");
        scanf("%lf", &imovel.valor);
        printf("O imovel esta disponivel para venda ou aluguel?\n");
        fgets(imovel.disp, 256, stdin);
        fgets(imovel.disp, 256, stdin);
        imovel.disp[strlen(imovel.disp) - 1] = '\0';

        imovel.c = 1;
        imovel.casa = casa;
    }
    if(op == 2)
    {
        printf("Qual o titulo do Anuncio?\n");
        fgets(ap.titulo2, 256, stdin);
        fgets(ap.titulo2, 256, stdin);
        ap.titulo2[strlen(ap.titulo2)-1] = '\0';
        printf("Qual posicao esta localizaod?(Nascente Sul, Nascente Norte, etc)\n");
        fgets(ap.position, 256, stdin);
        ap.position[strlen(ap.position)-1] = '\0';
        printf("Em qual andar esta localizado?\n");
        scanf("%d", &ap.andar);
        printf("Qual a area do apartamento?\n");
        scanf("%lf", &ap.areaAp);
        printf("Quantas vagas na garagem?\n");
        scanf("%d", &ap.garagem);
        printf("Quantos quartos possui o apartamento?\n");
        scanf("%d", &ap.quartosap);
        printf("Qual o valor do imovel?\n");
        scanf("%lf", &imovel.valor);
        printf("O imovel esta disponivel para venda ou aluguel?\n");
        fgets(imovel.disp, 256, stdin);
        fgets(imovel.disp, 256, stdin);
        imovel.disp[strlen(imovel.disp)-1] = '\0';

        imovel.a = 1;
        imovel.apartamento = ap;

    }
    if(op == 3)
    {
        printf("Qual o titulo do Anuncio?\n");
        fgets(terreno.titulo3, 256, stdin);
        fgets(terreno.titulo3, 256, stdin);
        terreno.titulo3[strlen(terreno.titulo3)-1] = '\0';
        printf("Qual a area do terreno?\n");
        scanf("%lf", &terreno.areaTerreno);
        printf("Qual o valor do terreno?\n");
        scanf("%lf", &imovel.valor);
        printf("O imovel esta disponivel para venda ou aluguel?\n");
        fgets(imovel.disp, 256, stdin);
        fgets(imovel.disp, 256, stdin);
        imovel.disp[strlen(imovel.disp)-1] = '\0';

        imovel.terreno = terreno;
        imovel.t = 1;
    }
    imovel.end = endereco;
    imovel.i = 1;

    return imovel;
}
void ListaImoveis(tImovel *imovel, int tamanho)
{
    int i=0;
    while(i<tamanho)
    {
        if(imovel[i].c == 1 && imovel[i].i!=2 && imovel[i].i != 0)
        {
            printf("Imovel: %s\n", imovel[i].casa.titulo);
            printf("Valor: %.2lf\n\n", imovel[i].valor);
            printf("Disponibilidade: %s\n", imovel[i].disp);
            printf("Endereco: \n");
            printf("Cidade: %s\nBairro: %s\nRua: %s\nCep: %s\nNumero: %d\n\n", imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num);
            printf("Pavimentos: %d\n\n", imovel[i].casa.pavimentos);
            printf("Quartos: %d\n\n", imovel[i].casa.quartos);
            printf("Area construida: %.2lf\n\nArea total do terreno: %.2lf\n\n", imovel[i].casa.areaConstruida, imovel[i].casa.areaTerrenoCasa);
        }
        if(imovel[i].a == 1 && imovel[i].i!=2 && imovel[i].i != 0)
        {
            printf("Imovel: %s\n", imovel[i].apartamento.titulo2);
            printf("Valor: %.2lf\n\n", imovel[i].valor);
            printf("Disponibilidade: %s\n", imovel[i].disp);
            printf("Endereco: \n");
            printf("Cidade: %s\nBairro: %s\nRua: %s\nCep: %s\nNumero: %d\n\n", imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num);
            printf("Andar: %d\n\n", imovel[i].apartamento.andar);
            printf("Area do Apartamento: %.2lf\n\n", imovel[i].apartamento.areaAp);
            printf("Vagas na Garagem: %d\n\n", imovel[i].apartamento.garagem);
            printf("Posicao: %s\n", imovel[i].apartamento.position);
            printf("Quartos: %d\n\n", imovel[i].apartamento.quartosap);
        }
        if(imovel[i].t == 1 && imovel[i].i!=2 && imovel[i].i != 0)
        {
            printf("Imovel: %s\n", imovel[i].terreno.titulo3);
            printf("Valor: %.2lf\n\n", imovel[i].valor);
            printf("Disponibilidade: %s\n", imovel[i].disp);
            printf("Endereco: \n");
            printf("Cidade: %s\nBairro: %s\nRua: %s\nCep: %s\nNumero: %d\n\n", imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num);
            printf("Area do terreno: %.2lf\n", imovel[i].terreno.areaTerreno);
        }
        i++;
    }

}

void BuscaImovelT(tImovel *imovel, char *tituloT, int tamanho)
{
    int i = 0;
    while(i<tamanho){
        if(imovel[i].a == 1 && imovel[i].i==1)
        {
            if(!strcmp(tituloT, imovel[i].apartamento.titulo2))
            {
                printf("Imovel: %s\n", imovel[i].apartamento.titulo2);
                printf("Valor: %.2lf\n\n", imovel[i].valor);
                printf("Disponibilidade: %s\n", imovel[i].disp);
                printf("Endereco: \n");
                printf("Cidade: %s\nBairro: %s\nRua: %s\nCep: %s\nNumero: %d\n\n", imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num);
                printf("Andar: %d\n\n", imovel[i].apartamento.andar);
                printf("Area do Apartamento: %.2lf\n\n", imovel[i].apartamento.areaAp);
                printf("Vagas na Garagem: %d\n\n", imovel[i].apartamento.garagem);
                printf("Posição: %s\n", imovel[i].apartamento.position);
                printf("Quartos: %d\n\n", imovel[i].apartamento.quartosap);
            }
        }
        if(imovel[i].c == 1 && imovel[i].i==1)
        {
            if(!strcmp(tituloT, imovel[i].casa.titulo))
            {
                printf("Imovel: %s\n", imovel[i].casa.titulo);
                printf("Valor: %.2lf\n\n", imovel[i].valor);
                printf("Disponibilidade: %s\n", imovel[i].disp);
                printf("Endereco: \n");
                printf("Cidade: %s\nBairro: %s\nRua: %s\nCep: %s\nNumero: %d\n\n", imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num);
                printf("Pavimentos: %d\n\n", imovel[i].casa.pavimentos);
                printf("Quartos: %d\n\n", imovel[i].casa.quartos);
                printf("Area construida: %.2lf\n\nArea total do terreno: %.2lf\n\n", imovel[i].casa.areaConstruida, imovel[i].casa.areaTerrenoCasa);
            }
        }
        if(imovel[i].t == 1 && imovel[i].i==1)
        {
            if(!strcmp(tituloT, imovel[i].terreno.titulo3))
            {
                printf("Imovel: %s\n", imovel[i].terreno.titulo3);
                printf("Valor: %.2lf\n\n", imovel[i].valor);
                printf("Disponibilidade: %s\n", imovel[i].disp);
                printf("Endereco: \n");
                printf("Cidade: %s\nBairro: %s\nRua: %s\nCep: %s\nNumero: %d\n\n", imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num);
                printf("Area do terreno: %.2lf\n", imovel[i].terreno.areaTerreno);
            }
         }
         i++;
    }
}

void BuscaImovelTipo(tImovel *imovel, int tipo, char *disponibilidade, int tamanho)
{
    int i=0;

    while(i<tamanho)
    {
        if(tipo == 1 && (!strcmp(imovel[i].disp, disponibilidade)) && imovel[i].i==1)
        {
            if(imovel[i].c == 1)
            {
            printf("Imovel: %s\n", imovel[i].casa.titulo);
            printf("Valor: %.2lf\n\n", imovel[i].valor);
            printf("Disponibilidade: %s\n", imovel[i].disp);
            printf("Endereco: \n");
            printf("Cidade: %s\nBairro: %s\nRua: %s\nCep: %s\nNumero: %d\n\n", imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num);
            printf("Pavimentos: %d\n\n", imovel[i].casa.pavimentos);
            printf("Quartos: %d\n\n", imovel[i].casa.quartos);
            printf("Area construida: %.2lf\n\nArea total do terreno: %.2lf\n\n", imovel[i].casa.areaConstruida, imovel[i].casa.areaTerrenoCasa);

            }
        }
        if(tipo == 2 && (!strcmp(imovel[i].disp, disponibilidade)) && imovel[i].i==1)
        {
            if(imovel[i].a == 1)
            {
                printf("Imovel: %s\n", imovel[i].apartamento.titulo2);
                printf("Valor: %.2lf\n\n", imovel[i].valor);
                printf("Disponibilidade: %s\n", imovel[i].disp);
                printf("Endereco: \n");
                printf("Cidade: %s\nBairro: %s\nRua: %s\nCep: %s\nNumero: %d\n\n", imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num);
                printf("Andar: %d\n\n", imovel[i].apartamento.andar);
                printf("Area do Apartamento: %.2lf\n\n", imovel[i].apartamento.areaAp);
                printf("Vagas na Garagem: %d\n\n", imovel[i].apartamento.garagem);
                printf("Posição: %s\n", imovel[i].apartamento.position);
                printf("Quartos: %d\n\n", imovel[i].apartamento.quartosap);
            }
        }
        if(tipo == 3 && (!strcmp(imovel[i].disp, disponibilidade)) && imovel[i].i==1)
        {
            if(imovel[i].t == 1)
            {
                printf("Imovel: %s\n", imovel[i].terreno.titulo3);
                printf("Valor: %.2lf\n\n", imovel[i].valor);
                printf("Disponibilidade: %s\n", imovel[i].disp);
                printf("Endereco: \n");
                printf("Cidade: %s\nBairro: %s\nRua: %s\nCep: %s\nNumero: %d\n\n", imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num);
                printf("Area do terreno: %.2lf\n", imovel[i].terreno.areaTerreno);
            }
        }
        i++;
    }
}

void BuscaImovelBairro (tImovel *imovel, char *bairro, int tamanho)
{
    int i=0;
    while(i<tamanho)
    {
        if(!strcmp(bairro, imovel[i].end.bairro) && imovel[i].c == 1 && imovel[i].i==1)
        {
            printf("Imovel: %s\n", imovel[i].casa.titulo);
            printf("Valor: %.2lf\n\n", imovel[i].valor);
            printf("Disponibilidade: %s\n", imovel[i].disp);
            printf("Endereco: \n");
            printf("Cidade: %s\nBairro: %s\nRua: %s\nCep: %s\nNumero: %d\n\n", imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num);
            printf("Pavimentos: %d\n\n", imovel[i].casa.pavimentos);
            printf("Quartos: %d\n\n", imovel[i].casa.quartos);
            printf("Area construida: %.2lf\n\nArea total do terreno: %.2lf\n\n", imovel[i].casa.areaConstruida, imovel[i].casa.areaTerrenoCasa);
        }
        if(!strcmp(bairro, imovel[i].end.bairro) && imovel[i].a == 1 && imovel[i].i==1)
        {
                printf("Imovel: %s\n", imovel[i].apartamento.titulo2);
                printf("Valor: %.2lf\n\n", imovel[i].valor);
                printf("Disponibilidade: %s\n", imovel[i].disp);
                printf("Endereco: \n");
                printf("Cidade: %s\nBairro: %s\nRua: %s\nCep: %s\nNumero: %d\n\n", imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num);
                printf("Andar: %d\n\n", imovel[i].apartamento.andar);
                printf("Area do Apartamento: %.2lf\n\n", imovel[i].apartamento.areaAp);
                printf("Vagas na Garagem: %d\n\n", imovel[i].apartamento.garagem);
                printf("Posição: %s\n", imovel[i].apartamento.position);
                printf("Quartos: %d\n\n", imovel[i].apartamento.quartosap);
        }
        if(!strcmp(bairro, imovel[i].end.bairro) && imovel[i].t == 1 && imovel[i].i==1)
        {
            printf("Imovel: %s\n", imovel[i].terreno.titulo3);
            printf("Valor: %.2lf\n\n", imovel[i].valor);
            printf("Disponibilidade: %s\n", imovel[i].disp);
            printf("Endereco: \n");
            printf("Cidade: %s\nBairro: %s\nRua: %s\nCep: %s\nNumero: %d\n\n", imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num);
            printf("Area do terreno: %.2lf\n", imovel[i].terreno.areaTerreno);
        }
        i++;
    }
}

int RemoverImovel(tImovel *imovel, int tamanho)
{
    char nomedimovel[256];
    int i;
    printf("Digite o nome do imovel que quer remover:\n");
    fgets(nomedimovel, 256, stdin);
    fgets(nomedimovel, 256, stdin);
    nomedimovel[strlen(nomedimovel)-1] = '\0';

    for(i = 0; i<tamanho; i++)
    {
        if(!strcmp(nomedimovel, imovel[i].casa.titulo))
        {
            imovel[i].i = 2;
            return 0;
        }
        if(!strcmp(nomedimovel, imovel[i].apartamento.titulo2))
        {
            imovel[i].i = 2;
            return 0;
        }
        if(!strcmp(nomedimovel, imovel[i].terreno.titulo3))
        {
            imovel[i].i = 2;
            return 0;
        }
    }
    return 1;
}

void ListarValor(tImovel *imovel, int tamanho)
{
    double valor;
    printf("A partir de qual valor devo buscar?\n");
    scanf("%lf", &valor);

    int i = 0;

    while(i<tamanho)
    {
        if(imovel[i].valor >= valor && imovel[i].i==1)
        {
            if(imovel[i].c == 1)
            {
                printf("Imovel: %s\n", imovel[i].casa.titulo);
                printf("Valor: %.2lf\n\n", imovel[i].valor);
                printf("Disponibilidade: %s\n", imovel[i].disp);
                printf("Endereco: \n");
                printf("Cidade: %s\nBairro: %s\nRua: %s\nCep: %s\nNumero: %d\n\n", imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num);
                printf("Pavimentos: %d\n\n", imovel[i].casa.pavimentos);
                printf("Quartos: %d\n\n", imovel[i].casa.quartos);
                printf("Area construida: %.2lf\n\nArea total do terreno: %.2lf\n\n", imovel[i].casa.areaConstruida, imovel[i].casa.areaTerrenoCasa);
            }
            if(imovel[i].a == 1)
            {
                printf("Imovel: %s\n", imovel[i].apartamento.titulo2);
                printf("Valor: %.2lf\n\n", imovel[i].valor);
                printf("Disponibilidade: %s\n", imovel[i].disp);
                printf("Endereco: \n");
                printf("Cidade: %s\nBairro: %s\nRua: %s\nCep: %s\nNumero: %d\n\n", imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num);
                printf("Andar: %d\n\n", imovel[i].apartamento.andar);
                printf("Area do Apartamento: %.2lf\n\n", imovel[i].apartamento.areaAp);
                printf("Vagas na Garagem: %d\n\n", imovel[i].apartamento.garagem);
                printf("Posição: %s\n", imovel[i].apartamento.position);
                printf("Quartos: %d\n\n", imovel[i].apartamento.quartosap);
            }
            if(imovel[i].t == 1)
            {
                printf("Imovel: %s\n", imovel[i].terreno.titulo3);
                printf("Valor: %.2lf\n\n", imovel[i].valor);
                printf("Disponibilidade: %s\n", imovel[i].disp);
                printf("Endereco: \n");
                printf("Cidade: %s\nBairro: %s\nRua: %s\nCep: %s\nNumero: %d\n\n", imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num);
                printf("Area do terreno: %.2lf\n", imovel[i].terreno.areaTerreno);
            }
        }
        i++;
    }

}

tImovel EditarImovel(tImovel *imovel, int tamanho, int *h)
{
    printf("Qual o nome do imovel que deseja editar?\n");
    char nomedimovel[256];

    fgets(nomedimovel, 256, stdin);
    fgets(nomedimovel, 256, stdin);
    nomedimovel[strlen(nomedimovel)-1] = '\0';

    int op;

    printf("Digite:\n\n1 - Se for uma casa\n2 - Se for um Apartamento\n3 - Se for um terreno\n");
    scanf("%d", &op);

    int i = 0,x;

    while(i<tamanho)
    {
        if(op == 1 && !strcmp(nomedimovel, imovel[i].casa.titulo) && imovel[i].i==1)
        {
            imovel[i] = CadastraImovel(op);
            *h = i;
        }
        if(op == 2 && !strcmp(nomedimovel, imovel[i].apartamento.titulo2) && imovel[i].i==1)
        {
            imovel[i] = CadastraImovel(op);
            *h = i;
        }
        if(op == 3 && !strcmp(nomedimovel, imovel[i].terreno.titulo3) && imovel[i].i==1)
        {
            imovel[i] = CadastraImovel(op);
            *h = i;
        }
        i++;
    }
    x=*h;
    return imovel[x];
}

int CalcularTamanhoArray(tImovel *imovel)
{
    int i=0, tamanhoC1 = 0, tamanhoC2 = 0;

    while(1)
    {
        if(imovel[i].i == 1)
        {
            tamanhoC1 += 1;
        }
        if(imovel[i].i == 2)
        {
            tamanhoC2 += 1;
        }
        if(imovel[i].i == 0)
        {
            break;
        }
        i++;
    }
    return tamanhoC1 + tamanhoC2;
}

void SalvarArquivo(tImovel *imovel, int tamanho)
{
    int i=0;
    FILE *Casa, *Apartamento, *Terreno;
    Apartamento = fopen("APARTAMENTOS.txt", "w");
    Casa = fopen("CASAS.txt", "w");
    Terreno = fopen("TERRENOS.txt", "w");
    while(i<tamanho)
    {
        if(imovel[i].c == 1 && imovel[i].i!=2 && imovel[i].i != 0)
        {
            fprintf(Casa, "%s\n"
                    "%.2lf\n"
                    "%s\n"
                    "%s\n%s\n%s\n%s\n%d\n"
                    "%d\n"
                    "%d\n"
                    "%.2lf\n%.2lf\n",
                    imovel[i].casa.titulo,
                    imovel[i].valor,
                    imovel[i].disp,
                    imovel[i].end.cidade,
                    imovel[i].end.bairro,
                    imovel[i].end.nomedrua,
                    imovel[i].end.cep,
                    imovel[i].end.num,
                    imovel[i].casa.pavimentos,
                    imovel[i].casa.quartos,
                    imovel[i].casa.areaConstruida, imovel[i].casa.areaTerrenoCasa);
        }
        if(imovel[i].a == 1 && imovel[i].i!=2 && imovel[i].i != 0)
        {
            fprintf(Apartamento, "%s\n"
                    "%.2lf\n"
                    "%s\n"
                    "%s\n"
                    "%s\n"
                    "%s\n"
                    "%s\n"
                    "%d\n"
                    "%d\n"
                    "%.2lf\n"
                    "%d\n"
                    "%d\n"
                    "%s\n",
                    imovel[i].apartamento.titulo2,
                    imovel[i].valor,
                    imovel[i].disp,
                    imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num,
                    imovel[i].apartamento.andar,
                    imovel[i].apartamento.areaAp,
                    imovel[i].apartamento.garagem,
                    imovel[i].apartamento.quartosap,
                    imovel[i].apartamento.position);
        }
        Terreno = fopen("TERRENOS.TXT", "w");
        if(imovel[i].t == 1 && imovel[i].i!=2 && imovel[i].i != 0)
        {
            fprintf(Terreno, "%s\n"
                    "%.2lf\n"
                    "%s\n"
                    "%s\n%s\n%s\n%s\n%d\n"
                    "%.2lf\n",
                    imovel[i].terreno.titulo3,
                    imovel[i].valor,
                    imovel[i].disp,
                    imovel[i].end.cidade, imovel[i].end.bairro, imovel[i].end.nomedrua, imovel[i].end.cep, imovel[i].end.num,
                    imovel[i].terreno.areaTerreno);
        }
        if(imovel[i].i == 2 && imovel[i].c == 1 && tamanho < 2)
        {
            fprintf(Casa,"");
        }
        if(imovel[i].i == 2 && imovel[i].a == 1 && tamanho < 2)
        {
            fprintf(Apartamento,"");
        }
        if(imovel[i].i == 2 && imovel[i].t == 1 && tamanho < 2)
        {
            fprintf(Terreno,"");
        }

        i++;
    }
    fclose(Terreno);
    fclose(Casa);
    fclose(Apartamento);
}

int LerArquivo(tImovel *imovel)
{
    FILE *Casa, *Apartamento, *Terreno;
    int i = 0;
    Casa = fopen("CASAS.txt", "r");

        if(Casa == NULL)
            return 1;

        while(!feof(Casa))
        {
            fscanf(Casa,"%[^\n]\n", imovel[i].casa.titulo);
            fscanf(Casa,"%lf\n", &imovel[i].valor);
            fscanf(Casa,"%[^\n]\n", imovel[i].disp);
            fscanf(Casa,"%[^\n]\n", imovel[i].end.cidade);
            fscanf(Casa,"%[^\n]\n", imovel[i].end.bairro);
            fscanf(Casa,"%[^\n]\n", imovel[i].end.nomedrua);
            fscanf(Casa,"%[^\n]\n", imovel[i].end.cep);
            fscanf(Casa,"%d\n", &imovel[i].end.num);
            fscanf(Casa,"%d\n", &imovel[i].casa.pavimentos);
            fscanf(Casa,"%d\n", &imovel[i].casa.quartos);
            fscanf(Casa,"%lf\n", &imovel[i].casa.areaConstruida);
            fscanf(Casa,"%lf\n", &imovel[i].casa.areaTerrenoCasa);
            if(imovel[i].casa.titulo[0] != '\0')
                imovel[i].i = 1;

            imovel[i].c = 1;
            imovel[i].a = 0;
            imovel[i].t = 0;

            i++;
        }
        fclose(Casa);
        Apartamento = fopen("APARTAMENTOS.txt", "r");

            if(Apartamento == NULL)
                return 1;
        while(!feof(Apartamento))
        {
            fscanf(Apartamento,"%[^\n]\n", imovel[i].apartamento.titulo2);
            fscanf(Apartamento,"%lf\n", &imovel[i].valor);
            fscanf(Apartamento,"%[^\n]\n", imovel[i].disp);
            fscanf(Apartamento,"%[^\n]\n", imovel[i].end.cidade);
            fscanf(Apartamento,"%[^\n]\n", imovel[i].end.bairro);
            fscanf(Apartamento,"%[^\n]\n", imovel[i].end.nomedrua);
            fscanf(Apartamento,"%[^\n]\n",imovel[i].end.cep);
            fscanf(Apartamento,"%d\n", &imovel[i].end.num);
            fscanf(Apartamento,"%d\n", &imovel[i].apartamento.andar);
            fscanf(Apartamento,"%lf\n", &imovel[i].apartamento.areaAp);
            fscanf(Apartamento,"%d\n", &imovel[i].apartamento.garagem);
            fscanf(Apartamento,"%d\n", &imovel[i].apartamento.quartosap);
            fscanf(Apartamento,"%[^\n]\n", imovel[i].apartamento.position);
            if(imovel[i].apartamento.titulo2[0] != '\0')
                imovel[i].i = 1;

            imovel[i].c = 0;
            imovel[i].a = 1;
            imovel[i].t = 0;

            i++;
        }
        fclose(Apartamento);
        Terreno = fopen("TERRENOS.txt", "r");

        if(Terreno == NULL)
            return 1;

        while(!feof(Terreno))
        {
            fscanf(Terreno,"%[^\n]\n", imovel[i].terreno.titulo3);
            fscanf(Terreno,"%lf\n", &imovel[i].valor);
            fscanf(Terreno,"%[^\n]\n", imovel[i].disp);
            fscanf(Terreno,"%[^\n]\n", imovel[i].end.cidade);
            fscanf(Terreno,"%[^\n]\n", imovel[i].end.bairro);
            fscanf(Terreno,"%[^\n]\n", imovel[i].end.nomedrua);
            fscanf(Terreno,"%[^\n]\n",imovel[i].end.cep);
            fscanf(Terreno,"%d\n", &imovel[i].end.num);
            fscanf(Terreno,"%lf\n", &imovel[i].terreno.areaTerreno);
            if(imovel[i].terreno.titulo3[0] != '\0')
                imovel[i].i = 1;

            imovel[i].c = 0;
            imovel[i].a = 0;
            imovel[i].t = 1;
            i++;
        }
        fclose(Terreno);
    return 0;
}

int main()
{
    int opmenu,tamanho2, opcadastro, i = 0;
    tImovel imovel[100];
    char disponibilidade[256], tituloT[256];

    LerArquivo(imovel);

    i = CalcularTamanhoArray(imovel);
    ApresentaMenu();
    scanf("%d", &opmenu);

    while(opmenu != 9)
    {
        if(opmenu == 1){
            printf("\tDigite:\n\t1 para cadastrar uma casa\n\t2 para cadastrar um apartamento\n\t3 para cadastrar um terreno\n\t4 para voltar ao menu\n");
            scanf("%d", &opcadastro);

            if(opcadastro == 1)
            {
                imovel[i] = CadastraImovel(opcadastro);
            }
            if(opcadastro == 2)
            {
                imovel[i] = CadastraImovel(opcadastro);
            }
            if(opcadastro == 3)
            {
                imovel[i] = CadastraImovel(opcadastro);
            }
            if(opcadastro == 4)
            {
                ApresentaMenu();
                scanf("%d", &opmenu);
            }
            i++;
        }
        if(opmenu==2)
        {
            ListaImoveis(imovel, CalcularTamanhoArray(imovel));
            ApresentaMenu();
            scanf("%d", &opmenu);
        }
        if(opmenu == 3)
        {
            printf("Qual o titulo do imovel que deseja buscar?\n");
            fgets(tituloT, 256, stdin);
            fgets(tituloT, 256, stdin);
            tituloT[strlen(tituloT)-1] = '\0';
            BuscaImovelT(imovel, tituloT, CalcularTamanhoArray(imovel));

            ApresentaMenu();
            scanf("%d", &opmenu);
        }
        if(opmenu == 4)
        {
            printf("\n\t\t1 - Casa\n\t\t2 - Apartamento\n\t\t3 - Terreno\n\t\t4 - Voltar ao menu\n");

            int opbuscatipo;
            scanf("%d", &opbuscatipo);

            if(opbuscatipo!=4){
                printf("Por venda ou aluguel?\n");
                fgets(disponibilidade, 256, stdin);
                fgets(disponibilidade, 256, stdin);
                disponibilidade[strlen(disponibilidade)-1] = '\0';
                BuscaImovelTipo(imovel, opbuscatipo, disponibilidade, CalcularTamanhoArray(imovel));
            }
            if(opbuscatipo == 4)
            {
                ApresentaMenu();
                scanf("%d", &opmenu);
            }
        }
        if(opmenu == 5)
        {
            if(!RemoverImovel(imovel, CalcularTamanhoArray(imovel)))
            {
                printf("Imovel removido com sucesso.\n\n");
            }else{
                printf("Falha ao remover imovel\n\n");
            }
            ApresentaMenu();
            scanf("%d", &opmenu);
        }
        if(opmenu == 6)
        {
            ListarValor(imovel, CalcularTamanhoArray(imovel));
            ApresentaMenu();
            scanf("%d", &opmenu);
        }
        if(opmenu == 7)
        {
            int h;
            tImovel aux;
            aux = EditarImovel(imovel, CalcularTamanhoArray(imovel), &h);
            imovel[h] = aux;
            ApresentaMenu();
            scanf("%d", &opmenu);
        }
        if(opmenu == 8)
        {
            char bairro[256];
            printf("Digite o bairro que deseja buscar:\n");
            fgets(bairro,256,stdin);
            fgets(bairro,256,stdin);
            bairro[strlen(bairro)-1] = '\0';
            BuscaImovelBairro(imovel, bairro, CalcularTamanhoArray(imovel));
            ApresentaMenu();
            scanf("%d", &opmenu);
        }
    }

    SalvarArquivo(imovel, CalcularTamanhoArray(imovel));

    system("pause");
}
