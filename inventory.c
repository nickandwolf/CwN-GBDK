#include <gb/gb.h>
#include <stdlib.h>

#define MAX_ITEMS 20 // maximum number of items in the inventory

uint8_t pointer;

// a structure to represent an item
typedef struct {
    char name[ITEM_NAME_LENGTH]; // the name of the item
    UINT8 quantity; // the quantity of the item
} item;

// a global array to store the inventory
item inventory[MAX_ITEMS];

// a global variable to keep track of the number of items in the inventory
UINT8 num_items = 0;

// a function to add an item to the inventory
void add_item(char* name, UINT8 quantity) {
    // check if the inventory is full
    if (num_items == MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }

    // check if the item already exists in the inventory
    for (UINT8 i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // update the quantity of the existing item
            inventory[i].quantity += quantity;
            printf("Added %u %s(s) to the inventory.\n", quantity, name);
            return;
        }
    }

    // create a new item and add it to the inventory
    item new_item;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    inventory[num_items] = new_item;
    num_items++;
    printf("Added %u %s(s) to the inventory.\n", quantity, name);
}

// a function to remove an item from the inventory
void remove_item(char* name, UINT8 quantity) {
    // check if the inventory is empty
    if (num_items == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    // find the item in the inventory
    for (UINT8 i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // check if the quantity to remove is valid
            if (quantity > inventory[i].quantity) {
                printf("Cannot remove more than what you have!\n");
                return;
            }

            // update the quantity of the item
            inventory[i].quantity -= quantity;
            printf("Removed %u %s(s) from the inventory.\n", quantity, name);

            // check if the item is depleted
            if (inventory[i].quantity == 0) {
                // shift the remaining items to fill the gap
                for (UINT8 j = i; j < num_items - 1; j++) {
                    inventory[j] = inventory[j + 1];
                }
                // decrement the number of items in the inventory
                num_items--;
            }
            return;
        }
    }

    // if the item is not found, print a message
    printf("No such item in the inventory!\n");
}

// a function to display the inventory
void show_inventory() {
    // check if the inventory is empty
    if (num_items == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    // print a header
    printf("Inventory:\n");
    printf("Name\t\tQuantity\n");

    // print each item and its quantity
    for (UINT8 i = 0; i < num_items; i++) {
        printf("%s\t\t%u\n", inventory[i].name, inventory[i].quantity);
    }
}

// a function to handle user input and commands
void handle_input() {
    char buffer[32]; // a buffer to store user input
    char command[10]; // a buffer to store user command
    char name[ITEM_NAME_LENGTH]; // a buffer to store item name
    UINT8 quantity; // a variable to store item quantity

    while (1) { // loop forever until user quits
        printf("\nEnter a command: ");
        gets(buffer); // get user input

        // parse user input into command and arguments
        sscanf(buffer, "%s %s %u", command, name, &quantity);

        // execute command based on user input
        if (strcmp(command, "add") == 0) { // add an item to the inventory
            add_item(name, quantity);
        } else if (strcmp(command, "remove") == 0) { // remove an item from the inventory
            remove_item(name, quantity);
        } else if (strcmp(command, "show") == 0) { // show the inventory
            show_inventory();
        } else if (strcmp(command, "quit") == 0) { // quit the program
            break;
        } else { // invalid command
            printf("Invalid command!\n");
        }
    }
}

// the main function
void main() {
    // initialize the Game Boy
    gb_init();

    // print a welcome message
    printf("Welcome to the inventory management program!\n");
    printf("You can use the following commands:\n");
    printf("add [name] [quantity] - to add an item to the inventory\n");
    printf("remove [name] [quantity] - to remove an item from the inventory\n");
    printf("show - to show the inventory\n");
    printf("quit - to quit the program\n");

    // handle user input and commands
    handle_input();
}