#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char word;
    int concurrence;
    struct Node *next;
    struct Node *prev;
};

void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf("(%s, %d)", &(n->word), n->concurrence);
        n = n->next;
    }
}

int _searchWord(struct Node *root, char wordToSearch)
{
    int fined = 1;
    while (root)
    {
        char aux = root->word;
        if (aux == wordToSearch)
        {
            root->concurrence = (root->concurrence) + 1;
            fined = -1;
            break;
        }
        root = root->next;
    }
    return fined;
}

void push(struct Node **head_ref, char new_word, int new_concurrence)
{
    if (_searchWord(*head_ref, new_word) > 0)
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->word = new_word;
        new_node->concurrence = new_concurrence;
        new_node->prev = NULL;
        new_node->next = (*head_ref);
        if ((*head_ref) != NULL)
        {
            (*head_ref)->prev = new_node;
        }
        (*head_ref) = new_node;
    }
}

struct Node *lastNode(struct Node *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}

void swap(char *word1, int *concurrence1, char *word2, int *concurrence2)
{
    char temp1 = *word1;
    *word1 = *word2;
    *word1 = temp1;
    int temp2 = *concurrence1;
    *concurrence1 = *concurrence2;
    *concurrence2 = temp2;
}

struct Node *partition(struct Node *l, struct Node *h)
{
    char aux0 = h->word;
    int aux = h->concurrence;

    struct Node *i = l->prev;

    for (struct Node *j = l; j != h; j = j->next)
    {
        if (j->concurrence <= aux)
        {
            i = (i == NULL) ? l : i->next;

            swap(&(i->word), &(i->concurrence), &(j->word), &(j->concurrence));
        }
    }
    i = (i == NULL) ? l : i->next;
    swap(&(i->word), &(i->concurrence), &(h->word), &(h->concurrence));
    return i;
}

void _quickSort(struct Node *l, struct Node *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        struct Node *p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}

void quickSort(struct Node *head)
{
    struct Node *h = lastNode(head);

    _quickSort(head, h);
}

int main(int argc, char **argv)
{
    struct Node *a = NULL;
    push(&a, 'a', 5);
    push(&a, 'b', 20);
    push(&a, 'c', 4);
    push(&a, 'd', 3);
    push(&a, 'e', 30);
    push(&a, 'e', 1);

    printf("Linked List before sorting \n");
    printList(a);

    quickSort(a);

    printf("\nLinked List after sorting \n");
    printList(a);

    return 0;
}