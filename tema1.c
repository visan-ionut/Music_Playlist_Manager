#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node {
	struct Node *next;
	struct Node *previous;
	char *tag;
	char *title;
	char *artist;
	char *album;
	char *year;
};

struct List {
	struct Node *head;
	struct Node *tail;
	struct Node* cursor;
	int size;
};

void init_list(struct List *list) {
	//initializare
	list->head->previous = NULL;
	list->tail->next = NULL;
	list->cursor = NULL;
	list->size = 0;
}

void free_list(struct List **pp_list) {
    struct Node* tmp;
    struct Node *head = (*pp_list)->head;
    head = head->next;
    free(head->previous);
    while (head != (*pp_list)->head) {
       tmp = head;
       head = head->next;
       free(tmp);
    }
    free (*pp_list);
}

void read_data(FILE *f) {
	//alocari
	struct Node *node = malloc(sizeof(struct Node));
	node->tag = malloc(3*sizeof(char));
	node->title = malloc(30*sizeof(char));
	node->artist = malloc(30*sizeof(char));
	node->album = malloc(30*sizeof(char));
	node->year = malloc(4*sizeof(char));
	//preluare informatii din fisiere si distribuire
	fseek(f, -97, SEEK_END);
	fread(node->tag, sizeof(char), 3, f);
	fread(node->title, sizeof(char), 30, f);
	fread(node->artist, sizeof(char), 30, f);
	fread(node->album, sizeof(char), 30, f);
	fread(node->year, sizeof(char), 4, f);
}

void print_data(FILE *f) {
	//alocari
	struct Node *node = malloc(sizeof(struct Node));
	node->tag = malloc(3*sizeof(char));
	node->title = malloc(30*sizeof(char));
	node->artist = malloc(30*sizeof(char));
	node->album = malloc(30*sizeof(char));
	node->year = malloc(4*sizeof(char));
	//preluare informatii din fisiere si distribuire
	fseek(f, -97, SEEK_END);
	fread(node->tag, sizeof(char), 3, f);
	fread(node->title, sizeof(char), 30, f);
	fread(node->artist, sizeof(char), 30, f);
	fread(node->album, sizeof(char), 30, f);
	fread(node->year, sizeof(char), 4, f);
	//afisari
	printf("%s\n", node->tag);
	printf("Title: %s\n", node->title);
	printf("Artist: %s\n", node->artist);
	printf("Album: %s\n", node->album);
	printf("Year: %s\n", node->year);
}

void ADD_FIRST(FILE *f) {
	//alocari
	struct Node *node = malloc(sizeof(struct Node));
	node->tag = malloc(3*sizeof(char));
	node->title = malloc(30*sizeof(char));
	node->artist = malloc(30*sizeof(char));
	node->album = malloc(30*sizeof(char));
	node->year = malloc(4*sizeof(char));
	//citire informatii
	fseek(f, -97, SEEK_END);
	fread(node->tag, sizeof(char), 3, f);
	fread(node->title, sizeof(char), 30, f);
	fread(node->artist, sizeof(char), 30, f);
	fread(node->album, sizeof(char), 30, f);
	fread(node->year, sizeof(char), 4, f);
	
}

void DEL_FIRST(FILE *f) {
	//alocari
	struct List* list = malloc(sizeof(struct List));
	struct Node *node = malloc(sizeof(struct Node));
	node->tag = malloc(3*sizeof(char));
	node->title = malloc(30*sizeof(char));
	node->artist = malloc(30*sizeof(char));
	node->album = malloc(30*sizeof(char));
	node->year = malloc(4*sizeof(char));
	//preluare informatii din fisiere si distribuire
	fseek(f, -97, SEEK_END);
	fread(node->tag, sizeof(char), 3, f);
	fread(node->title, sizeof(char), 30, f);
	fread(node->artist, sizeof(char), 30, f);
	fread(node->album, sizeof(char), 30, f);
	fread(node->year, sizeof(char), 4, f);
	struct Node *NodeToDel;
	if (list->head == NULL) {
		printf("Error:delete from empty playlist\n");
	} else {
		NodeToDel = list->head;
		list->head = list->head->next;
		list->head->previous = NULL;
		free(NodeToDel);
	}
}

void DEL_LAST(FILE *f) {
	//alocari
	struct List* list = malloc(sizeof(struct List));
	struct Node *node = malloc(sizeof(struct Node));
	node->tag = malloc(3*sizeof(char));
	node->title = malloc(30*sizeof(char));
	node->artist = malloc(30*sizeof(char));
	node->album = malloc(30*sizeof(char));
	node->year = malloc(4*sizeof(char));
	//preluare informatii din fisiere si distribuire
	fseek(f, -97, SEEK_END);
	fread(node->tag, sizeof(char), 3, f);
	fread(node->title, sizeof(char), 30, f);
	fread(node->artist, sizeof(char), 30, f);
	fread(node->album, sizeof(char), 30, f);
	fread(node->year, sizeof(char), 4, f);
	struct Node *NodeToDel;
	if (list->tail == NULL) {
		printf("Error:delete from empty playlist\n");
	} else {
		NodeToDel = list->tail;
		list->tail = list->tail->previous;
		list->tail->next = NULL;
		free(NodeToDel);
	}
}

void MOVE_NEXT(struct List* list, FILE* fout) {
	if (list == NULL) {
		return;
	}
	if (list->cursor == NULL) {
		fprintf(fout, "Error:no track playing\n");
		return;
	}
	if (list->cursor->next == NULL) {
		return;
	}
	list->cursor = list->cursor->next;
}

void MOVE_PREV(struct List* list, FILE* fout) {
	if (list == NULL) {
		return;
	}
	if (list->cursor == NULL) {
		fprintf(fout, "Error:no track playing\n");
		return;
	}
	if (list->cursor->previous == NULL) {
		return;
	}
	list->cursor = list->cursor->previous;
}

int main(int argc, char *argv[]) {
	struct List* list = malloc(sizeof(struct List));
	int q;
	char commandcopy[15], command[15];
	char song[30];
	char songcopy[30];

	FILE *fin, *fout;
	fin = fopen(argv[1], "rt");
	fout = fopen(argv[2], "a+");

	fscanf(fin, "%d", &q);
	printf("%d\n", q);

	for(int i = 0; i < q; i++) {
	fscanf(fin, "%s", commandcopy);
	strcpy(command, commandcopy);
	if (strcmp(command, "DEL_FIRST") == 0) {
		printf("%s\n", command);

	} else if (strcmp(command, "DEL_LAST") == 0) {
		printf("%s\n", command);

	} else if (strcmp(command, "DEL_CURR") == 0) {
		printf("%s\n", command);

	} else if (strcmp(command, "MOVE_NEXT") == 0) {
		printf("%s\n", command);

	} else if (strcmp(command, "MOVE_PREV") == 0) {
		printf("%s\n", command);

	} else if (strcmp(command, "SHOW_FIRST") == 0) {
		printf("%s\n", command);

	} else if (strcmp(command, "SHOW_LAST") == 0) {
		printf("%s\n", command);

	} else if (strcmp(command, "SHOW_CURR") == 0) {
		printf("%s\n", command);

	} else if (strcmp(command, "SHOW_PLAYLIST") == 0) {
		printf("%s\n", command);

	} else {
		printf("%s ", command);
	}
	if (strcmp(command, "ADD_FIRST") == 0) {
		fscanf(fin, "%[^\n]\n", songcopy);
		printf("%s\n", songcopy);
		sprintf(song, "%s%s", "./songs/", songcopy+1);
	} else if (strcmp(command, "ADD_LAST") == 0) {
		fscanf(fin, "%[^\n]\n", songcopy);
		printf("%s\n", songcopy);
		sprintf(song, "%s%s", "./songs/", songcopy+1);
	} else if (strcmp(command, "ADD_AFTER") == 0) {
		fscanf(fin, "%[^\n]\n", songcopy);
		printf("%s\n", songcopy);
		sprintf(song, "%s%s", "./songs/", songcopy+1);
	} else if (strcmp(command, "DEL_SONG") == 0) {
		fscanf(fin, "%[^\n]\n", songcopy);
		printf("%s\n", songcopy);
		sprintf(song, "%s%s", "./songs/", songcopy+1);
		}
	FILE *fsongs = fopen(song, "rb");
	if (fsongs == NULL) {
		exit(-1);
	}
	}
}