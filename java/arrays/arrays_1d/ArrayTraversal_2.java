import java.util.Scanner;
class ArrayTraversal_2{
    public static void main(String args[]){
        int n;
        System.out.print("Enter size of array :");

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        int [] arr = new int[n];
        System.out.println("Enter Array Elements : ");
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }

        System.out.println("Traversal of array : ");
        for(int i = 0; i < n; i++){
            System.out.println("arr["+i+"]"+" = "+ arr[i]);
        }

    }
}