#include <stdio.h>

int main(void) {
    int idade;
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    int anosDormindo;
    anosDormindo = idade / 3;
    printf("Voce passou aproximadamente %d anos dormindo.\n", anosDormindo);

}
