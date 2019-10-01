import java.util.Arrays;

enum 星期 {
    一(1), 二(2), 三(3),
    四(4);

    private int day;
    星期(int day) {
        this.day = day;
    }

    public void print() {
        System.out.println(day);
    }
}

enum Gender {
    FEMALE, MALE
}
public class EnumDemo {
    public static void main(String[] args) {
        Gender gender = Gender.FEMALE;
        星期 week = 星期.一;
        week.print();
        System.out.println(gender);
        System.out.println(Arrays.toString(Gender.values()));
        Gender g = Gender.valueOf("FEMALE");
        System.out.println(g);
        Gender.valueOf("FEMAL");
    }
}
