import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        
        int N = sc.nextInt();
        int M = sc.nextInt();
        
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextLong();
        }
        
        long[] B = new long[M];
        for (int j = 0; j < M; j++) {
            B[j] = sc.nextLong();
        }
        
        Arrays.sort(A);
        Arrays.sort(B);
        int i = 0, j = 0;
        int sushiCount = 0;
        
        while (i < N && j < M) {
            if (B[j] <= 2 * A[i]) {
                sushiCount++;
                i++;
                j++;
            } else {
                i++;
            }
        }
        
        System.out.println(sushiCount);
        sc.close();
    }
}
