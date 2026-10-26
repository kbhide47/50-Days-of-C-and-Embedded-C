/* =========================================================
   01_basic_linked_list.c
   Create a basic linked-list node
   ========================================================= */

#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node node;

    node.data = 10;
    node.next = NULL;

    printf("Data = %d\n", node.data);
    printf("Next = %p\n", (void *)node.next);

    return 0;
}


/* =========================================================
   02_create_two_nodes.c
   Create and connect two nodes
   ========================================================= */

#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node node1;
    struct Node node2;

    node1.data = 10;
    node2.data = 20;

    node1.next = &node2;
    node2.next = NULL;

    printf("Node 1 = %d\n", node1.data);
    printf("Node 2 = %d\n", node1.next->data);

    return 0;
}


/* =========================================================
   03_traverse_linked_list.c
   Traverse a linked list
   ========================================================= */

#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node node1;
    struct Node node2;
    struct Node node3;

    node1.data = 10;
    node2.data = 20;
    node3.data = 30;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    struct Node *current = &node1;

    printf("Linked List: ");

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    return 0;
}


/* =========================================================
   04_insert_beginning.c
   Insert a node at the beginning
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node *head = NULL;

    struct Node *node1 = malloc(sizeof(struct Node));
    struct Node *node2 = malloc(sizeof(struct Node));

    if (node1 == NULL || node2 == NULL)
    {
        free(node1);
        free(node2);
        return 1;
    }

    node1->data = 20;
    node1->next = NULL;
    head = node1;

    /* Insert 10 at beginning */
    node2->data = 10;
    node2->next = head;
    head = node2;

    printf("List: ");

    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    free(node2);
    free(node1);

    return 0;
}


/* =========================================================
   05_insert_end.c
   Insert a node at the end
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));

    if (head == NULL || second == NULL)
    {
        free(head);
        free(second);
        return 1;
    }

    head->data = 10;
    head->next = NULL;

    second->data = 20;
    second->next = NULL;

    head->next = second;

    /* Insert new node at end */
    struct Node *new_node = malloc(sizeof(struct Node));

    if (new_node == NULL)
    {
        free(second);
        free(head);
        return 1;
    }

    new_node->data = 30;
    new_node->next = NULL;

    second->next = new_node;

    printf("List: ");

    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    free(new_node);
    free(second);
    free(head);

    return 0;
}


/* =========================================================
   06_delete_beginning.c
   Delete the first node
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node *first = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));

    if (first == NULL || second == NULL)
    {
        free(first);
        free(second);
        return 1;
    }

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = NULL;

    struct Node *head = first;

    /* Delete first node */
    struct Node *temp = head;
    head = head->next;
    free(temp);

    printf("After deletion: ");

    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    free(head);

    return 0;
}


/* =========================================================
   07_delete_end.c
   Delete the last node
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node *first = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    if (first == NULL || second == NULL || third == NULL)
    {
        free(first);
        free(second);
        free(third);
        return 1;
    }

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    struct Node *current = first;

    /* Find second-last node */
    while (current->next != third)
    {
        current = current->next;
    }

    current->next = NULL;
    free(third);

    printf("After deletion: ");

    current = first;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    free(second);
    free(first);

    return 0;
}


/* =========================================================
   08_search_node.c
   Search for an element
   ========================================================= */

#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node node1;
    struct Node node2;
    struct Node node3;

    node1.data = 10;
    node2.data = 20;
    node3.data = 30;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    int target = 20;
    struct Node *current = &node1;

    while (current != NULL)
    {
        if (current->data == target)
        {
            printf("%d found\n", target);
            return 0;
        }

        current = current->next;
    }

    printf("%d not found\n", target);

    return 0;
}


/* =========================================================
   09_count_nodes.c
   Count number of nodes
   ========================================================= */

#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node node1;
    struct Node node2;
    struct Node node3;

    node1.data = 10;
    node2.data = 20;
    node3.data = 30;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    int count = 0;
    struct Node *current = &node1;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    printf("Number of nodes = %d\n", count);

    return 0;
}


/* =========================================================
   10_embedded_linked_list.c
   Embedded-style fixed node pool
   No malloc/free
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

#define MAX_NODES 5U

typedef struct Node
{
    uint16_t data;
    int8_t next;
} Node;

static Node node_pool[MAX_NODES];
static uint8_t used[MAX_NODES];
static int8_t head = -1;

int8_t Allocate_Node(void)
{
    for (uint8_t i = 0U; i < MAX_NODES; i++)
    {
        if (used[i] == 0U)
        {
            used[i] = 1U;
            node_pool[i].next = -1;
            return (int8_t)i;
        }
    }

    return -1;
}

void Insert_Front(uint16_t data)
{
    int8_t index = Allocate_Node();

    if (index == -1)
    {
        printf("Node pool full\n");
        return;
    }

    node_pool[index].data = data;
    node_pool[index].next = head;
    head = index;
}

void Display_List(void)
{
    int8_t current = head;

    while (current != -1)
    {
        printf("%u ", (unsigned)node_pool[current].data);
        current = node_pool[current].next;
    }

    printf("\n");
}

int main(void)
{
    Insert_Front(30U);
    Insert_Front(20U);
    Insert_Front(10U);

    printf("Embedded linked list: ");
    Display_List();

    return 0;
}
