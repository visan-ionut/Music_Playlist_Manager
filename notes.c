#include <stdio.h>
#include <stdlib.h>

#include "CircularDoublyLinkedList.h"

/*
 * Functie care trebuie apelata dupa alocarea unei liste, pentru a o initializa.
 * (Setare valori initiale pentru campurile specifice structurii LinkedList).
 */
void init_list(struct CircularDoublyLinkedList *list) {
    /* TODO */
    list->head = NULL;
    list->tail = NULL;
}

/*
 * Functia intoarce un pointer la nodul de pe pozitia n din lista.
 * Pozitiile din lista sunt indexate incepand cu 0 (i.e. primul nod din lista se afla pe pozitia n=0).
 * Daca n >= nr_noduri, atunci se intoarce nodul de pe pozitia rezultata daca am "cicla" (posibil de mai multe ori) pe
 * lista si am trece de la ultimul nod, inapoi la primul si am continua de acolo. Cum putem afla pozitia dorita fara sa
 * simulam intreaga parcurgere?
 * Daca n < 0, eroare.
 */
struct Node* get_nth_node(struct CircularDoublyLinkedList *list, int n) {
    /* TODO */
    if (n < 0) {return NULL;}

    struct Node *current = list->head; 
    int i;
    while (1) {
        i++;
        if (i == n) {
            return current;
        } else {
            current = current->next;
        }
    }

    return NULL;
}

/*
 * Pe baza datelor trimise prin pointerul new_data, se creeaza un nou nod care e adaugat pe pozitia n a listei
 * reprezentata de pointerul list. Pozitiile din lista sunt indexate incepand cu 0 (i.e. primul nod din lista se afla
 * pe pozitia n=0).
 * Cand indexam pozitiile nu "ciclam" pe lista circulara ca la get, ci consideram nodurile in ordinea de la head la
 * ultimul (adica acel nod care pointeaza la head ca nod urmator in lista). Daca n >= nr_noduri, atunci adaugam nodul
 * nou la finalul listei. Daca n < 0, eroare.
 */
void add_nth_node(struct CircularDoublyLinkedList *list, int n, void *new_data) {
    /* TODO */
    struct Node *currentNode = list->head;
    if (list->head == NULL) {
    printf("intra in primul if");

        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
        new_node->data  = new_data; 
        new_node->next = new_node;
        new_node->prev = new_node;
        list->head = new_node;
        list->tail = new_node;
        return;
    } else {
        int i;
        for (i = 0; i < n; i++) {
            if (currentNode->next == list->head) {
                    printf("intra in primul for in if");

                struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
                new_node->data  = new_data; 
                new_node->next = list->head;
                new_node->prev = currentNode;
                currentNode->next = new_node;
                list->head->prev = new_node;
                        printf("current %d\n ", *(int *) currentNode->data);

                return;
            } else {
                currentNode = currentNode->next;
            }
        }
        if (n == 0) {
            struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 

        }
        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
        new_node->data  = new_data; 
        new_node->next = currentNode;
        new_node->prev = currentNode->prev;
        struct Node *x = currentNode->prev;
        x->next = new_node;
        currentNode->prev = new_node;
        if (n == 0) {
            list->head = new_node;
        }
        return;
    }
}

/*
 * Elimina nodul de pe pozitia n din lista al carei pointer este trimis ca parametru.
 * Pozitiile din lista se indexeaza de la 0 (i.e. primul nod din lista se afla pe pozitia n=0).
 * Functia intoarce un pointer spre acest nod proaspat eliminat din lista. Daca n >= nr_noduri - 1, se elimina nodul de
 * la finalul listei. Daca n < 0, eroare.
 * Este responsabilitatea apelantului sa elibereze memoria acestui nod.
 */
struct Node* remove_nth_node(struct CircularDoublyLinkedList *list, int n) {
    /* TODO */
    struct Node *currentNode = list->head, *x;
    if (n < 0) {return NULL;}
    int i;
    for (i = 0; i < n; i++) {
        if (currentNode->next == NULL) {
            x = currentNode->prev;
            x->next = list->head;
            return currentNode;
        } else {
            currentNode = currentNode->next;
        }
    }
    if (n == 0) {
        list->head = NULL;
        list->tail = NULL;
        return currentNode;
    }
    x = currentNode->prev;
    x->next = currentNode->next;
    currentNode->next->prev = x;
    return currentNode;
}

/*
 * Functia intoarce numarul de noduri din lista al carei pointer este trimis ca parametru.
 */
int get_size(struct CircularDoublyLinkedList *list) {
    /* TODO */
    struct Node *currentNode = list->head;
    int i = 0;
    while (1) {
        i++;
        if (currentNode->next == list->head) {
            return i;
        } else {
            currentNode = currentNode->next;
        }
    }
    return i;
}

/*
 * Procedura elibereaza memoria folosita de toate nodurile din lista, iar la sfarsit, elibereaza memoria folosita
 * de structura lista.
 */
void free_list(struct CircularDoublyLinkedList **pp_list) {
    /* TODO */
    struct Node* tmp;
    struct Node *head = (*pp_list)->head;
    head = head->next;
    free(head->prev);
    while (head != (*pp_list)->head) {
       tmp = head;
       head = head->next;
       free(tmp);
    }
    free (*pp_list);
}

/*
 * Atentie! Aceasta functie poate fi apelata doar pe liste ale caror noduri STIM ca stocheaza int-uri.
 * Functia afiseaza toate valorile int stocate in nodurile din lista separate printr-un spatiu, incepand de la primul
 * nod din lista.
 */
void print_int_list(struct CircularDoublyLinkedList *list) {
    /* TODO */
    struct Node *nod = list->head;
    printf("%d ", *(int *) nod->data);
    nod = nod->next;
    while (nod != list->head) {
        printf("%d ", *(int *) nod->data);
        nod = nod->next;
    }
    printf("\n");
}

/*
 * Atentie! Aceasta functie poate fi apelata doar pe liste ale caror noduri STIM ca stocheaza string-uri.
 * Functia afiseaza toate string-urile stocate in nodurile din lista separate printr-un spatiu, incepand de la primul
 * nod din lista.
 */
void print_string_list(struct CircularDoublyLinkedList *list) {
    /* TODO */
    struct Node *nod = list->head->next;
    while (nod->next != list->head) {
        printf("%s ", (char *) nod->data);
        nod = nod->next;
    }
    printf("\n");
}

/*
 * Atentie! Aceasta functie poate fi apelata doar pe liste ale caror noduri STIM ca stocheaza int-uri.
 * Functia afiseaza o singura data toate valorile int stocate in nodurile din lista, separate printr-un spatiu, incepand
 * de la nodul dat ca parametru si continuand la stanga in lista dublu inlantuita circulara, pana cand sunt afisate
 * valorile tuturor nodurilor.
 */
void print_ints_left_circular(struct Node *start) {
    /* TODO */
    struct Node *nod = start->prev;
    while (start->prev != start) {
        printf("%d ", *(int *) nod->data);
        nod = nod->prev;
    }
    printf("\n");}

/*
 * Atentie! Aceasta functie poate fi apelata doar pe liste ale caror noduri STIM ca stocheaza int-uri.
 * Functia afiseaza o singura data toate valorile int stocate in nodurile din lista, separate printr-un spatiu, incepand
 * de la nodul dat ca parametru si continuand la dreapta in lista dublu inlantuita circulara, pana cand sunt afisate
 * valorile tuturor nodurilor.
 */
void print_ints_right_circular(struct Node *start) {
    /* TODO */
    struct Node *nod = start->next;
    while (start->next != start) {
        printf("%d ", *(int *) nod->data);
        nod = nod->next;
    }
    printf("\n");
}