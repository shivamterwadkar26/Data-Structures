class Book {
    int bookID;
    String title, author;
    double price;
    static int count = 0;

    Book(int id, String t, String a, double p) {
        bookID = id;
        title = t;
        author = a;
        price = p;
        count++;
    }

    void display() {
        System.out.println("Book ID: " + bookID);
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
        System.out.println("Price: " + price);
        System.out.println();
    }

    void search(int id) {
        if (bookID == id)
            display();
    }

    void search(String t) {
        if (title.equalsIgnoreCase(t))
            display();
    }

    Book costlier(Book b) {
        if (price > b.price)
            return this;
        else
            return b;
    }
}

public class Main {
    public static void main(String[] args) {
        Book b1 = new Book(101, "Java", "James", 500);
        Book b2 = new Book(102, "C Programming", "Dennis", 400);
        Book b3 = new Book(103, "Python", "Guido", 600);

        System.out.println("Book Details:");
        b1.display();
        b2.display();
        b3.display();

        System.out.println("Search by Book ID:");
        b1.search(101);

        System.out.println("Search by Title:");
        b2.search("C Programming");

        System.out.println("Costlier Book:");
        Book b = b1.costlier(b3);
        b.display();

        System.out.println("Total Books: " + Book.count);
    }
}
