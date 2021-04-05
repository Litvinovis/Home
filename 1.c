// don't forget to paste imports
// import ...
import java.util.*;
// don't change class name and main function signature
public class Main {
    static double deter(double A[][]) {
        int n = A.length;
        if(n == 1) {
            return A[0][0];
        }
        double ans = 0;
        double B[][] = new double[n-1][n-1];
        int l = 1;
        for(int i = 0; i < n; ++i) {
            int x = 0, y = 0;
            for(int j = 1; j < n; ++j) {
                for(int k = 0; k < n; ++k) {
                    if(i == k) {
                        continue;
                    }
                    B[x][y] = A[j][k];
                    y++;
                    if(y == n - 1){
                        y = 0;
                        x++;
                    }
                }
            }
            ans += l * A[0][i] * deter(B);
            l *= (-1);
        }
        return ans;
    }
    
    public static void main(String[] args){
        // Your code here
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        double[][] array = new double[N][N];
        int i = 0;
        int q = 0;
        while (i < N) {
            q = 0;
            while (q < N) {
                array[i][q] = scanner.nextDouble();   
                q++;
            }
            i++;
        }
        int fin = (int)deter(array);
        System.out.println(fin);
    }
}