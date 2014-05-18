/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
 *
 * 1º Trabalho Prático - Mét. Iterativos Sist. Lineares
 * Prof. Murilo Francisco Tomé
 *
 * Desenvolvido por:
 * Antonio Carlos Moreira Lopes Júnior  NUSPº 7987290
 * Gabriela Pinto Cesar Duque           NUSPº 7694220
 * Leonardo Sampaio Ferraz Ribeiro      NUSPº 8532300
 *
 *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */

#include <stdio.h>
#include "functions.h"

int main(int argc, const char * argv[]) {
    
    // variáveis auxiliares
    int opcao;
    
    // repete até encontrar um break
    do {
    
        imprimeMenu();
        
        scanf("%d", &opcao);
        
        // seleciona opção do usuário
        switch (opcao) {
            
            // 1) Entrar com as matries A e B
            case 1:
                testarComEntradasDoUsuario();
                break;
            
            // 2) Testar com exercício b)
            case 2:
                testarComExercicioB();
                break;
            
            // 3) Testar com exercício c)
            case 3:
                testarComExercicioC();
                break;
                
            // Sair
            case 4:
                break;
                
            default:
                printf("Opção Inválida!\n");
                break;
                
        }
        
    } while (opcao != 4);
    

}

