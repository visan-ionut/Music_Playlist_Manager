======================
Music Playlist Manager
======================

This project is a music playlist management system. The code is written
in C and includes functions for initializing, freeing, and manipulating
a doubly linked circular list that represents a playlist of songs.
The main program reads commands from a file, performs various playlist
operations (e.g., adding, deleting songs), and prints the results.

Here is a brief summary of the code:
Circular Doubly Linked List (CircularDoublyLinkedList.h)
struct Node: Represents a node in the circular doubly linked list,
storing information about a song.
struct CircularDoublyLinkedList: Represents the circular doubly linked list.

List Operations (notes.c)
init_list: Initializes a circular doubly linked list.
get_nth_node: Returns a pointer to the nth node in the list.
add_nth_node: Adds a new node at the nth position in the list.
remove_nth_node: Removes the nth node from the list.
get_size: Returns the number of nodes in the list.
free_list: Frees the memory allocated for the list nodes.
print_int_list: Prints the integer values stored in the list.
print_string_list: Prints the string values stored in the list.
print_ints_left_circular: Prints integer values starting from a given
node and moving left in the circular list.
print_ints_right_circular: Prints integer values starting from a given
node and moving right in the circular list.
Main Program (tema1.c)
main: Reads commands from a file, performs playlist operations, and prints
the results.
Commands include adding, deleting, and moving songs within the playlist.
Other Functions
read_data: Reads song information from a file.
print_data: Prints song information.
Functions like ADD_FIRST, DEL_FIRST, DEL_LAST, DEL_CURR, MOVE_NEXT, MOVE_PREV,
etc., implement playlist operations.

!! The code has incomplete parts.
