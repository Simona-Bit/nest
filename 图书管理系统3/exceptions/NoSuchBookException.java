package exceptions;

public class NoSuchBookException extends Exception {
    public NoSuchBookException() {
    }

    public NoSuchBookException(String s) {
        super(s);
    }

    public NoSuchBookException(String s, Throwable throwable) {
        super(s, throwable);
    }

    public NoSuchBookException(Throwable throwable) {
        super(throwable);
    }

    public NoSuchBookException(String s, Throwable throwable, boolean b, boolean b1) {
        super(s, throwable, b, b1);
    }
}
