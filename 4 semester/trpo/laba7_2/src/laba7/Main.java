package laba7;

import java.time.LocalDate;
import java.util.List;
import java.util.Scanner;

public class Main {
	private static Scanner scanner;
	
    public static void main(String[] args) {
        scanner = new Scanner(System.in);
        while(true) {
        	System.out.println("1. SQL Warehouse");
        	System.out.println("2. Server");
        	System.out.println("3. Exit");
        	int choise = scanner.nextInt();
        	scanner.nextLine();
        	switch (choise) {
	        	case 1:
	        		menu();
	        		break;
	        	case 2:
	        		serverStart();
	        		break;
	        	case 3:
	                scanner.close();
	                return;
	            default:
	                System.out.println("Invalid choise");
        	}
        }
    }
    
    private static void serverStart() {
    	try {    		
    		Server.start();
    	}catch (Exception e) {
    	    System.err.println("Произошла ошибка: " + e.getMessage());
    	    return;
    	}
    }
    
    private static void menu() {
    WarehouseDao warehouseDao = new WarehouseDao();
	int sector, row, place;
	boolean exit = false;
	 while (!exit) {
         System.out.println("1. Add product");
         System.out.println("2. Remove product");
         System.out.println("3. Find product by sector, row, place");
         System.out.println("4. Get products by date");
         System.out.println("5. All products");
         System.out.println("6. Exit");

         int choise = scanner.nextInt();
         scanner.nextLine();

         switch (choise) {
			case 1:
			warehouseDao.addWarehouse(createProduct());
			break;
            case 2:
            	System.out.print("Enter sector: ");
         		sector = scanner.nextInt();
         		
         		System.out.print("Enter row: ");
         		row = scanner.nextInt(); 
         		
         		System.out.print("Enter place: ");
         		place = scanner.nextInt();
         		 
         		warehouseDao.deleteWarehouse(sector, row, place);
                break;
            case 3:
            	try {
                     System.out.print("Enter sector: ");
                     sector = scanner.nextInt();
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

                 Product foundProduct = warehouseDao.getWarehouse(sector, row, place);
                 if (foundProduct != null) {
                     System.out.println(foundProduct);
                 }
                 break;
             case 4:
             	System.out.print("Enter from date (yyyy-MM-dd): ");
             	LocalDate from = LocalDate.parse(scanner.next());
             	System.out.print("Enter to date (yyyy-MM-dd): ");
             	LocalDate to = LocalDate.parse(scanner.next());
             	scanner.nextLine();

             	List<Product> productsByDate = warehouseDao.getWarehousesInDate(from.toString(), to.toString());
             	for (Product product : productsByDate) {
             	    System.out.println(product);
             	}
             	break;
             case 5:
            	 List<Product> products = warehouseDao.getAllWarehouses();
            	 for (Product product : products) {
            		 System.out.println(product);
            	 }
            	 break;
             case 6:
                 warehouseDao.closeConnection();
                 exit = true;
                 break;
             default:
                 System.out.println("Invalid choise");
         }
     }
    	 
    }
    
    private static Product createProduct() {	
    	System.out.print("Enter id: ");
		int id = scanner.nextInt();
	
		System.out.print("Enter sector: ");
		int sector = scanner.nextInt();
		
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
		
		return new Product(id, sector, row, place, quantity, date.toString());
    }
}