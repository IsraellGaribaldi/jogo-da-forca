// Documentar o código (boas práticas)
#include <stdio.h>
#include <string.h>

// Modificar o código de acordo com as pendencias abaixo:

// Utilize array com alocação dinâmica baseado na palavra da vez
// Utilize struct para armazenar em memória e depois transferir para arquivo
// Controle de jogada deve ser feito utilizando entrada de dados pelo teclado contendo informação da posição e usuário

char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

abertura() {
    printf("//\n");
    printf("/ Jogo de Forca */\n");
    printf("//\n\n");
    printf("digite a palavra a ser descoberta: ")
    scanf("%s", &palavrasecreta);
}

chuta() {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
}

int chutou(char letra) {
    int achou = 0;
    for(int j = 0; j < tentativas; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

desenhaforca() {

    printf("Você já deu %d chutes\n", tentativas);

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

escolhepalavra() {
    sprintf(palavrasecreta, "MELANCIA"); // Mudar esse trecho de código (Utilize array com alocação dinâmica baseado na palavra da vez)
}

int main() {

    int acertou = 0;
    int enforcou = 0;

    abertura();
    escolhepalavra();

    do {

        desenhaforca();
        chuta();

        tentativas++;

    } while (!acertou && !enforcou);
}
// 1º) Na função abertura (), será exibido a mensagem de abertura contida na função;

// 2º) A função escolhepalavra (), atribuirá a string "MELANCIA" a variável palavrasecreta, que agora "vale" MELANCIA;

// 3º) No loop do...while, será invocada a função desenhaforca(). Essa função faz o seguinte: primeiro ela printa a quantidade de tentativas que o usuário já efetuou. Depois, ela invoca a função jachutou() passando como parâmetro para ela a variável palavrasecreta na posição do indexador i, ficando jachutou(palavrasecreta[i]). A função strlen varre a string e retorna a quantidade de posições que ela possui, então no caso a palavra MELANCIA, retornará o valor 8. Como o usuário ainda não chutou nenhuma letra, a função cairá na condicional "else", imprimindo os 8 underscores (_ ).

// 4º) Agora será invocada a função chuta(), onde o usuário irá informar a letra que ele deseja chutar. Essa letra, será salva na variável chutes, que é um vetor de 26 posições, contemplando assim, todas as letras do alfabeto.

// 5º) Como as condições do while não foram satisfeitas, o loop se reinicia. Quando a função desenhaforca() for invocada novamente, automaticamente a função jachutou(palavrasecreta[i]) também será. Agora, como o usuário já informou uma letra, a função jachutou() pegará essa letra e irá comparar com todas as posições da palavrasecreta. Caso a letra seja encontrada, a função retornará o valor 1, ou seja, verdadeiro e a função desenhaforca() executará a condicional if, imprimindo a letra no lugar do underscore, caso contrário, o underscore será impresso novamente. O loop se repete sempre que o usuário informar uma nova letra.

// A única coisa que reparei, é que seu algoritmo está num loop infinito no do...while, pois a negação das variáveis enforcou e acertou estão sempre retornando um valor verdadeiro.
