// Documentar o c�digo (boas pr�ticas)
#include <stdio.h>
#include <string.h>

// Modificar o c�digo de acordo com as pendencias abaixo:

// Utilize array com aloca��o din�mica baseado na palavra da vez
// Utilize struct para armazenar em mem�ria e depois transferir para arquivo
// Controle de jogada deve ser feito utilizando entrada de dados pelo teclado contendo informa��o da posi��o e usu�rio

char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

abertura() {
    printf("//\n");
    printf("/ Jogo de Forca */\n");
    printf("//\n\n");
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

    printf("Voc� j� deu %d chutes\n", tentativas);

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
    sprintf(palavrasecreta, "MELANCIA"); // Mudar esse trecho de c�digo (Utilize array com aloca��o din�mica baseado na palavra da vez)
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
// 1�) Na fun��o abertura (), ser� exibido a mensagem de abertura contida na fun��o;

// 2�) A fun��o escolhepalavra (), atribuir� a string "MELANCIA" a vari�vel palavrasecreta, que agora "vale" MELANCIA;

// 3�) No loop do...while, ser� invocada a fun��o desenhaforca(). Essa fun��o faz o seguinte: primeiro ela printa a quantidade de tentativas que o usu�rio j� efetuou. Depois, ela invoca a fun��o jachutou() passando como par�metro para ela a vari�vel palavrasecreta na posi��o do indexador i, ficando jachutou(palavrasecreta[i]). A fun��o strlen varre a string e retorna a quantidade de posi��es que ela possui, ent�o no caso a palavra MELANCIA, retornar� o valor 8. Como o usu�rio ainda n�o chutou nenhuma letra, a fun��o cair� na condicional "else", imprimindo os 8 underscores (_ ).

// 4�) Agora ser� invocada a fun��o chuta(), onde o usu�rio ir� informar a letra que ele deseja chutar. Essa letra, ser� salva na vari�vel chutes, que � um vetor de 26 posi��es, contemplando assim, todas as letras do alfabeto.

// 5�) Como as condi��es do while n�o foram satisfeitas, o loop se reinicia. Quando a fun��o desenhaforca() for invocada novamente, automaticamente a fun��o jachutou(palavrasecreta[i]) tamb�m ser�. Agora, como o usu�rio j� informou uma letra, a fun��o jachutou() pegar� essa letra e ir� comparar com todas as posi��es da palavrasecreta. Caso a letra seja encontrada, a fun��o retornar� o valor 1, ou seja, verdadeiro e a fun��o desenhaforca() executar� a condicional if, imprimindo a letra no lugar do underscore, caso contr�rio, o underscore ser� impresso novamente. O loop se repete sempre que o usu�rio informar uma nova letra.

// A �nica coisa que reparei, � que seu algoritmo est� num loop infinito no do...while, pois a nega��o das vari�veis enforcou e acertou est�o sempre retornando um valor�verdadeiro.
