package classes;

public class Book {
    private String ISBN;
    private String title;
    private String author;
    private double price;
    private int count;
    //存量
    private int currentCount;
    // 总量
    private int totalCount;
    // 借阅次数
    private int borrowedCount;

    public Book(String ISBN, String title, String author, double price, int count) {
        this.ISBN = ISBN;
        this.title = title;
        this.author = author;
        this.price = price;
        this.currentCount = count;
        this.totalCount = count;
        this.borrowedCount = 0;
    }

    public boolean is(String ISBN) {
        return this.ISBN.equals(ISBN);
    }

    public void increaseCount(int count) {
        currentCount += count;
        totalCount += count;
    }

    String getTitle() {
        return title;
    }

    public int getCurrentCount() {
        return currentCount;
    }

    public void borrowBook() {
        currentCount--;
        borrowedCount++;
    }

    private String getAuthor() {
        return author;
    }

    private double getPrice() {
        return price;
    }

    private int getBorrowedCount() {
        return borrowedCount;
    }

    public void returnBook() {
        currentCount++;
    }
}
