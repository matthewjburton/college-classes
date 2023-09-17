// This program is intended to investigate the properties of scope in Java
class Scope {
    static int integer = -1; // declaring a global variable

    static void sub(int[] integer) // declaring a subroutine which takes in an integer parameter by reference
    {
        integer[0] = 0; // alter the value
    }

    public static void main(String[] args) {
        int integer = 1; // declaring a local variable with the same name as the global variable "integer"

        // Display the value of integer before and after being passed into the subroutine
        System.out.println("Integer\n=======");
        System.out.println("before: " + integer);
        sub(new int[]{integer});
        System.out.println(" after: " + integer);
    }
}