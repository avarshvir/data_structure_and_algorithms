import java.util.Scanner;
class ArrayCreation_1{
    public static void main(String args[]){
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array :");
        n = sc.nextInt();
        int []arr = new int[n];

        System.out.println("Enter the elements of array :");
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }

        for(int j = 0; j < n; j++){
            System.out.print(arr[j]+" ");
        }
    }
}