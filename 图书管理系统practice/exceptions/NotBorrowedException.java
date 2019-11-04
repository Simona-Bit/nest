package exceptions;

public class NotBorrowedException extends Exception{
    public NotBorrowedException() {
    }

    public NotBorrowedException(String s) {
        super(s);
    }

    public NotBorrowedException(String s, Throwable throwable) {
        super(s, throwable);
    }

    public NotBorrowedException(Throwable throwable) {
        super(throwable);
    }

    public NotBorrowedException(String s, Throwable throwable, boolean b, boolean b1) {
        super(s, throwable, b, b1);
    }
}
