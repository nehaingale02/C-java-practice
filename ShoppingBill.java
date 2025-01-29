import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;

class Product {
    int quantity;
    double rate, productTotal;
    String name, id;

    Product(String id, String name, double rate, int quantity, double productTotal) {
        this.id = id;
        this.name = name;
        this.rate = rate;
        this.quantity = quantity;
        this.productTotal = productTotal;
    }

    static void displayHeader() {
		
        
        System.out.println("---------------------------------------------------------------------------------");
        System.out.printf("%-10s %-15s %-10s %-10s %-10s\n", "ID", "Name", "Price", "Quantity", "Total");
        System.out.println("---------------------------------------------------------------------------------");
    }

    void displayProduct() {
        System.out.printf("%-10s %-15s %-10.2f %-10d %-10.2f\n", id, name, rate, quantity, productTotal);
    }
}

public class ShoppingBill {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Product> productList = new ArrayList<>();
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
        Date date = new Date();
        
        System.out.println("Enter Customer Name: ");
        String customerName = sc.nextLine();
        System.out.println("Enter Contact Number: ");
        String contactNumber = sc.nextLine();

        System.out.println("\nEnter the products (Press 'N' to stop): ");
        char choice = 'Y';
        int totalQuantity = 0;
        double totalAmount = 0;

        while (choice == 'Y' || choice == 'y') {
            System.out.print("Enter Product ID: ");
            String id = sc.next();
            System.out.print("Enter Product Name: ");
            String name = sc.next();
            System.out.print("Enter Price per Unit: ");
            double rate = sc.nextDouble();
            System.out.print("Enter Quantity: ");
            int quantity = sc.nextInt();

            double productTotal = rate * quantity;
            productList.add(new Product(id, name, rate, quantity, productTotal));
            totalAmount += productTotal;
            totalQuantity += quantity;

            System.out.print("Do you want to continue? (Y/N): ");
            choice = sc.next().charAt(0);
        }

        // Print bill header
		System.out.println("=================================================================================");
        System.out.println("\t\t\tWELCOME TO ONE STOP SUPERMARKET        ");
        System.out.println("=================================================================================");
		System.out.println("\n\t\t\t\t\t\t\tDate: " + formatter.format(date));
        System.out.println("---------------------------------------------------------------------------------");
        System.out.println("\t\t\t\t\tFinal Bill");
        System.out.println("---------------------------------------------------------------------------------");
		System.out.printf("%25s: %s\n", "Customer Name", customerName);
        System.out.printf("%25s: %s\n", "Contact No", contactNumber);

        Product.displayHeader();
        for (Product pr : productList) {
            pr.displayProduct();
        }

        System.out.println("---------------------------------------------------------------------------------");

        // Applying Discount
        double discount = totalAmount * 0.10;
        double gst = totalAmount * 0.12;
        double finalAmount = (totalAmount + gst) - discount;

        // Print totals
        System.out.printf("\t\t\t\t\t\t\tTotal: %.2f\n", totalAmount);
        System.out.println("\t\t\t\t\t\t\t----------------");
        System.out.printf("\t\t\t\t\t\t\tDiscount: -%.2f\n", discount);
        System.out.println("\t\t\t\t\t\t\t----------------");
        System.out.printf("\t\t\t\t\t\t\tGST (12%%): +%.2f\n", gst);
        System.out.println("\t\t\t\t\t\t\t----------------");
        System.out.printf("\t\t\t\t\t\t\tTOTAL PAYABLE: %.2f\n", finalAmount);
        System.out.println("---------------------------------------------------------------------------------");
        System.out.printf("\t\t\t\t\t\t\tTotal Quantity: %d\n", totalQuantity);
        System.out.println("---------------------------------------------------------------------------------");

        // Payment Method
        System.out.println("Payment Method:\n1. Cash\n2. Credit/Debit Card\n3. UPI");
        System.out.print("Choose (1/2/3): ");
        int paymentMethod = sc.nextInt();
        String paymentType = switch (paymentMethod) {
            case 1 -> "Cash";
            case 2 -> "Credit/Debit Card";
            case 3 -> "UPI";
            default -> "Cash";
        };
        System.out.printf("\t\t\t\t\t\t\tPayment Done via: %s\n", paymentType);
        System.out.println("---------------------------------------------------------------------------------");
        System.out.println("\t\t\tTHANK YOU FOR SHOPPING WITH US!");
        System.out.println("---------------------------------------------------------------------------------");

        sc.close();
    }
}

