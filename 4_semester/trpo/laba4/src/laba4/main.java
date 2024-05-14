package laba4;

import java.time.LocalDate;
import java.util.List;
import java.util.Scanner;

public class main {
	private static Scanner scanner;
	
    public static void main(String[] args) {
        Warehouse warehouse = new Warehouse();
        String sector = null;
        scanner = new Scanner(System.in);
        
        menu(warehouse, sector);
    }
    
    private static void menu(Warehouse warehouse, String sector) {
    	int row, place;
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
                	 Product productToRemove = productToRemove();
                	 Product foundProductRemove = warehouse.findProduct(productToRemove.getSector(), 
                			 productToRemove.getRow(), productToRemove.getPlace());
                	 if (foundProductRemove != null) {
                    	 warehouse.removeProduct(foundProductRemove);
                     } else {
                         System.out.println("Product not found");
                     }
                     break;
                 case 3:
                	 try {
	                     System.out.print("Enter sector: ");
	                     sector = scanner.nextLine();
	                     System.out.print("Enter row: ");
	                     row = scanner.nextInt();
	                     System.out.print("Enter place: ");
	                     place = scanner.nextInt();
	                     scanner.nextLine();
                	 } catch (Exception e) {
                         System.out.println("Invalid input. Please try again.");
                         scanner.nextLine(); // clear the scanner buffer
                         continue;
                     }

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
			LocalDate date = null;
			while(true) {
				try {
					System.out.print("Enter date (yyyy-MM-dd): ");
					date = LocalDate.parse(scanner.next());
					break;
				}catch (Exception e) {
					System.out.println("Invalid input. Please try again.");
					scanner.nextLine(); // clear the scanner buffer
					continue;
				}
			}
			System.out.print("Enter quantity: ");
			int quantity = scanner.nextInt();
			scanner.nextLine();
			
			return new Product(sector, row, place, date, quantity);
    }
    
    private static Product productToRemove() {
    	while(true) {  
	    	try {
	            System.out.print("Enter sector: ");
	            String sector = scanner.nextLine();
	            System.out.print("Enter row: ");
	            int row = scanner.nextInt();
	            System.out.print("Enter place: ");
	            int place = scanner.nextInt();
	            scanner.nextLine(); // Очистка буфера сканера
	
	            // Создаем объект типа Product для удаления из склада
	            Product product = new Product(sector, row, place, null, 0);
	            return product;
	        } catch (Exception e) {
	            System.out.println("Invalid input. Please try again.");
	            scanner.nextLine(); // Очистка буфера сканера
	            continue;
	        }
    	}
    }
}
