import java.util.Scanner;

class leet {
    public static void main(String[] args) {
        Scanner obj = new Scanner(System.in);
        int n;
        System.out.println("enter size");
        n = obj.nextInt();
        int rt[] = new int[n];
        int cd[] = new int[n];
        for (int i = 0; i < n; i++) {
            rt[i] = obj.nextInt();
            cd[i] = 1;
        }
        for (int i = 0; i < n - 1; i++) {
            if (rt[i] < rt[i + 1] && cd[i + 1] = cd[i]) {
                cd[i + 1] += 1;
            }
            if (rt[i] > rt[i + 1]) {
                cd[i] += 1;
            }

        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = sum + cd[i];
        }
        System.out.println("sum=" + sum);
        for (int i = 0; i < n; i++) {
            System.out.println(cd[i]);
        }

    }
}