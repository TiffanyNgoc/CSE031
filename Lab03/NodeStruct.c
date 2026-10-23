#include <stdio.h>
#include <stdlib.h>

struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
	
	// Insert code here
	// head is a pointer, so it stores the address of the Node
    // %p is used to print memory addresses
    printf("Value of head: %p\n", (void *)head);

    // &head gives the address of the pointer variable itself
    // this is different from the address stored inside head
    printf("Address of head: %p\n", (void *)&head);

    // head->iValue accesses the integer inside the Node
    // & gets the address of that integer
    printf("Address of iValue: %p\n", (void *)&head->iValue);

    // head->fValue accesses the float inside the Node
    // & gets the address of that float
    printf("Address of fValue: %p\n", (void *)&head->fValue);

    // head->next accesses the pointer member inside the Node
    // & gets the address where the next pointer is stored
    printf("Address of next: %p\n", (void *)&head->next);

	
	return 0;
}