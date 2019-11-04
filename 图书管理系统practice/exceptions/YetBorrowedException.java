package exceptions;

public class YetBorrowedException extends Exception {
    public YetBorrowedException() {
    }

    public YetBorrowedException(String s) {
        super(s);
    }

    public YetBorrowedException(String s, Throwable throwable) {
        super(s, throwable);
    }

    public YetBorrowedException(Throwable throwable) {
        super(throwable);
    }

    public YetBorrowedException(String s, Throwable throwable, boolean b, boolean b1) {
        super(s, throwable, b, b1);
    }
}
