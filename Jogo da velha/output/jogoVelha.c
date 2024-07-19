#include <stdio.h>

void criarTabuleiro(char tabuleiro[3][3]){
    //Nessa fução criamos um tabuleiro 3x3 preenchendo ele com espaços vazios
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = ' ';
        }
    }
}

void printarTabuleiro(char tabuleiro[3][3]){
    //Aqui printamos a matriz botando os indices em cima
    printf("0   1   2\n");
    for(int i = 0; i < 3; i++){
        //esse for vai andar as linhas
        for(int j = 0; j < 3; j++){
            //a cada indice de linha andamos todas as colunas antes de trocar o indice de linha
            printf("%c", tabuleiro[i][j]);
            if( j < 2){
                printf(" | ");
            }
        }
        printf("\n");
        if( i < 2){
            printf("----------\n");
        }
    }
}

int jogadaJogadorX(char tabuleiro[3][3], int linha, int coluna){
    //essa função implementa a vez do jogador X jogar
    while (1)
    //Esse looping é infinito
    {
        printf("Vez do jogador que joga de X \n");
        printf("Digite a linha que você quer jogar: ");
        scanf("%d", &linha);
        printf("Digite a coluna que você quer jogar: ");
        scanf("%d", &coluna);
        //"Ouvimos" a linha e coluna do jogador e verificamos se ela é do tamanho da matriz
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2){
            //Se ela sair do limite da matriz tentamos denovo
            printf("Tente novamente! Posição invalida");
            continue;
        }
        //Se no lugar onde queremos botar for vazio botamos o X
        //E saimos do laço
        if (tabuleiro[linha][coluna] == ' '){
            tabuleiro[linha][coluna] = 'X';
            break;
        //Se tiver algo pedirmos para tentar novamente
        }else if (tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O'){
            printf("Tente novamente! ");
            continue;
        }
    }
    //Retornamos 0
    return 0;
}

int jogadaJogadorO(char tabuleiro[3][3], int linha, int coluna){
    //Essa implementa a jogada do jogador O
    //Faz a mesma coisa da de cima, só que em vez de botar x botamos O
    while (1)
    {
        printf("Vez do jogador que joga de O \n");
        printf("Digite a linha que você quer jogar: ");
        scanf("%d", &linha);
        printf("Digite a coluna que você quer jogar: ");
        scanf("%d", &coluna);
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2){
            printf("Tente novamente! Posição invalida");
            continue;
        }
        if (tabuleiro[linha][coluna] == ' '){
            tabuleiro[linha][coluna] = 'O';
            break;
        }else if (tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O'){
            printf("Tente novamente! ");
            continue;
        }
    }
    return 0;
}

int verificarVitoriaJogadorX(char tabuleiro[3][3]){
    //Verificamos aqui cada linha, coluna e diagonal para vez se X ganhou se sim retorna 1
    if(tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X'){
        return 1;
    }else if(tabuleiro[2][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[0][2] == 'X'){
        return 1;
    }
    for(int i = 0; i < 3; i++){
        if(tabuleiro[0][i] == 'X' && tabuleiro[1][i] == 'X' && tabuleiro[2][i] == 'X'){
            return 1;
        }
        if(tabuleiro[i][0] == 'X' && tabuleiro[i][1] == 'X' && tabuleiro[i][2] == 'X'){
            return 1;
        }
    }
    //Se nao retorna 0 ( que significa que queremos voltar para main ou para a função que chamou ela)
    return 0;
}

int verificarVitoriaJogadorO(char tabuleiro[3][3]){
    //Faz a mesma coisa do de cima Só que com O
    if(tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O'){
        return 1;
    }else if(tabuleiro[2][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[0][2] == 'O'){
        return 1;
    }
    for(int i = 0; i < 3; i++){
        if(tabuleiro[0][i] == 'X' && tabuleiro[1][i] == 'X' && tabuleiro[2][i] == 'X'){
            return 1;
        }
        if(tabuleiro[i][0] == 'X' && tabuleiro[i][1] == 'X' && tabuleiro[i][2] == 'X'){
            return 1;
        }
    }
    return 0;
}

int deuvelha(char tabuleiro[3][3]){
    int deuvelhavar = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tabuleiro[i][j] != ' '){
                deuvelhavar += 1;
            }
        }
    }
    if(deuvelhavar == 9){
        return 1;
    }
    return 0;
}


int main(){
    //A main, aqui criamos de verdade a variavel tabuleiro, linha colula e vez do jogador
    char tabuleiro[3][3];
    int linha;
    int coluna; 
    int vezjogador = 1;
    int deuvelhavar = 0;

    //Iniciamos o tabuleiro e damos boas vindas
    criarTabuleiro(tabuleiro);
    printf("BEM VINDO AO JOGO DA VELHA DE PEDRO!!!!! \n");

    while(1){
        //Loop infinito
        printarTabuleiro(tabuleiro);
        //Printamos o tabuleiro
        //Se vez do jogador for 1 então é vez do jogador X
        if(vezjogador == 1){
            //Puxamos a função para o jogador X jogar
            jogadaJogadorX(tabuleiro, linha, coluna);
            //Mudamos para 0 para o jogador O poder jogar
            vezjogador = 0;
            if(verificarVitoriaJogadorX(tabuleiro)){
                //Se retornar 1 (verdadeiro ) a nossa função verificar vitoria
                //Printamos que x ganhou 
                //Saimos do loop
                printf("Jogador X ganhou\n");
                printarTabuleiro(tabuleiro);
                break;
            }else if(deuvelha(tabuleiro)){
                printf("\n");
                printarTabuleiro(tabuleiro);
                printf("Deu velha!!");
                break;
            }
        }else if(vezjogador == 0){
            //Aqui é quando a vez do jogador é 0 Assim é a vez do jogador O
            //Botamos o jogador O jogar
            jogadaJogadorO(tabuleiro, linha, coluna);
            //Mudamos para o jogodor 1 denovo
            vezjogador = 1;
            if(verificarVitoriaJogadorO(tabuleiro)){
                //Mesmo esquema de verificação de vitoria
                printf("Jogado O ganhou\n");
                printarTabuleiro(tabuleiro);
                break;
            }else if(deuvelha(tabuleiro)){
                printf("\n");
                printarTabuleiro(tabuleiro);
                printf("Deu velha!!\n");
                break;
            }
        }
    
    }


    //Fim de jogo
    printf("Fim de jogo!!!");

    //Finalizamos a função ( finalizar o programa )
    return 0;
}