package exceptions;

public class BorrowedOutException extends Exception {
    public BorrowedOutException() {
    }

    public BorrowedOutException(String s) {
        super(s);
    }

    public BorrowedOutException(String s, Throwable throwable) {
        super(s, throwable);
    }

    public BorrowedOutException(Throwable throwable) {
        super(throwable);
    }

    public BorrowedOutException(String s, Throwable throwable, boolean b, boolean b1) {
        super(s, throwable, b, b1);
    }
}
