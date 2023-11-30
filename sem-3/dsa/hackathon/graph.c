#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>



struct graph_node {
    char name[1024];
    int is_Dir;
    int size;
    time_t create_time;
    struct graph_node *prev_node; 
    struct graph_node *next_sibling;
    struct graph_node *kids;
};
struct Graph {
    struct graph_node *curr_Dir;
    struct graph_node *root;
};

void add_kid_graph(struct graph_node *prev_node, struct graph_node *child) {
    child->next_sibling = prev_node->kids;
    child->prev_node = prev_node;
    prev_node->kids = child;
}

struct graph_node *c_graph_node(const char *name, int is_Dir){
    struct graph_node *newnode = malloc(sizeof(struct graph_node));
    strncpy(newnode->name, name, 1024);
    newnode->name[1024 - 1] = '\0';
    newnode->is_Dir = is_Dir;
    newnode->size = is_Dir ? 0 : rand() % 1024;
    newnode->create_time = time(NULL);
    newnode->next_sibling = NULL;
    newnode->kids = NULL;
    newnode->prev_node = NULL;

    return newnode;
}

void inside_files(struct graph_node *node, int depth) {
    printf("Contents of %s:\n", node->name);

    struct graph_node *curr = node->kids;
    while (curr != NULL) {
        for (int i = 0; i < depth; ++i) {
            printf("  ");
        }
        printf("%s %s (Size: %d, Created: %s)",
               curr->is_Dir ? "D" : "F",
               curr->name,
               curr->size,
               ctime(&curr->create_time));

        if (curr->is_Dir) {
            inside_files(curr, depth + 1);
        }

        curr = curr->next_sibling;
    }
}



void displayFileMetadataInGraph(struct graph_node *node) {
    printf("Metadata of files in %s:\n", node->name);

    struct graph_node *curr = node->kids;
    while (curr != NULL) {
        if (!curr->is_Dir) {
            printf("  %s (Size: %d, Created: %s)\n",
                   curr->name,
                   curr->size,
                   ctime(&curr->create_time));
        }

        curr = curr->next_sibling;
    }
}

struct graph_node *changeDirInGraph(struct Graph *graph, const char *dirName) {
    if (strcmp(dirName, "..") == 0) {
        if (graph->curr_Dir->prev_node != NULL) {
            return graph->curr_Dir->prev_node;
        } else {
            printf("Already in the root Dir.\n");
            return graph->curr_Dir;
        }
    }

    struct graph_node *curr = graph->curr_Dir->kids;
    while (curr != NULL) {
        if (strcmp(curr->name, dirName) == 0 && curr->is_Dir) {
            return curr;
        }
        curr = curr->next_sibling;
    }

    printf("Dir '%s' not found.\n", dirName);
    return graph->curr_Dir;
}

void createDirInGraph(struct Graph *graph, const char *dirName) {
    struct graph_node *newDir = c_graph_node(dirName, 1);
    add_kid_graph(graph->curr_Dir, newDir);
    printf("Dir '%s' created successfully.\n", dirName);
}

void create_files_graph(struct Graph *graph, const char *fileName) {
    struct graph_node *newFile = c_graph_node(fileName, 0);
    add_kid_graph(graph->curr_Dir, newFile);
    printf("File '%s' created successfully.\n", fileName);
}

int main() {
    struct Graph graph;
    graph.root = c_graph_node("/", 1);
    graph.curr_Dir = graph.root;

    while (1) {
        printf("\ncurr Dir: %s\n", graph.curr_Dir->name);
        printf("\nMenu:\n");
        printf("1. List Contents\n");
        printf("2. Create Dir\n");
        printf("3. Change Dir\n");
        printf("4. Create File\n");
        printf("5. Display File Metadata\n");
        printf("6. Exit\n");

        char input[1024];
        printf("Enter option (1-6): ");
        fgets(input, sizeof(input), stdin);

        switch (atoi(input)) {
            case 1:
                inside_files(graph.curr_Dir, 0);
                break;
            case 2:
                printf("Enter new Dir name: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                createDirInGraph(&graph, input);
                break;

            case 3:
                printf("Enter Dir name: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                graph.curr_Dir = changeDirInGraph(&graph, input);
                break;

            case 4:
                printf("Enter new file name: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                create_files_graph(&graph, input);
                break;

             case 5:
                displayFileMetadataInGraph(graph.curr_Dir);
                break;

            case 6:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}