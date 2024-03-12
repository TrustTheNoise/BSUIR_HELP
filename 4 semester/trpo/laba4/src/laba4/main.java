package laba4;

import java.time.LocalDate;
import java.util.List;
import java.util.Scanner;

public class main {
	private static Scanner scanner;
	
    public static void main(String[] args) {
        Warehouse warehouse = new Warehouse();
        String sector;
        int row, place;
        scanner = new Scanner(System.in);
        
        while (true) {
            System.out.println("1. Add product");
            System.out.println("2. Remove product");
            System.out.println("3. Find product by sector, row, place");
            System.out.println("4. Get products by date");
            System.out.println("5. Exit");

            int choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    warehouse.addProduct(createProduct());
                    break;
                case 2:
                    warehouse.removeProduct(productToRemove());
                    break;
                case 3:
                    System.out.print("Enter sector: ");
                    sector = scanner.nextLine();
                    System.out.print("Enter row: ");
                    row = scanner.nextInt();
                    System.out.print("Enter place: ");
                    place = scanner.nextInt();
                    scanner.nextLine();

                    Product foundProduct = warehouse.findProduct(sector, row, place);
                    if (foundProduct != null) {
                        System.out.println(foundProduct);
                    } else {
                        System.out.println("Product not found");
                    }
                    break;
                case 4:
                	System.out.print("Enter from date (yyyy-MM-dd): ");
                	LocalDate from = LocalDate.parse(scanner.next());
                	System.out.print("Enter to date (yyyy-MM-dd): ");
                	LocalDate to = LocalDate.parse(scanner.next());
                	scanner.nextLine();

                	List<Product> productsByDate = warehouse.getProductsByDate(from, to);
                	for (Product product : productsByDate) {
                	    System.out.println(product);
                	}
                	break;
                case 5:
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice");
            }
        }
    }
    
    private static Product createProduct() {
    	System.out.print("Enter sector: ");
        String sector = scanner.nextLine();
        System.out.print("Enter row: ");
        int row = scanner.nextInt();
        System.out.print("Enter place: ");
        int place = scanner.nextInt();
        System.out.print("Enter date (yyyy-MM-dd): ");
        LocalDate date = LocalDate.parse(scanner.next());
        System.out.print("Enter quantity: ");
        int quantity = scanner.nextInt();
        scanner.nextLine();

        return new Product(sector, row, place, date, quantity);
    }
    
    private static Product productToRemove() {
    	System.out.print("Enter sector: ");
        String sector = scanner.nextLine();
        System.out.print("Enter row: ");
        int row = scanner.nextInt();
        System.out.print("Enter place: ");
        int place = scanner.nextInt();
        scanner.nextLine();
        
        return new Product(sector, row, place, null, 0);
    }
}
