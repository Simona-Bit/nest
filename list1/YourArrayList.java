package list;

import java.util.Arrays;

public class YourArrayList implements List {
    @Override
    public boolean add(int element) {
        return false;
    }

    @Override
    public boolean add(int index, int element) {
        return false;
    }

    @Override
    public int get(int index) {
        return 0;
    }

    @Override
    public int set(int index, int val) {
        return 0;
    }

    @Override
    public int remove(int index) {
        return 0;
    }

    @Override
    public int size() {
        return 0;
    }

    @Override
    public boolean isEmpty() {
        return false;
    }

    @Override
    public Iterator iterator() {
        return null;
    }
}
