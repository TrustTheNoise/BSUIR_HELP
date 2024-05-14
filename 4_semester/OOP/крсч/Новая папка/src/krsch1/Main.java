package krsch1;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		CBookCard book1 = new CBookCard("Александр Пушкин", "Евгений Онегин", "Издательство АСТ", 1833, 384, "821.3.38");
		book1.setRating(3);
		CBookCard book2 = new CBookCard("Фёдор Достоевский", "Преступление и наказание", "Издательство Эксмо", 1866, 480, "821.3.34");
        book2.setRating(2);

        System.out.println(book1);
        System.out.println();
        System.out.println(book2);

        CBookCard[] books = new CBookCard[5];
        books[0] = new CBookCard("Михаил Булгаков", "Мастер и Маргарита", "Издательство Эксмо", 1966, 416, "616.12-084.5");
        books[1] = new CBookCard("Лев Толстой", "Война и мир", "Издательство Азбука-Аттикус", 1869, 1296, "821.161.1");

        System.out.print("\n\n");
        
        System.out.println("\nДо сортировки:");
        for (int i = 0; i < books.length; i++) {
            if (books[i] != null) {
                System.out.println(books[i] + "\n");
            }
        }

        sortByYear(books);

        System.out.println("\nПосле сортировки:");
        for (int i = 0; i < books.length; i++) {
            if (books[i] != null) {
                System.out.println(books[i] + "\n");
            }
        }
    }
	
	public static void sortByYear(CBookCard[] books) {
		
		//Этот метод сортирует массив объектов CBookCard по их году.
		//Если оба или один из объектов равен null, они считаются равными.
		//Сортировка выполняется в порядке возрастания.
		
		Arrays.sort(books, (bookA, bookB) -> {
            if (bookA == null || bookB == null) {
                return 0;
            }
            return bookA.getYear() - bookB.getYear();
        });
    }
}
