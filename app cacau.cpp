#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <iostream>
struct itens{
    char nome[40];
    int codbar, ativo;
    float preco;
};

int main(void)
{
    srand(time(NULL));
    setlocale(LC_ALL,"");
    itens produtos[60];
    int cp=0, codex[60],ativoex[60],op;
    float precoex[60];
    char codtex[10], precotex[7], ativotex[2];
    FILE *arquivo;
    arquivo = fopen("arq.txt","w");
    
    
    while(op!=5)
    {
        printf("\nEntre com a opcao desejada:\n1 - cadastrar produto\n2 - consultar produto\n3 - gerar arquivo de texto\n4 - excluir registro\n5 - sair\n");
        scanf("%d",&op);
        getchar();
        //op1 cadastrar
        if(op==1)
        {
            printf("Entre com o nome do produto: ");
            gets(produtos[cp].nome);

            printf("Entre com o codigo de barra do produto: ");
            scanf("%d",&produtos[cp].codbar);
            codex[cp]=produtos[cp].codbar;

            printf("Entre com o preco do produto: ");
            scanf("%f",&produtos[cp].preco);
            precoex[cp]=produtos[cp].preco;
   
            produtos[cp].ativo=1;
            ativoex[cp]=produtos[cp].ativo;
            cp++;


        }
        //op2 consultar
        if(op==2)
        {
            int  codbarc, achou=62;
            printf("Entre com o codigo de barras do produto a ser consultado: ");
            scanf("%d",&codbarc);
            for(int i=0;i<cp;i++)
            {
                if(produtos[i].codbar==codbarc)
                    achou=i;
            }
            if(achou==62)
                printf("Nao foi encontrado produto com esse codigo de barras, tente novamente!");
            else
            {
                printf("Nome do produto: %s\nCodigo de barras do produto: %d\nPreco do produto: %.2f\nStatus do produto: %d",produtos[achou].nome,produtos[achou].codbar,produtos[achou].preco,produtos[achou].ativo);
            }


        }
        if(op==3)
        {
            
            //op3 gerar arquivo de texto

            sprintf(codtex, "%d", codex[cp-1]);
            sprintf(precotex, "%f", precoex[cp-1]);
            sprintf(ativotex, "%d", ativoex[cp-1]);
            if (arquivo == NULL)
            {
            printf("\narq.txt nao pode ser aberto\n");
            }
            else
            {
                fputs(produtos[cp-1].nome, arquivo);
                fputc('\n', arquivo);
                fputs(codtex, arquivo);
                fputc('\n', arquivo);
                fputs(precotex, arquivo);
                fputc('\n', arquivo);
                fputs(ativotex, arquivo);
                fputc('\n', arquivo);
                printf("\nArquivo gerado com sucesso!\n");
            }

        }
        if(op==4)
        {
            //op4 excluir arquivo
            int codbarc2, achou2=62;
            printf("Entre com o codigo de barras do arquivo a ser exluido: ");
            scanf("%d",&codbarc2);
            for(int i=0;i<cp;i++)
            {
                if(produtos[i].codbar==codbarc2)
                    achou2=i;
            }
            if(achou2==62)
                printf("Nao foi encontrado produto com esse codigo de barras, tente novamente!");
            else
                {
                    produtos[achou2].ativo=0;
                    ativoex[achou2]=produtos[achou2].ativo;
                    sprintf(ativotex, "%d", ativoex[achou2]);
                    fputs(produtos[achou2].nome, arquivo);
                    fputc('\n', arquivo);
                    fputs(codtex, arquivo);
                    fputc('\n', arquivo);
                    fputs(precotex, arquivo);
                    fputc('\n', arquivo);
                    fputs(ativotex, arquivo);
                    fputc('\n', arquivo);
                    printf("Arquivo Excluido!");
                }

        }
        if(op==5)
        {
        //op5 sair
        fclose(arquivo);
        system("pause");
        }
    }
}

