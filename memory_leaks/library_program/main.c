#include <stdio.h>
#include "library.h"

int main() {
    Library *library = create_library();

    add_book(library, "The Great Gatsby", "F. Scott Fitzgerald", 1925);
    add_book(library, "To Kill a Mockingbird", "Harper Lee", 1960);
    add_book(library, "1984", "George Orwell", 1949);

    printf("Books in the library:\n");
    view_books(library);

    free_library(library);
    return 0;
}
