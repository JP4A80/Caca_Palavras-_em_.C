#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void menumatriz(){
    //procedimento para imprimir o menu matriz
    printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("+-+-+-+-+-+-+-+-+- Bem vindo ao Caca Palavra -+-+-+-+-+-+-+-+-+\n");
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("\n1 - matriz aleatoria");
    printf("\n2 - matriz pre-definida");
    printf("\n0 - Sair do programa");
    printf("\nEscolha uma opcao:  ");
}

void menu(char mat[10][10]){
    //procedimento para imprimir o menu escolha
    printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("+-+-+-+-+-+-+-+-+-+-+- Escolha uma opcao -+-+-+-+-+-+-+-+-+-+-+\n");
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    imprimirmatriz(mat);
    printf("\n1 - Esquerda para direita");
    printf("\n2 - Direita para esquerda");
    printf("\n3 - Baixo para cima");
    printf("\n4 - Cima para baixo");
    printf("\n5 - voltar");
    printf("\n0 - Sair do programa");
}

void imprimirmatriz(char mat[10][10]){
//procedimento para imprimir a matriz
    printf("\n");
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            printf("%c   ", mat[i][j]);
        }
        printf("\n");
        
    }
}

void esquerdadireita(char pesquisa[10],int tamanhopalavra,char mat[10][10]){
int i,j,cont=0,cont2=0,tamanhosub=0,falso=0;
char subpalavra[10];
/*vou deixar esse parte com todos esses "printf" caso o senhor 
queira entender a logica de como funciona o codigo, como esse foi o 
primeiro forma de buscar que eu fiz ele esta com muitos printf
pois eu fui testando as variaveis varias vezes. As outras de formas de 
buscar são adpatações dessa primeira forma*/

//printf("\ntamanho da string: %d\n\n",tamanhopalavra);

        //esse for e para rodar as linhas da matriz
        for(i=0; i < 10;i++){
            /*contador auxiliar para ajudar prencher a minha sub palavras com caracter diferentes*/
            cont2 = 0;
            //printf("\ncontador i: %d",i);
            /*esse "while" e para que o "for" não insira desnecessariamente 
            palavras que não existe na subpalavra e tambem um limite para que 
            "for" se repetir ate 10, ja que temos uma matriz 10x10*/
            while(11 > (tamanhopalavra + cont2)){
                /*contador auxiliar para que na subpalavras seja insirado sempre 
                caracter nas primeiras posições, pois assim evita da strings na subpalavra
                fica com lixo nas outras posições*/
                cont = 0;
                //"memeset" foi uma função que achei para deixar "vazia" a string
                memset(subpalavra,0,sizeof(subpalavra));
                    //esse for e para percorer as colunas 
                    for(j = cont2; j < (tamanhopalavra+cont2);j++){
                        /*essa variavbel subpalavra este recebendo caracteres da matriz
                        para comparação*/
                        subpalavra[cont] = mat[i][j];
                        //printf("\n%s",subpalavra);
                        //printf("\npalavra recebida no sub %s",subpalavra);
                        //printf("\nvalor de j: %d\t",j);
                        //printf("\nvalor de contador: %d",cont);
                        //printf("\ntamano da sub: %d",tamanhosub);
                        cont++;
                    }
                    //printf("\n%s",subpalavra);
                    tamanhosub = strlen(subpalavra);
                    //printf("\ntamano da sub: %d",tamanhosub);
                    /*para evitar comparações desnecessarias, eu uso "if" para comparar o tamanho
                    das palavras, se for dos mesmo tamanho as variaveis subpalavra e pesquisa entro no "if"*/
                    if( tamanhosub == tamanhopalavra){
                        //"strcmp" para comparar as duas strings
                        if(strcmp(pesquisa,subpalavra) == 0){
                            /*os três printf abaixo e para e para imprimir as posições da palavra*/
                            printf("\npalavra encontrada: %s",subpalavra);
                            printf("\nlinha --> %d",i+1);
                            printf("\ncoluna --> %d ah %d",(j-tamanhosub)+1,j); 
                            falso++;
                        }
                    }
                cont2++;
            }
        }
    //esse "if" é caso não encontre uma palavra que esta sendo pesquisada
    if(falso == 0){
        printf("Palavra nao encontrada");
    }
}

void direitaesquerda(char pesquisa[10],int tamanhopalavra,char mat[10][10]){
int i,j,cont,cont2,tamanhosub=0,falso=0;
char subpalavra[10];
/*aqui temos a mesma logica do procedimento esquerdadireita a diferença
e que no segundo contador ele ja começa com 10 e vai diminuindo as posições 
ate chegar a zero*/

        for(i=0; i < 10;i++){
            cont2 = 0;
            while(11 > (tamanhopalavra + cont2)){
                cont = (tamanhopalavra-1);
                memset(subpalavra,0,sizeof(subpalavra));
                    for(j = cont2; j < (tamanhopalavra+cont2);j++){
                        /*na subpalavra e recebido os valores ao contrario do procedimento
                        direitaesquerda as posições vai decrementando ate chegar a zero*/ 
                        subpalavra[cont] = mat[i][j];
                        cont--;
                    }

                    //aqui e mesma logica de comparação
                    tamanhosub = strlen(subpalavra);
                    if( tamanhosub == tamanhopalavra){
                        if(strcmp(pesquisa,subpalavra) == 0){
                            printf("\npalavra encontrada: %s",subpalavra);
                            printf("\nlinha --> %d",i+1);
                            printf("\ncoluna --> %d ah %d",j,(j-tamanhosub)+1);  
                            falso++;
                        }
                    }   
                cont2++;
            }
        }
    if(falso == 0){
        printf("Palavra nao encontrada");
    }
}

void cimabaixo(char pesquisa[10],int tamanhopalavra,char mat[10][10]){
int i,j,cont=0,cont2=0,tamanhosub=0,falso=0;
char subpalavra[10];

        for(i=0; i < 10;i++){
            cont2 = 0;
            while(11 > (tamanhopalavra + cont2)){
                cont = 0;
                memset(subpalavra,0,sizeof(subpalavra));
                    for(j = cont2; j < (tamanhopalavra+cont2);j++){
                        /*aqui para fazer as busca de cima para baixo eu inventi os valores
                        a ser recebido na subpalavra nesse for abaixo, antes era mat[i][j]
                        aqui eu coloquei mat[j][i] isso fez com que subpalavra recebesse os
                        valores da coluna invés da linha*/
                        subpalavra[cont] = mat[j][i];
                        cont++;
                    }

                    //a logica de compração tambem e igual 
                    tamanhosub = strlen(subpalavra);
                    if( tamanhosub == tamanhopalavra){
                        if(strcmp(pesquisa,subpalavra) == 0){
                            printf("\npalavra encontrada: %s",subpalavra);
                            printf("\nlinha --> %d ah %d",(j-tamanhosub)+1,j);
                            printf("\ncoluna --> %d",i+1);  
                            falso++;
                        }
                    }
                cont2++;
            }
        }
    //"if" vai usado caso não encontre nenhuma palavra(esplicado no procedimento esquerdadireita)
    if(falso == 0){
        printf("Palavra nao encontrada");
    }
}

void baixocima(char pesquisa[10],int tamanhopalavra,char mat[10][10]){
int i,j,cont,cont2,tamanhosub=0,falso=0;
char subpalavra[10];
/*mesma logica usado no procedimento cimabaixo o que muda e o segundo for*/

        for(i=0; i < 10;i++){
            cont2 = 0;
            while(11 > (tamanhopalavra + cont2)){
                cont = (tamanhopalavra-1);
                memset(subpalavra,0,sizeof(subpalavra));
                    /*aqui o for vem decrementando(não começa com zero) como no procedimento direitaesquerda
                    mas com inversão nos valores do indice inves de mat[i][j] e
                    mat[j][i] para receber os valores no fim da matriz*/
                    for(j = cont2; j < (tamanhopalavra+cont2);j++){
                        subpalavra[cont] = mat[j][i];
                        cont--;
                    }

                    /*a logica de comparação e a mesma com todos os procedimento que
                    expliquei no procedimento esquerdadireita*/
                    tamanhosub = strlen(subpalavra);
                    if(tamanhosub == tamanhopalavra){
                        if(strcmp(pesquisa,subpalavra) == 0){
                            printf("\npalavra encontrada: %s",subpalavra);
                            printf("\nlinha --> %d ah %d",j,(j-tamanhosub)+1);
                            printf("\ncoluna --> %d",i+1);  
                            falso++;
                        }
                    }
                cont2++;
            }
        }
    //"if" vai usado caso não encontre nenhuma palavra(esplicado no procedimento esquerdadireita)
    if(falso == 0){
        printf("Palavra nao encontrada");
    }
}

int main(){

int tamanhopalavra=0,resnum,resnum0;
char mat[10][10], pesquisa[10];

/* o usuario tem o poder de escolher duas matrizes uma pre-definida
ou uma que e gerado pelo sistema de forma automatica*/ 
do{
    //imprimi o menu matriz e pergunta para escolher uma opção
    menumatriz();
    setbuf(stdin,NULL);
    scanf("%d",&resnum0);
    /*se escolher a função 1 vai gerado uma matriz aleatoria*/
    if(resnum0 == 1){
    //"srand" para sortear numeros aleatorios
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            mat[i][j] = 97 + (rand()%26);
        }
    }
    }

    if(resnum0 == 2){
    //caso escolha opção 2, essa vai ser a matriz pre-definda
    //Declarando uma matriz pre-definada
    mat[0][0]='a'; mat[0][1]='b'; mat[0][2]='a'; mat[0][3]='c'; mat[0][4]='a'; mat[0][5]='x'; mat[0][6]='a'; mat[0][7]='b'; mat[0][8]='a'; mat[0][9]='a';
	mat[1][0]='c'; mat[1][1]='b'; mat[1][2]='y'; mat[1][3]='f'; mat[1][4]='a'; mat[1][5]='z'; mat[1][6]='a'; mat[1][7]='a'; mat[1][8]='a'; mat[1][9]='l'; 
	mat[2][0]='i'; mat[2][1]='t'; mat[2][2]='a'; mat[2][3]='e'; mat[2][4]='h'; mat[2][5]='p'; mat[2][6]='e'; mat[2][7]='r'; mat[2][8]='o'; mat[2][9]='a';
	mat[3][0]='p'; mat[3][1]='i'; mat[3][2]='r'; mat[3][3]='a'; mat[3][4]='v'; mat[3][5]='e'; mat[3][6]='r'; mat[3][7]='o'; mat[3][8]='f'; mat[3][9]='f';
	mat[4][0]='o'; mat[4][1]='z'; mat[4][2]='t'; mat[4][3]='a'; mat[4][4]='z'; mat[4][5]='m'; mat[4][6]='a'; mat[4][7]='d'; mat[4][8]='i'; mat[4][9]='f';
	mat[5][0]='i'; mat[5][1]='x'; mat[5][2]='q'; mat[5][3]='m'; mat[5][4]='u'; mat[5][5]='a'; mat[5][6]='l'; mat[5][7]='a'; mat[5][8]='l'; mat[5][9]='i';
	mat[6][0]='t'; mat[6][1]='c'; mat[6][2]='w'; mat[6][3]='n'; mat[6][4]='u'; mat[6][5]='s'; mat[6][6]='u'; mat[6][7]='l'; mat[6][8]='g'; mat[6][9]='n';
	mat[7][0]='t'; mat[7][1]='e'; mat[7][2]='s'; mat[7][3]='t'; mat[7][4]='e'; mat[7][5]='d'; mat[7][6]='e'; mat[7][7]='l'; mat[7][8]='i'; mat[7][9]='n';
	mat[8][0]='h'; mat[8][1]='o'; mat[8][2]='m'; mat[8][3]='a'; mat[8][4]='r'; mat[8][5]='o'; mat[8][6]='b'; mat[8][7]='o'; mat[8][8]='b'; mat[8][9]='a';
	mat[9][0]='k'; mat[9][1]='o'; mat[9][2]='a'; mat[9][3]='z'; mat[9][4]='z'; mat[9][5]='z'; mat[9][6]='a'; mat[9][7]='m'; mat[9][8]='a'; mat[9][9]='l'; 
    }
    
    //caso escolha 0, vai sair do programa
    if(resnum0 == 0){
        system("cls");
        printf("Voce esta sainda programa\nAte a proxima");
        printf("\n");
        system("pause");
        return 0;
    }


    /*usando um "do while" para fazer o menu iniciar quantas vezes forem necessaria
    ou se por acaso o usuario escolhar uma opção invalida*/
if((resnum0 == 1)||(resnum0==2)){
    system("cls");
    do{
        
        menu(mat); 
        /*"setbuf" aqui para limpar caso o usuario digite uma letra e 
        guardar no buffer o valor de enter, ISSO EVITA BUGS*/
        setbuf(stdin,NULL);
        //com o menu ja impresso, aqui o usuario vai escolher uma das opções
        printf("\nEscolha uma opcao:   ");
        scanf("%d",&resnum);
        system("cls");

        /*Como no menu de opções são usadas numeros para indicar a opção,
        eu achei melhor usar um "switch - case", eu poderia usar "ifs" para fazer 
        isso funcionar tambem, mas com "switch - case" fica mais organizado.*/
        switch (resnum){

            //opção 0 e para sair do programa
            case 0:
                printf("\nVoce esta saindo do programa.");
                printf("\nAte a proxima");
                printf("\n");
                system("pause");
                return 0;
            break;

            case 1:
                //os tres printf, são para imprimir essa cabeçalho 
                printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
                printf("+-+-+-+-+-+-+-+-+-+- Esquerda para direita -+-+-+-+-+-+-+-+-+-+\n");
                printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
                //chamando função para imprimir matriz
                imprimirmatriz(mat);
                /*O "memset" e caso o usario queira fazer mais de uma pesquisa, a VARIAVEL pesquisa
                posso receber novos valores diferentes*/
                memset(pesquisa,0,sizeof(pesquisa));
                printf("\n\nQual palavra vc quer pesquisar ?  ");
                setbuf(stdin,NULL);
                gets(pesquisa);
                //descobrindo o tamanho da palavra que vai ser buscada
                tamanhopalavra = strlen(pesquisa);
                //chamando a função para fazer a pesquisa 
                esquerdadireita(pesquisa,tamanhopalavra,mat);
                printf("\n");
                system("pause");
                /*resnum aqui recebe 100 pois e para cair no laço de repetição, eu tentei colocar NULL, mas 
                o compilador da um warnig então optei por ser um valor alto para cair no while de novo*/
                resnum = 100;
                system("cls");
            break;

            case 2:
                //os tres printf, são para imprimir essa cabeçalho 
                printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
                printf("+-+-+-+-+-+-+-+-+-+- Direita para esquerda -+-+-+-+-+-+-+-+-+-+\n");
                printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
                //chamando função para imprimir matriz
                imprimirmatriz(mat);
                /*O "memset" e caso o usario queira fazer mais de uma pesquisa, a VARIAVEL pesquisa
                posso receber novos valores diferentes*/
                memset(pesquisa,0,sizeof(pesquisa));
                printf("\n\nQual palavra vc quer pesquisar ?  ");
                setbuf(stdin,NULL);
                gets(pesquisa);
                //descobrindo o tamanho da palavra que vai ser buscada
                tamanhopalavra = strlen(pesquisa);
                //chamando a função para fazer a pesquisa 
                direitaesquerda(pesquisa,tamanhopalavra,mat);
                printf("\n");
                system("pause");
                /*resnum aqui recebe 100 pois e para cair no laço de repetição, eu tentei colocar NULL, mas 
                o compilador da um warnig então optei por ser um valor alto para cair no while de novo*/
                resnum = 100;
                system("cls");
            break;

            case 3:
                //os tres printf, são para imprimir essa cabeçalho 
                printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
                printf("+-+-+-+-+-+-+-+-+-+-+-+ Cima para baixo +-+-+-+-+-+-+-+-+-+-+-+\n");
                printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
                //chamando função para imprimir matriz
                imprimirmatriz(mat);
                /*O "memset" e caso o usario queira fazer mais de uma pesquisa, a VARIAVEL pesquisa
                posso receber novos valores diferentes*/
                memset(pesquisa,0,sizeof(pesquisa));
                printf("\n\nQual palavra vc quer pesquisar ?  ");
                setbuf(stdin,NULL);
                gets(pesquisa);
                //descobrindo o tamanho da palavra que vai ser buscada
                tamanhopalavra = strlen(pesquisa);
                //chamando a função para fazer a pesquisa 
                cimabaixo(pesquisa,tamanhopalavra,mat);
                printf("\n");
                system("pause");
                /*resnum aqui recebe 100 pois e para cair no laço de repetição, eu tentei colocar NULL, mas 
                o compilador da um warnig então optei por ser um valor alto para cair no while de novo*/
                resnum = 100;
                system("cls");
            break;

            case 4:
                //os tres printf, são para imprimir essa cabeçalho 
                printf("\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
                printf("+-+-+-+-+-+-+-+-+-+-+-+ Baixo para cima +-+-+-+-+-+-+-+-+-+-+-+\n");
                printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
                //chamando função para imprimir matriz
                imprimirmatriz(mat);
                /*O "memset" e caso o usario queira fazer mais de uma pesquisa, a VARIAVEL pesquisa
                posso receber novos valores diferentes*/
                memset(pesquisa,0,sizeof(pesquisa));
                printf("\n\nQual palavra vc quer pesquisar ?  ");
                setbuf(stdin,NULL);
                gets(pesquisa);
                //descobrindo o tamanho da palavra que vai ser buscada
                tamanhopalavra = strlen(pesquisa);
                //chamando a função para fazer a pesquisa 
                baixocima(pesquisa,tamanhopalavra,mat);
                printf("\n");
                system("pause");
                /*resnum aqui recebe 100 pois e para cair no laço de repetição de novo, eu tentei colocar NULL,
                mas o compilador da um warnig então optei por ser um valor alto para cair no while de novo*/
                resnum = 100;
                system("cls");
            break;

            case 5:
                //voltar para menumatriz e escolher uma matriz diferente
                resnum0 = 50;
            break;

            default:
                system("cls");
                printf("\nOpcao invalida\n");
            break;
        }
    //repetir caso o usuario escolha uma opção invalida
    }while ((resnum < 0)||(resnum > 6)); 
}

    /*"if" para mostrar para o usuario caso ele escolha uma opção 
    invalido no menumatriz ou caso ele escolha o case 5 que volta para 
    o menu escolha matriz*/
    if(resnum0 == 50){ 
        printf("\nVoltando ao menu inicial\n");
    }else{
        setbuf(stdin,NULL);
        system("cls");
        printf("\nopcao invalida\n");   
    }
//repetir caso o usuario escolha uma opção invalida
}while ((resnum0 < 0)||(resnum0 > 2));

}
