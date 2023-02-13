#include <stdio.h>
#include <stdlib.h>

struct node
{
    int real;
    int partilha;
    struct node *esq;
    struct node *dir;
};

struct node *search(int key, struct node *root)
{
    if (root == NULL)
        return NULL;

    if (key == root->real)
        return root;
    else if (key <= root->partilha)
        return search(key, root->esq);
    else
        return search(key, root->dir);
}

struct node *cria_arvore(int chaves[], int frequencias[], int size)
{
    if (size == 0)
        return NULL;

    int max_frequency_index = 0;
    for (int i = 1; i < size; i++)
    {
        if (frequencias[i] > frequencias[max_frequency_index])
        {
            max_frequency_index = i;
        }
    }

    int key = chaves[max_frequency_index];
    int frequency = frequencias[max_frequency_index];

    int chaves_esq[size - 1];
    int frequencias_esq[size - 1];
    int chaves_dir[size - 1];
    int frequencias_dir[size - 1];

    int esq_index = 0;
    int dir_index = 0;
    for (int i = 0; i < size; i++)
    {
        if (i == max_frequency_index)
            continue;
        if (chaves[i] <= frequency)
        {
            chaves_esq[esq_index] = chaves[i];
            frequencias_esq[esq_index] = frequencias[i];
            esq_index++;
        }
        else
        {
            chaves_dir[dir_index] = chaves[i];
            frequencias_dir[dir_index] = frequencias[i];
            dir_index++;
        }
    }

    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->real = key;
    root->partilha = frequency;
    root->esq = cria_arvore(chaves_esq, frequencias_esq, esq_index);
    root->dir = cria_arvore(chaves_dir, frequencias_dir, dir_index);

    return root;
}

void print_tree(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->real);
        print_tree(root->esq);
        print_tree(root->dir);
    }
}

int main(){

int chaves[] = {11,22,33,44,55,66,77,88,99};

int frequencias[] = {1,222,3,494,25,26,27,8,99};

print_tree(cria_arvore(chaves, frequencias,9));

}