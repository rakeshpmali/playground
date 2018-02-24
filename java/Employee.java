import java.io.*;

public class Employee {
    String sEmpName;
    int iEmpId;

    Employee() {
        System.out.println("Employee()"); 
        sEmpName = "Default";
    }
    
    Employee(String asEmpName) {
        System.out.println("Employee(String)"); 
        sEmpName = asEmpName; 
    }

    public void setEmpId(int aiEmpId) {
        iEmpId = aiEmpId;
    }

    public void printEmpInfo() {
        System.out.println("***\nEmp Name: "+sEmpName);
        System.out.println("Emp ID: "+iEmpId+"\n***");
    }

    public static void main(String args[]) {
        System.out.println("Employee main()"); 
        
        Employee empObj1 = new Employee();
        empObj1.setEmpId(0);

        Employee empObj2 = new Employee("Rakesh");
        empObj2.setEmpId(100);

        empObj1.printEmpInfo();
        empObj2.printEmpInfo();
    }
}
