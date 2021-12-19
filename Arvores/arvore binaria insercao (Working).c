#include <stdio.h>
#include <stdlib.h>
 
struct NO {
    int key;
    struct NO *esq, *dir;
};

// funcao utilitaria para criar o NO da arvore
struct NO* novoNO(int item)
{
    struct NO* temp
        = (struct NO*)malloc(sizeof(struct NO));
    temp->key = item;
    temp->esq = temp->dir = NULL;
    return temp;
}
 
// funcao utilitaria para fazer a  transversal da arvore
void ordem(struct NO* root)
{
    if (root != NULL) {
        ordem(root->esq);
        printf("%d \n", root->key);
        ordem(root->dir);
    }
}
 
/* funcao utilitaria para  inserir
   um novo NO com key dentro da arvore*/
struct NO* insert(struct NO* NO, int key)
{
    /* se a arvore esta vazia, volta no novoNO */
    if (NO == NULL)
        return novoNO(key);
 
    /* do contrario, seguir a arvore */
    if (key < NO->key)
        NO->esq = insert(NO->esq, key);
    else if (key > NO->key)
        NO->dir = insert(NO->dir, key);
 
    /* retorna para o ponteiro do NO inicial */
    return NO;
}
 
int main()
{
    struct NO* root = NULL;
    root = insert(root, 40);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    // imprime a arvore em ordem
    ordem(root);
 
    return 0;
}
