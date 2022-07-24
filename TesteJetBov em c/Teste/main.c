#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Animal {
        char brinco[20];
        float peso;
};

int main(){
    int i,n, totalArea = 0;
    float peso,aux,dias;
    int area, areaEscolhida = 0;
    int *b;

    printf("Ola, bem-vindo ao Gerenciamento de Pastejo Rotacionado\n");

    printf("\nQuantas areas de pastejo voce possui? ");
    scanf("%d", &totalArea);

    printf("Quantos animais deseja rotacionar? ");
    scanf("%d", &n);

    while(n > 10 * totalArea){
        printf("\nCada area possui a capacidade de 10 animais e voce possui capacidade para no maximo %d animais.\nDigite um numero de animais menor ou igual a %d: ", 10*totalArea,10*totalArea );
        scanf("%d", &n);
    }

    struct Animal *a = malloc( sizeof(struct Animal) * n);

    b = malloc(sizeof(int) * totalArea);

    for( i = 0 ; i < n ; i++ )
        a[i].peso = 0; // zera todos os pesos

    for( i = 0 ; i < n ; i++ )
        b[i] = 0; // zera as areas

    for(i = 0; i < n; i++){
        printf("\nDigite o codigo do brinco do animal %d: ", i+1);
        scanf("%s", a[i].brinco);
        printf("Digite o peso do animal de brinco '%s': ",a[i].brinco);
        scanf("%f", &a[i].peso);
    }

    printf("\n");

    for(i = 0; i < totalArea; i++){
        printf("Qual o GMD da area %d? ", i+1);
        scanf("%d", &b[i]);
    }

    for(i = 0; i < n; i++){

        areaEscolhida = 0;

        while(areaEscolhida != -1){
            printf("\nDeseja movimentar o animal de brinco %s para que Area (Ex: 1)?  (Digite '-1' para simular o proximo boi)? ", a[i].brinco);
            scanf(" %d", &areaEscolhida);

            if(areaEscolhida != -1){
            printf("\nDeseja que o animal %s fique por quantos dias na area %d?: ", a[i].brinco, areaEscolhida);
            scanf("%f", &dias);

            a[i].peso += (dias * b[areaEscolhida-1]);

            printf("O animal ficara com %f kg", a[i].peso);
            }
        }
    }

    printf("Lista de Animais:\n");
	for( i = 0 ; i < n ; i++ ){
		printf("\nAnimal %d ", i+1);
		printf("(%s, %.2f kg)\n", a[i].brinco, a[i].peso);
	}

        free( a );
        free( b );

        return 0;
}
